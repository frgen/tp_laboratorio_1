#include <stdio.h>
#include <stdlib.h>

#define OCUPADO 1
#define VACIO 0
#define ELIMINADO -1

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

void menuEmployees(Employee*, int);

int initEmployeesHardCode(Employee*, int);

/** \brief Para indicar que todas las posiciones del array están vacías
*
esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
*
* \param list Employee* Puntero array de employees
* \param len int longitud del Array
* \return int Retorna (-1) Si hay Error [Longitud invalida o puntero NULL]
*                   - (0) Si esta Ok
*/
int initEmployees(Employee*, int);

/** \brief Agrega en un array de empleados existente los valores recibidos como parámetro
*
en la primer posición libre.
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Retorna (-1) Si hay Error [Longitud invalida o puntero NULL o sin espacio libre]
*                   - (0) Si esta Ok
*/
int addEmployee(Employee*, int, int, char[], char[], float, int);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
*
* \param list Employee*
* \param len int
* \param id int
* \return Retorna la posicion del indice del empleado o (-1) si [Longitud invalida o puntero NULL
*         recibido o empleado no encontrado]
*
*/
int findEmployeeById(Employee*, int, int);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee*, int, int);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee*, int, int);

/** \brief Imprime el array de empleados de forma encolumnada.
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee*, int);
