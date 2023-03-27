 .text
	.align 4
	.globl Ordenar
	.type Ordenar,@function
Ordenar:
	pushl %ebp
	movl %esp, %ebp
	subl $8, %esp
	pushl %ebx			#ebx <- i
	pushl %esi 			#esi <- j
	pushl %edi			#edi <- @v
	xorl %ebx, %ebx
	movl 8(%ebp), %edi

for1:
	imul $12, %ebx, %eax
	cmpl $0x80000000, 4(%edi, %eax)
	je fi_for1
	movl %ebx, %esi
	incl %esi

for2:
	imul $12, %esi, %eax
	cmpl $0x80000000, 4(%edi, %eax)
	je fi_for2

if:
	imul $12, %ebx, %ecx
	movl 4(%edi, %ecx), %ecx
	cmpl %ecx, 4(%edi, %eax)
	jge fi_if
	pushl %esi
	pushl %ebx
	pushl %edi
	call Intercambiar 
	addl $12, %esp

fi_if:
	incl %esi
	jmp for2

fi_for2:
	incl %ebx
	jmp for1

fi_for1:
	movl %ebx, %eax
	popl %edi
	popl %esi
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret

