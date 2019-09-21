.data
str_exit: .asciiz "testeeoftxt.txt"

haha: .byte 1
.text
	
add $t0, $zero, $zero

file_open:
    li $v0, 13
    la $a0, str_exit
    li $a1, 0
    li $a2, 0
    syscall
    move $s0, $v0
    
loop:
	li $v0, 14
	add $a0, $s0, $zero
	la $a1, haha
	li $a2, 1
	syscall
	ble $v0, $zero, fimm
	addi $t0, $t0, 1
	j loop
fimm:
	li $v0, 1
	move $a0, $t0
	syscall
	
li $v0, 16
add $a0, $s0, $zero
syscall

li $v0, 10
syscall