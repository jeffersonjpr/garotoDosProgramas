.data
.align 4

	localArquivo: .space 150				# String para guardar nome do arquivo
	resultado: .asciiz "resultado.pgm"			# Nome do modelo de fundo
	bbyte: .half 1						# Meia palavra reservada para leitura dos arquivos

	vetorDDA: .word 11					# 11 palavras, 1 resultado e 10 para arquivos

	# Mensagens de apoio
	mLarq: .asciiz "Digite o nome ou caminho do arquivo (com o %):"
	mLqnt: .asciiz "Digite a quantidade de arquivos(max 10):"
	mAerro: .asciiz "Erro, programa finalizado!"

.text
	#imprimindo mensagem de auxilio usuario
	li $v0, 4						# code sc 4 print string
	la $a0, mLarq						# endere�o da string
	syscall

	#lendo o nome do arquivo
	li $v0, 8						# code sc 8 ler string
	la $a0, localArquivo					# local da memoria para guardar input do ususario
	li $a1, 149						# tamanho maximo de caracteres (149 + NULL)
	syscall


	# removendo o '\n' inserido pelo enter
	la $a0, localArquivo					# preparando para chamada da funcao removebarran
	jal removebarran					# chamando removebarran


	#imprimindo mensagem de auxilio usuario
	li $v0, 4						# code sc 4 print string
	la $a0, mLqnt						# endere�o da string
	syscall

	#lendo quandidade de arquivos (maximo 10)
	li $v0, 5						# code sc 5 ler int
	syscall
	add $s0, $zero, $v0					# guardando o tamanho em s0
	#### $s0 = quantidade de arquivos

	bge $s0, 11, finalizandocomerro				# tamanho nao suportado
	blt $s0, 1, finalizandocomerro				# tamanho invalido

	add $a0, $s0, $zero					# quantidade de arquivos
	jal abreDescritores					# abrir todos os Descritores de arquivo no vetorDDA

	add $a0, $s0, $zero					# quantidade de arquivos
	jal contaResultado

	addi $a0, $s0, 1					#fechando os arquivos (arquivos + resultado)
	jal fechandoarquivos

	li $v0, 10
	syscall

#funcoes
contaResultado:
	add $t0, $a0, $zero					#salvando quantidade de arquivos
	loopprincipalcr:
		la $t1, vetorDDA + 4				# t1 = vetorDDA[1]
		# t2 resultado temporario
		add $t3, $t0, $zero				# t3 = tamanho para o loop secundario
		#t4 byte arquivo tual

		li $v0, 14					# code syscall ler arquivo
		lw $a0, 0($t1)					# dda primeiro arquivo
		la $a1, bbyte					# buffer 1 byte
		li $a2, 1					# ler 1 byte
		syscall
		ble $v0, $zero, fimlooppcr			# eof do primeiro arquivo

		lb $t4, bbyte					# t4 byte do arquivo atual
		addu $t2, $zero, $t4				# somando ao resutlado temporario
		addi $t3, $t3, -1
		add $t1, $t1, 4

		loopcrsecundario:
			beq $t3, $zero, continualoopcr
			li $v0, 14				# code syscall ler arquivo
			lw $a0, 0($t1)				# dda primeiro arquivo
			la $a1, bbyte				# buffer 1 byte
			li $a2, 1				# ler 1 byte
			syscall
			ble $v0, $zero, finalizandocomerro	# erro arquivos dimensoes diferentes

			lb $t4, bbyte				# t4 = byte do arquivo atual
			addu $t2, $t2, $t4			# somando ao resutlado temporario
			addi $t3, $t3, -1
			add $t1, $t1, 4
			j loopcrsecundario

		continualoopcr:
			div $t2, $t2, $t0
			sb $t2, bbyte				#guardando o resultado da divisao

			li $v0, 15				# code syscall escrever arquivo
			lw $a0, vetorDDA			# descritor de arquivo do resultado
			la $a1, bbyte				# byffer de saida
			li $a2, 1				# escrever 1 byte
			syscall
			j loopprincipalcr

	fimlooppcr:
		jr $ra


