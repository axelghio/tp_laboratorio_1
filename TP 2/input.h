/** \brief                  PEDIMOS UN MENSAJE Y EL INGRESO DE UN NUMERO ENTERO.
 * \param char* int         PUNTERO A CHAR QUE VA A SER EL MENSAJE QUE VAMOS A MOSTAR.
 * \return int              DEVUELVE EL ENTERO.
 */
int getInt(char* mensaje);

/** \brief                  PIDE UN FLOAT Y LO DEVUELVE
 * \param numero float      FLOAT A PEDIR.
 * \return float            DEVUELVE FLOAT.
 */
float getFloat(char* mensaje);

/** \brief                  PIDE UN CHAR Y LO DEVUELVE
 * \param texto char        CHAR A PEDIR.
 * \return char             DEVUELVE CHAR.
 */
char getChar(char* mensaje);

/** \brief                  PEDIMOS UN NUMERO VALIDAMOS QUE NO SEA O CONTENGA LETRAS.
 * \param cadena char*      PUNTERO A CADENA DONDE NOS INGRESARA LOS DATOS A ANALIZAR.
 * \return int              DEVUELVE ESTADO DE LA OPERACION (1 SI CONTIENE LETRAS, 0 SI NO CONTIENE).
 */
int esNumero(char* cadena);

/** \brief                  FUNCION QUE VALIDA ENTRADA DE NUMEROS.
 *
 * \param pBuffer char*     PEDIMOS UNA CADENA DE CHAR.
 * \return int              RETORNA VALIDACION.
 *
 */
int validarNumeroConSignos(char* pBuffer);

/** \brief                  PEDIMOS UN FLOAT Y VALIDAMOS QUE SEA POSITIVO.
 *
 * \param MSJ const char*   PEDIMOS UN MENSAJE A MOSTRAR.
 * \return float            RETORNA VALIDACION.
 *
 */
float getFloatPositivo(const char* MSJ);

/** \brief                  PEDIMOS UNA LETRA Y VERIFICAMOS QUE SOLO LEA UNA LETRA.
 *
 * \param letra char*       VARIABLE QUE CONTIENE EL CHAR.
 * \return  int             DEVUELVE ESTA DE LA OPERACION (1 SI CONTIENE LETRAS, 0 SI NO CONTIENE).
 *
 */
void esLetra(char* letras);

/** \brief                  VALIDA QUE SOLO SEAN LETRAS LAS INGRESADAS.
 * \param cadena* char      RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \return int              DEVUELVE SI SE PUDO REALIZAR ACCION.
 */
int esCadena(char* cadena);


/** \brief                  PIDE HASTA QUE EL DATO SEA CORRECTO.
 *
 * \param dato char*        RECIBE UN PUNTERO A CADENA CON LA INFO DEL USUARIO.
 * \param texto char*       RECIBE UN PUNTERO A CADENA CON TEXTO A MOSTRAR POR EJEMPLO (NOMBRE, APELLIDO, DIRECCION, ETC.
 * \return int              DEVUELVE VALIDANDO LA ENTRADA DE ESE TIPO DE DATO QUE QUEREMOS 0 SI SON SOLO DATOS 1 SI TIENE ERROR.
 *
 */
int esDato(char* dato, char* texto);

/** \brief                  PIDE SECTOR VALIDA QUE SEA MAYOR A 0.
 *
 * \param sector int        SECTOR A VERIFICAR.
 * \return int              RETORNA SI ERA VALIDO.
 *
 */
int sector();
