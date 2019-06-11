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
    char opcionSwitch = 's';
    char salirCase = 's';

    do{
        switch(menu())
        {
            case 1:
                if(controller_loadFromText("data.csv", listaEmpleados)==0)
                {
                    printf("NO SE PUDO CARGAR LA LISTA.\n");
                    system("pause");
                }
                else
                {
                    printf("SE CARGO EXITOSAMENTE LA LISTA.\n");
                    system("pause");
                }
                break;
            case 2:
                controller_loadFromBinary("data.bin", listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 10:
                printf("DESEAS SALIR");
                while(salirCase != 'n' || salirCase != 's')
                {
                    printf("INGRESE 'N' o 'S': ");
                    fflush(stdin);
                    scanf("%c", &salirCase);
                    salirCase = tolower(salirCase);
                    if(salirCase != 's' && salirCase != 'n')
                    {
                        printf("ERROR, OPCION INCORRECTA.\n");
                        system("pause");
                    }
                    if(salirCase == 's')
                    {
                        break;
                    }
                    if(salirCase == 'n')
                    {
                        salirCase = 'n';
                        break;
                    }
                }
            break;
        }
        printf("%c",&opcionSwitch);
    }while(opcionSwitch == 's');
    return 0;
}