abreDescritores:
	addi $sp, $sp, -8
	sw $ra, 0($sp)						# guardando enderco de retorno
	sw $s0, 4($sp)						# guardando s0
	# s1 nao estava em uso

	add $s0, $a0, $zero					# quantidade de arquivos
	# s0 tem quantidade de arquivos
	jal achaporcentagem					# encontra endere�o porcentagem
	add $s1, $v0, $zero					# guardando retorno
	beq $s1, -1, finalizandocomerro				# nome arquivo invalido

	# s1 tem o enren�o do porcentagem

	addi $s2, $zero, 48					# codigo em ASCII para '0'
	sb $s2, 0($s1)						# mudando % para 0
	la $a0, localArquivo					# abrindo primeiro arquivo
	la $a1, 0
	jal abriarquivo

	blt $v0, $zero, finalizandocomerro			# erro ao abrir o 1� arquivo (nao existe ou nome errado)

	sw $v0, vetorDDA + 4					# guardando o dda do primeiro arquivo
	addi $s0, $s0, -1					# reduzindo tamanho de arquivos (ja abri o primeiro corretamente)

	la $a0, resultado					# abrindo o arquivo de resultado
	la $a1, 1						# para escrita
	jal abriarquivo

	blt $v0, $zero, finalizandocomerro			# caso aconte�a erro ao abrir o arquivo
	sw $v0, vetorDDA					# guardando o dda do arquivo de resultado

	jal greri
	add $s4, $v0, $zero					#guardando numero de bytes que serao ignorados
	# s4 numero de bytes ignorados

	la $s3, vetorDDA + 8					# carregando vetorDDA[3]
	addi $s2, $s2, 1					# aumentando s2
	loopabreDescritores:
		beq $s0, 0, fimlades				# fim do loop abredescritores
		sb $s2, 0($s1)					# modificando o indentificador do arquivo

		#abrindo arquivos
		la $a0, localArquivo				# abrindo i arquivo
		la $a1, 0
		jal abriarquivo
		ble $v0, $zero, finalizandocomerro

		sw $v0,0($s3)

		add $s3, $s3, 4					# aumentando i vetorDDA[i]
		add $s0, $s0, -1 				# diminuindo quantida de arquivos restantes

		add $a0, $v0, $zero				# descritor do arquivo atual
		add $a1, $s4, $zero				# numero de bytes a serem ignorados
		jal ignorabyte

		addi $s2, $s2, 1				# aumentando s2

		j loopabreDescritores


	fimlades:
		lw $ra, 0($sp)					# restaurando enderco de retorno
		lw $s0, 4($sp)					# restaurando registradores
		addi $sp, $sp, 8

		jr $ra


# funcao ignorabyte: ignora a1 bytes do arquivo a0
ignorabyte:							# ignorabyte
	add $t0, $a1, $zero					# contador de bytes
	loopignorabyte:
		beq $t0, $zero, fimignbyte
		li $v0, 14					# code syscall ler arquivo
		# a0 ja possui dda arquivo
		la $a1, bbyte					# buffer 1 byte
		li $a2, 1					# ler 1 byte
		syscall
		blt $v0, $zero, finalizandocomerro
		addi $t0, $t0, -1
		j loopignorabyte
	fimignbyte:
		jr $ra

