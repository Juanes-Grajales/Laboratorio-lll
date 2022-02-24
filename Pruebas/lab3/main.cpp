#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

bool lectura(string contrasena);
int main()
{
    int opcion=1;
    int modo=1;
    ofstream usuarios;
    string cedula,clave,saldo;
    string contrasena;
    while (opcion!=0)
    {
    cout<<"Bienvenido"<<endl<<"seleccione una opcion"<<endl;
    cout<<"0. Salir"<<endl;
    cout<<"1. ingresar como administrador"<<endl;
    cout<<"2. ingresar como usuario"<<endl;

    cin>>opcion;
    switch (opcion)
    {
       case 1:
    {
        cout<<"ingrese su clave de administrador"<<endl;
        cin>>contrasena;

        if(lectura(contrasena)==true)
        {
            while (modo!=0)
            {
                cout<<"seleccione una opcion"<<endl;
                cout<<"0. Salir"<<endl;
                cout<<"1. Registrar usuarios"<<endl;
                cout<<"2. Consultar saldo"<<endl;
                cout<<"3. Retirar dinero"<<endl;
                cin>>modo;

                switch (modo)
                {
                    case 1:
                    {
                        usuarios.open("usuarios.txt",ios::app);//abrir el archivo
                        if(usuarios.fail())
                        {
                            cout<<"No se pudo abrir el archivo"<<endl;
                            exit(1);
                        }

                        cout<<"";
                        getline(cin,cedula);
                        usuarios<<""<<cedula<<endl;

                        cout<<"Digite la cedula del usuario: ";
                        getline(cin,cedula);
                        usuarios<<"CC: "<<cedula<<endl;

                        cout<<"Digite la clave del usuario: ";
                        getline(cin,clave);
                        usuarios<<"Clave: "<<clave<<endl;

                        cout<<"Digite el saldo del usuario: ";
                        getline(cin,saldo);
                        usuarios<<"Saldo: "<<saldo<<" COP"<<endl;


                        usuarios.close();
                    }
                    break;
                }
            }
        }




    }
        break;

    case 2:
        {

        }
        break;

    default:
        if(opcion !=0)
                        {
                        cout<<"opcion invalida"<<endl;
                        }

                return 0;
    }
    }
}


bool lectura(string contrasena)
{
    fstream archivo;
    string texto;

    archivo.open("clave.txt", fstream::in); //abrimos en modo lectura
    if(archivo.is_open())
    {
        cout<<"Abierto correctamente"<<endl;
        getline(archivo,texto);
        archivo.close();
    }
    else
    {
        cout<<"el archivo no pudo ser abierto"<<endl;
    }

    if(contrasena.compare(texto)==0)
    {
        cout<<"clave valida"<<endl;
        return true;
    }

    else
    {
        cout<<"clave invalida"<<endl;
        return false;
    }

}
