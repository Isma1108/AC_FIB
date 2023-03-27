# Traduccion ej 1:

					movl 8(%ebp), %ecx
					movl $1, -8(%ebp)
ini_for:	movl -8(%ebp), %eax 
					cmpl 12(%ebp), %eax
					jge fi_for
if_cond:	movl (%ecx, %eax, 4), %eax
					cmpl -4(%ebp), %eax
					jle fi_if
					movl %eax, -4(%ebp)
fi_if:		incl -8(%ebp)
					jmp ini_for
fi_for:		
