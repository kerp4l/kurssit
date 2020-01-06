.data
	msg1:	.string "Counting \n"
	msg2:	.string "%d\n"
	i:	.quad 10
		.text
		.global main
main:
	pushq	%rbp
	movq	%rsp ,%rbp
	movq	$msg1, %rdi
	call	printf
loop:
	movq	i, %rsi
	movq	$msg2, %rdi
	call	printf
	decq	i
	cmpq	$0, i
	jne	loop
	movq	%rbp, %rsp
	popq	%rbp
	ret	$0
