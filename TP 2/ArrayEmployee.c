#include "ArrayEmployee.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menuPrincipal()
{
    int opcion;
    printf("BIENVENIDO AL PROGRAMA ABM EMPLEADOS.\n\n");
    printf("INGRESE LA OPCION CORRESPONDIENTE AL MENU.\n\n");
    printf("1.- DAR DE ALTA UN EMPLEADO.\n");
    printf("2.- DAR DE BAJA UN EMPLEADO.\n");
    printf("3.- MODIFICAR UN EMPLEADO.\n");
    printf("4.- LISTAR EMPLEADOS.\n");
    printf("5.- SALIR.\n");
    printf("\nOPCION: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

int menuModifica()
{
    int opcion;
    printf("MIDIFICADOR DE EMPLEADOS.\n\n");
    printf("INGRESE LA OPCION CORRESPONDIENTE AL MENU.\n\n");
    printf("1.- MODIFICAR APELLIDO.\n");
    printf("2.- MODIFICAR NOMBRE.\n");
    printf("3.- MODIFICAR SALARIO.\n");
    printf("4.- MODIFICAR SECTOR.\n");
    printf("5.- SALIR.\n");
    printf("\nOPCION: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}

void initEmployees(eEmployee* empleado, int tam)
{
    for(int i = 0; i<tam; i++)
    {
        empleado[i].isEmpty = LIBRE;
    }
}

int buscarEspacio(eEmployee* empleado, int tam)
{
    int index=-1;
    for(int i = 0; i<tam; i++)
    {
        /*if(i>= tam)
        {
            printf("NO HAY ESPACIO EN EL SISTEMA PARA AGREGAR UN NUEVO EMPLEADO.\n");
            system("pause");
        }*/
        if(empleado[i].isEmpty==LIBRE)
        {
            index=i;
            break;
        }

    }
    return index;
}
int cantidadEmpleados(eEmployee* empleado, int tam)
{
    int index=0;
    for(int i = 0; i<tam; i++)
    {
        if(empleado[i].isEmpty==OCUPADO)
        {
            index=1;
            break;
        }
    }
    return index;
}
int addEmployee(eEmployee* empleado, int tam)
{
    int altaExitosa = 0;
    int index;

    index = buscarEspacio(empleado, tam);
    if(index != -1)
    {
        empleado[index]=cargaEmpleado();
        empleado[index].isEmpty = OCUPADO;
        empleado[index].id = index +1;
        altaExitosa = 1;
    }

    return altaExitosa;
}
eEmployee cargaEmpleado()
{
    eEmployee empleado;
    esDato(empleado.lastName, "APELLIDO");
    esDato(empleado.name, "NOMBRE");
    empleado.salary=getFloatPositivo("SALARIO");
    empleado.sector=sector();
    return empleado;
}
int findEmployeeById(eEmployee* empleado, int tam, int auxId)
{
    int busquedaExitosa = 0;
    int retornoEmpleado = -1;
    int flag=0;
    do
    {
        for(int i = 0; i<tam; i++)
        {
            if(empleado[i].id == auxId && empleado[i].isEmpty == OCUPADO)
            {
                flag = 1;
                retornoEmpleado = i;
                break;
            }
        }
        if(flag==0)
        {
            system("cls");
            printf("NO SE HA ENCONTRADO NINGUN EMPELADO CON ESE ID.\n");
            system("pause");
        }
    }
    while(busquedaExitosa == 1);
    return retornoEmpleado;
}

void removeEmployee(eEmployee* empleado, int tam)
{
    int encontrarEmpleado;
    char opcionBaja = 'n';
    char opcionSeguir = 's';
    int auxID;
    do
    {
        system("cls");
        printf("INGRESE NUMERO DE LEGAJO DE EMPLEADO A BUSCAR: ");
        fflush(stdin);
        scanf("%d", &auxID);
        encontrarEmpleado=findEmployeeById(empleado, tam, auxID);
        if(encontrarEmpleado != -1)
        {
            system("cls");
            printf("EL EMPLEADO A DAR DE BAJA ES: ");
            mostrarEmpleado(empleado, tam, encontrarEmpleado);
            printf("DESEA DARLO DE BAJA 'S' o 'N': ");
            fflush(stdin);
            scanf("%c",&opcionBaja);
            opcionBaja = tolower(opcionBaja);
            if(opcionBaja == 's')
            {
                empleado[encontrarEmpleado].isEmpty = ELIMINADO;
                break;
            }
            else
            {
                system("cls");
                printf("DESEA INGRESAR OTRO LEGAJO PARA REALIZAR UNA BAJA??? 'S' 'N': ");
                fflush(stdin);
                scanf("%c", &opcionSeguir);
                opcionSeguir=tolower(opcionSeguir);
                if(opcionSeguir == 'n')
                {
                    opcionBaja = 'n';
                    break;
                }
            }

        }
    }
    while(opcionBaja == 's');

}

/////////********//////////////
void eGenerica_hardCode(eEmployee* pGenerica)
{
    int i;

    int hardcode_ID[5]={100,101,102,103,104};
    char hardcode_NAME[5][51]={"Juan","Carlos", "Belen", "Mathias", "Adrian"};
    char hardcode_LASTNAME[5][51]={"Bautista","Zarate", "Damiano", "Bustamante", "Lopez"};
    float hardcode_SALARY[5]={15200.5,10100.75,12700.50,20700.25,14300.20};
    int hardcode_SECTOR[5]={3,5,6,8,1};

    for(i=0; i<5; i++)
    {
        pGenerica[i].id=hardcode_ID[i];
        strcpy(pGenerica[i].name, hardcode_NAME[i]);
        strcpy(pGenerica[i].lastName, hardcode_LASTNAME[i]);
        pGenerica[i].salary=hardcode_SALARY[i];
        pGenerica[i].sector=hardcode_SECTOR[i];
        pGenerica[i].isEmpty=OCUPADO;
    }
}
/////////********//////////////

int modifyEmployee(eEmployee* empleado, int tam)
{
    int modificacionExitosa = 1;
    int auxId;
    int encontrarEmpleado;
    char salirModifica='s';
    char opcionModifica = 's';
    int flag=0;

    do
    {
        system("cls");
        printf("INGRESE ID DEL EMPELADO A MODIFICAR\n");
        fflush(stdin);
        scanf("%d", &auxId);
        encontrarEmpleado=findEmployeeById(empleado, tam, auxId);
        if(encontrarEmpleado != -1)
        {
            system("cls");
            printf("EL EMPLEADO A MODIFICAR ES:\n");
            mostrarEmpleado(empleado, tam, encontrarEmpleado);
            printf("DESEA MODIFICARLO 'S' o 'N': ");
            fflush(stdin);
            scanf("%c",&opcionModifica);
            opcionModifica = tolower(opcionModifica);
            if(opcionModifica == 'n')
            {
                salirModifica = 's';
            }
            else
            {
                do
                {
                    system("cls");
                    switch(menuModifica())
                    {
                    case 1:
                        esDato(empleado[encontrarEmpleado].lastName, "APELLIDO");
                        printf("SE CARGO EXITOSAMENTE EL APELLIDO\n");
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        esDato(empleado[encontrarEmpleado].name, "NOMBRE");
                        printf("SE CARGO EXITOSAMENTE EL NOMBRE\n");
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        empleado[encontrarEmpleado].salary=getFloatPositivo("SALARIO");
                        printf("SE CARGO EXITOSAMENTE EL SALARIO\n");
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        empleado[encontrarEmpleado].sector=sector();
                        printf("SE CARGO EXITOSAMENTE EL SECTOR\n");
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        salirModifica='s';
                        flag=1;
                        break;
                    default:
                        printf("INGRESE UNA OPCION CORRECTA\n");
                        system("pause");
                    }
                }while(flag == 0);
            }
        }
    }
    while(salirModifica=='n');
    return modificacionExitosa;
}

void listarEmpleado(eEmployee* empleado, int tam)
{

}

void mostrarEmpleado(eEmployee* empleado, int tam, int id)
{
    printf("%d\t\t%s \t\t %s \t\t %.2f \t\t %d\n", empleado[id].id, empleado[id].lastName, empleado[id].name, empleado[id].salary, empleado[id].sector);
}

void mostrarEmpleados(eEmployee* empleado, int tam)
{
    printf("\nID\t\tAPELLIDO\t\tNOMBRE\t\tSALARIO\t\tSECTOR\n");
    for(int i = 0; i<tam; i++)
    {
        if(empleado[i].isEmpty==OCUPADO)
        {
            mostrarEmpleado(empleado, tam, i);
        }
    }
}
