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
		beq $t0, '\0', fim
		
		add $a0, $zero, $t0
		li $v0, 11
		syscall
		
		addi $s0, $s0, 1	# andando um byte com o ponteiro
		lb $t0, 0($s0)		#
		j loop
		
	
fim:
	li $v0, 10
	syscall
	

