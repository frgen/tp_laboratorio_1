#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r, i = 0;
    char var1[50], var2[50], var3[50], var4[50];

    Node* actual;
    Employee* arrayEmpleados[10];
    //Employee* auxiliar;

    do
    {
        r =fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

        if(r==4)
        {
            Employee* empleado = employee_new();
            employee_setId(empleado,atoi(var1));
            employee_setNombre(empleado,var2);
            employee_setHorasTrabajadas(empleado, atoi(var3));
            employee_setSueldo(empleado, atoi(var4));

            actual = pArrayListEmployee->pFirstNode;

            while(actual!=NULL)
            {
                actual = actual->pNextNode;
            }

            ll_add(pArrayListEmployee, empleado);

            arrayEmpleados[i] = ll_get(pArrayListEmployee, i);

            printf("%d %s %d %d\n", arrayEmpleados[i]->id, arrayEmpleados[i]->nombre,
                                    arrayEmpleados[i]->horasTrabajadas, arrayEmpleados[i]->sueldo);

            i++;
        }

    }
    while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}

int parser_EmployeeListText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int r, i = 0;
    char var1[50], var2[50], var3[50], var4[50];

    //int len;
    //len = ll_len(pArrayListEmployee);

    do
    {
        r =fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

        if(r==4)
        {
            printf("%s, %s, %s, %s\n", var1, var2, var3, var4);
            //pArrayListEmployee[i] = pAux;
            i++;
        }

    }
    while(!feof(pFile));

    return 1;
}
