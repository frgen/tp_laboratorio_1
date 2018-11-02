#include <stdio.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee empleado;

    printf("Ingrese el id: ");
    scanf("%d", &empleado.id);
    printf("Ingrese el nombre: ");
    scanf("%s", empleado.nombre);
    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &empleado.horasTrabajadas);
    printf("Ingrese el sueldo: ");
    scanf("%d", &empleado.sueldo);

    return 0;
}

int employee_setId(Employee* this,int id)
{

}

int employee_getId(Employee* this,int* id)
{

}


