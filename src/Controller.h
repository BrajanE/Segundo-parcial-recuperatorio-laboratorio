#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "Parser.h"
#include "FuncEspecificas.h"

int controller_loadFromText(char* path , LinkedList* pll_listaLibros, LinkedList* pll_ListaEditorales);
int controller_ListLibros(LinkedList* pll_listaLibros);
int MostrarListas(LinkedList* pll_listaLibros, LinkedList* pll_ListaEditorales);
int MostrarListadoMinotauro(LinkedList* ListaEditMinotauro);
int controller_SaveLibrosAsText(char* path, LinkedList* this);

#endif /* CONTROLLER_H_ */
