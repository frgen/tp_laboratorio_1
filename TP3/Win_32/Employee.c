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
    int id, horasTrabajadas, sueldo=0;

    empleado = employee_new();

    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);

    employee_setId(empleado, id);
    employee_setNombre(empleado, nombreStr);
    employee_setHorasTrabajadas(empleado, horasTrabajadas);
    employee_setSueldo(empleado, sueldo);

    return empleado;
}

int employee_setId(Employee* this,int id)
{
    this->id = id;

    return 0;
}

int employee_getId(Employee* this, int* id)
{
    printf("%d", *id);

    return 0;
}


int employee_setNombre(Employee* this,char* nombre)
{
    strcpy(this->nombre, nombre);

    return 0;
}


int employee_getNombre(Employee* this,char* nombre)
{
    printf("%s", this->nombre);

    return 0;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    this->horasTrabajadas = horasTrabajadas;

    return 0;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    printf("%d", *horasTrabajadas);

    return 0;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo = sueldo;

    return 0;
}


int employee_getSueldo(Employee* this, int* sueldo)
{
    printf("%d", *sueldo);

    return 0;
}





