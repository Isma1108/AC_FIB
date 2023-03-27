.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
	xorl %eax, %eax
	movl 8(%ebp), %ecx
	movl $0, -4(%ebp)

for1:
	cmpl $3, %eax
	jge fi_for1
	xorl %ebx, %ebx

for2:
	cmpl $3, %ebx
	jge fi_for2
	imul $3, %eax, %edx
	addl %ebx, %edx
	movl (%ecx, %edx, 4), %edx
	addl %edx, -4(%ebp)
	addl 12(%ebp), %ebx
	jmp for2

fi_for2:
	addl 12(%ebp), %eax
	jmp for1

fi_for1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
