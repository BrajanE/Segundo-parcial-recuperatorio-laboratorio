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
	int rtn=-1;
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
		rtn=1;
	}
    return rtn;
}
