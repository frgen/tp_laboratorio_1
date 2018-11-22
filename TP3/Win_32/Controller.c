#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/*static int ultimoId()
{
    static int id = 0;
    id++;
    return id;
}*/

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
    char id[20], nombre[50], horasTrabajadas[20];
    Employee* empleado;

    printf("Ingrese el ID: ");
    fflush(stdin);
    fgets(id, 20, stdin);

    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%s", nombre);

    printf("Ingrese las horas trabajadas: ");
    fflush(stdin);
    scanf("%s", horasTrabajadas);

    empleado = employee_newParametros((char*)id, nombre, horasTrabajadas);

    ll_add(pArrayListEmployee, empleado);

    printf("Dando de alta...\n");

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
    char option;
    char nombre[20], horasTrabajadas[20];
    int id, len, i, sueldo;

    len = ll_len(pArrayListEmployee);

    Employee* arrayEmpleados[len];

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    for(i=0; i<len; i++)
    {
        arrayEmpleados[i] = ll_get(pArrayListEmployee, i);
        if(arrayEmpleados[i]->id == id)
        {
            printf("El empleado es: %s\n", arrayEmpleados[i]->nombre);
            printf("1.NOMBRE\n2.HORAS TRABAJADAS\n3.SUELDO\n");
            printf("Elija una opcion: ");
            fflush(stdin);
            scanf("%c", &option);

            switch(option)
            {
            case '1':
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                scanf("%s", nombre);
                employee_setNombre(arrayEmpleados[i], nombre);
                break;
            case '2':
                printf("Ingrese nuevas horas trabajadas: ");
                fflush(stdin);
                scanf("%s", horasTrabajadas);
                employee_setHorasTrabajadas(arrayEmpleados[i], atoi(horasTrabajadas));
                break;
            case '3':
                printf("Ingrese nuevo sueldo: ");
                scanf("%d", &sueldo);
                employee_setSueldo(arrayEmpleados[i], sueldo);
                break;
            default:
                printf("Opcion incorrecta\n");
            }
        }
    }

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
    char option;
    int id, len, i, index;

    len = ll_len(pArrayListEmployee);

    Employee* arrayEmpleados[len];

    printf("Ingrese el ID: ");
    scanf("%d", &id);

    for(i=0; i<len; i++)
    {
        arrayEmpleados[i] = ll_get(pArrayListEmployee, i);
        if(arrayEmpleados[i]->id == id)
        {
            index = ll_indexOf(pArrayListEmployee, arrayEmpleados[i]);
            printf("El empleado es: %s\n", arrayEmpleados[i]->nombre);
            printf("Desea borrarlo?: ");
            fflush(stdin);
            scanf("%c", &option);
            option = toupper(option);

            if(option=='S')
            {
                ll_remove(pArrayListEmployee, index);
                printf("Dando de baja...\n");
            }
            break;
        }
    }

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
    printf("Listando...\n");

    int len, i;

    len = ll_len(pArrayListEmployee);

    Employee* arrayEmpleados[len];

    for(i=0; i<len; i++)
    {
        arrayEmpleados[i] = ll_get(pArrayListEmployee, i);
        if(arrayEmpleados[i]->id !=0)
        {
            printf("%d %s %d %d\n", arrayEmpleados[i]->id, arrayEmpleados[i]->nombre,
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
    int len, i;

    len = ll_len(pArrayListEmployee);

    Employee* arrayEmpleados[len];

    /*char tempText[51];
    int temp;
    float  tempSalary;
    int i, j;
    for(i=0; i<len-1; i++)
    {
        if(arrayEmpleados[i]->id !=0)
        {
            for(j=i+1; j<len; j++)
            {
                if(arrayEmpleados[i]->id !=0 && stricmp(arrayEmpleados[i]->nombre, arrayEmpleados[j]->nombre)>0)
                {
                    strcpy(tempText, arrayEmpleados[i]->nombre);
                    strcpy(arrayEmpleados[i]->nombre, arrayEmpleados[j]->nombre);
                    strcpy(arrayEmpleados[j]->nombre, tempText);

                    strcpy(tempText, arrayEmpleados[i]->nombre);
                    strcpy(arrayEmpleados[i]->nombre, arrayEmpleados[j]->nombre);
                    strcpy(arrayEmpleados[j]->nombre, tempText);

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
    }*/
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
        if(arrayEmpleados[i]->id !=0)
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
        if(arrayEmpleados[i]->id !=0)
        {
            fprintf(pFile, "%d, %s, %d, %d\n", arrayEmpleados[i]->id, arrayEmpleados[i]->nombre,
                    arrayEmpleados[i]->horasTrabajadas, arrayEmpleados[i]->sueldo);
        }
    }

    fclose(pFile);

    return 1;
}

