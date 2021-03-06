#include <stdio.h>
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
        fflush(stdin);

        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            break;
        case 2:
            controller_loadFromBinary("data.csv",listaEmpleados);
            break;
        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.csv", listaEmpleados);
            break;
        case 10:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }
        system("pause");
        system("cls");
    }
    while(option != 10);
    return 0;
}
