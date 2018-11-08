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
    int len, r, i = 0;
    char var1[50], var2[50], var3[50], var4[50];

    len = ll_len(pArrayListEmployee);

    do
    {
        r =fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", var1, var2, var3, var4);

        if(r==4)
        {
            pArrayListEmployee = (LinkedList*)employee_new();
            employee_setId((Employee*)pArrayListEmployee,atoi(var1));
            employee_setNombre((Employee*)pArrayListEmployee,var2);
            employee_setHorasTrabajadas((Employee*)pArrayListEmployee,(long int)var3);
            employee_setSueldo((Employee*)pArrayListEmployee, (long int)var4);
            i++;
        }

    }
    while(!feof(pFile) && i<len);

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
