grau = int(input("Digite o grau do seu polinomio: "))
poli= [] #lista que guarda os monomios
qci = []
divis=[]
x = 1
print("###Regras de digitação###")
print("Para variaveis use somente 'x'.")
print('Potenciacao use o sinal "**".')
print('Coloque o "*" entre as multiplicaçoes')
print("Se estiver faltando um ou mais monomios na expressao, utilize 1*1**b|b é o grau correspondente")
print("No monomio de primeiro grau eleve a 1")
print("Nunca deixe o x sozinho, sempre multiplique por 1 ou -1")
for i in range(grau,0,-1):#roda o loop para registrar todos monomios
    b = input("Digite o monomio de %iº grau: " % i)
    while True:#verifica se o monomio é valido
        while int(b[-1]) != i:
            print("Grau errado, digite novamente")
            b = input("Digite o monomio de %iº grau: " % i)
        try:
            eval(b)
            break
        except:
            print("Sintaxe errada, digite novamente.")
        b = input("Digite o monomio de %iº grau: " % i)
    poli.append(b)

b = input("Digite a constante: ")
while True:#verifica se a constante é valida
    try:
        int(b)
        break
    except:
        print("Valor errado, digite novamente")
    b = input("Digite a constante: ")
poli.append(int(b))
def quocientes(n):#cria uma lista com os quocientes
    del qci[:]
    for i in range(len(n)-1):
        atual = poli[i]
        quociatual = ""
        for i in atual:
            if i != "*":
                quociatual+=i
            else:
                break
        qci.append(int(quociatual))
    qci.append(poli[-1])
def divisores(n):
    del divis[:]
    n = int(n[-1])
    for i in range
        
            
            
        
        

    
    

