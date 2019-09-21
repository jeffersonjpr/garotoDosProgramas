.data
	vetor: .word 2
.text
	la $t0,vetor #copiando ponteiro
	li $t1,1 # n iteraçao loop
	
	loop:
		beq $t1,11,fim
		sw $t1,0($t0) # t0[i] = i
		addi $t0,$t0,4 # movendo ponteiro para frente
		addi $t1,$t1,1 # aumentando indice
		j loop
	fim:
		li $v0,10
		syscall