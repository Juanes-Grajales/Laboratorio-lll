#include<Met2_Archivos.h>

bool codificacion(int semilla, string nombre, string guardar){

    bool result = true;
    string texto, binario;
    try {

        texto = leer(nombre,true); // Extraer el contenido del archivo
        binario = texto_bin(texto);
        binario = reglas_codificacion(binario, semilla, true);
        texto = bin_texto(binario);
        escribir(texto,guardar,false);

    }  catch (...) {
       result = false;
    }

    return result;
}

string texto_bin(string texto){

    string binario,aux;

    //recorre el texto letra por letra
    for(unsigned long long i=0;i<texto.length();i++){
        aux = int_bin(int(texto[i]));
        binario.append(aux);
    }
    return binario;
}

string int_bin(char letra){

    string binario;
    //0b10000000
    for(int i=0;i<8;i++) binario.push_back(((letra<<i)&128)/128);
    return binario;

}

string reglas_codificacion(string binario, int semilla, bool f){

    string bloque, datos;


    if(f){
        //Recorre todo el binario
        //Codificacion es rotacion a la derecha
    for(unsigned long long i=0;i<binario.length();i++){
        bloque.push_back(binario[i]);
            //Verificar que el bloque este correctamente dividido
            if((i+1)%semilla==0 || i==binario.length()-1){
                bloque = metodo2(bloque);
                datos.append(bloque);
                bloque.clear();
            }
    }
}
    //Decodificacion
    else{
        for(unsigned long long i=0;i<binario.length();i++){
            bloque.push_back(binario[i]);
            if((i+1)%semilla==0 || i==binario.length()-1){
                    bloque = metodo2_deco(bloque);
                    datos.append(bloque);
                    bloque.clear();
                }
        }

    }

    return datos;
}

string metodo2(string bloque){

    string datos;
    //
    datos.push_back(bloque[bloque.length()-1]);
    for(unsigned long long i=0;i<bloque.length()-1;i++){
        datos.push_back(bloque[i]);
    }
    return datos;
}

string metodo2_deco(string bloque){

        string datos;
        for(unsigned long long i=0;i<bloque.length()-1;i++){
           datos.push_back(bloque[i+1]);

        }
        datos.push_back(bloque[0]);

    return datos;
}

string bin_texto(string binario){

    string datos,bloque;

    for(unsigned long long i=0; i<binario.length();i++){
        bloque.push_back(binario[i]);
            if((i+1)%8==0){
                datos.push_back(convert_letra(bloque));
                bloque.clear();
            }
    }
    return datos;
}

char convert_letra(string bloque){
    char l=0;
    for(unsigned long long i=0, k=128 ;i<bloque.length();i++,k/=2){
        l+= k*bloque[i];
    }
    return l;
}

bool decodificacion (int semilla, string nombre, string svnombre){

    string bin, texto;
    bool result = true;
    try {
        texto = leer(nombre,false);
        bin = texto_bin(texto);
        bin = reglas_codificacion(bin, semilla, false);
        texto = bin_texto(bin);
        escribir(texto,svnombre,true);

    }  catch (...) {
        result = false;

    }
    return result;
}

