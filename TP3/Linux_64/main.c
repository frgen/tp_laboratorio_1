#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        printf("1.Cargar datos (modo texto)\n2.Cargar datos (modo binario)\n");
        printf("3.Alta de empleado\n4.Modificar datos de empleado\n");
        printf("5.Baja de empleado\n6.Listar empleados\n7.Ordenar empleados\n");
        printf("8.Guardar datos (modo texto)\n9.Guardar datos (modo binario)\n");
        printf("10.Salir\nElija una opcion: ");

        scanf("%d", &option);
        __fpurge(stdin);

        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            printf("Cargando datos en texto...\n");
            break;
        case 2:
            //controller_loadFromBinary("data.csv",listaEmpleados);
            printf("Cargando datos en binario...\n");
            break;
        case 3:
            //controller_addEmployee(LinkedList* pArrayListEmployee);
            printf("Dando de alta...\n");
            break;
        case 4:
            //controller_editEmployee(LinkedList* pArrayListEmployee);
            printf("Modificando datos de empleado\n");
            break;
        case 5:
            //controller_removeEmployee(LinkedList* pArrayListEmployee);
            printf("Dando de baja...\n");
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            printf("Listando...\n");
            break;
        case 7:
            //controller_sortEmployee(LinkedList* pArrayListEmployee);
            printf("Ordenando...\n");
            break;
        case 8:
            //controller_saveAsText(char* path, LinkedList* pArrayListEmployee);
            printf("Guardando datos en texto...\n");
            break;
        case 9:
            //controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee);
            printf("Guardando datos en binario...\n");
            break;
        case 10:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
        system("sleep 3s");
        system("clear");
    }
    while(option != 10);
    return 0;
}
