#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pll_listaLibros)
{
	int rtn = -1;
	char libros[15]="Libro.csv";
	char editoriales[15]="Editorial.csv";
	FILE* pFile;
	if(pll_listaLibros!=NULL && path!=NULL)
	{
		//if(strcmp(path,libros)==0)
		{
			pFile = fopen(path, "r");
			if(pFile!=NULL)
			{
				rtn=parser_LibrosFromText(pFile ,pll_listaLibros);
			}

		}
		/*if(strcmp(path,editoriales)==0)
		{
			pFile = fopen(path, "r");
			if(pFile!=NULL)
			{
				parser_LibrosFromText(pFile,pll_ListaEditorales);
				rtn=1;
			}
		}*/
		fclose(pFile);
	}
    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_ListLibros(LinkedList* pll_listaLibros)
{
	int rtn=-1;
	int lenLibros;
	lenLibros=ll_len(pll_listaLibros);
    if(pll_listaLibros!=NULL)
    {
    	printf("ID\t\tTitulo\tAutor\tPrecio\tID Editorial\n");
    	for(int i=0;i<lenLibros;i++)
    	{
    		PrintArraysLibros(pll_listaLibros,i);
    		rtn=1;
    		printf("ingreso");
    	}
    }
	return rtn;
}
