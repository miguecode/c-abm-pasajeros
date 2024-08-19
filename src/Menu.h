#ifndef MENU_H_
#define MENU_H_

/// @brief Muestra un men� de opciones y le pide al usuario
/// que ingrese una opci�n. Tambi�n muestra la cantidad actual de pasajeros.
///
/// @param pArrayListPassenger recibe la ddm de la linkedlist
/// @return devuelve el valor de la opci�n, o 0 si no funciono
int menu(LinkedList *pArrayListPassenger);

/// @brief Muestra un men� de opciones de modificaciones y le pide al usuario
/// que ingrese una opci�n.
///
/// @return devuelve el valor de la opci�n, o 0 si no funciono
int menuModificar();

/// @brief Le pide al usuario que responda con 's' o 'n' si quiere salir
/// o no del men�.
///
/// @param p es un puntero que va a cargar el valor de la respuesta
void confirmarSalidaMenu(char *p);

/// @brief Muestra un men� de opciones de ordenamiento y le pide al usuario
/// que ingrese una opci�n.
///
/// @return  devuelve el valor de la opci�n, o 0 si no funciono
int menuOrdenar();

#endif /* MENU_H_ */
