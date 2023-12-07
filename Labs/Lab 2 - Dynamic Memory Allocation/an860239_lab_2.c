#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StringType
{
    char *string;
    int length;
} StringType;

typedef struct Employee
{
    StringType *ename;
    double salary;
} Employee;

Employee *createEmployees(char names[][50], double *salaries, int empCount)
{
    Employee *employees = malloc(empCount * sizeof(Employee));

    for (int i = 0; i < empCount; i++) {
        StringType *name = malloc(sizeof(StringType));

        int length = strlen(names[i]);
        name->string = malloc((length + 1) * sizeof(char));

        strncpy(name->string, names[i], length);
        name->string[length] = '\0';
        name->length = length;

        employees[i].ename = name;
        employees[i].salary = salaries[i];
    }

    return employees;
}


int main()
{
    const int EMPLOYEE_COUNT = 4;
    // array of employees’ names
    char nameList[][50] = {"Bill", "Mary", "Kevin", "Denise"};
    // array of salaries, where 15.80 is the salary of Bill, 13.50 is
    //  the salary of Mary, etc.
    double salaries[] = {15.80, 13.5, 20.9, 12.99};
    Employee *pEmployees = createEmployees(nameList, salaries, EMPLOYEE_COUNT);
    // Print Employees
    int e = 0;
    Employee *pEmployee = pEmployees;
    printf("\tEMPLOYEE NAME\t\tSALARY\n");
    for (e = 0; e < EMPLOYEE_COUNT; ++e)
    {
        printf("\t%s\t\t\t%.2lf\n", pEmployee->ename->string, pEmployee->salary);
        pEmployee++;
    }
    // Deallocate memory
    pEmployee = pEmployees;
    for (e = 0; e < EMPLOYEE_COUNT; ++e)
    {
        free(pEmployee->ename->string);
        pEmployee->ename->string = NULL;
        free(pEmployee->ename);
        pEmployee->ename = NULL;
        pEmployee++;
    }
    free(pEmployees);
    pEmployees = NULL;
    return 0;
}