from sys import exit
import math

# Funcion para calcular el exponente de descifrado
def decryptionExponent(p, q, e):
    d = 1
    while (d * e) % ((p - 1) * (q - 1)) != 1:
        d = d + 1
    return d

# Funcion para cifrar el mensaje
def encryptMessage(message, e, product):
    return (message ** e) % product

# Funcion para descifrar el mensaje
def decryptMessage(cipherMessage, d, product):
    return (cipherMessage ** d) % product

# Pedimos al usuario que introduzca numeros primos con el fin de construir las claves
p = int(input('Introduzca un numero primo >> '))
q = int(input('Introduzca un numero primo >> '))
N = p * q
e = int(input('Introduzca un exponente de cifrado: '))

# Comprobamos que el exponente de cifrado es válido
while math.gcd(e, (p - 1) * (q - 1)) != 1:
    print('Exponente de cifrado no es valido')
    e = input('Pruebe con otro exponente de cifrado: ')

print('\n')
print('La clave publica es (N = {0}, e = {1})'.format(N, e))
print('Puede hacer publica esta informacion para que sus amigos le envien mensajes cifrados!')

# Calculamos el exponente de descifrado 
d = decryptionExponent(p, q, e)

print('\n');
print('El exponente de desencriptacion es >> {0}'.format(d))
print('La clave privada es (p = {0}, q = {1}, e = {2})'.format(p, q ,d))
print('No revele esta informacion a nadie!!\n\n')

# Pedimos al usuario que introduzca un mensaje
m = int(input('Introduzca el mensaje que desea cifrar >> '))

# Ciframos el mensaje introducido por el usuario y a continuación lo desciframos
c = encryptMessage(m, e, N);
md = decryptMessage(c, d, N);

# Mostramos resultados en pantalla
print('Mensaje cifrado >> {0}'.format(c))
print('Mensaje descifrado >> {0}'.format(md))
