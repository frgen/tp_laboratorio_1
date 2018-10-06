#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include "menu.h"

#define LIST 1000

int main()
{
    Employee employeeList[LIST];

    initEmployees(employeeList, LIST);

    //initEmployeesHardCode(employeeList, LIST);

    menuEmployees(employeeList, LIST);

    return 0;
}
