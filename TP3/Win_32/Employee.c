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
    int id, horasTrabajadas, sueldo;

    empleado = employee_new();

    sueldo = rand()*100 + 200;
    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    sueldo = horasTrabajadas*sueldo;

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
    *id = this->id;

    return 0;
}


int employee_setNombre(Employee* this,char* nombre)
{
    strcpy(this->nombre, nombre);

    return 0;
}


int employee_getNombre(Employee* this,char* nombre)
{
    strcpy(nombre, this->nombre);

    return 0;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    this->horasTrabajadas = horasTrabajadas;

    return 0;
}


int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    *horasTrabajadas = this->horasTrabajadas;

    return 0;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    this->sueldo = sueldo;

    return 0;
}


int employee_getSueldo(Employee* this, int* sueldo)
{
    *sueldo= this->sueldo;

    return 0;
}





