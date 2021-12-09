#include "Editoriales.h"

/**
 * Inicia el Array
 * @return eEditorial
 */
eEditorial* editoriales_new()
{
	eEditorial* plistaEditoriales;
	plistaEditoriales = (eEditorial*) malloc(sizeof(eEditorial));

	return plistaEditoriales;
}

/**
 * funcion alberga las demas funciones del set, toma cada dato y los guarda en la variable correspondiente
 * @param idStr
 * @param nombreStr
 * @return eEditorial
 */
eEditorial* editorial_newParametros(char* idEditorialStr, char* nombreStr)
{
	eEditorial* plistaEditoriales;
	plistaEditoriales = editoriales_new();
	if(plistaEditoriales!=NULL && idEditorialStr!=NULL && nombreStr!=NULL)
	{
		editorial_setIdEditorial(plistaEditoriales, atoi(idEditorialStr));
		editorial_setNombre(plistaEditoriales,nombreStr);
	}
	return plistaEditoriales;
}

/**
 * Elimina un elemento
 * @param this
 */
void editorial_delete(eEditorial* this)
{
	if(this!=NULL)
	{
		free(this);
		this=NULL;
	}
}

/**
 * Toma un dato ID y lo guarda en el listado
 * @param this
 * @param id
 * @return rtn
 */
int editorial_setIdEditorial(eEditorial* this,int idEditorial)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->idEditorial=idEditorial;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un Id del listado y lo guarda en la variable id que luego se enviara por puntero
 * @param this
 * @param id
 * @return
 */
int editorial_getIdEditorial(eEditorial* this,int* idEditorial)
{
	int rtn = -1;
	if(this!=NULL && idEditorial!=NULL)
	{
		*idEditorial=this->idEditorial;
		rtn = 1;
	}

	return rtn;
}


/**
 * Toma un dato Nombre y lo guarda en el listado
 * @param this
 * @param nombre
 * @return
 */
int editorial_setNombre(eEditorial* this,char* nombre)
{
	int rtn = -1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un Nombre del listado y lo guarda en la variable nombre que luego se enviara por puntero
 * @param this
 * @param nombre
 * @return
 */
int editorial_getNombre(eEditorial* this,char* nombre)
{
	int rtn = -1;
	if(this!=NULL && nombre !=NULL)
	{
		strcpy(nombre,this->nombre);
		rtn = 1;
	}

	return rtn;
}
