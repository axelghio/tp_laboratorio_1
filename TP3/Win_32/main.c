#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    char opcionSwitch = 'n';

    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv", listaEmpleados))
                {
                    printf("SE CARGO EXITOSAMENTE LA LISTA.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE PUDO CARGAR LA LISTA.\n");
                    system("pause");
                }
                break;
            case 2:
                if(controller_loadFromBinary("data.bin", listaEmpleados))
                {
                    printf("SE CARGO EXITOSAMENTE LA LISTA.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE PUDO CARGAR LA LISTA.\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("SE REALIZO EXITOSAMENTE EL ALTA.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE PUDO REALIZAR EL ALTA.\n");
                    system("pause");
                }
                break;
            case 4:
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("SE REALIZO EXITOSAMENTE LA MODIFICACION.\n");
                    system("pause");
                }
                break;
            case 5:
                if(controller_removeEmployee(listaEmpleados)==1)
                {
                    printf("SE REALIZO EXITOSAMENTE LA BAJA.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE HA PODIDO REALIZAR LA BAJA.\n");
                    system("pause");
                }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                system("pause");
                system("cls");
                break;
            case 7:
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("SE REALIZO EXITOSAMENTE EL ORDENAMIENTO DE LA LISTA.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE HA PODIDO ORDENAR LA LISTA.\n");
                    system("pause");
                }
                break;
            case 8:
                if(controller_saveAsText("data.csv", listaEmpleados))
                {
                    printf("SE GUARDO EXITOSAMENTE LA LISTA EN TEXTO.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE PUDO GUARDAR LA LISTA EN TEXTO.\n");
                    system("pause");
                }
                break;
            case 9:
                if(controller_saveAsBinary("data.bin", listaEmpleados))
                {
                    printf("SE GUARDO EXITOSAMENTE LA LISTA EN BINARIO.\n");
                    system("pause");
                }
                else
                {
                    printf("NO SE PUDO GUARDAR LA LISTA EN BINARIO.\n");
                    system("pause");
                }
                break;
            case 10:
                opcionSwitch = getChar("DESEA SALIR 'S' o N : ");
                {
                    if ( opcionSwitch == 's')
                    {
                        break;
                    }
                }
            break;
        }
    }while(opcionSwitch == 'n');
    return 0;
}
