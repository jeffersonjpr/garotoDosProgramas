.data
.align 4

localArquivo: .space 150
resultado: .asciiz "resultado.pgm"
bbyte: .half 1

vetorDDA: .word 11

mLarq: .asciiz "Digite o nome do arquivo (com o %):"
mLqnt: .asciiz "Digite a quantidade de arquivos(max 10):"
mAerro: .asciiz "Erro, programa finalizado!"
ln: .asciiz "\n"

.text
	li $v0, 4
	la $a0, mLarq
	syscall
	li $v0, 8
	la $a0, localArquivo
	li $a1, 149
	syscall

	la $a0, localArquivo
	jal removebarran

	li $v0, 4
	la $a0, mLqnt
	syscall
	li $v0, 5
	syscall
	add $s0, $zero, $v0

	bge $s0, 11, finalizandocomerro
	blt $s0, 1, finalizandocomerro

	add $a0, $s0, $zero
	jal abreDescritores

	add $a0, $s0, $zero
	jal contaResultado

	addi $a0, $s0, 1
	jal fechandoarquivos

	li $v0, 10
	syscall

contaResultado:
	add $t0, $a0, $zero
	loopprincipalcr:
		la $t1, vetorDDA + 4
		add $t3, $t0, $zero

		li $v0, 14
		lw $a0, 0($t1)
		la $a1, bbyte
		li $a2, 1
		syscall
		ble $v0, $zero, fimlooppcr

		lb $t4, bbyte
		addu $t2, $zero, $t4
		addi $t3, $t3, -1
		add $t1, $t1, 4

		loopcrsecundario:
			beq $t3, $zero, continualoopcr
			li $v0, 14
			lw $a0, 0($t1)
			la $a1, bbyte
			li $a2, 1
			syscall
			ble $v0, $zero, finalizandocomerro

			lb $t4, bbyte
			addu $t2, $t2, $t4
			addi $t3, $t3, -1
			add $t1, $t1, 4
			j loopcrsecundario

		continualoopcr:
			div $t2, $t2, $t0
			sb $t2, bbyte

			li $v0, 15
			lw $a0, vetorDDA
			la $a1, bbyte
			li $a2, 1
			syscall
			j loopprincipalcr

	fimlooppcr:
		jr $ra


abreDescritores:
	addi $sp, $sp, -8
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	add $s0, $a0, $zero

	jal achaporcentagem
	add $s1, $v0, $zero
	beq $s1, -1, finalizandocomerro


	addi $s2, $zero, 48
	sb $s2, 0($s1)
	la $a0, localArquivo
	la $a1, 0
	jal abriarquivo

	blt $v0, $zero, finalizandocomerro

	sw $v0, vetorDDA + 4
	addi $s0, $s0, -1

	la $a0, resultado
	la $a1, 1
	jal abriarquivo

	blt $v0, $zero, finalizandocomerro
	sw $v0, vetorDDA

	jal greri
	add $s4, $v0, $zero

	la $s3, vetorDDA + 8
	addi $s2, $s2, 1

loopabreDescritores:
	beq $s0, 0, fimlades
	sb $s2, 0($s1)

	la $a0, localArquivo
	la $a1, 0
	jal abriarquivo
	ble $v0, $zero, finalizandocomerro

	sw $v0,0($s3)

	add $s3, $s3, 4
	add $s0, $s0, -1

	add $a0, $v0, $zero
	add $a1, $s4, $zero
	jal ignorabyte

	addi $s2, $s2, 1

	j loopabreDescritores


fimlades:
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	addi $sp, $sp, 8

	jr $ra



ignorabyte:
	add $t0, $a1, $zero
	loopignorabyte:
		beq $t0, $zero, fimignbyte
		li $v0, 14

		la $a1, bbyte
		li $a2, 1
		syscall
		blt $v0, $zero, finalizandocomerro
		addi $t0, $t0, -1
		j loopignorabyte
	fimignbyte:
		jr $ra


greri:
	add $t0, $zero, $zero
	add $t1, $zero, $zero
	addi $t3, $zero, 3
	loopgreri:
		beq $t3, $zero, fimmgreri
		li $v0, 14
		lw $a0, vetorDDA + 4
		la $a1, bbyte
		li $a2, 1
		syscall
		ble $v0, $zero, finalizandocomerro

		lb $t2, bbyte

		bne $t2, 35, barraene
		bne $t0, $zero,	barraene
		addi $t3, $t3, 1
		addi $t0, $t0, 1

		barraene:
		bne $t2, 10, continuagreri
		addi $t3, $t3, -1

		continuagreri:
		addi $t1, $t1, 1

		li $v0, 15
		lw $a0, vetorDDA
		la $a1, bbyte
		li $a2, 1
		syscall
		j loopgreri

	fimmgreri:
	add $v0, $t1, $zero

	jr $ra

abriarquivo:
	li $v0, 13
	li $a2, 0
	syscall
	jr $ra

achaporcentagem:
	la $t0, localArquivo
	loopap:
		lb $t1, 0($t0)
		beq $t1, 37, fimapsucesso
		beq $t1, 0, fimapfalha
		addi $t0, $t0, 1
		j loopap
	fimapsucesso:
		add $v0, $t0, $zero
		jr $ra
	fimapfalha:
		addi $v0, $zero, -1
		jr $ra


removebarran:
	addi $sp, $sp, -4
	sw $t0, 0($sp)

	lb $t0, 0($a0)
	loopremovebn:
		beq $t0, '\n', fimlrbn
		beq $t0, '\0', fimlrbn

		addi $a0, $a0, 1
		lb $t0, 0($a0)
		j loopremovebn
	fimlrbn:
		sb $zero, 0($a0)

		lw $t0, 0($sp)
		addi $sp, $sp, 4

		jr $ra

fechandoarquivos:
	add $t0, $a0, $zero
 	la $t1, vetorDDA
	loopfda:
		beq $t0, $zero, fimfda
		li $v0, 16
		lw $a0, 0($t1)
		syscall
		addi $t1, $t1, 4
		addi $t0, $t0, -1
		j loopfda
	fimfda:
		jr $ra

finalizandocomerro:
	li $v0, 4
	la $a0, mAerro
	syscall

	li $v0, 10
	syscall
