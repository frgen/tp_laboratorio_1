#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
#define LIST 5

int main()
{
    Employee employeeList[LIST];

    initEmployees(employeeList, LIST);

    initEmployeesHardCode(employeeList, LIST);

    menuEmployees(employeeList, LIST);

    return 0;
}
