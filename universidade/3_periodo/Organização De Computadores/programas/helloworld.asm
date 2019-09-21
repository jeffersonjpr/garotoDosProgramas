.data
.align 4
helloWorld: .asciiz "Hello World \n"
.text

li $v0, 4
la $a0, helloWorld
syscall #chamada impressao

li $v0, 10
syscall #chamada exit