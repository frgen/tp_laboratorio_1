#include <stdio_ext.h>
#include "menu.h"

void menuEmployees(Employee* list, int len)
{
    char option;
    int flag=0;

    do
    {
        printf("1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\n");
        printf("Elija una opcion: ");
        //fflush(stdin);
        __fpurge(stdin);
        scanf("%c", &option);

        switch(option)
        {
        case '1':
            printf("Alta de empleado\n");
            addEmployee(list, len, list[len].id, list[len].name, list[len].lastName,
                        list[len].salary, list[len].sector);
            flag=1;
            break;
        case '2':
            if(flag!=0)
            {
                printf("Modificacion de empleado\n");
                findEmployeeById(list,len,list[len].id);
                printf("Buscando...busqueda exitosa!\n");
            }
            else
            {
                printf("No se ingreso ningun empleado\n");
            }
            break;
        case '3':
            if(flag!=0)
            {
                printf("borrado de empleado\n");
                removeEmployee(list,len,list[len].id);
            }
            else
            {
                printf("No se ingreso ningun empleado\n");
            }
            break;
        case '4':
            if(flag!=0)
            {
                printf("Muestra de empleado\n");
                printEmployees(list, len);
            }
            else
            {
                printf("No se ingreso ningun empleado\n");
            }
            break;
        case '5':
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

    }
    while(option!='5');

}
