#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "Passenger_ABM.h"
#include "Validaciones.h"
#include "Menu.h"

int controller_getPath(char *path)
{
	int todoOk = 0;

	if (path != NULL)
	{
		gets(path);
		validarPath(path);
		todoOk = 1;
	}

	return todoOk;
}

int controller_loadFromText(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *f = fopen("data.csv", "r");

		if (f == NULL)
		{
			printf("No se pudo abrir el archivo de texto\n\n");
			return todoOk;
		}

		parser_PassengerFromText(f, pArrayListPassenger);

		printf("\nCargado correctamente desde texto\n\n");
		fclose(f);
	}

	return todoOk;
}

int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *f = fopen("data.bin", "rb");
		if (f == NULL)
		{
			printf("No se pudo abrir el archivo binario\n\n");
			return todoOk;
		}

		parser_PassengerFromBinary(f, pArrayListPassenger);

		printf("\nCargado correctamente desde binario\n\n");
		fclose(f);
	}

	return todoOk;
}

int controller_addPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (pArrayListPassenger != NULL)
	{
		Passenger *nuevoPasajero = NULL;

		char nombre[50];
		char apellido[50];
		char codigo[15];
		int validarPrecio = 0;
		float precio = 0;
		int validTipo = 0;
		int tipo = 0;
		int status = 0;

		printf("\n[>] Ingrese el nombre del pasajero: ");
		fflush(stdin);
		gets(nombre);
		validarPalabra(nombre);

		printf("\n[>] Ingrese el apellido del pasajero: ");
		fflush(stdin);
		gets(apellido);
		validarPalabra(apellido);

		printf("\n[>] Ingrese precio: ");
		validarPrecio = scanf("%f", &precio);
		validarFloat(validarPrecio, &precio);

		printf("\nCodigo de vuelo\n");
		printf("Recuerde que debe tener 7 digitos y empezar con 'A', 'B', 'C' o 'D'\n\n");
		printf("[>] Ingrese codigo: ");
		fflush(stdin);
		gets(codigo);
		validarCodigoYStatus(codigo, &status);

		printf("\n\nAclaracion: Todos los vuelos de la linea 'C' ya aterrizaron\n");
		printf("Aclaracion: Todos los vuelos de la linea 'A' se encuentran en vuelo\n");
		printf("Aclaracion: Todos los vuelos de la linea 'B' se encuentran estan en horario\n");
		printf("Aclaracion: Todos los vuelos de la linea 'D' se encuentran demorados\n\n");

		system("pause");

		printf("Tipos de pasajero \n\n");
		printf("1. Executive Class \n");
		printf("2. First Class \n");
		printf("3. Economy Class \n\n");
		printf("[>] Seleccione su tipo: ");
		validTipo = scanf("%d", &tipo);
		validarTipo(validTipo, &tipo);

		int idActual = controller_getUltimaID();

		nuevoPasajero = Passenger_newParametrosAdd(idActual, nombre, apellido, precio, codigo, tipo, status);

		if (nuevoPasajero != NULL)
		{
			ll_add(pArrayListPassenger, nuevoPasajero);

			controller_actualizarID(idActual);

			todoOk = 1;

			printf("\nSe agrego correctamente al nuevo pasajero\n\n");
		}
	}

	if (todoOk == 0)
	{
		printf("No se pudo agregar al pasajero\n\n");
	}

	return todoOk;
}

