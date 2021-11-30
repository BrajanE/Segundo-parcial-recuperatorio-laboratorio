#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "Parser.h"
#include "FuncEspecificas.h"

int SortByAutor(void* primerDato, void* segundoDato)
{
	eLibro* primerLibro;
	eLibro* segundoLibro;
	int comparacion =-1;
	primerLibro=(eLibro*) primerDato;
	segundoLibro=(eLibro*) segundoDato;
	if(primerLibro!=NULL && segundoLibro!=NULL)
	{
		comparacion = strcmp(primerLibro->autor, segundoLibro->autor);
	}
	return comparacion;
}

void PrintArraysLibros(LinkedList* pll_listaLibros, int index)
{
	eLibro* pLibrosAuxiliar;
	int id;
	char titulo[100];
	char autor[51];
	float precio;
	int libroIdEditorial;

	pLibrosAuxiliar = ll_get(pll_listaLibros, index);

	libro_getId(pLibrosAuxiliar,&id);
	libro_getTitulo(pLibrosAuxiliar,titulo);
	libro_getAutor(pLibrosAuxiliar,autor);
	libro_getPrecio(pLibrosAuxiliar,&precio);
	libro_getIdEditorial(pLibrosAuxiliar,&libroIdEditorial);


	printf("%d\t\t%s\t\t%s\t%.2f\t%d\n", id,titulo,autor,precio,libroIdEditorial);

}

void CargarArchivo(char* path , LinkedList* pll_listaLibros)
{
	FILE* pLibros;
	eLibro* pListaLibros=libros_new();
	eLibro* auxiliar=libros_new();
	char  idStr [100];
	char tituloStr[100];
	char autorStr[100];
	char precioStr[100];
	char idEditorial[100];
	int i=0;
	pLibros = fopen(path,"r");
	while(!feof(pLibros))
	{
		fscanf(pLibros,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,tituloStr,autorStr,precioStr,idEditorial);
		auxiliar->id = atoi(idStr);
		strcpy(auxiliar->titulo,tituloStr);
		strcpy(auxiliar->autor,autorStr);
		auxiliar->precio=atof(precioStr);
		auxiliar->idEditorial = atoi(idEditorial);
		pListaLibros[i]=auxiliar[i];
		ll_add(pll_listaLibros, pListaLibros);
		i++;
	}

	fclose(pLibros);
}
