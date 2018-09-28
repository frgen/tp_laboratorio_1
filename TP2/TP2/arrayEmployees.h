#include <stdio.h>
#include <stdlib.h>

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

/** \brief Para indicar que todas las posiciones del array están vacías
*
esta función pone la bandera (isEmpty) en TRUE en todas las posiciones del array.
*
* \param list Employee* Puntero array de employees
* \param len int longitud del Array
* \return int Retorna (-1) Si hay Error [Longitud invalida o puntero NULL]
*                   - (0) Si esta Ok
*/
int initEmployees(Employee* list, int len);

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
int addEmployee(Employee* list, int len, int id, char name[],char
                lastName[],float salary,int sector);

/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
*
* \param list Employee*
* \param len int
* \param id int
* \return Retorna la posicion del indice del empleado o (-1) si [Longitud invalida o puntero NULL
*         recibido or empleado no encontrado]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);

/** \brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente.
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief Imprime el array de empleados de forma encolumnada.
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);
