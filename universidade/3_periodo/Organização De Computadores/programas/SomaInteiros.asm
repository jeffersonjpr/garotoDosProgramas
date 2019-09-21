.data

string1: .asciiz "Digite o primeiro inteiro:"
string2: .asciiz "Digite o segundo inteiro:"
string3: .asciiz "Soma:"

.text

# A
# imprimindo primeira mensagem
li $v0,4
la $a0,string1
syscall

# lendo primeiro valor
li $v0,5
syscall
move $t0, $v0 ##movento o valor informado pelo usuario para t0

# B
# imprimindo a segunda mensagem
li $v0,4
la $a0,string2
syscall

#lendo segundo valor
li $v0,5
syscall

# A + B

add $t0,$t0,$v0 #soma

#imprimindo mensagem final
li $v0,4
la $a0,string3
syscall

#imprimindo resultado
li $v0,1
move $a0,$t0
syscall

#FINALIZANDO
li $v0,10
syscall