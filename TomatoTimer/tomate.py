import winsound
import time
import os


def bg():
    winsound.PlaySound("begin",winsound.SND_FILENAME)
def tm():
    tm = winsound.PlaySound("time",winsound.SND_FILENAME)
def mi():
    mi = winsound.PlaySound("minus",winsound.SND_FILENAME)


def tempo(m):
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
        print("Maximo em minutos:%.2f"%m)
        print("%i:%i:%i" %(hrs,mino,sec))
        time.sleep(1)
while(True):
    tom = float(input("Digite quantos minutos de trabalho: "))
    pausa = float(input("Digite quantos minutos de pausa: "))
    mi()
    bg()
    tempo(tom)
    tm()
    tempo(pausa)
    mi()
    bg()
    tempo(tom)
    tm()
