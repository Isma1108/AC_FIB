 .text
	.align 4
	.globl Intercambiar
	.type Intercambiar,@function
Intercambiar:
	pushl %ebp
	movl %esp, %ebp
	subl $12, %esp
	pushl %ebx

	imul $12, 12(%ebp), %eax
	addl 8(%ebp), %eax				
	movb (%eax), %bl					
	imul $12, 12(%ebp), %ecx	
	addl 8(%ebp), %ecx			
	movb (%ecx), %dl					
	movb %dl, (%eax)					
	movb %bl, (%ecx)

	movl 4(%eax), %ebx
	movl 4(%ecx), %edx
	movl %edx, 4(%eax)
	movl %ebx, 4(%ecx)
	
	movl 8(%eax), %ebx
	movl 8(%ecx), %edx		
	movl %edx, 8(%eax)
	movl %ebx, 8(%ecx)

	popl %ebx								
	movl %ebp, %esp
	popl %ebp
	ret



