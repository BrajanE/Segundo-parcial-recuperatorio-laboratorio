#ifndef FUNCESPECIFICAS_H_
#define FUNCESPECIFICAS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "Parser.h"

int SortByAutor(void* primerDato, void* segundoDato);
void PrintLibro(LinkedList* pll_listaLibros, int index);
int SelecEdMinotauro(void* pElement);
void MostrarLibroEdMinotauro(LinkedList* ListaEditMinotauro, int index);
void* AplicarDescuento(void* pElement, float* pDescuento);
int OperacionesConPrecios(void* pElement, float* precioTotal);

#endif /* FUNCESPECIFICAS_H_ */
