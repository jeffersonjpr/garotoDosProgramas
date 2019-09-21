.data
	
	vet: -11,-10,0,-3,-100
	maior: .asciiz "O maior é: "
	menor: .asciiz "O menor é "
	quebra: .asciiz "\n"
.text

	main:
		addi $s0, $zero, 0 #indice vetor --> n precisa começar no 1 espaco
		addi $t7, $zero, 5 #iteracao 
		
		lw $t2, vet($s0)
		add $s1, $zero, $t2 # s1 = 1 espaco do vetor
		add $s2, $zero, $t2 # s2 = 2 espaco do vetor
		
		while:
			beqz $t7, fim
			
			lw $t2, vet($s0)
			
			slt $t0, $t2, $s2
			sgt $t1, $t2, $s1
			
			addi $t7, $t7, -1
			addi $s0, $s0, 4
			
			beqz $t0, maiors
			add $s2, $zero, $t2
			
			maiors:
				beqz $t1, while
				add $s1, $zero, $t2
				j while
			
		fim:
			
			li $v0, 4
			la $a0, maior
			syscall
			
			li $v0, 1
			add $a0, $zero, $s1
			syscall
			
			li $v0, 4
			la $a0, quebra
			syscall
			
			li $v0, 4
			la $a0, menor
			syscall
			
			li $v0, 1
			add $a0, $zero, $s2
			syscall
			
			li $v0, 10
			syscall