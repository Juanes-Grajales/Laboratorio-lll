#include "Met1_Archivos.h"

void codificar(int semilla, char *name, char *guardar){

    bool result = true;
    unsigned long long tam = 0;
    tam = tamano(name);

    char *data, *binario;

    try {

        // Memoria dinamica
        data = new char [tam+1];
        binario = new char [8*tam+1];


        if(leer(name,data,tam)){
           texto_bin(data,binario,tam);
           metodo1(binario,semilla,8*tam,true);

           bin_texto(binario,data,tam);
           escribir(guardar,data,tam,false);
        }
        delete [] binario;
        delete [] data;



    }  catch (...) {
       result = false;

    }

}

void texto_bin(char *text, char *bin, unsigned long long tam){

    for(unsigned long long i=0;i<tam;i++){
        for(int j=0;j<=7;j++) bin[i*8+j]= ((text[i]<<j)&128)/128;
    }
    bin[8*tam]='\0';
}


void metodo1(char *bin, int semilla, unsigned long long tam, bool f){

    char *bloque;
    unsigned int uno=0;

    bloque = new char [semilla+1];
    bloque[semilla]='\0';


    //True Codificar

    if(f){
        for(unsigned long long i=0,j=0,bloques=0;i<tam;i++,j++){
            bloque[j] = bin[i];
            if((i+1)%semilla==0 || i==tam-1){
                uno = reglas(bloque,semilla,uno);
                j=-1;
                for(int d=0;d<semilla;d++){
                    if(bloque[d]!=-1) bin[semilla*bloques+d]=bloque[d];
                    bloque[d] = -1;

                }
                bloques++;
            }
        }
    }
    else{
        for(unsigned long long i=0,j=0,bloques=0;i<tam;i++,j++){
            bloque[j] = bin[i];
            if((i+1)%semilla==0 || i==tam-1){
                uno = reglas1(bloque,semilla,uno);
                j=-1;
                for(int d=0;d<semilla;d++){
                    if(bloque[d]!=-1) bin[semilla*bloques+d]=bloque[d];
                    bloque[d] = -1;

                }
                bloques++;
            }
        }
    }
    delete [] bloque;
}

//Codificar
unsigned int reglas(char *bloque, int semilla, unsigned int cantidad){

    static bool band = true;
    unsigned int uno=0;

    if (band || semilla-cantidad==cantidad){
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if(bloque[i]!=-1) bloque[i]=1-bloque[i]; //Ecuacion para invertir bits.

           }
        band = false;
    }
    else if(semilla-cantidad>cantidad){
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if(i%2==1 && bloque[i]!=-1) bloque[i]=1-bloque[i];
            }
    }
    else{
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if((i+1)%3==0 && bloque[i]!=-1) bloque[i]=1-bloque[i];
            }
    }
    return uno;
}


//Decodificar
unsigned int reglas1(char *bloque, int semilla, unsigned int cantidad)
{
    static bool band = true;
    unsigned int uno = 0;


    if (band ||semilla-cantidad==cantidad){
        for(int i=0;i<semilla;i++){
            if(bloque[i]!=-1){
                bloque[i]=1-bloque[i]; //Ecuacion para invertir bits.-- Modificación del binario

            }
            uno+=bloque[i];
           }
        band = false;

    }
    else if(semilla-cantidad>cantidad){
        for(int i=0;i<semilla;i++){
            if((i%2)==1 && bloque[i]!=-1) bloque[i]=1-bloque[i];
            uno+=bloque[i];
            }

    }
    else{
        for(int i=0;i<semilla;i++){
            if((i+1)%3==0 && bloque[i]!=-1) bloque[i]=1-bloque[i];
            uno+=bloque[i];
            }
    }
    return uno;
}


void bin_texto(char *bin, char *texto, unsigned long long tam){

    char *bloque;
    bloque = new char [9];
    bloque[8] = '\0';

    for(unsigned long long i=0,j=0,k=0;i<8*tam;i++,j++){
        bloque[j] = bin[i];
        if((i+1)%8==0){
                texto[k]=bloque_char(bloque);
                k++;
                j=-1;
        }
    }
    delete [] bloque;

}

char bloque_char(char *bloque)
{
    int k = 128,l=0;
    for(int i=0;i<=7;i++,k/=2) l+=bloque[i]*k;
    return char(l);
}

void decodificar(int semilla, char *name, char *guardar)
{
    bool result = true;
    unsigned long long tam = 0;
    tam = tamano(name);

    char *data, *binario;

    try {

        // Memoria dinamica
        data = new char [tam+1];
        binario = new char [8*tam+1];


        if(leer(name,data,tam)){
           texto_bin(data,binario,tam);
           metodo1(binario,semilla,8*tam,false);
           bin_texto(binario,data,tam);
           escribir(guardar,data,tam,true);
        }
        delete [] binario;
        delete [] data;



    }  catch (...) {
       result = false;

    }

}
