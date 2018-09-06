#include <stdio_ext.h>
#include <ctype.h>
#include "UTN_INPUT.h"

float pedirNumero(float resultado, char texto[], char textoError[])
{
    float num;

    printf("%s", texto);
    if(scanf("%f", &num)==1)
    {
        resultado = num;
    }
    else
    {
        printf("%s", textoError);
    }

    return resultado;
}

float calcularSuma(float numUno, float numDos)
{
    float resultado;

    resultado = numUno+numDos;
    printf("Sumando...\n");

    return resultado;
}

float calcularResta(float numUno, float numDos)
{
    float resultado;

    resultado = numUno-numDos;
    printf("Restando...\n");

    return resultado;
}

float calcularDivision(float numUno, float numDos)
{
    float resultado;

    if(numDos!=0)
    {
        resultado = numUno/numDos;
        printf("Dividiendo...\n");
    }

    return resultado;
}

float calcularMultiplicacion(float numUno, float numDos)
{
    float resultado;

    resultado = numUno*numDos;
    printf("Multiplicando...\n");

    return resultado;
}

int calcularFactorial(float numero)
{
    int resultado;

    if(numero==0)
    {
        resultado = 1;
        printf("Factorizando...\n");
    }
    else if(numero>0)
    {
        resultado = numero * calcularFactorial(numero -1);
    }

    return resultado;
}
