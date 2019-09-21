.text
	li $t0, 5
	li $t1, 2
	
	divu $t3,$t0, $t1
	
	li $v0, 1
	move $a0, $t3
	syscall
	
	li $v0, 10
	syscall