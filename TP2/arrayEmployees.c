#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

void menuEmployees(Employee* list, int len)
{
    char option;

    do
    {
        printf("1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%c", &option);

        switch(option)
        {
        case '1':
            printf("Alta de empleado\n");
            //addEmployee();
            break;
        case '2':
            printf("Modificacion de empleado\n");
            //findEmployeeById();
            break;
        case '3':
            printf("Borrado de empleado\n");
            //removeEmployee();
            break;
        case '4':
            printf("Muestra de empleado\n");
            //printEmployee(list, len);
            break;
        case '5':
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

    }
    while(option!='5');

    return;
}

int initEmployees(Employee* list, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = VACIO;
    }

    return 0;
}

int initEmployeesHardCode(Employee* list, int len)
{
    int id[5]= {100,101,102,103,104};
    char name[5][51]= {"Juan","Maria","Pedro","Belen","Jose"};
    char lastName[5][51]= {"Gomez","Perez","Ramirez","Soto","Oliva"};
    float salary[5]= {5000,4500,6000,6500,5800};
    int sector[5]= {10,11,12,13,14};

    int i;

    for(i=0; i<len; i++)
    {
        list[i].id=id[i];
        list[i].salary=salary[i];
        list[i].sector=sector[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].isEmpty=OCUPADO;
    }

    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    printf("Ingrese el ID: ");
    scanf("%d", &id);
    printf("Ingrese el nombre: ");
    gets(name);
    printf("Ingrese el apellido: ");
    gets(lastName);
    printf("Ingrese el salario: ");
    scanf("%f", &salary);
    printf("Ingrese el sector: ");
    scanf("%d", &sector);

    return 0;
}

int findEmployeeById(Employee* list, int len,int id)
{
    return 0; //NULL
}

int removeEmployee(Employee* list, int len, int id)
{
    return 0;
}

int sortEmployees(Employee* list, int len, int order)
{
    return 0;
}

int printEmployees(Employee* list, int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        printf("%d\t%s\t%s\t%.2f\t%d\n", list[i].id,list[i].name,list[i].lastName,
               list[i].salary,list[i].sector);
    }

    return 0;
}
