	.arch msp430g2553
	.p2align 1,0
	.text


	.global assembleAdvance
button2State:	add #1, &assembleAdvance
	cmp #2, &assembleAdvance
