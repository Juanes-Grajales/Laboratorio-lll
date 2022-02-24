#include <Met2_Archivos.h>

//Manejo de archivos

void crear_txt(string name){
    fstream text(name, fstream::out);
    text.close();
}

void escribir(string texto, string nombre, bool modo)
{
    if(modo){
        fstream text(nombre, fstream::out);
        text << texto;
        text.close();

    }
    else{
        fstream text(nombre, fstream::out | fstream::binary | fstream::app);
        text << texto;
        text.close();

    }
}


string leer(string nombre, bool modo)
{
    string datos;
    fstream text;
    unsigned long long tam;

    // True- Convencional
    if(modo){
        text.open(nombre, fstream::in);
        if(text.is_open()){
            while(!text.eof()) datos.push_back(text.get());
            datos.pop_back();

        }
        else cout << "El archivo no pudo ser abierto" << endl;

    }
    else{
        // fstream::ate posiciona el curso al final del archivo
        text.open(nombre, fstream::in | fstream::binary | fstream::ate);
        if(text.is_open()){
            tam = text.tellg();     //obtenemos la cantidad de carac
            text.seekg(0);          //posiciona el curso al inicio de las cadenas
            for(unsigned long long i=0; i<tam; i++) datos.push_back(text.get());

        }
        else cout <<"El archivo no pudo ser abierto" << endl;

    }
    text.close();
    return datos;
}

