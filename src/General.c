#include "General.h"

void MostrarMenu()
{
	printf("1- Leer/Cargar archivos.\n"
			"2- Ordenar la lista generada de forma ascendente por autor.\n"
			"3- Imprimer datos de los libros y editorial.\n"
			"4- Listado y gardado de libros de la editorial MINOTAURO.\n"
			"5- Generar archivo de salida 'mapeado.csv', luego de aplicar funcion map.\n"
			"6- Mostrar cantidad de libros con precio mayor a 500.\n"
			"7- Mostrar sumatoria del valor total de libros de editorial PEARSON.\n"
			"8- SALIR.\n");
}

void MostrarMenuDeCarga()
{
	printf("\t1- Escriba 'libro.csv' para cargar los Libros.\n"
			"\t2- Escriba 'editorial.csv' para cargar las Editoriales.\n"
			"\t3- Para volver al menu ingrese cualquier digito.\n");
}

void MostrarMapeado()
{
	printf("\t1- Ver lista con descuentos.\n"
			"\t2- Volver al menu principal.\n");
}
/*****************************************************************************************/

void MensajeDeCorroboracion(int corroboracion, char mensajeOk[], char mensajeError[])
{
	if(corroboracion>=0)
	{
		printf("%s",mensajeOk);
	}else {
		printf("%s",mensajeError);
	}
}

int PedirEntero(char mensaje[])
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n'))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

int PedirEnteroFull(char mensaje[],int maximo)
{
	int numeroIngresado;
	char term;
	printf("%s",mensaje);
	while((scanf("%d%c", &numeroIngresado, &term) != 2 || term != '\n')||(numeroIngresado<1 || numeroIngresado>maximo))
	{
		printf("Digito invalido. %s",mensaje);
		fflush(stdin);
	}
	return numeroIngresado;
}

void CorreccionDeCadenas(char array[])
{
	char auxiliar[51];
	strcpy(auxiliar,array);
	strlwr(auxiliar);
	for(int i=0; i<strlen(auxiliar);i++)
	{
		auxiliar[0] = toupper(auxiliar[0]);
		break;
	}
	strcpy(array,auxiliar);
}

int ValidacionDeStrings(char array[])
{
	int rtn=0;
	for(int i=0;i<strlen(array);i++)
	{	//if((array[i]>=65 && array[i]<=90) && (array[i]>=97 && array[i]<=122) && (array[i]==46));
		if(!(array[i]>=65 && array[i]<=90) && !(array[i]>=97 && array[i]<=122))
		{
			if(array[i]!=' ' || array[i-1]==' ')
			{
				rtn=-1;
				break;
			}
		}
	}
	return rtn;
}

void GetString(char mensaje[], char stringIngresado[])
{
	int corroboracion;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	corroboracion=ValidacionDeStrings(stringIngresado);
	CorreccionDeCadenas(stringIngresado);
	while(corroboracion ==-1)
	{
		printf("Digito invalido. Ingrese letras: ");
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		corroboracion=ValidacionDeStrings(stringIngresado);
		CorreccionDeCadenas(stringIngresado);
	}
}

void PedirArchivo(char mensaje[], char stringIngresado[])
{
	int contadorError=0;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);
	CorreccionDeCadenas(stringIngresado);
	while(strcmp(stringIngresado,"Libro.csv")!=0 && strcmp(stringIngresado,"Editorial.csv")!=0 && contadorError<2)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
		CorreccionDeCadenas(stringIngresado);
		contadorError++;
	}

}

int CorroboracionDeCargado(int flagCarga)
{
	int rtn = -1;
	switch (flagCarga)
	{
	case -1:
		printf("Error en la carga.\n");
		break;
	case 1:
		printf("Archivo de Libros cargado.\n");
		break;
	case 2:
		printf("Archivo de Editoriales cargado.\n");
		rtn = 3;
		break;
	}
	return rtn;
}
