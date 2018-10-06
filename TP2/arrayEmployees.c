#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayEmployees.h"

/*int initEmployeesHardCode(Employee* list, int len)
{
    int id[5]= {1104,1103,1100,1101,1102};
    char name[5][51]= {"Walter","Maria","Andres","Belen","Jose"};
    char lastName[5][51]= {"Ramirez","Perez","Gomez","Soto","Oliva"};
    float salary[5]= {5000,4500,6000,6500,5800};
    int sector[5]= {17,11,15,10,11};

    int i;
    for(i=0; i<5; i++)
    {
        list[i].id=id[i];
        list[i].salary=salary[i];
        list[i].sector=sector[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].isEmpty=FULL;
    }
    return 0;
}  */

int initEmployees(Employee* list, int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = EMPTY;
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
            list[i].id = rand() % 100 + 2000;
            printf("Ingrese el nombre: ");
            scanf("%s", list[i].name);
            printf("Ingrese el apellido: ");
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
            printf("No hay espacio\n");
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
            printf("El empleado es: %s %s\n", list[i].name, list[i].lastName);
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
            fflush(stdin);
            //__fpurge(stdin);
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
    char tempText[51];
    int temp;
    float  tempSalary;
    int i, j;
    for(i=0; i<len-1; i++)
    {
        if(list[i].isEmpty==FULL)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[j].isEmpty==FULL && stricmp(list[i].lastName, list[j].lastName)>0)
                {
                    strcpy(tempText, list[i].lastName);
                    strcpy(list[i].lastName, list[j].lastName);
                    strcpy(list[j].lastName, tempText);

                    strcpy(tempText, list[i].name);
                    strcpy(list[i].name, list[j].name);
                    strcpy(list[j].name, tempText);

                    temp=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=temp;

                    temp=list[i].sector;
                    list[i].sector=list[j].sector;
                    list[j].sector=temp;

                    tempSalary=list[i].salary;
                    list[i].salary=list[j].salary;
                    list[j].salary=tempSalary;
                }
                else if(list[j].isEmpty==FULL && stricmp(list[i].lastName, list[j].lastName)==0)
                {
                    if(list[i].sector>list[j].sector)
                    {
                        temp=list[i].sector;
                        list[i].sector=list[j].sector;
                        list[j].sector=temp;
                    }
                }
            }
        }
    }
    return 0;
}

int printEmployees(Employee* list, int length)
{
    double average;
    double totalSalary=0;
    int salaryCounter=0;
    int employeeCounter=0;
    int i;
    for(i=0; i<length; i++)
    {
        if(list[i].isEmpty==FULL)
        {
            printf("%d\t%s\t%s\t%.2f\t%d\n", list[i].id,list[i].name,list[i].lastName,
                   list[i].salary,list[i].sector);
            totalSalary+=list[i].salary;
            salaryCounter+=i;
        }
    }

    average=totalSalary/salaryCounter;

    for(i=0; i<length; i++)
    {
        if(list[i].isEmpty==FULL && list[i].salary > average)
        {
            employeeCounter+=1;
        }
    }

    printf("El salario total es: %.2f\n", totalSalary);
    printf("El promedio total es: %.2f\n", average);
    printf("Empleados que superan el salario promedio: %d\n", employeeCounter);
    return 0;
}