int controller_editPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	int len = ll_len(pArrayListPassenger);
	int indice;

	if (pArrayListPassenger != NULL)
	{
		do
		{
			if (len == 0)
			{
				printf("No hay pasajeros en el sistema\n\n");
				return todoOk;
			}
			controller_ListPassenger(pArrayListPassenger);
			printf("[>] Ingrese la ID del pasajero a modificar: ");
			fflush(stdin);
			scanf("%d", &id);

			if (controller_buscarPasajeroPorID(pArrayListPassenger, len, id) == -1)
			{
				printf("No hay ningun pasajero con esa ID \n");
				system("pause");
			}
			else
			{
				indice = controller_buscarPasajeroPorID(pArrayListPassenger, len, id);
				Passenger *pasajeroEditado = ll_get(pArrayListPassenger, indice);

				char nombre[50];
				char apellido[50];
				char codigo[15];
				int validarPrecio = 0;
				float precio = 0;
				int validTipo = 0;
				int tipo = 0;
				int status = 0;

				switch (menuModificar())
				{
				case 1:
					printf("\n[>] Ingrese el nuevo nombre: ");
					fflush(stdin);
					gets(nombre);
					validarPalabra(nombre);
					Passenger_setNombre(pasajeroEditado, nombre);
					ll_set(pArrayListPassenger, indice, pasajeroEditado);

					printf("\nNombre modificado correctamente \n\n");
					todoOk = 1;
					break;
				case 2:
					printf("[>] Ingrese el nuevo apellido: ");
					fflush(stdin);
					gets(apellido);
					validarPalabra(apellido);
					Passenger_setApellido(pasajeroEditado, apellido);
					ll_set(pArrayListPassenger, indice, pasajeroEditado);

					printf("\nApellido modificado correctamente \n\n");
					todoOk = 1;
					break;
				case 3:
					printf("\n[>] Ingrese el nuevo precio: ");
					validarPrecio = scanf("%f", &precio);
					validarFloat(validarPrecio, &precio);
					Passenger_setPrecio(pasajeroEditado, precio);
					ll_set(pArrayListPassenger, indice, pasajeroEditado);

					printf("\nPrecio modificado correctamente \n\n");
					todoOk = 1;
					break;
				case 4:
					printf("\nCodigo de vuelo\n");
					printf("Recuerde que debe tener 10 digitos y empezar con 'A', 'B', 'C' o 'D'\n\n");
					printf("[>] Ingrese codigo: ");
					fflush(stdin);
					gets(codigo);
					validarCodigoYStatus(codigo, &status);

					printf("\nAclaracion: Todos los vuelos de la linea 'C' ya aterrizaron\n");
					printf("Aclaracion: Todos los vuelos de la linea 'A' se encuentran en vuelo\n");
					printf("Aclaracion: Todos los vuelos de la linea 'B' se encuentran estan en horario\n");
					printf("Aclaracion: Todos los vuelos de la linea 'D' se encuentran demorados\n\n");

					system("pause");
					Passenger_setCodigoVuelo(pasajeroEditado, codigo);
					Passenger_setStatusFlight(pasajeroEditado, status);
					ll_set(pArrayListPassenger, indice, pasajeroEditado);

					printf("\nCodigo modificado correctamente \n\n");
					todoOk = 1;
					break;
				case 5:
					printf("Tipos de pasajero \n\n");
					printf("1. Executive Class \n");
					printf("2. First Class \n");
					printf("3. Economy Class \n\n");
					printf("[>] Seleccione su tipo: ");
					validTipo = scanf("%d", &tipo);
					validarTipo(validTipo, &tipo);
					pasajeroEditado->tipoPasajero = tipo;
					Passenger_setTipoPasajero(pasajeroEditado, tipo);
					ll_set(pArrayListPassenger, indice, pasajeroEditado);

					printf("\nTipo modificado correctamente \n\n");
					todoOk = 1;
					break;

				default:
					printf("Opcion incorrecta\n\n");
					system("pause");
					break;
				}
			}
		} while (todoOk == 0);
	}

	return 1;
}

int controller_removePassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	int len = ll_len(pArrayListPassenger);
	int indice;
	char confirma;

	if (pArrayListPassenger != NULL)
	{
		do
		{
			if (len == 0)
			{
				printf("No hay pasajeros en el sistema\n\n");
				return todoOk;
			}
			controller_ListPassenger(pArrayListPassenger);
			printf("[>] Ingrese la ID del pasajero a eliminar: ");
			fflush(stdin);
			scanf("%d", &id);

			if (controller_buscarPasajeroPorID(pArrayListPassenger, len, id) == -1)
			{
				printf("No hay ningun pasajero con esa ID \n");
				system("pause");
			}
			else
			{
				indice = controller_buscarPasajeroPorID(pArrayListPassenger, len, id);
				printf("[>] Confirma la baja del pasajero? (si = 's'  no = 'n') \n");
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
				if (confirma == 'n')
				{
					printf("La baja del pasajero fue cancelada\n");
					system("pause");
					return todoOk;
				}
				else
				{
					ll_remove(pArrayListPassenger, indice);
					printf("Baja realizada correctamente\n");
					system("pause");
					todoOk = 1;
				}
			}

		} while (todoOk == 0);
	}
	return todoOk;
}

