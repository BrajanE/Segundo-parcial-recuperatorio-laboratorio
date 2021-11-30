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
	int corroboracion;
	char libro[TAM_S]="Libro.csv";
	char archivoLibro[100]="C:\\Users\\estra\\Desktop\\Segundo Parcial\\Parcial-2\\src\\Libro.csv";
	char editorial[TAM_S]="Editorial.csv";
	LinkedList* pll_listaLibros=NULL;
	//LinkedList* pll_ListaEditorales=NULL;
	pll_listaLibros=ll_newLinkedList();
	//pll_ListaEditorales=ll_newLinkedList();
	do
	{
		MostrarMenu();
		opcion=PedirEnteroFull("Ingrese opcion: ",6);
		switch(opcion)
		{
		case 1:
			//controller_loadFromText("Libro.csv",pll_listaLibros);
			MostrarMenuDeCarga();
			PedirArchivo("Ingrese nombre de archivo: ", opcionDeCarga);
			if(strcmp(opcionDeCarga,libro)==0)
			{
				corroboracion=controller_loadFromText(archivoLibro,pll_listaLibros);
				MensajeDeCorroboracion(corroboracion,"Se cargo el archivo elegido.\n","Error en la carga.\n");
				flagOpcion=1;
			} else {
				printf("No se cargaron los archivos.\n");
			}
			break;
		case 2:
			if(flagOpcion!=-1)
			{
				corroboracion=ll_sort(pll_listaLibros,SortByAutor,1);
				MensajeDeCorroboracion(corroboracion,"Ordenado exitosamente, para ver los cambios vaya a la opcion 6 del menu principal.\n","Error al ordenar los datos.\n");
			}
			break;
		case 3:

				controller_ListLibros(pll_listaLibros);

			break;
		case 4:
			if(flagOpcion!=-1)
			{

			}
			break;
			if(flagOpcion == -1)
			{
				printf("\nPrimero debe cargar los datos.\n");
			}
		}
	}while(opcion != 5);
	ll_deleteLinkedList(pll_listaLibros);
	//ll_deleteLinkedList(pll_ListaEditorales);
	return EXIT_SUCCESS;
}
