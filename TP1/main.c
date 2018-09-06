#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "UTN_INPUT.h"

int main()
{
    float numUno=0;
    float numDos=0;
    float suma=0;
    float resta=0;
    float division=0;
    float multiplicacion=0;
    int factorialUno=1;
    int factorialDos=1;
    char opcion;

    do
    {
        printf("(1)Ingresar primer operando(A= %.2f)\n", numUno);
        printf("(2)Ingresar segundo operando(B= %.2f)\n", numDos);
        printf("(3)Calcular todas las operaciones\n");
        printf("(4)Informar resultados\n");
        printf("(5)Salir\n");
        printf("Elija una opcion: ");
        __fpurge(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
        case '1':
            numUno = pedirNumero(numUno, "Ingrese primer operando\n", "Error (no es un numero)\n");
            break;
        case '2':
            numDos = pedirNumero(numDos, "Ingrese segundo operando\n", "Error (no es un numero)\n");
            break;
        case '3':
            printf("Calculo de las operaciones\n");
            printf("(S)uma\n");
            printf("(R)esta\n");
            printf("(D)ivision\n");
            printf("(M)ultiplicacion\n");
            printf("(F)actorial\n");
            printf("Elija una operacion: ");
            __fpurge(stdin);
            scanf("%c", &opcion);
            opcion = toupper(opcion);

            switch(opcion)
            {
            case 'S':
                suma = calcularSuma(numUno, numDos);
                break;
            case 'R':
                resta = calcularResta(numUno, numDos);
                break;
            case 'D':
                division = calcularDivision(numUno, numDos);
                break;
            case 'M':
                multiplicacion = calcularMultiplicacion(numUno, numDos);
                break;
            case 'F':
                factorialUno = calcularFactorial(numUno);
                factorialDos = calcularFactorial(numDos);
                break;
            default:
                printf("Opcion incorrecta\n");
            }
            break;
        case '4':
            printf("Informacion de resultados\n");
            printf("(S)uma resultado\n");
            printf("(R)esta resultado\n");
            printf("(D)ivision resultado\n");
            printf("(M)ultiplicacion resultado\n");
            printf("(F)actorial resultado\n");
            printf("Elija mostrar un resultado: ");
            __fpurge(stdin);
            scanf("%c", &opcion);
            opcion = toupper(opcion);

            switch(opcion)
            {
            case 'S':
                printf("La suma de A+B es: %.2f\n", suma);
                break;
            case 'R':
                printf("La resta de A-B es: %.2f\n", resta);
                break;
            case 'D':
                if(numDos !=0)
                {
                    printf("La division de A/B es: %.2f\n", division);
                }
                else
                {
                    printf("No es posible dividir por cero\n");
                }
                break;
            case 'M':
                printf("La multiplicacion de A*B es: %.2f\n", multiplicacion);
                break;
            case 'F':
                if(numUno<=0 && numDos<=0)
                {
                    printf("El factorial de A es: %d\n", factorialUno);
                    printf("El factorial de B es: %d\n", factorialDos);
                }
                else
                {
                    printf("No es posible calcular el factorial de un negativo\n");
                }
                break;
            default:
                printf("Opcion incorrecta\n");
            }
            break;
        case '5':
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("sleep 3s");
        system("clear");
    }
    while(opcion != '5');

    return 0;
}
