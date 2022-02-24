#ifndef APP_H
#define APP_H
#include <Met1_Archivos.h>

bool acceso(string user, string clave, bool acess);
bool verificar(string texto, string user, string pass, bool f);
void ingreso(); // ingreso de usuarios
string type(bool acess); //Switch de archivos
void user_op(string user); // Operaciones de usuarios
unsigned int consult_sa(string user, string texto, unsigned int rest); // Consulta de saldo
void finish(string user, string limit, string texto, int saldo);
void escribir_info(string texto, string nombre);


#endif // APP_H


/* Version 1.1

        texto = leer("sudo.dat",false);
        binario = texto_bin(texto);
        binario = reglas_codificacion(binario,4,false);
        texto = bin_texto(binario);


        string limit = texto.substr(0, texto.find(limitador));
        while(user==limit){
            texto.erase(0, texto.find(limitador)+1);
            limit = texto.substr(0, texto.find(limitador));
           if(clave==limit){
               result = true;
               limit.clear();
           }
           break;
        }
        else{
            result = false;
        }



        1.2

        Tomar todo el texto completo, string texto;
        Tomar el texto decodificado, string limit;
        Utilizar funcion de compare de strings añadiendo la funcion erase para quitar los ultimos valores

       //


       char* char_arr;
       string cadena = "23213,andres,12000.100023,sandra,20000.",r="202312",k="sandra";;
       char_arr = &cadena[0];
       int h=0;
       char delimitador[] = ",.";
       char *token = strtok(char_arr, delimitador);
       if(token != NULL){
           while(token != NULL){
               // Sólo en la primera pasamos la cadena; en las siguientes pasamos NULL
               printf("Token: %s\n", token);
               if(token==r) h++;
               else if (token==k)h++;
               token = strtok(NULL, delimitador);
           }
           if(h==2) return false;
       }


tengo hambre

*/
