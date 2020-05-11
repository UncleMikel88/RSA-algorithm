from sys import exit
import math


# Funcion para calcular el exponente de cifrado
def decryptionExponent(p, q, e):
    d = 1
    while (d * e) % ((p - 1) * (q - 1)) != 1:
        d = d + 1
    return d


# Funcion para cifrar el mensaje
def encryptMessage(message, e, product):
    return int(math.pow(message, e) % product)

        
# Funcion para descifrar el mensaje
def decryptMessage(cipherMessage, d, product):
    return int(math.pow(cipherMessage, d) % product)

        
# Pedimos al usuario que introduzca numeros primos con el fin de construir las claves
p = int(input('Introduzca un numero primo >> '))
q = int(input('Introduzca un numero primo >> '))
N = p * q
e = int(input('Introduzca un exponente de cifrado: '))

# Comprobamos que el exponente de cifrado es válido
while math.gcd(e, (p - 1) * (q - 1)) != 1:
    printf('Exponente de cifrado no es valido')
    e = input('Pruebe con otro exponente de cifrado: ')

# Calculamos el exponente de descifrado 
d = decryptionExponent(p, q, e)

# Pedimos al usuario que introduzca un mensaje
print('\n');
print('El exponente de desencriptacion es >> {0}'.format(d))
print('No revele esta informacion a nadie!!\n\n')
m = int(input('Introduzca el mensaje que desea cifrar >> '))

# Ciframos el mensaje introducido por el usuario y a continuación lo desciframos
c = encryptMessage(m, e, N);
md = decryptMessage(c, d, N);

# Mostramos resultados en pantalla
print('Mensaje cifrado >> {0}'.format(c))
print('Mensaje descifrado >> {0}'.format(md))
