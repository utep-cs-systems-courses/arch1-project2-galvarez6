	.arch msp430g2553
	.p2align 1,0
	.text


	.global add2State
add2State:	add #1, &add2State
	cmp #2, &add2State
