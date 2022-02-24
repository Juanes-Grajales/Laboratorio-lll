#ifndef MET1_ARCHIVOS_H
#define MET1_ARCHIVOS_H
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


//Metodo uno -Archivos

void crear_txt(char *name);
bool leer(char *name, char *datos, unsigned long long tam);
void escribir(char *name, char *datos, unsigned long long int tam, bool f);
unsigned long long tamano(char *name);


//Codificacion

void codificar(int semilla, char *name, char *guardar);
void texto_bin(char *text, char *bin, unsigned long long tam);
void metodo1(char *bin, int semilla, unsigned long long tam, bool f);
unsigned int reglas(char *bloque, int semilla, unsigned int cantidad);
void bin_texto(char *bin, char *texto, unsigned long long tam);
char bloque_char(char *bloque);

//Decodificar

void decodificar(int semilla,char *name, char *guardar);
unsigned int reglas1(char *bloque, int semilla, unsigned int cantidad);
#endif // MET1_ARCHIVOS_H
