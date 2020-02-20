import math
i=0.0
seno = 0.0
coseno = 0.0
tangente = 0.0
logaritmo = 0.0
raizCuad = 0.0

while(i < 87000000):
    seno += math.sin(i)
    coseno += math.cos(i)
    tangente += math.tan(i)
    logaritmo += math.log(i+1)
    raizCuad += math.sqrt(i)
    i+=1

print('seno {}'.format(seno))
print('coseno {}'.format(coseno))
print('tangente {}'.format(tangente))
print('logaritmo {}'.format(logaritmo))
print('raiz {}'.format(raizCuad))