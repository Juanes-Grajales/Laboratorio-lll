#include<Archivos.h>
/*
void codificar(int semilla, string nombre, string guardar, bool met)
{
        //No funciona el tamaño

        //Metodo para codificar cadenas.
        unsigned long long tam=0;
        //Pasar string a char
        int z = nombre.length();
        char *cadena;
        cadena = new char[z];

        char *dat, *bin;
        strncpy(cadena,nombre.c_str(),sizeof(nombre));
        tam = tamano(cadena);

        //
        int j = guardar.length();
        char *g;
        g = new char[j];

        static bool f = false;
        //Excepciones de memoria
        try {

           dat = new char[tam+1];
           bin = new char [8*tam+1];

           //Apertura del archivo
           if(leer(cadena,dat,tam)){
               binario2(dat,bin,tam); //OK
               metodouno(bin,semilla,8*tam,f);//OK
               bintext(bin,dat,tam);

               strncpy(g,guardar.c_str(),sizeof(guardar));  //Forma Funcional generica
               escritura(g,tam,dat);


           }
           delete [] g;
           delete [] dat;
           delete [] bin;
           delete [] cadena;

        }  catch (...) {
           cout << "Ha ocurrido una excepcion";

        }

}

// Metodo 1
void metodouno(char *bin, int semilla, unsigned long long tam,bool f)
{
    char *bloque;
    unsigned int uno=0;
    bloque = new char[semilla+1];
    bloque[semilla]='\0';

    if(f==true){
        for(unsigned long long i=0,j=0,bloques=0; i<tam; i++,j++){
            bloque[j] = bin[i];
            if((i+1)%semilla==0 || i==tam-1){
                uno = pasos1(bloque,semilla,uno);
                j=-1;
                //Guardar dentro del binario:
                for(int j=0;j<semilla;j++){
                    if(bloque[j]!=-1) bin[semilla*bloques+j]=bloque[j];
                    bloque[j]= -1;
                }
                 bloques++;
            }

        }
    }
    else{
        for(unsigned long long i=0,j=0,bloques=0; i<tam; i++,j++){
            bloque[j] = bin[i];
            if((i+1)%semilla==0 || i==tam-1){
                uno = pasos(bloque,semilla,uno);
                j=-1;
                //Guardar dentro del binario:
                for(int j=0;j<semilla;j++){
                    if(bloque[j]!=-1) bin[semilla*bloques+j]=bloque[j];
                    bloque[j]= -1;
                }
                 bloques++;
            }

        }
    }

    delete [] bloque;

}

void bintext(char *bin, char *text, unsigned long long tam)
{
    char *bloque;
    bloque = new char [9];
    bloque[8]='\0';
    for(unsigned long long i=0,j=0,k=0;i<8*tam;i++,j++){
        bloque[j] = bin[i];
        if((i+1)%8==0){
                text[k]=bloque2char(bloque);
                k++;
                j=-1;
        }
    }
    delete [] bloque;
}

char bloque2char(char *bloque)
{
 int k = 128,l=0;
 for(int i=0;i<=7;i++,k/=2){
     l+=bloque[i]+k;
 }
 return char(l);
}




//Reglas de codificacion
unsigned int pasos(char *bloque, int semilla, unsigned int cantidad)
{
    static bool band = true;
    unsigned int uno = 0;

    if (band ||semilla-cantidad==cantidad){
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if(bloque[i]!=-1){
                bloque[i]=1-bloque[i]; //Ecuacion para invertir bits.
            }
           }
        band = false;

    }
    else if(semilla-cantidad>cantidad){
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if((i%2)==1 && bloque[i]!=-1) bloque[i]=1-bloque[i];
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

//Reglas de decodifcacion
unsigned int pasos1(char *bloque, int semilla, unsigned int cantidad)
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

//Convertir a binario
void binario2(char *txt, char *bin, unsigned long long tam)
{

  for(unsigned long long i=0; i<tam; i++){
      for(int k=0; k<=7; k++) bin[i*8+k] = ((txt[i]<<k)&128)/128;

        }
  bin[8*tam]='\0';

}


//Escritura en el archivo en binario (Solo funciona para texto Natural).
void escritura(char *name, unsigned long long tam, char *bin)
{
   fstream text;
   text.open(name, fstream::out | fstream::binary);
   text.write(bin,tam);
   text.close();
}


bool leer(char *name, char *dato, unsigned long long tam){

    //Lectura binaria

    fstream text(name, fstream::in | fstream::binary);
    bool confirm = text.is_open();
        if(confirm){
            for(unsigned long long int j=0; j<tam; j++) dato[j]=text.get();
            dato[tam] = '\0';
    }
        else cout << "El archivo no fue leido correctamente ";

  return confirm;
}

//ok.
unsigned long long int tamano(char *name)
{
    unsigned long long int tam=0;
    fstream text(name, fstream::in | fstream::ate | fstream:: binary);
    if (text.is_open()) {
        tam = text.tellg();

    }
    text.close();
    return tam;
}


void decodificar(int semi, char *name, char *save)
{
    char *datos, *bin;
    unsigned long long tam;
    static bool f = true;
    tam = tamano(name);
    //Excepciones de memoria
    try {

       datos = new char[tam+1]; //Datos no funciona
       bin = new char [8*tam+1];

       //Apertura del archivo
       if(leer(name,datos,tam)){
           binario2(datos,bin,tam); //OK
           metodouno(bin,semi,tam,f);
           bintext(bin,datos,tam);
           escritura(save,tam,datos);

       }
    }
    catch(...){
        cout << "Ha ocurido una excepcion";
    }
    delete [] datos;
    delete [] bin;
}

*/
