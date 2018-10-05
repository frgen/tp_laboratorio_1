#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "menu.h"

#define LIST 5

int main()
{
    Employee employeeList[LIST]; //biblioteca "arrayEmployees.h"

    initEmployees(employeeList, LIST);  //biblioteca "arrayEmployees.h"

    //initEmployeesHardCode(employeeList, LIST);  //biblioteca "arrayEmployees.h"

    menuEmployees(employeeList, LIST);  //biblioteca "menu.h"

    return 0;
}
