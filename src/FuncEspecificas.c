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

void PrintLibro(LinkedList* pll_listaLibros, int index)
{
	eLibro* pLibrosAuxiliar;
	int id;
	char titulo[100];
	char autor[51];
	float precio;
	int libroIdEditorial;
	if(pll_listaLibros!=NULL)
	{
		pLibrosAuxiliar = ll_get(pll_listaLibros, index);

		libro_getId(pLibrosAuxiliar,&id);
		libro_getTitulo(pLibrosAuxiliar,titulo);
		libro_getAutor(pLibrosAuxiliar,autor);
		libro_getPrecio(pLibrosAuxiliar,&precio);
		libro_getIdEditorial(pLibrosAuxiliar,&libroIdEditorial);

		printf("%d\t%s\t\t%s\t\t%.2f\t\t%d\n", id,titulo,autor,precio, libroIdEditorial);
	}
}

int SelecEdMinotauro(void* pElement)
{
	int rtn =0;
	eLibro* pLibroBuscado;
	pLibroBuscado = (eLibro*) pElement;
	if(pLibroBuscado!=NULL)
	{
		if(pLibroBuscado->idEditorial == 4)
		{
			rtn=1;
		}
	}
	return rtn;
}

void MostrarLibroEdMinotauro(LinkedList* ListaEditMinotauro, int index)
{
	eLibro* pLibrosAuxiliar;
	int id;
	char titulo[100];
	char autor[51];
	float precio;
	//int libroIdEditorial;
	if(ListaEditMinotauro!=NULL)
	{
		pLibrosAuxiliar = ll_get(ListaEditMinotauro, index);
		libro_getId(pLibrosAuxiliar,&id);
		libro_getTitulo(pLibrosAuxiliar,titulo);
		libro_getAutor(pLibrosAuxiliar,autor);
		libro_getPrecio(pLibrosAuxiliar,&precio);
		//libro_getIdEditorial(pLibrosAuxiliar,&libroIdEditorial);

		printf("%d\t%s\t\t%s\t\t%.2f\n", id,titulo,autor,precio);
	}
}

void* AplicarDescuento(void* pElement, float* pDescuento)
{
	eLibro* pLibroBuscado;
	pLibroBuscado = (eLibro*) pElement;
	if(pLibroBuscado!=NULL)
	{
		if(pLibroBuscado->idEditorial == 1 && pLibroBuscado->precio>=300)
		{
			pLibroBuscado->precio=pLibroBuscado->precio*0.8;
		}
		if(pLibroBuscado->idEditorial == 2 && pLibroBuscado->precio<=200)
		{
			pLibroBuscado->precio=pLibroBuscado->precio*0.9;
		}
		*pDescuento=pLibroBuscado->precio;
	}
	return pLibroBuscado;
}

int OperacionesConPrecios(void* pElement, float* precioTotal)
{
	int rtn =0;
	float total=0;
	total=*precioTotal;
	eLibro* pLibroBuscado;
	pLibroBuscado = (eLibro*) pElement;
	if(pLibroBuscado!=NULL)
	{
		if(pLibroBuscado->precio >= 500)
		{
			rtn=1;
		}
		if(pLibroBuscado->idEditorial==3)
		{
			total=pLibroBuscado->precio+total;
		}
		*precioTotal=total;
	}
	return rtn;
}
