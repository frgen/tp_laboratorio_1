#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = EMPTY;
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
        list[i].isEmpty=FULL;
    }
    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty != FULL)
        {
            printf("Ingrese el ID: ");
            scanf("%d", &list[i].id);
            printf("Ingrese el nombre: ");
            //gets(name);
            scanf("%s", list[i].name);
            printf("Ingrese el apellido: ");
            //gets(lastName);
            scanf("%s", list[i].lastName);
            printf("Ingrese el salario: ");
            scanf("%f", &list[i].salary);
            printf("Ingrese el sector: ");
            scanf("%d", &list[i].sector);
            list[i].isEmpty = FULL;
            break;
        }
        else if(i==len-1)
        {
            printf("No hay lugar!\n");
        }
    }
    return 0;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index;
    int i;
    printf("Ingrese el numero de ID: ");
    scanf("%d", &index);

    for(i=0; i<len; i++)
    {
        if(list[i].id==index)
        {
            printf("Bingo! El empleado es: %s\n", list[i].name);
            index = list[i].id;
            break;
        }
        else if(i==len-1)
        {
            printf("Numero no encontrado\n");
            index = -1;
        }
    }
    return index;
}

int removeEmployee(Employee* list, int len, int id)
{
    int i;
    char option;

    id = findEmployeeById(list,len,list[len].id);

    for(i=0; i<len; i++)
    {
        if(list[i].id==id)
        {
            printf("Esta seguro de borrar(s/n)?(No se puede deshacer)\n");
            //fflush(stdin);
            __fpurge(stdin);
            scanf("%c", &option);
            option = toupper(option);

            if(option=='S')
            {
                list[i].isEmpty = FIRED;
                printf("Borrando...Listo!\n");
            }
            break;
        }
    }
    return 0;
}

int sortEmployees(Employee* list, int len, int order)
{
    /*int i;
    for(i=0; i<len; i++)
    {
        strcmp(list[i].name, list[i+1].name);
    }*/

    return 0;
}

int printEmployees(Employee* list, int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(list[i].isEmpty==FULL)
        {
            printf("%d\t%s\t%s\t%.2f\t%d\n", list[i].id,list[i].name,list[i].lastName,
                   list[i].salary,list[i].sector);
        }
    }
    return 0;
}
