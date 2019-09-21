.data
.align 4

	localArquivo: .word 25				# espaço para nome do arquivo ou caminho ate ele
	residuo: .asciiz "residuo.jprm"			# Arquivo utilizado para auxiliar no somatorio
	buffer: .word 3					# buffer
	bbyte: .word 1					# espaço para um byte
	
	#abaixo labels de manutencao
	mLarq: .asciiz "Digite o nome ou caminho do arquivo (com o %):"
	mLqnt: .asciiz "Digite a quantidade de arquivos(max 10):"
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
	
	#imprimindo mensagem de auxilio usuario
	li $v0, 4					# code v0 print string
	la $a0, mLqnt					# adresss para printar
	syscall
	
	#lendo quandidade de arquivos (maximo 10 temporariamente)
	li $v0, 5					# code v0 ler int
	syscall
	add $s0, $zero, $v0				# guardando o tamanho em s0
	#### $s0 = quantidade de arquivos
	
	add $s1, $zero, $zero				# contador loop principal
	#### $s1 = contador loop principal
	
	jal pegatamanho					# funcao que pega o tamanho da imagem
	
	add $s2, $v0, $zero				# guardando primeira dimensao em s2
	#### $s2 = primeira dimensao
	
	add $s3, $v1, $zero				# guardando segunda dimensao em s3
	#### $s3 = segunda dimensao
	
	li $v0, 1
	add $a0, $s2, $zero
	syscall
	
	#li $v0, 4
	#li $a0, 2560
	#syscall
	
	li $v0, 1
	add $a0, $s3, $zero
	syscall
	
	li $v0, 10
	syscall
		

#funcoes
pegatamanho:
	addi $sp, $sp, -8				# espaço para guardar 1 palavra: return adress
	sw $ra, 0($sp)					# guardando return adress
	sw $s0, 4($sp)					# guardando s0
	
	la $t0, localArquivo
	loopptAchaPct:					# loop para encontrar a posicao da porcentagem
		lb $t2, 0($t0)				# t2 recebe o primeiro byte de t0
		beq $t2, '%', fimlooppt			# comparacao porcentagem
		add $t0, $t0, 1				# incremento do ponteiro com o nome do arquivo
		j loopptAchaPct
		
	fimlooppt:					# agora t0 tem a posicao da porcentagem no nome do arquivo
		addi $t2, $zero, 48			# t2 = '0'
		sb $t2, 0($t0)				# mudando de '%' para '0'
		
		##apagar
		li $v0, 4
		la $a0, localArquivo
		syscall
		##apagar
		
		#abrindo a primeira imagem para buscar as dimensoes
		li $v0, 13				# code v0 abrir arquivo
		la $a0, localArquivo			# a0 = nome do arquivo
		add $a1, $zero, $zero			# argumento1= somente leitura
		add $a2, $zero, $zero
		syscall	
		add $s0, $v0, $zero			# s0 contem descritor do arquivo
		
		# ignorando o começo do arquivo
		li  $v0, 14				# code vo ler arquivo
		add $a0, $s0, $zero			# a0 da
		la $a1, buffer				# a1 enderco buffer
		li $a2 , 4				# lendo 4 bytes para ignorar a primeira linha do raquivo
		
		##apagar
		li $v0, 4
		la $a0, buffer
		syscall
		##apagar
		
		la $a0, buffer				
		li $a1, 5				# numero de bytes a serem resetados
		jal limpabuffer				# limpado o buffer
		
		li $v0, 14				# code v0 ler arquivo
		add $a0, $s0, $zero			# descritor do arquivo
		la $a1, buffer				# buffer
		li $a2, 1				# numero de bytes a serem lidos do arquivo
		
		lb $t2, buffer				# t2 recebe o conteudo do buffer(1 byte)
		
		la $t3, buffer				# guardando ederenco do buffer em t3
		
		bne $t2, '#', naotemcomentario
		#preparacao chamada funcao ignora comentario
		add $a0, $s0, $zero			# a0 contem o dda guardado em s0
		jal ignoracomentario
		j tevecomentario
		
		naotemcomentario:
			
			sb $t2, 0($t3)			#guardando o primeiro caratere no buffer
			addi $t3, $t3, 1		# andando uma posicao com o t3 (caso onde nao tem comentario)
			
		tevecomentario:
			
			add $a0, $s0, $zero
			add $a1, $t3, $zero
			jal pegaintArquivo
			
			##apagar
			li $v0, 4
			la $a0, buffer
			syscall
			##apagar
			
			la $a0, buffer
			jal pegaIntAscii
			add $t6, $v0, $zero
			
			la $a0, buffer				
			li $a1, 10				# numero de bytes a serem resetados
			jal limpabuffer				# limpado o buffer
			
			la $t3, buffer				# guardando ederenco do buffer em t3
			add $a0, $s0, $zero
			add $a1, $t3, $zero
			jal pegaintArquivo
			
			##apagar
			li $v0, 4
			la $a0, buffer
			syscall
			##apagar
			
			la $a0, buffer
			jal pegaIntAscii
			add $v1, $v0, $zero
			
			add $v0, $t6, $zero
			
			lw $ra, 0($sp)					# guardando return adress
			lw $s0, 4($sp)					# guardando s0
			addi $sp, $sp, 8				# espaço para guardar 1 palavra: return adress
			
			jr $ra
			
