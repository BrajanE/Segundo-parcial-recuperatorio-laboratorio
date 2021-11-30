#ifndef LIBROS_H_
#define LIBROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "General.h"
#include "LinkedList.h"

#define TAM_LIBROS 500

typedef struct
{
	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;
}eLibro;

eLibro* libros_new(); //Inicializar el array "initArray"
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* idEditorialStr);
void libro_delete(eLibro* this);

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

int libro_setTitulo(eLibro* this,char* titulo);
int libro_getTitulo(eLibro* this,char* titulo);

int libro_setAutor(eLibro* this,char* autor);
int libro_getAutor(eLibro* this,char* autor);

int libro_setPrecio(eLibro* this,float precio);
int libro_getPrecio(eLibro* this,float* precio);

int libro_setIdEditorial(eLibro* this,int idEditorial);
int libro_getIdEditorial(eLibro* this,int* idEditorial);













#endif /* LIBROS_H_ */
