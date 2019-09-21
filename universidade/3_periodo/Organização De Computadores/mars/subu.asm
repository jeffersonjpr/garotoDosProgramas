.data
str_exit: .asciiz "testttt.txt"
str_data: .asciiz "Digite a quantidade de arquivos(max 10):"
str_data_end:

.text

file_open:
    li $v0, 13
    la $a0, str_exit
    li $a1, 1
    li $a2, 0
    syscall
file_write:
    move $a0, $v0
    li $v0, 15
    la $a1, str_data
    la $a2, str_data_end
    la $a3, str_data
    subu $a2, $a2, $a3
    syscall

    li $v0, 1
    add $a0, $a2, $zero
    syscall
file_close:
    li $v0, 16  
    syscall
