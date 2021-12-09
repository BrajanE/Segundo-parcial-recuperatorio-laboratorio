#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "Parser.h"
#include "FuncEspecificas.h"
/// @param primerDato
/// @param segundoDato
/// @return int
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
/// @imprime un solo libro
/// @param pll_listaLibros
/// @param index
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

		printf("%d\t%s%25s%20.2f%20d\n", id,titulo,autor,precio, libroIdEditorial);
	}
}
/// funcion parametro que selecciona los elementos de la editorial minotauro
/// @param pElement
/// @return int
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
/// @brief muestra la lista de editorial minotauro
/// @param ListaEditMinotauro
/// @param index
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
/// @brief toma un pElement y realiza los calculos de descuentos segun editorial y precio
/// @param pElement
/// @param pDescuento
void* AplicarDescuento(void* pElement)
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
	}
	return pLibroBuscado;
}
/// @brief toma el pElement y reliza un conteo y/o suma de los precios correspondientes a una editorial
/// @param pElement
/// @param precioTotal
/// @return contador y por punteo la suma de los precios totales
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
