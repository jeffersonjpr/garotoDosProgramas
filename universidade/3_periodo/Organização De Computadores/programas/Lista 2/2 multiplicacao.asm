.data
	string: .asciiz "\n"
	string1: .asciiz "Primeiro numero:"
	string2: .asciiz "Segundo numero:"
	string3: .asciiz "Resultado:"
	
.text
	#lendo primeiro valor
	li $v0,4
	la $a0,string1
	syscall
	
	li $v0,5
	syscall
	move $s0,$v0
	
	#lendo segundo valor
	li $v0,4
	la $a0,string2
	syscall
	
	li $v0,5
	syscall
	move $s1,$v0
	
	## verificando se o resultado vai ser positivo ou negativo
	
	slt $t0, $s0, $zero # t0 = 1 se s0 < 0
	slt $t1, $s1, $zero # t1 = 1 se s1 < 0
	xor $t2, $t0, $t1   # t0 = t0 xor t1
	
	##invertendo sinais
	beq $t0, $zero, segundo
	sub $s0, $zero, $s0
		segundo:
	beq $t1, $zero, pronto
	sub $s1, $zero, $s1
	
	#preparando para chamar a funcao
		pronto:
	add $a0, $s0, $zero
	add $a1, $s1, $zero
	
	beq $t2, $zero, positivo #se t2 for verdadeiro, multiplicação positiva
	
	#chamada para resultado negativo
	jal multiplica
	sub $s1, $zero, $v0
	j final
	
	positivo:
	jal multiplica
	add $s1, $zero, $v0
	
	final:
		li $v0, 4
		la $a0, string3
		syscall
		
		li $v0, 1
		add $a0, $zero, $s1
		syscall
		
		j exit
		
	
	
multiplica:
	add $v0, $zero, $zero
	addi $t0, $zero, 0
	
	loop:
		beq $t0, $a0, fim
		
		add $v0, $v0, $a1
		addi $t0, $t0, 1
		
		j loop
	
	fim:
		jr $ra
	
exit:
	li $v0, 10
	syscall
	
	
	
	
