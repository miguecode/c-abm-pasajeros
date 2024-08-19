#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/** \brief Le pido un path al usuario para abrir el archivo.
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return ints
 *
 */
int controller_getPath(char *path);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return ints
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger);

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger);

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger);

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger);

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger);

/// @brief Busca encontrar la ID recibida en la lista de pasajeros y devuelve
/// el indice correspondiente si es que la encuentra.
///
/// @param lista recibe el array de la estructura
/// @param len recibe el tamaño del linkedlist
/// @param id recibe la ID que tiene que buscar
/// @return retorna el indice correspondiente o -1 si no logro encontrarlo
int controller_buscarPasajeroPorID(LinkedList *pArrayListPassenger, int len, int id);

/// @brief Abre un archivo (si no existe lo crea), y le escribe el valor
/// del último ID ingresado.
///
/// @return retorna el valor que este escrito en el archivo
int controller_getUltimaID();

/// @brief Recibe el valor de la id actual, le suma 1+ y la escribe en el archivo
///
/// @param idActual recibe el valor de la id actual
/// @return retorna 1 si funciona, 0 si no funciona
int controller_actualizarID(int idActual);

/// @brief Escribe '1' en el archivo de backup del ID y se ejecuta
/// al iniciar el programa.
///
/// @return
void controller_setearID();

#endif /* CONTROLLER_H_ */