int controller_buscarPasajeroPorID(LinkedList *pArrayListPassenger, int len, int id)
{
	int indice = -1;
	int idEncontrado;

	Passenger *pass = NULL;

	if (pArrayListPassenger != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			pass = ll_get(pArrayListPassenger, i);

			if (pass != NULL)
			{
				Passenger_getId(pass, &idEncontrado);

				if (idEncontrado == id)
				{
					indice = i;
				}
			}
		}
	}

	return indice;
}

int controller_ListPassenger(LinkedList *pArrayListPassenger)
{
	if (pArrayListPassenger != NULL)
	{
		Passenger *auxPass = NULL;
		int flag = 0;

		printf("                                           *** Listado de Pasajeros ***\n\n");
		printf(" ID          Nombre              Apellido           Precio         Codigo de vuelo        Tipo de Pasajero         Estado de Vuelo\n");
		printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger *)ll_get(pArrayListPassenger, i);
			if (auxPass != NULL)
			{
				mostrarPasajero(auxPass);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("                                            No hay pasajeros cargados                         \n\n");
		}
	}

	return 1;
}

int controller_sortPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (pArrayListPassenger != NULL)
	{
		if (ll_len(pArrayListPassenger) == 0)
		{
			printf("No hay pasajeros en el sistema\n");
			return 0;
		}

		int criterio;
		char criterioString[20];

		switch (menuOrdenar())
		{
		case 1:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararId, criterio);
			printf("\nLa lista ahora esta ordenada por ID (%s)\n\n", criterioString);
			break;

		case 2:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararNombre, criterio);
			printf("\nLa lista ahora esta ordenada por Nombre (%s)\n\n", criterioString);
			break;

		case 3:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararApellido, criterio);
			printf("\nLa lista ahora esta ordenada por Apellido (%s)\n\n", criterioString);
			break;

		case 4:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararPrecio, criterio);
			printf("\nLa lista ahora esta ordenada por Precio (%s)\n\n", criterioString);
			break;

		case 5:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararCodigo, criterio);
			printf("\nLa lista ahora esta ordenada por Codigo de Vuelo (%s)\n\n", criterioString);
			break;

		case 6:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararTipo, criterio);
			printf("\nLa lista ahora esta ordenada por Tipo (%s)\n\n", criterioString);
			break;

		case 7:
			criterio = preguntarCriterio(criterioString);
			ll_sort(pArrayListPassenger, pasajeroCompararEstado, criterio);
			printf("\nLa lista ahora esta ordenada por Estado de Vuelo (%s)\n\n", criterioString);
			break;

		default:
			printf("Opcion erronea\n");
			return 0;
			break;
		}
		todoOk = 1;
	}

	return todoOk;
}

int controller_saveAsText(char *path, LinkedList *pArrayListPassenger)
{
	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *f = fopen("data.csv", "w");
		Passenger *auxPass = NULL;

		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger *)ll_get(pArrayListPassenger, i);
			fprintf(f, "%d,%s,%s,%f,%s,%d,%d\n",
							auxPass->id, auxPass->nombre, auxPass->apellido, auxPass->precio,
							auxPass->codigoVuelo, auxPass->tipoPasajero, auxPass->statusFlight);
		}

		fclose(f);
	}

	return 1;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger)
{
	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *f = fopen("data.bin", "wb");
		Passenger *auxPass = NULL;

		for (int i = 0; i < ll_len(pArrayListPassenger); i++)
		{
			auxPass = (Passenger *)ll_get(pArrayListPassenger, i);
			fwrite(auxPass, sizeof(Passenger), 1, f);
		}

		fclose(f);
	}

	return 1;
}

int controller_getUltimaID()
{
	int ultimaId = 1;
	char ultimaIdStr[100];

	FILE *f = fopen("ultimaID.txt", "r");

	if (f != NULL)
	{
		fscanf(f, "%[^\n]", ultimaIdStr);
		ultimaId = atoi(ultimaIdStr);
	}
	else
	{
		f = fopen("ultimaID.txt", "w");
		fprintf(f, "%d\n", ultimaId);
	}

	fclose(f);

	return ultimaId;
}

int controller_actualizarID(int idActual)
{
	int todoOk = 0;

	FILE *f = fopen("ultimaID.txt", "w");

	if (f != NULL)
	{
		fprintf(f, "%d\n", idActual + 1);
		todoOk = 1;
	}
	fclose(f);

	return todoOk;
}

void controller_setearID()
{
	FILE *f = fopen("ultimaID.txt", "w");

	if (f != NULL)
	{
		fprintf(f, "%d\n", 1);
	}
	fclose(f);
}