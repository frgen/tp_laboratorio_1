#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* empleado;

    empleado = (Employee*)malloc(sizeof(Employee));

    if(empleado!=NULL)
    {
        empleado->id = 0;
        empleado->horasTrabajadas = 0;
        strcpy(empleado->nombre, " ");
    }

    return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* empleado;

    empleado = employee_new();

    idStr = (int)idStr;
    horasTrabajadasStr = (int)horasTrabajadasStr;

    if(empleado != NULL)
    {
        employee_setId(empleado, idStr);
        //employee_setHorasTrabajadas(empleado, horasTrabajadasStr);
        //employee_setNombre(empleado, nombreStr);
    }

    return empleado;
}

int employee_setId(Employee* this,int id)
{
    //printf("Ingrese el id: ");
    //scanf("%d", &id);

    this->id = id;

    return 0;
}


int employee_getId(Employee* this, int* id)
{


    printf("%d", *id);

    return 0;
}



