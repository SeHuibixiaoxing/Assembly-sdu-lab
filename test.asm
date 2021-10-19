code segment
     assume cs:code
main	proc	far
	push	ds
	sub		ax, ax
	push	ax
start:
	ret
main	endp
code	ends
end		main