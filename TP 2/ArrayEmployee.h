#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED
#define LIBRE 0
#define OCUPADO 1
#define ELIMINADO -1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} eEmployee;

/************* FUNCIONES PRINCIPALES DEL ABM *************/

/** \brief                      INICIA TODOS LOS EMPLEADOS EN SU ESTADO LIBRE.
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return void                 NO RETORNA.
 *
 */
void initEmployees(eEmployee* empleado, int tam);

/** \brief                      FUNCION QUE REALIZA EL ALTA DE EMPELADOS.
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return int                  DEVUELVE ESTADO REALIZADO (1 REALIZO, 0 ERROR).
 *
 */
int addEmployee(eEmployee* empleado, int tam);

/** \brief                      CARGA UN EMPLEADO AUXILIAR.
 *
 * \return eEmployee            RETORNA EL EMPLEADO.
 *
 */
eEmployee cargaEmpleado();

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \param id int                REFERENCIA ID EMPLEADO.
 * \return int                  DEVUELVE ESTADO REALIZADO (1 REALIZO, 0 ERROR).
 *
 */
void  removeEmployee(eEmployee* empleado, int tam);

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return int                  DEVUELVE ESTADO REALIZADO (1 REALIZO, 0 ERROR).
 *
 */
int modifyEmployee(eEmployee* empleado, int tam);

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return int                  DEVUELVE ESTADO REALIZADO (1 REALIZO, 0 ERROR).
 *
 */
void listarEmpleado(eEmployee* empleado, int tam);


/************* FUNCIONES DENTRO DE LAS PRINCIPALES *************/

int menuPrincipal();

int menuModifica();

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return int                  DEVUELVE ESPACIO LIBRE (Nº > 0 HAY ESPACIO, 0 NO HAY).
 *
 */
int buscarEspacio(eEmployee* empleado, int tam);

int cantidadEmpleados(eEmployee* empleado, int tam);

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \param id int                REFERENCIA ID EMPLEADO.
 * \return int                  DEVUELVE ID EMPLEADO.
 *
 */
int findEmployeeById(eEmployee* empleado, int tam, int id);

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return int                  DEVUELVE ESTADO REALIZADO (1 REALIZO, 0 ERROR).
 *
 */
void mostrarEmpleado(eEmployee* empleado, int tam, int id);

/** \brief
 *
 * \param empleado eEmployee*   PUNTERO AL ARRAY DEL TIPO EMPLEADO.
 * \param tam int               TAMAÑO DEL ARRAY.
 * \return int                  DEVUELVE ESTADO REALIZADO (1 REALIZO, 0 ERROR).
 *
 */
void mostrarEmpleados(eEmployee* empleado, int tam);
#endif // ARRAYEMPLOYEE_H_INCLUDED
