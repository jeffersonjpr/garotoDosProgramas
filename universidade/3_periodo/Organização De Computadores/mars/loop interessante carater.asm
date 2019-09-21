.data
.align 4

string: .asciiz "teste%.txt"
nl: .asciiz "\n"
char:  .ascii "0"

.text
	la $s0,string
	lb $t2, nl
	
	lb $t0, 0($s0)	
	loop:
		beq $t0, '\0', mudando
		
		add $a0, $zero, $t0
		li $v0, 11
		syscall
		
		addi $s0, $s0, 1	# andando um byte com o ponteiro
		lb $t0, 0($s0)		#
		j loop
		
mudando:
	li $v0, 4
	la $a0, nl
	syscall 
	
	la $s0,string
	lb $t0, 0($s0)	
	mudandoc:
		beq $t0, '\0', continuando
		
		lb $t1, 0($s0)		#t1 = so[0]
		bne $t1, '%', ignora
		lb $t1, char
		sb $t1, 0($s0)		#mudando % para 0
		
		ignora:
		addi $s0, $s0, 1	# andando um byte com o ponteiro
		lb $t0, 0($s0)		#
		j mudandoc
		
continuando:
	la $s0,string
	lb $t2, nl
	
	lb $t0, 0($s0)	
	loop2:
		beq $t0, '\0', fim
		
		add $a0, $zero, $t0
		li $v0, 11
		syscall
		
		addi $s0, $s0, 1	# andando um byte com o ponteiro
		lb $t0, 0($s0)		#
		j loop2
	
	
fim:
	li $v0, 1
	li $a0, 'a'
	syscall
	
	li $v0, 10
	syscall
	

