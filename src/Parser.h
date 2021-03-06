#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"
#include "Controller.h"

int parser_LibrosFromText(FILE* pFile , LinkedList* pll_listaLibros);
int parser_EditorialFromText(FILE* pFile , LinkedList* pll_ListaEditorales);
int parser_SaveLibrosAsText(LinkedList* this, FILE* path);

#endif /* PARSER_H_ */
