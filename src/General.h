#ifndef GENERAL_H_
#define GENERAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void MostrarMenu();
void MostrarMenuDeCarga();

void MensajeDeCorroboracion(int corroboracion, char mensajeOk[], char mensajeError[]);
int PedirEntero(char mensaje[]);
int PedirEnteroFull(char mensaje[],int maximo);
void CorreccionDeCadenas(char array[]);
int ValidacionDeStrings(char array[]);
void GetString(char mensaje[], char stringIngresado[]);
void PedirArchivo(char mensaje[], char stringIngresado[]);




#endif /* GENERAL_H_ */
