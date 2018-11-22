#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    printf("Cargando datos en modo texto...\n");

    FILE* pFile;

    pFile = fopen(path, "r");

    parser_EmployeeFromText(pFile, pArrayListEmployee);

    fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    printf("Cargando datos en modo binario...\n");

    FILE* pFile;

    pFile = fopen(path, "rb");

    parser_EmployeeFromBinary(pFile, pArrayListEmployee);

    fclose(pFile);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char id[10], nombre[128], horasTrabajadas[10];
    Employee* empleado;

    printf("Ingrese el ID: ");
    __fpurge(stdin);
    fgets(id, 20, stdin);

    printf("Ingrese el nombre: ");
    __fpurge(stdin);
    scanf("%s", nombre);

    printf("Ingrese las horas trabajadas: ");
    __fpurge(stdin);
    scanf("%s", horasTrabajadas);

    printf("Dando de alta...\n");

    empleado = employee_newParametros(id, nombre, horasTrabajadas);

    ll_add(pArrayListEmployee, empleado);

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    printf("Modificando datos de empleado\n");

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    printf("Dando de baja...\n");

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len, i;

    len = ll_len(pArrayListEmployee);

    printf("Listando...\n");

    Employee* arrayEmpleados[len];

    for(i=0; i<len; i++)
    {
        arrayEmpleados[i] = ll_get(pArrayListEmployee, i);

        if(i>0)
        {
            printf("%d\t%s\t%d\t%d\n", arrayEmpleados[i]->id, arrayEmpleados[i]->nombre,
                                    arrayEmpleados[i]->horasTrabajadas, arrayEmpleados[i]->sueldo);
        }

    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    printf("Ordenando...\n");

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    printf("Guardando datos en modo texto...\n");

    FILE* pFile;

    pFile = fopen(path, "w");

    int len, i;

    len = ll_len(pArrayListEmployee);

    Employee* arrayEmpleados[len];

    for(i=0; i<len; i++)
    {
        arrayEmpleados[i] = ll_get(pArrayListEmployee, i);
        if(i > 0)
        {
            fprintf(pFile, "%d, %s, %d, %d\n", arrayEmpleados[i]->id, arrayEmpleados[i]->nombre,
                    arrayEmpleados[i]->horasTrabajadas, arrayEmpleados[i]->sueldo);
        }
    }

    fclose(pFile);

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    printf("Guardando datos en modo binario...\n");

    FILE* pFile;

    pFile = fopen(path, "wb");

    int len, i;

    len = ll_len(pArrayListEmployee);

    Employee* arrayEmpleados[len];

    for(i=0; i<len; i++)
    {
        arrayEmpleados[i] = ll_get(pArrayListEmployee, i);
        if(i > 0)
        {
            fprintf(pFile, "%d, %s, %d, %d\n", arrayEmpleados[i]->id, arrayEmpleados[i]->nombre,
                    arrayEmpleados[i]->horasTrabajadas, arrayEmpleados[i]->sueldo);
        }
    }

    fclose(pFile);

    return 1;
}

