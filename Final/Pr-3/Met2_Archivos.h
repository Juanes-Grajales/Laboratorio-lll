#ifndef MET2_ARCHIVOS_H
#define MET2_ARCHIVOS_H
#include <Met1_Archivos.h>

//Metodo dos -Archivos

void crear_txt(string name);
void escribir(string texto, string nombre, bool modo);
string leer(string nombre, bool modo);


//Codificacion

bool codificacion(int semilla, string nombre, string snombre);
string texto_bin(string texto);
string int_bin(char letra);
string reglas_codificacion(string binario, int semilla, bool f);
string metodo2(string bloque);
string bin_texto(string binario);
char convert_letra (string bloque);

//Decodificacion

bool decodificacion(int semilla, string nombre, string svnombre);
string metodo2_deco(string bloque);

//Proceso--- Leer en modo binario, convertir texto a binaro, aplicar reglas de decodificacion (Rotacion izq), convertir a texto y escribir.
#endif // MET2_ARCHIVOS_H
