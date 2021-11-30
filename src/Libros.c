#include "Libros.h"

/**
 * Inicia el Array
 * @return
 */
eLibro* libros_new()
{
	eLibro* plistaLibros;
	plistaLibros = (eLibro*) calloc(sizeof(eLibro),1);

	return plistaLibros;
}

/**
 * funcion alberga las demas funciones del set, toma cada dato y los guarda en la variable correspondiente
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return
 */
eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr,char* idEditorialStr)
{
	eLibro* plistaLibros = libros_new();
	if(plistaLibros!=NULL && idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && idEditorialStr!=NULL)
	{
		libro_setId(plistaLibros, atoi(idStr));
		libro_setTitulo(plistaLibros,tituloStr);
		libro_setAutor(plistaLibros,autorStr);
		libro_setPrecio(plistaLibros, atof(precioStr));
		libro_setIdEditorial(plistaLibros, atoi(idEditorialStr));
	}
	return plistaLibros;
}

/**
 * Elimina un elemento
 * @param this
 */
void libro_delete(eLibro* this)
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
int libro_setId(eLibro* this,int id)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->id=id;
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
int libro_getId(eLibro* this,int* id)
{
	int rtn = -1;
	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
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
int libro_setTitulo(eLibro* this,char* titulo)
{
	int rtn = -1;
	if(this!=NULL && titulo!=NULL)
	{
		strcpy(this->titulo,titulo);
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
int libro_getTitulo(eLibro* this,char* titulo)
{
	int rtn = -1;
	if(this!=NULL && titulo !=NULL)
	{
		strcpy(titulo,this->titulo);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato nuevo "horas trabajadas" y lo guarda en el listado
 * @param this
 * @param horasTrabajadas
 * @return
 */
int libro_setAutor(eLibro* this,char* autor)
{
	int rtn = -1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(this->autor,autor);
		rtn = 1;
	}

	return rtn;
}
/**
 * Toma un dato de Horas trabajadas del listado y lo guarda en la variable "horas trabajadas" que luego se enviara por puntero
 * @param this
 * @param horasTrabajadas
 * @return
 */
int libro_getAutor(eLibro* this,char* autor)
{
	int rtn = -1;
	if(this!=NULL && autor!=NULL)
	{
		strcpy(autor,this->autor);
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato "sueldo" y lo guarda en el listado
 * @param this
 * @param sueldo
 * @return
 */
int libro_setPrecio(eLibro* this,float precio)
{
	int rtn = -1;
	if(this!=NULL)
	{
		this->precio=precio;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato de "sueldo" del listado y lo guarda en la variable "sueldo" que luego se enviara por puntero
 * @param this
 * @param sueldo
 * @return
 */
int libro_getPrecio(eLibro* this,float* precio)
{
	int rtn = -1;
	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		rtn = 1;
	}

	return rtn;
}

/**
 * Toma un dato ID y lo guarda en el listado
 * @param this
 * @param id
 * @return rtn
 */
int libro_setIdEditorial(eLibro* this,int idEditorial)
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
int libro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int rtn = -1;
	if(this!=NULL && idEditorial!=NULL)
	{
		*idEditorial=this->idEditorial;
		rtn = 1;
	}

	return rtn;
}
