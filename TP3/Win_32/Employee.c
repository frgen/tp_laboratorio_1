#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* empleado;

    empleado = (Employee*)malloc(sizeof(Employee));

    employee_newParametros((char*)empleado->id, empleado->nombre, (char*)empleado->horasTrabajadas);

    return 0;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* empleado;

    employee_setId(empleado, (int)idStr);
    employee_getId(empleado, (int)idStr);

    return 0;
}

int employee_setId(Employee* this,int id)
{
    printf("Ingrese el id: ");
    scanf("%d", &id);

    this = (Employee*)malloc(sizeof(Employee));
    this->id = id;

    return 0;
}


int employee_getId(Employee* this,int* id)
{
    this = employee_setId(this, id);

    printf("%d", this->id);

    return 0;
}
