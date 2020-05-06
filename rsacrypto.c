#include <stdio.h>

/******************************************/
/***CABECERAS DE LAS FUNCIONES DEFINIDAS***/
/******************************************/
unsigned long long gcd(unsigned long long a, unsigned long long b);
unsigned long long decryptionExponent(unsigned long long p, unsigned long long q, unsigned long long e);
unsigned long long encriptMessage(unsigned long long message, unsigned long long e, unsigned long long product);
unsigned long long decriptMessage(unsigned long long cipherMessage, unsigned long long d, unsigned long long product);
unsigned long long lpow(unsigned long long base, unsigned long long exponent);

/***********************/
/***FUNCION PRINCIPAL***/
/***********************/
int main(void)
{

    unsigned long long p;  //Numero primo arbitrario
    unsigned long long q;  //Numero primo arbitrario
    unsigned long long N;  // N = p * q
    unsigned long long e;  //Numero arbitario que satisfaga gcd(e, (p-1)*(q-1))=1 (exponente de cifrado)
    unsigned long long d;  //Exponente de desencriptado, se calcula mediante d * e = 1 mod((p-1)*(q-1))
    unsigned long long m;  //Mensaje (numero) a cifrar
    unsigned long long c;  //Mensaje cifrado
    unsigned long long md; // Mensaje original

    printf("Introduzca un numero primo >> ");
    scanf("%llu", &p);

    printf("Introduzca otro numero primo >> ");
    scanf("%llu", &q);

    N = p * q;

    printf("Introduzca un exponente de cifrado >> ");
    scanf("%llu", &e);

    while (gcd(e, (p - 1) * (q - 1)) != 1)
    {
        printf("\n");
        printf("Exponente de cifrado no es valido\n");
        printf("Pruebe con otro exponente de cifrado >> ");
        scanf("%llu", &e);
    }

    d = decryptionExponent(p, q, e);

    printf("\n");
    printf("El exponente de desencriptacion es >> %llu  \n", d);
    printf("No revele esta informacion a nadie!!\n\n");
    printf("Introduzca el mensaje que desea cifrar >> ");
    scanf("%llu", &m);

    c = encriptMessage(m, e, N);

    md = decriptMessage(c, d, N);

    printf("\n");
    printf("Mensaje cifrado >> %llu\n", c);
    if (md == d)
    {
        printf("Mensaje descifrado >> %llu", md);
    }
    else
    {
        printf("Mensaje descifrado >> OVERFLOW ERROR!!", md);
    }

    return 0;
}

/****************************************/
/***FUNCIONES DEFINIDAD POR EL USUARIO***/
/****************************************/

/*GCD CALCULA EL MAXIMO COMUN DIVISOR DE DOS NUMEROS*/
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    unsigned long long temp;
    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

/*DECRYPTIONEXPONENT RESUELVE UNA ECUACION PARA HALLAR EL EXPONENTE DE DESENCRIPTAMIENTO*/
unsigned long long decryptionExponent(unsigned long long p, unsigned long long q, unsigned long long e)
{

    unsigned long long d = 1;

    while ((d * e) % ((p - 1) * (q - 1)) != 1)
    {
        d++;
    }

    return d;
}

/*ENCRIPTMESSAGE ENCRIPTA UN MENSAJE (NUMERO)*/
unsigned long long encriptMessage(unsigned long long message, unsigned long long e, unsigned long long product)
{
    unsigned long long cipherMessage = lpow(message, e) % product;
    return cipherMessage;
}

/*DECRYPTMESSAGE DESENCRIPTA EL MENSAJE CIFRADO*/
unsigned long long decriptMessage(unsigned long long cipherMessage, unsigned long long d, unsigned long long product)
{
    unsigned long long message = lpow(cipherMessage, d) % product;
    return message;
}

unsigned long long lpow(unsigned long long base, unsigned long long exponent)
{
    unsigned long long res = 1;
    unsigned long long i = 1;

    for (i = 1; i <= exponent; i++)
    {
        res *= base;
    }
    return res;
}
