.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo
	movl $1, %eax	
	movl 8(%ebp), %ecx

ini_for:
	cmpl 12(%ebp), %eax
	jge fi_for

ini_if:
	movl (%ecx, %eax, 4), %edx
	cmpl -4(%ebp), %edx
	jle fi_if
	movl %edx, -4(%ebp)

fi_if:
	incl %eax
	jmp ini_for

fi_for:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
