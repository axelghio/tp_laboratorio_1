#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayEmployee.h"
#define MAX_EMP 200

int main()
{
    char switchOpcion = 'n';
    eEmployee employees[MAX_EMP];

    initEmployees(employees,MAX_EMP);

    //eGenerica_hardCode(employees);//HARCODEO PARA TESTEAR.


    do
    {
        system("cls");
        switch(menuPrincipal())
        {
        case 1:
            if(addEmployee(employees, MAX_EMP)==1)
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
            if(verificarEmpleados(employees, MAX_EMP))
            {
                removeEmployee(employees, MAX_EMP);
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 3:
            if(verificarEmpleados(employees, MAX_EMP))
            {
                modifyEmployee(employees, MAX_EMP);
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 4:
            if(verificarEmpleados(employees, MAX_EMP))
            {
                mostrarEmpleados(employees, MAX_EMP);
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
            if(verificarEmpleados(employees, MAX_EMP))
            {
                system("cls");
                listarTotalYpromedioSalarios(employees, MAX_EMP);
                system("pause");
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 6:
            if(verificarEmpleados(employees, MAX_EMP))
            {
                int tipoOrden;
                do{
                    system("cls");
                    printf("INGRESE '0' PARA ORDENAR DESCENDENTE\n");
                    printf("INGRESE '1' PARA ORDENAR ASCENDENTE\n");
                    printf("OPCION: ");
                    fflush(stdin);
                    scanf("%d",&tipoOrden);
                    if(tipoOrden == 0)
                    {
                        if(shortEmployees(employees, MAX_EMP, tipoOrden)==1)
                        {
                            printf("\nORDENAMIENTO REALIZADO CON EXITO.\n");
                            system("pause");
                        }
                    }
                    else if(tipoOrden == 1)
                    {

                        if(shortEmployees(employees, MAX_EMP, tipoOrden)==1)
                        {
                            printf("\nORDENAMIENTO REALIZADO CON EXITO.\n");
                            system("pause");
                        }
                    }
                    else
                    {
                        system("cls");
                        printf("ERROR, TIPO DE ORDENAMIENTO NO EXISTENTE SOLO '0' Y '1'\n");
                        system("pause");
                    }
                }while(tipoOrden != 0 && tipoOrden != 1);
            }
            else
            {
                system("cls");
                printf("DEBES REALIZAR AL MENOS UN ALTA PARA INGRESAR A ESTA OPCION.\n");
                system("pause");
            }
            break;
        case 7:
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
