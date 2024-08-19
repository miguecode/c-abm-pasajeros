#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Menu.h"
#include "Controller.h"

int menu(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int opcion;
	int cant = ll_len(pArrayListPassenger);
	int proximaId = controller_getUltimaID();

  printf("|=====================================================|\n");
  printf("|         *****  ABM PASAJEROS - MENU  *****          |\n");
  printf("|=====================================================|\n");
  printf("|                  Seccion Principal                  |\n");
  printf("|=====================================================|\n");
  printf("|  1  | Cargar pasajeros desde archivo data.csv       |\n");
  printf("|  2  | Cargar pasajeros desde archivo data.bin       |\n");
  printf("|  3  | Alta de pasajero                              |\n");
  printf("|  4  | Modificar pasajero                            |\n");
  printf("|  5  | Baja de pasajero                              |\n");
  printf("|=====================================================|\n");
  printf("|                  Seccion Secundaria                 |\n");
  printf("|=====================================================|\n");
  printf("|  6  | Listar pasajeros                              |\n");
  printf("|  7  | Ordenar Pasajeros                             |\n");
  printf("|  8  | Guardar pasajeros en archivo data.csv         |\n");
  printf("|  9  | Guardar pasajeros en archivo data.bin         |\n");
  printf("|=====================================================|\n");
  printf("|  0  | Salir                                         |\n");
  printf("|=====================================================|\n\n");

  printf("[>] Proxima ID a insertar: %d\n", proximaId);
  printf("[>] Cantidad de pasajeros: %d\n", cant);
  printf("[>] Ingrese opcion: ");

	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if (todoOk)
	{
		return opcion;
	}

	return todoOk;
}

int menuModificar()
{
	int todoOk = 0;
	int opcion;

	printf("\n");
  printf("|=====================================================|\n");
  printf("|         *****  MENU DE MODIFICACION  *****          |\n");
  printf("|=====================================================|\n");
  printf("|  1  | Modificar Nombre                              |\n");
  printf("|  2  | Modificar Apellido                            |\n");
  printf("|  3  | Modificar Precio                              |\n");
  printf("|  4  | Modificar Codigo                              |\n");
  printf("|  5  | Modificar Tipo de vuelo                       |\n");
  printf("|=====================================================|\n\n");

	printf("[>] Ingrese opcion: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if (todoOk)
	{
		return opcion;
	}

	printf("\n");

	return todoOk;
}

void confirmarSalidaMenu(char *p)
{
	if (p != NULL)
	{
		char confirma;

		printf("Seguro que desea salir? (si = 's'  no = 'n') \n");
		fflush(stdin);
		scanf("%c", &confirma);
		confirma = tolower(confirma);

		while (confirma != 's' && confirma != 'n')
		{
			printf("[>] Error, debe responder con 's' o 'n':  \n");
			fflush(stdin);
			scanf("%c", &confirma);
			confirma = tolower(confirma);
		}
		*p = confirma;
	}
}

int menuOrdenar()
{
	int todoOk = 0;
	int opcion;


	printf("\n");
  printf("|=====================================================|\n");
  printf("|         *****  MENU DE ORDENAMIENTO  *****          |\n");
  printf("|=====================================================|\n");
  printf("|  1  | Ordenar por ID                                |\n");
  printf("|  2  | Ordenar por Nombre                            |\n");
  printf("|  3  | Ordenar por Apellido                          |\n");
  printf("|  4  | Ordenar por Precio                            |\n");
  printf("|  5  | Ordenar por Codigo de vuelo                   |\n");
  printf("|  6  | Ordenar por Tipo de pasajero                  |\n");
  printf("|  7  | Ordenar por Estado de vuelo                   |\n");
  printf("|=====================================================|\n\n");

	printf("[>] Ingrese opcion: ");
	fflush(stdin);
	todoOk = scanf("%d", &opcion);

	if (todoOk)
	{
		return opcion;
	}

	return todoOk;
}
