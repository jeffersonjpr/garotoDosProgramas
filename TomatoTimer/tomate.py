import winsound
import time
import os


def bg():
    winsound.PlaySound("begin",winsound.SND_FILENAME)
def tm():
    tm = winsound.PlaySound("time",winsound.SND_FILENAME)
def mi():
    mi = winsound.PlaySound("minus",winsound.SND_FILENAME)
def ta():
    mi = winsound.PlaySound("tadaa",winsound.SND_FILENAME)



def tempo(m,xx,cont):
    sec = 0
    mino = 0
    hrs = 0

    m2 = 0.0
    while(m2 < m):
        if(sec >= 60):
            sec = 0
            mino += 1
        if(mino >= 60):
            mino = 0
            hrs +=1
        if(hrs >= 24):
            hrs = 0
        os.system('cls')
        sec+=1
        m2 += 0.0166666667
        if(xx == 1):
            print("---Work Time---")
        else:
            print("---Rest Time---")
        print("%iº round." % cont)
        print("%.2i:%.2i:%.2i/%.2i:%.2i:00" %(hrs,mino,sec,m/60,m%60))
        time.sleep(1)
    os.system('cls')
while(True):
    tom = float(input("Digite quantos minutos de trabalho: "))
    pausa = float(input("Digite quantos minutos de pausa: "))
    rounds = float(input("Digite a quantidade de Rounds: "))
    cont = 1
    """mi()"""
    while(rounds > 0):
        bg()
        tempo(tom,1,cont)
        tm()
        tempo(pausa,0,cont)
        tm()
        rounds -= 1
        cont += 1
    ta()
