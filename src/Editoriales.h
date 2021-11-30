#ifndef EDITORIALES_H_
#define EDITORIALES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"

#define TAM_EDITORIALES 6

typedef struct
{
	int idEditorial;
	char nombre[51];
}eEditorial;

eEditorial* editoriales_new();
eEditorial* editorial_newParametros(char* idEditorialStr, char* nombreStr);
void editorial_delete(eEditorial* this);

int editorial_setIdEditorial(eEditorial* this,int idEditorial);
int editorial_getIdEditorial(eEditorial* this,int* idEditorial);

int editorial_setNombre(eEditorial* this,char* nombre);
int editorial_getNombre(eEditorial* this,char* nombre);







#endif /* EDITORIALES_H_ */
