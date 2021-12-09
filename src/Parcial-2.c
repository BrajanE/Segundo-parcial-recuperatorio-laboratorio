#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"
#include "Editoriales.h"
#include "Libros.h"
#include "Controller.h"
#include "Parser.h"
#include "FuncEspecificas.h"
#define TAM_S 16
int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	char opcionDeCarga[TAM_S];
	int flagOpcion=-1;
	int flagCarga;
	int corroboracion;
	char libro[TAM_S]="Libro.csv";
	char editorial[TAM_S]="Editorial.csv";
	float precioTotalPearson=-1;
	int cantLibrosMayor500;

	LinkedList* pll_listaLibros=NULL;
	LinkedList* pll_ListaEditorales=NULL;
	LinkedList* pll_ListaMinotauro=NULL;
	LinkedList* pll_ListaConDescuestos=NULL;
	pll_listaLibros=ll_newLinkedList();
	pll_ListaEditorales=ll_newLinkedList();
	pll_ListaMinotauro=ll_newLinkedList();
	pll_ListaConDescuestos=ll_newLinkedList();

	do
	{
		MostrarMenu();
		opcion=PedirEnteroFull("Ingrese opcion: ",8);
		switch(opcion)
		{
		case 1:
			MostrarMenuDeCarga();
			PedirArchivo("Ingrese nombre de archivo(tiene 3 intentos): ", opcionDeCarga);
			if(strcmp(opcionDeCarga,libro)==0)
			{
				flagCarga=controller_loadFromText(opcionDeCarga,pll_listaLibros,pll_ListaEditorales);
			}else if(strcmp(opcionDeCarga,editorial)==0){
				flagCarga=controller_loadFromText(opcionDeCarga,pll_listaLibros,pll_ListaEditorales);
			}
			flagOpcion=CorroboracionDeCargado(flagCarga);
			break;
		case 2:
			if(flagOpcion!=-1)
			{
				corroboracion=ll_sort(pll_listaLibros,SortByAutor,1);
				MensajeDeCorroboracion(corroboracion,"Ordenado exitosamente, para ver los cambios elija opcion 3 del menu principal.\n","Error al ordenar los datos.\n");
			}
			break;
		case 3:
			if(flagOpcion==3)
			{
				MostrarListas(pll_listaLibros, pll_ListaEditorales);
			} else
			{
				printf("Para ver la lista de los libros con sus respectivos editoriales deberia caragr el archivo 'editorial.csv'.\n");
			}
			break;
		case 4:
			if(flagOpcion!=-1)
			{
				pll_ListaMinotauro= ll_filter(pll_listaLibros, SelecEdMinotauro);
				if(pll_ListaMinotauro!=NULL)
				{
					//corroboracion= MostrarListadoMinotauro(pll_ListaMinotauro);
					corroboracion = controller_ListLibros(pll_ListaMinotauro);
					if(corroboracion==1)
					{
						corroboracion =controller_SaveLibrosAsText("MinotauroEditorial.csv", pll_ListaMinotauro);
						MensajeDeCorroboracion(corroboracion,"\nListado guardado en archivo 'MinotauroEditorial'.\n","Error escribir archivo.\n");
					}
				}
				else{
					printf("\nError, no hay datos en la lista.\n");
				}
			}
			break;
		case 5:
			if(flagOpcion!=-1)
			{
				pll_ListaConDescuestos= ll_map (pll_listaLibros, AplicarDescuento);
				//PrintLibro(pll_ListaConDescuestos, 6);
				//PrintLibro(pll_ListaConDescuestos, 16);
				if(pll_ListaConDescuestos!=NULL)
				{
					corroboracion =controller_SaveLibrosAsText("Mapeado.csv", pll_ListaConDescuestos);
					MensajeDeCorroboracion(corroboracion,"Listado guardado en archivo 'Mapeado.csv'.\n","Error escribir archivo.\n");
					if(corroboracion==1)
					{
						MostrarMapeado();
						opcion=PedirEnteroFull("Ingrese opcion: ",2);
						if(opcion==1)
						{
							MostrarListas(pll_ListaConDescuestos, pll_ListaEditorales);
						}
					}
				}
			}
			else{
				printf("\nError, no hay datos en la lista.\n");
			}
			break;
		case 6:
			if(flagOpcion!=-1)
			{
				cantLibrosMayor500 = ll_count(pll_listaLibros,OperacionesConPrecios,&precioTotalPearson);
				if(cantLibrosMayor500>0)
					{
						printf("La cantidad de Libros con valor mayor a 500 es:\n"
								"Total: %d\n", cantLibrosMayor500);
					}
			}
			break;
		case 7:
			if(flagOpcion!=-1)
			{
				cantLibrosMayor500 = ll_count(pll_listaLibros,OperacionesConPrecios,&precioTotalPearson);
				if(precioTotalPearson!=-1)
				{
					printf("La sumatoria de los precios de los libros de la editorial PEARSON es:\n"
							"Total: %.2f\n",precioTotalPearson);
				}
			}
			break;

			if(flagOpcion == -1)
			{
				printf("\nPrimero debe cargar los datos.\n");
			}
		}

	}while(opcion != 8);
	ll_deleteLinkedList(pll_listaLibros);
	ll_deleteLinkedList(pll_ListaEditorales);
	ll_deleteLinkedList(pll_ListaMinotauro);
	ll_deleteLinkedList(pll_ListaConDescuestos);
	return EXIT_SUCCESS;
}
