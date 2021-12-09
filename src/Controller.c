#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pll_listaLibros, LinkedList* pll_ListaEditorales)
{
	int rtn = -1;
	char libros[15]="Libro.csv";
	char editoriales[15]="Editorial.csv";
	//char ubicacionLibro[100]="C:\\Users\\estra\\Desktop\\Segundo Parcial\\Parcial-2\\src\\Libro.csv";
	//char ubicacionEditorial[100]="C:\\Users\\estra\\Desktop\\Segundo Parcial\\Parcial-2\\src\\Editorial.csv";
	FILE* pFile;
	if(pll_listaLibros!=NULL && path!=NULL)
	{
		if(strcmp(path,libros)==0)
		{
			pFile = fopen(libros, "r");
			if(pFile!=NULL)
			{
				parser_LibrosFromText(pFile ,pll_listaLibros);
			}
			rtn=1;
		}
		if(strcmp(path,editoriales)==0)
		{
			pFile = fopen(editoriales, "r");
			if(pFile!=NULL)
			{
				parser_EditorialFromText(pFile ,pll_ListaEditorales);
			}
			rtn=2;
		}
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
    	printf("ID\tTitulo\t\tAutor\t\tPrecio\t\tID\t\tEditorial\n");
    	for(int i=0;i<lenLibros;i++)
    	{
    		PrintLibro(pll_listaLibros,i);
    		rtn=1;
    	}
    }
	return rtn;
}

int MostrarListas(LinkedList* pll_listaLibros, LinkedList* pll_ListaEditorales)
{
	int rtn=-1;
	int lenLibros=ll_len(pll_listaLibros);
	int lenEditoriales=ll_len(pll_ListaEditorales);
	eLibro* pLibrosAuxiliar;
	eEditorial* pEditorialesAuxiliar;
	int id;
	char titulo[100];
	char autor[51];
	float precio;
	int libroIdEditorial;

	int EdIdEditorial;
	char nombre[51];

	if(pll_listaLibros!=NULL && pll_ListaEditorales!=NULL && lenEditoriales>0 && lenLibros>0)
	{
		printf("ID\tTitulo\t\tAutor\t\tPrecio\t\tID\t\tEditorial\n");
		for(int i=0; i<lenLibros;i++)
		{
			pLibrosAuxiliar = ll_get(pll_listaLibros, i);

			if(pLibrosAuxiliar!=NULL)
			{	rtn=1;
				libro_getId(pLibrosAuxiliar,&id);
				libro_getTitulo(pLibrosAuxiliar,titulo);
				libro_getAutor(pLibrosAuxiliar,autor);
				libro_getPrecio(pLibrosAuxiliar,&precio);
				libro_getIdEditorial(pLibrosAuxiliar,&libroIdEditorial);
				for(int j=0; j<lenEditoriales;j++)
				{
					pEditorialesAuxiliar = ll_get(pll_ListaEditorales, j);
					if(pLibrosAuxiliar!=NULL)
					{
						editorial_getIdEditorial(pEditorialesAuxiliar,&EdIdEditorial);
						editorial_getNombre(pEditorialesAuxiliar,nombre);
						if(libroIdEditorial == EdIdEditorial)
						{
							printf("%d\t%s\t\t%s\t\t%.2f\t\t%s\n", id,titulo,autor,precio, nombre);
						}
					}
				}
			}
		}
	}
	return rtn;
}

int MostrarListadoMinotauro(LinkedList* ListaEditMinotauro)
{
	int rtn=-1;
	int len=ll_len(ListaEditMinotauro);
	if(ListaEditMinotauro!=NULL && len>0)
	{
		printf("ID\tTitulo\t\tAutor\t\tPrecio\n");
		for(int i=0;i<len;i++)
		{
			MostrarLibroEdMinotauro(ListaEditMinotauro,i);
			rtn=1;
		}
	}
	return rtn;
}

int controller_SaveLibrosAsText(char* path, LinkedList* this)
{
	int rtn=-1;
	FILE* pFile;
	if(path!=NULL && this!=NULL)
	{
		pFile=fopen(path,"w");
		if(pFile!=NULL)
		{
			rtn= parser_SaveLibrosAsText(this, pFile);
		}
		fclose(pFile);
	}
	return rtn;
}
