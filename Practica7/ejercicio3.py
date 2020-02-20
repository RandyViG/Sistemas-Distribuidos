from random import randint

cadenota=""
for i in range(87000000):
    cadena = ''
    for j in range(3):
        c = chr(randint(65,80))
        cadena += c
    cadenota += cadena + ' '
    
cont = cadenota.count('IPN')
#print("La cadenota es : \n")
#print(cadenota)
print("Apariciones de IPN: {}".format(cont))

