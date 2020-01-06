# CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
# Harjoitus 3, tehtävä 2
# Topi Jussinniemi, 0401301
# 99beers_skeleton.s
.data
	msg1:	.string "Lauletaanpa muutama säkeistö!\n"
	msg2:	.string "%d bottles of beer on the wall. "
	msg3:	.string "%d beers. "
	msg4:	.string "Take one, pass it around. %d beers on the wall.\n"
	i:	.quad 99
	j:	.quad 98
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
	movq	i, %rsi
	movq	$msg3, %rdi
	call printf
	movq	j, %rsi
	movq	$msg4, %rdi
	call	printf
	decq	j
	decq	i
	cmpq	$94, i
	jne	loop
	movq	%rbp, %rsp
	popq	%rbp
	ret	$0


