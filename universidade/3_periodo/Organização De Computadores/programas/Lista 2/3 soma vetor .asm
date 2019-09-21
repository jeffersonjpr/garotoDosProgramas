.data
.align 4
	vetor1: .space 20
	vetor2: .space 20
	string1: .asciiz "Primeiro vetor\n"
	string2: .asciiz "Segundo vetor\n"
	string3: .asciiz "º :"
	string4: .asciiz "\n"
	
	
.text
	#imprimeiro primeira mensagem
	li $v0, 4
	la $a0, string1
	syscall
	
	#chammando funcao de leitura primeiro vetor
	la $a0, vetor1
	jal lendovetor
	
	
	#imprimindo segudna mensagem
	li $v0, 4
	la $a0, string2
	syscall
	
	#chamando funcao de leitura segundo vetor
	la $a0,vetor2
	jal lendovetor
	
	
	#funcao soma
	la $a0, vetor1
	la $a1, vetor2
	jal somavetor
	
	
	#Imprimindo vetor resultante
	
	la $a0, vetor1
	jal printavetor
	
	li $v0, 10
	syscall
	

fim:
	jr $ra
	
#funcao para leitura de vetor
lendovetor:
	add $t0,$zero,$zero
	move $t2, $a0
	looplendo:
		beq $t0, 5, fim
		li $v0,1
		move $a0,$t0
		syscall
		
		li $v0, 4
		la $a0, string3
		syscall
		
		li $v0,5
		syscall
		move $t1, $v0
		
		sw $t1,0($t2)
		
		addi $t2, $t2, 4
		addi $t0, $t0, 1
		
		j looplendo

somavetor:
	add $t0, $zero, $zero
	move $t4, $a0
	move $t5, $a1
	loopsoma:
		beq $t0, 5, fim
		
		lw $t6, 0($t4)
		lw $t7, 0($t5)
		
		add $t2, $t6, $t7
		
		sw $t2, 0($t4)
		
		addi $t4, $t4, 4
		addi $t5, $t5, 4
		addi $t0, $t0, 1
		
		j loopsoma
		
printavetor:
	move $t1, $a0 #ponteiro
	add $t0, $zero, $zero #contador
	
	loopprinta:
		beq $t0, 5, fim
		lw $t2, 0($t1) #t2 = t1[0]
		
		#printado posicao
		li $v0, 1
		add $a0, $zero, $t0
		syscall
		
		#printado numero posicao
		li $v0, 4
		la $a0, string3 # "º :"
		syscall
		
		#printando conteudo posicao
		li $v0, 1
		add $a0, $t2, $zero
		syscall
		
		#printando qubra de linha
		li $v0, 4
		la $a0, string4
		syscall
		
		addi $t1, $t1, 4
		addi $t0, $t0, 1
		
		j loopprinta
		
