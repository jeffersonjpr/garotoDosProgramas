import random

lista =[]
while(True):
	a = random.randint(1,3)
	if(a not in lista):
		print(a)
		lista.append(a)
		input("Digite enter para continuar")
