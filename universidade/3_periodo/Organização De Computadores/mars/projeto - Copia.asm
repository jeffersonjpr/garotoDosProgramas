.data
.align 4

	localArquivo: .word 25				# espaço para nome do arquivo ou caminho ate ele
	residuo: .asciiz "residuo.jprm"			# Arquivo utilizado para auxiliar no somatorio
	
	#abaixo labels de manutencao
	mLarq: .asciiz "Digite o nome ou caminho do arquivo (com o %):"
.text
	#imprimindo mensagem de auxilio usuario
	li $v0, 4					# code v0 print string
	la $a0, mLarq					# adresss para printar
	syscall
	
	#lendo o caminho/nome do arquivo
	li $v0, 8					# code v0 ler string
	la $a0, localArquivo				# local da memoria input do arquivo
	li $a1, 100					# tamanho maximo de caracteres (99 + NULL)
	syscall
	
	#lendo quandidade de arquivos (maximo 10 temporariamente)
	li $v0, 5					# code v0 ler int
	syscall
	add $s0, $zero, $v0				# guardando o tamanho em s0
	#### $s0 = quantidade de arquivos
	
	add $s1, $zero, $zero				# contador loop principal
	#### $s1 = contador loop principal
	
	jal pegatamanho					# funcao que pega o tamanho da imagem
	
	mainLoop:
		beq $s0, $s1, NAOFIZAINDA
		

#funcoes
pegatamanho:
	addi $sp, $sp, -4				# espaço para guardar 1 palavra: return adress
	sw $ra, 0($sp)					# guardando return adress
	
	la $t0, localarquivo
	loopptAchaPct:					# loop para encontrar a posicao da porcentagem
		lb $t2, 0($t0)				# t2 recebe o primeiro byte de t0
		beq $t2, '%', fimlooppt			# comparacao porcentagem
		add $t0, $t0, 1				# incremento do ponteiro com o nome do arquivo
	fimlooppt:					# agora t0 tem a posicao da porcentagem no nome do arquivo
		addi $t2, $zero, 48			# t2 = '0'
		sb $t2, 0($t0)				# mudando de '%' para '0'
		
		#abrindo a primeira imagem para buscar as dimensoes
		li $v0, 13				# code v0 abrir arquivo
		la $a0, localarquivo			# a0 = nome do arquivo
		add $a1, $zero, $zero			# argumento1= somente leitura
		syscall
		add $t2, $zero, $v0			# t2 recebe o ponteiro para o começo do arquivo
		
		# ignorando o começo do arquivo
		addi $t2, $t2, 4			# ignorando a string "P5/r/n" do começo do arquivo
		lb $t1, 0($t2)				# carregando primeiro byte de t2 em t1
		bne $t1, '#', ignoraloopignora		# verificando se a segunda linha nao tem comentario
		loopignora:				# ignorando comentario da segunda linha
			addi $t2, $t2, 1		# incrementando o ponteiro de t2, ja considera o #, se existir
			lb $t1, 0($t2)			# carrega o primeiro byte de t2 em t1
			beq $t1, '\n', fimloopignora	# verificando se ele chegou na quebra de linha
			j loopignora
		fimloopignora:
			addi $t2, $t2, 1		# incrementando o ponteiro para sair do '\n'
		ignoraloopignora:
			
			
			
			
ignoracomentario:
	addi $sp, $sp, -4				# recuando 1 palavra no sp
	sw $t0, 0($sp)					# guardando t0 no sp
	
	loopigcmt:					#loop para ignorar o comentario
		lb $t0, 0($a0)				# carregando primeiro byte de $a0
		beq $t0, '\n', fimloopigmct		# verifica se chegou na quebra de linha
		addi $a0, $a0, 1			# anda 1 com o ponteiro
	fimloopigmct:
		#a0 agora ta apontando pro \n do comentario
		addi $a0, $a0, 1			# a0 agora esta apontando pra primeira dimensao
		add $v0, $a0, $zero			# retorno da funcao
		lw $t0, 0($sp)				# carregando o t0 anterior
		addi $sp, $sp, 4			# retornando sp a posiçao inicial
		jr $ra
		
#funcao que recebe uma string ascii (finalizado por null, espaço ou retorno de carro) contendo um numero inteiro positivo  e retorna em int
pegaIntAscii:						#funcao pegaintascii $a0 = string finalizada por (null/espaço/retorno de carro) $v0 = numero inteiro TESTADA FUNCIONANDO
	addi $t0, $zero, 1				# contador da volta
	addi $t1, $zero, 1				# base 10 para multiplicação
	add $v0, $zero, $zero				# retorno da funcao
	pegaintloop:					
		lb $t2, 1($a0)				# t2 recebe a proxima posiçao de a0
		beq $t2, '\r', voltapegaint		#
		beq $t2, '\n', voltapegaint		## comparaçoes de fim de texto
		beq $t2, '\0', voltapegaint		#
		beq $t2, ' ', voltapegaint		# espaço
		
		addi $a0, $a0, 1			# prox pos ponteiro string
		addi $t0, $t0, 1			# incremento do contador de volta
		j pegaintloop
		
	voltapegaint:
		beq $t0, $zero, fimpegaint		# compara se o contador de volta é igual a zero
		
		lb $t3, 0($a0)				# t3 vai receber o valor da ascii 
		addi $t4, $zero, -48			# 48 é o valor em ascii do caractere 0
		add $t3, $t3, $t4			# t3 agora representa o valor corretamente na casa das unidades
		
		mul $t3, $t3, $t1			# t3 agora representa o valor na sua ordem correta
		
		add $v0, $v0, $t3			# somando ao resultado final
		addi $a0, $a0, -1			# retornando com o ponteiro
		addi $t0, $t0, -1			# decremento do contador de volta
		mul $t1, $t1, 10			# incremento da ordem de t1
		j voltapegaint
	fimpegaint:
		jr $ra
		
		
		
		
		
		
