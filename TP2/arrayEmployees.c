#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"

void menuEmployees(int option)
{
    do
    {
        printf("1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
        printf("Elija una opcion: ");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            printf("Alta de empleado");
            addEmployee();
            break;
        case 2:
            printf("Modificacion de empleado");
            findEmployeeById();
            break;
        case 3:
            printf("Borrado de empleado");
            removeEmployee();
            break;
        case 4:
            printf("Muestra de empleado");
            printEmployees();
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta");
        }
    }
    while(option!=5);

    return;
}

int initEmployees(Employee* list, int len)
{
    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector)
{
    return -1;
}

int findEmployeeById(Employee* list, int len,int id)
{
    return; //NULL
}

int removeEmployee(Employee* list, int len, int id)
{
    return -1;
}

int sortEmployees(Employee* list, int len, int order)
{

}

int printEmployees(Employee* list, int length)
{

}
