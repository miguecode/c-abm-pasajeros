#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Menu.h"
#include "Passenger.h"
#include "Passenger_ABM.h"

int main()
{
	setbuf(stdout, NULL);

	char salirMenu = 'n';
	char path[100];

	int flagCargaTxt = 0;
	int flagCargaBin = 0;
	int flagGuardarTxt = 0;
	int flagGuardarBin = 0;

	controller_getUltimaID();

	LinkedList *listaPasajeros = ll_newLinkedList();

	if (listaPasajeros == NULL)
	{
		printf("No se pudo cargar en la memoria\n\n");
		exit(1);
	}

	do
	{
		switch (menu(listaPasajeros))
		{
		case 1:
			if (flagCargaTxt == 1 || flagCargaBin == 1)
			{
				printf("Ya se realizo la carga de datos anteriormente\n\n");
			}
			else
			{
				controller_getPath(path);

				controller_loadFromText(path, listaPasajeros);
				flagCargaTxt = 1;
			}

			break;
		case 2:
			if (flagCargaTxt == 1 || flagCargaBin == 1)
			{
				printf("Ya se realizo la carga de datos anteriormente\n\n");
			}
			else
			{
				controller_getPath(path);

				controller_loadFromBinary(path, listaPasajeros);
				flagCargaBin = 1;
			}

			break;
		case 3:
			controller_addPassenger(listaPasajeros);
			break;
		case 4:
			controller_editPassenger(listaPasajeros);

			break;
		case 5:
			controller_removePassenger(listaPasajeros);

			break;
		case 6:
			controller_ListPassenger(listaPasajeros);

			break;
		case 7:
			controller_sortPassenger(listaPasajeros);

			break;
		case 8:

			if (flagCargaBin)
			{
				printf("No se puede guardar como texto si se hizo una carga binaria\n\n");
			}
			else
			{
				controller_getPath(path);

				controller_saveAsText(path, listaPasajeros);
				printf("\nGuardado. Recuerde SALIR del programa para que el guardado funcione correctamente.\n\n");
				flagGuardarTxt = 1;
			}

			break;
		case 9:
			if (flagCargaTxt)
			{
				printf("No se puede guardar como binario si se hizo una carga de texto\n\n");
			}
			else
			{
				controller_getPath(path);

				controller_saveAsBinary(path, listaPasajeros);
				printf("\nGuardado. Recuerde SALIR del programa para que el guardado funcione correctamente.\n\n");
				flagGuardarBin = 1;
			}

			break;
		case 0:
			if (flagGuardarTxt == 1 || flagGuardarBin == 1)
			{
				confirmarSalidaMenu(&salirMenu);
			}
			else
			{
				printf("Primero deberias guardar datos\n\n");
			}
			break;

		default:
			printf("Opcion incorrecta (debe ser un numero del 1 al 9) \n\n");
		}
		system("pause");
		system("cls");

	} while (salirMenu != 's');

	if (flagGuardarTxt)
	{
		controller_saveAsBinary("data.csv", listaPasajeros);
	}
	else
	{
		controller_saveAsText("data.csv", listaPasajeros);
	}

	printf("¡Gracias por usar ABM Pasajeros!\n\n");

	Passenger_delete(listaPasajeros);

	return 0;
}
