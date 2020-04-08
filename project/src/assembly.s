	.arch msp430g2553
	.p2align 1,0
	.text

	.data
state:	.word 1

	.text
jt:	.word default
	.word s1
	.word s2
	.word s3

	.global nextS
nextS:	mov &state, r12
	cmp #4, r12
	jnc default
	add r12, r12
	mov jt(r12), r0

s1:	mov #50, r12
	call #buzzer_set_period
	jmp out			

s2:	mov #600, r12
	call #buzzer_set_period
	jmp out

s3:	mov #0, r12
	call #buzzer_set_period
	jmp out

default:
	mov #100, r1
	call #buzzer_set_period
	jmp out

out:	pop r0