# funcao grava o layot do resultado e retorna o numero de bytes que precisam ser ignorados nas outras imagens
greri:
	add $t0, $zero, $zero					# boleana para verifica�ao do comentario
	add $t1, $zero, $zero					# contador de ignora
	addi $t3, $zero, 3					# numero  de '\n' em um arquivo sem comentario
	loopgreri:
		beq $t3, $zero, fimmgreri
		li $v0, 14					# code syscall ler arquivo
		lw $a0, vetorDDA + 4				# dda do primeiro arquivo
		la $a1, bbyte					# buffer 1 byte
		li $a2, 1					# ler 1 byte
		syscall
		ble $v0, $zero, finalizandocomerro

		lb $t2, bbyte

		bne $t2, 35, barraene				# comparando come�o comentario
		bne $t0, $zero,	barraene			# comparando boleana
		addi $t3, $t3, 1				# adicionando mais 1 '\n' comentario
		addi $t0, $t0, 1				# ignorar possivel # dentro do comentario da segunda linha

		barraene:
		bne $t2, 10, continuagreri			# comparando fim de linha
		addi $t3, $t3, -1				# fim de linha alcan�ado

		continuagreri:
		addi $t1, $t1, 1				# bytes a serem ignorados

		# gravando modelo
		li $v0, 15					# code syscall escrever arquivo
		lw $a0, vetorDDA				# descritor de arquivo do resultado
		la $a1, bbyte					# byffer de saida
		li $a2, 1					# escrever 1 byte
		syscall
		j loopgreri

	fimmgreri:
	add $v0, $t1, $zero

	jr $ra


# funcao para abrir arquivo
abriarquivo:
	li $v0, 13						# code syscall abrir arquivo
	# a0 ja tem o nome do arquivo
	# a1 ja tem o tipo de abertura (leitura/escrita)
	li $a2, 0						# modo
	syscall
	#v0 ja tem o retorno
	jr $ra

# encontra o endereco da porcentagem na string que contem o nome do arquivo
achaporcentagem:
	la $t0, localArquivo					# carregando nome do arquivo
	loopap:
		lb $t1, 0($t0)					# primeiro byte do ponteiro
		beq $t1, 37, fimapsucesso			# comparando se e igual a porcentagem (37 em ASCII)
		beq $t1, 0, fimapfalha				# comparando se e igual a NULL (0 em ASCII)
		addi $t0, $t0, 1				# andando com o ponteiro da string
		j loopap
	fimapsucesso:
		add $v0, $t0, $zero				# retornando o endereco da string que contem o '%'
		jr $ra
	fimapfalha:
		addi $v0, $zero, -1				# nome de arquivo invalido
		jr $ra


## funcao removebarran: Substitui o \n (proveniente do input do syscall) do final da string por NULLO
## $a0 = ponteiro pro come�o da string
removebarran:
	addi $sp, $sp, -4					# recuando sp
	sw $t0, 0($sp)						# guardando t0

	lb $t0, 0($a0)						# guardando primeiro byte (1 caractere) contido em a0
	loopremovebn:
		beq $t0, '\n', fimlrbn				# compara�ao para saber se ja chegou no \n
		beq $t0, '\0', fimlrbn				# compara�ao para saber se chegou no final da string

		addi $a0, $a0, 1				# andando com o ponteiro da string
		lb $t0, 0($a0)					# guardando primeiro byte (1 caractere) contido em a0
		j loopremovebn
	fimlrbn:
		# a0 agora esta apontando pro \n da string
		sb $zero, 0($a0)				# substituindo o '\n' por null

		lw $t0, 0($sp)					# restaurando t0
		addi $sp, $sp, 4				# retornando sp a pos inicial

		jr $ra

# fecha todos os arquivos
# a0 tem quantidade de arquivos
fechandoarquivos:
	add $t0, $a0, $zero
 	la $t1, vetorDDA
	loopfda:
		beq $t0, $zero, fimfda
		li $v0, 16					# code syscall close file
		lw $a0, 0($t1)					# descritor de arquivo
		syscall
		addi $t1, $t1, 4
		addi $t0, $t0, -1
		j loopfda
	fimfda:
		jr $ra

finalizandocomerro:
	li $v0, 4						# code sc 4 print string
	la $a0, mAerro						# mensagem de erro
	syscall

	li $v0, 10
	syscall
