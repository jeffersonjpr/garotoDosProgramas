.data
	string1: .asciiz "Digite o "
	string2: .asciiz "º numero:"
	string3: .asciiz "(1) soma (2) subtracao (3) finalizar:"
	string4: .asciiz "Resultado: "
	string5: .asciiz "\n"
	
.text
	li $s0, 0
	
	loop:
		#printando opçoes
		li $v0, 4
		la $a0, string3
		syscall
		
		#lendo resposta
		li $v0, 5
		syscall
		move $t4, $v0 #movendo resposta para t0
		
		beq $t4, 1, leitura # r = 1 soma
		beq $t4, 2, leitura # r = 2 sub
		j fim               # else kill
		
		leitura:
			#imprimindo mensagem e pegando resultado primeiro elemento
			li $a1, 1
			jal leiturafunction
			move $t0, $v0
			
			#imprimindo mensagem e pegando resultado segundo elemento
			li $a1, 2
			jal leiturafunction
			move $t1, $v0
			
			beq $t4, 2, jumpsub
				jal somafunction
				move $t4,$t2
				j resultado
			jumpsub:
				jal subtracfunction
				move $t4,$t3
				j resultado
				
			resultado:
				li $v0, 4
				la $a0, string4
				syscall
				
				li $v0, 1
				move $a0, $t4
				syscall
				
				li $v0, 4
				la $a0, string5
				syscall
				
				j loop
				
	
		
	fim:
		li $v0, 10
		syscall
		
		
	
	leiturafunction:
		# digite o %i numero
		li $v0, 4
		la $a0, string1
		syscall
		
		li $v0, 1
		move $a0, $a1
		syscall
		
		li $v0, 4
		la $a0, string2
		syscall
		
		li $v0, 5
		syscall
		
		jr $ra
		#fim funcao
		
	somafunction:
		add $t2,$t0,$t1
		jr $ra
	subtracfunction:
		sub $t3,$t0,$t1
		jr $ra
		
		
		
		