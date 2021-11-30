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
void PrintArraysLibros(LinkedList* pll_listaLibros, int index);
void CargarArchivo(char* path , LinkedList* pll_listaLibros);


#endif /* FUNCESPECIFICAS_H_ */
