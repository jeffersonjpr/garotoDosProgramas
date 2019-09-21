.data
	vetor: .word 3
	
.text
	addi $t0, $zero, 42
	sw $t0, vetor + 4
	
	addi $t0, $zero, 10
	sw $t0, vetor
	
	addi $t0, $zero, 11
	sw $t0, vetor + 8
	
	lw $a0, vetor + 4
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall