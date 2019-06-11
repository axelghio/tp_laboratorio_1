#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
///SE ENCARGA DE IR DICIENDO LO QUE HAY QUE HACER..

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* newArchivo;
    newArchivo = fopen(path, "r");
    if(newArchivo == NULL && pArrayListEmployee == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO.\n");
        system("pause");
        retorno = 0;
    }
    else
    {
        parser_EmployeeFromText(newArchivo, pArrayListEmployee);
        retorno = 1;
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* newArchivo;
    newArchivo = fopen(path, "rb");
    if(newArchivo == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO.\n");
        system("pause");
        retorno = 0;
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmp = employee_new();
    int len=ll_len(pArrayListEmployee);
    int contador = 0;
    int auxId, auxHoras, auxSueldo;
    char auxNombre[50];


    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<len;i++ )
        {
            auxEmp = ll_get(pArrayListEmployee, i);
            if(auxEmp != NULL)
            {
                employee_getId(auxEmp, &auxId);
                employee_getNombre(auxEmp, auxNombre);
                employee_getHorasTrabajadas(auxEmp, &auxHoras);
                employee_getSueldo(auxEmp, &auxSueldo);
                printf("%5d %10s %10d %20d\n", auxId, auxNombre, auxHoras, auxSueldo);
                contador++;
                if(contador == 200)
                {
                    contador = 0;
                    system("pause");
                }
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

