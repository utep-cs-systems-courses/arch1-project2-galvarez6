	.arch msp430g2553
	.p2align 1,0
	.text

	.data
ss:
	.word 1 		;static variable to start at state1

	.text
jt:	
	.word default		;jt[0]
	.word s1		;jt[1]
	.word s2		;jt[2]
	.word s3		;jt[3]

	.global nextS
nextS:
	cmp #4, &ss		;stay within range for the amount of states
	jnc default		;if ss is greater than 3 it will jump to default
	
	mov &ss, r12		;index in jt
	add r12, r12		;for referencing the correct case
	mov jt(r12), r0		;jmp to jt[ss]

s1:	mov #500, r12		;pass parameter for set buzzer period 
	call #buzzer_set_period	;then call the method
	jmp out			;break


s2:	mov #700, r12
	call #buzzer_set_period
	jmp out


s3:	mov #0, r12
	call #buzzer_set_period
	jmp out


default:
	mov #0, r12
	call #buzzer_set_period
	jmp out

out:	pop r0
