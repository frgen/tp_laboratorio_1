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
    int r;
    char var1[50], var2[50], var3[50], var4[50];

    do
    {
        r =fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

        if(r==4)
        {
            Employee* empleado = employee_new();
            employee_setId((Employee*)empleado,atoi(var1));
            employee_setNombre((Employee*)empleado,var2);
            employee_setHorasTrabajadas((Employee*)empleado,atoi(var3));
            employee_setSueldo((Employee*)empleado, atoi(var4));
            ll_add(pArrayListEmployee, empleado);
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
    int r;
    char var1[50], var2[50], var3[50], var4[50];

    do
    {
        r =fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

        if(r==4)
        {
            Employee* empleado = employee_new();
            employee_setId((Employee*)empleado,atoi(var1));
            employee_setNombre((Employee*)empleado,var2);
            employee_setHorasTrabajadas((Employee*)empleado,atoi(var3));
            employee_setSueldo((Employee*)empleado, atoi(var4));
            ll_add(pArrayListEmployee, empleado);
        }

    }
    while(!feof(pFile));

    return 1;
}
