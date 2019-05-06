#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#define MAX_EMP 20

int main()
{
    char switchOpcion = 'n';
    eEmployee employee[MAX_EMP];

    initEmployees(employee,MAX_EMP);

    eGenerica_hardCode(employee);


    do
    {
        system("cls");
        switch(menuPrincipal())
        {
        case 1:
            if(addEmployee(employee, MAX_EMP)==1)
            {
                system("cls");
                printf("ALTA REALIZADA CON EXITO.\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("NO HAY ESPACIO PARA REALIZAR UN NUEVO ALTA DE EMPLEADOS.\n");
                system("pause");
            }
            break;
        case 2:
            if(cantidadEmpleados(employee, MAX_EMP))
            {
                removeEmployee(employee, MAX_EMP);
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 3:
            if(cantidadEmpleados(employee, MAX_EMP))
            {
                modifyEmployee(employee, MAX_EMP);
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 4:
            if(cantidadEmpleados(employee, MAX_EMP))
            {
                mostrarEmpleados(employee, MAX_EMP);
                system("pause");
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 5:
            printf("SEGURO QUE DESEA SALIR 'S' o 'N': ");
            fflush(stdin);
            scanf("%c", &switchOpcion);
            switchOpcion = tolower(switchOpcion);
            if(switchOpcion == 's')
            {
                system("cls");
                printf("GRACIAS POR UTILIZAR MI PROGRAMA.\n");
                printf("By: Axel.\n\n");
                system("pause");
            }
            break;
        default:
            printf("OPCION INCORRECTA.\n");
            fflush(stdin);
            system("pause");
        }
    }
    while(switchOpcion == 'n');
    return 0;
}
