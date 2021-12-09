#include "Parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* pll_listaLibros)
{
	int ultimoIdCargado;
	char idStr[100];
	char tituloStr[100];
	char autorStr[100];
	char precioStr[100];
	char idEditorial[100];
	eLibro* plistaLibros;
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,tituloStr,autorStr,precioStr,idEditorial);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,tituloStr,autorStr,precioStr,idEditorial);
		plistaLibros = libro_newParametros(idStr,tituloStr,autorStr,precioStr,idEditorial);
		ll_add(pll_listaLibros, plistaLibros);
		libro_getId(plistaLibros,&ultimoIdCargado);
	}
    return ultimoIdCargado;
}

int parser_EditorialFromText(FILE* pFile , LinkedList* pll_ListaEditorales)
{
	int ultimoIdCargado;
	char idStr[100];
	char nombreStr[100];
	eEditorial* plistaEditorial;

	fscanf(pFile,"%[^,],%[^\n]\n",idStr, nombreStr);
	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^\n]\n",idStr, nombreStr);
		plistaEditorial = editorial_newParametros(idStr, nombreStr);
		ll_add(pll_ListaEditorales, plistaEditorial);
		editorial_getIdEditorial(plistaEditorial,&ultimoIdCargado);

	}
    return ultimoIdCargado;
}

int parser_SaveLibrosAsText(LinkedList* this, FILE* path)
{
	int rtn=-1;
	eLibro* libroAuxiliar;
	int id;
	char titulo[100];
	char autor[100];
	float precio;
	int idEditorial;
	int len=ll_len(this);
	fprintf(path,"ID,Titulo,Autor,Precio,ID de Editorial\n");
	for(int i=0; i<len;i++)
	{
		libroAuxiliar=ll_get(this, i);
		libro_getId(libroAuxiliar,&id);
		libro_getTitulo(libroAuxiliar,titulo);
		libro_getAutor(libroAuxiliar,autor);
		libro_getPrecio(libroAuxiliar,&precio);
		libro_getIdEditorial(libroAuxiliar,&idEditorial);
		fprintf(path,"%d,%s,%s,%.2f,%d\n",id,titulo,autor,precio,idEditorial);
		rtn=1;
	}

	return rtn;
}
