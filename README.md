El programa simula el proceso de cifrado/descifrado RSA de un mensaje.

Se nos pedira dos números primos 'p' y 'q' para generar la clave pública N=p*q.
Se nos pedirá un exponente de cifrado 'e' (e informará de si es una opción válida), este exponente también forma parte de la clave pública.
El programa computa el exponente de descifrado 'd', este exponente forma parte de la clave privada. Solo debe conocerlo el receptor del 
mensaje.
El programa nos pide un mensaje 'm' y lo encripta con la clave pública previamente generada, es decir el par (N, e).
A continuación el programa desencripta el mensaje utilizando la clave privada, es decir el trio (p, q, d).

Nótese que el orden de magnitud de los números que suelen aparecer en estos computos son del orden de 2^100 incluso en los ejemplos
mas sencillos, desgraciadamente C no tiene tipos de datos predefinidos con este rango por tanto es muy posible que a menudo encontremos 
problemas de desbordamiento en este código.