#funcao pegaintarquivo: le as dimensoes da 2/3 linha do arquivo
#a0 = descritor de arquivo
#a1 = buffer para ser armazenado
pegaintArquivo:
	addi $sp, $sp, -8				#recuando duas palavras no sp
	sw $t0, 0($sp)					# guardando t0 no sp
	sw $s0, 0($sp)					# guardando s0 no sp
	
	looppia:
		
		li $v0, 14				# code v0 ler arquivo
		add $a0, $s0, $zero			# descritor do arquivo
		la $a1, bbyte				# buffer
		li $a2, 5				# numero de bytes a serem lidos do arquivo
		syscall
		
		##apagar
		li $v0, 4
		la $a0, bbyte
		syscall
		##apagar
		
		#la $t0, bbyte				# guardando o endereco de bbyte em t0
		#lb $t0, 0($t0)				# carregando em t0 o conteudo de bbyte
		
		li $t0, 10
		beq $t0,' ',fimlooppia
		beq $t0,'\n',fimlooppia
		beq $t0,'\r',fimlooppia
		
		sb $t0, 0($a1)				# guardando em t3 o conteudo lido do arquivo
		addi $a1, $a1, 1			# andando um byte com t3
		
		j looppia
		
	fimlooppia:
		lw $t0, 0($sp)				# recuperando t0
		lw $s0, 4($sp)				# recuperando so
		addi $sp, $sp, 8			# retornando sp a pos inicial
		
		jr $ra
	
	
# procedimento ignora comentario $a0 recebe descritor de arquivo
# ignora o comentario da segunda linha byte a byte		
ignoracomentario:
	addi $sp, $sp, -8				# recuando 2 palavras no sp
	sw $t0, 0($sp)					# guardando t0 no sp
	sw $s0, 4($sp)					# guardando s0
	
	add $s0, $a0, $zero				# s0 recebe dda
	add $t0, $zero, $zero				# resetando t0
	
	loopigm:
		beq $t0, '\n', fimigcm
		
		li $v0, 14				# code v0 ler arquivo
		add $a0, $s0, $zero			# descritor do arquivo
		la $a1, buffer				# buffer
		li $a2, 1				# numero de bytes a serem lidos do arquivo
		
		lb $t0, buffer				# t0 o caratere do buffer
		j loopigm
		
	fimigcm:
		lw $t0, 0($sp)				#recuperando t0
		lw $s0, 4($sp)				# recuperando s0
		
		jr $ra
		
		
		
#procedimento limpabuffer, $a0 endereco do buffer $a1 quantidade de bytes
limpabuffer:
	addi $sp, $sp, -4				#recuando 4 posicoes com o sp
	sw $t0, 0($sp)					#guardando t0
	
	add $t0, $zero, $zero				#contador do loop
	
	looplimpabuffer:
		beq $t0, $a1, limpabufferfim		#comparacao do loop i < n
		sb $zero, 0($a0)			#"resetando" o byte
		addi $a0, $a0, 1			# andando com o ponteiro
		addi $t0, $t0, 1			# incrementando o contador
		j looplimpabuffer
	limpabufferfim:
		lw $t0, 0($sp)				# retornando o t0
		addi $sp, $sp, 4
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
		
		
		
		
		
		
