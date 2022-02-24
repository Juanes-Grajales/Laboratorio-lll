#include <Met1_Archivos.h>

//Manejo de archivos
void crear_txt(char *name){

    fstream text(name, fstream::out);
    text.close();
}


void escribir(char *name, char *datos, unsigned long long tam, bool f){

    fstream text;

    if(f){
        text.open(name, fstream::out );
        text << datos;
    }
    else{
        text.open(name, fstream::out | fstream::binary);
        text.write(datos,tam);

    }
    text.close();
}


bool leer(char *name, char *datos, unsigned long long tam){

        fstream text(name, fstream::in | fstream:: binary);
        bool confirm = text.is_open();
              if(confirm){
                  for(unsigned long long j=0; j<tam; j++) datos[j] = text.get();
                  datos[tam]='\0';
              }

              else{
                  cout << "No se ha podido abrir el archivo.";
              }

    return confirm;
}

unsigned long long tamano(char *name){

    unsigned long long int tam=0;
    fstream text(name, fstream::in | fstream::ate | fstream:: binary);
    if (text.is_open()) {
        tam = text.tellg();

    }
    text.close();
    return tam;
}
