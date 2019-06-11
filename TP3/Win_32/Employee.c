#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmpleado = (Employee*) malloc(sizeof(Employee));
    if(newEmpleado != NULL)
    {
        newEmpleado->id = 0;
        strcpy(newEmpleado->nombre, "");
        newEmpleado->horasTrabajadas = 0;
        newEmpleado->sueldo = 0;
    }
    return newEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmpleado = employee_new();
    int ok = 0;
    if(newEmpleado != NULL)
    {
        if(employee_setid(newEmpleado, atoi(idStr)))
        {
            if(employee_setnombre(newEmpleado, nombreStr))
            {
                if(employee_setHorasTrabajadas(newEmpleado, horasTrabajadasStr))
                {
                    if(employee_setSueldo(newEmpleado, sueldoStr))
                    {
                        ok = 1;
                    }
                }
            }
        }
        if(ok == 0)
        {
            free(newEmpleado);
            newEmpleado = NULL;
        }
    }
    return newEmpleado;
}

int employee_setid(Employee* this, int id)
{
    int ok = 0;

    if(this!= NULL && id != NULL)
    {
        this->id = id;
        ok = 1;
    }
    return ok;
}

int employee_setnombre(Employee* this, int nombre)
{
    int ok = 0;

    if(this!= NULL && nombre != NULL)
    {
        ok = 1;
    }
    return ok;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ok = 0;

    if(this!= NULL && horasTrabajadas != NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        ok = 1;
    }
    return ok;
}
///ESCRIBIR EN EL SUELDO.
int employee_setSueldo(Employee* this, int sueldo)
{
    int ok;

    if(this!= NULL && sueldo != NULL)
    {
        this->sueldo = sueldo;
        ok = 1;
    }
    return ok;
}
int employee_getId(Employee* this, int* id)
{
     int ok = 0;

    if(this != NULL && id != NULL)
    {
        this->id = id;
        ok = 1;
    }
    return ok;
}
int employee_getNombre(Employee* this, char* nombre)
{
     int ok = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        ok = 1;
    }
    return ok;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
     int ok = 0;

    if(this != NULL && horasTrabajadas != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        ok = 1;
    }
    return ok;
}
///TRAEME SUELDO.
int employee_getSueldo(Employee* this, int* sueldo)
{
         int ok = 0;

    if(this != NULL && sueldo != NULL)
    {
        this->sueldo = sueldo;
        ok = 1;
    }
    return ok;
}

