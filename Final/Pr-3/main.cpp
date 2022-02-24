#include <Met2_Archivos.h>
#include <Met1_Archivos.h>
#include <app.h>

//Revisar modos de escritura metodo 2- OK
int main()
{

    short int op,semi,metodo,met;

    bool acess; //acceso

    string nombre,guardar;
    char name [15], save [15];
    string user, clave;

    cout << "1. Codificar  un archivo: " <<endl;
    cout << "2. Decodificar un archivo: " << endl;
    cout << "3. Aplicacion: " << endl;
    cin >> op;

    switch (op) {

    case 1:
        //Codificacion

        cout << "Elija el metodo a codificar: ";
        cin >> met;

        if(met==1){

            cout << "Digite el nombre del archivo (con extension): ";
            cin >> name;
            cout << "Digite el nombre del archivo a guardar(sin extension): ";
            cin >> save;
            cout << "Ingrese que semilla desea usar para la codificacion:";
            cin >> semi;

            codificar(semi,name,save);
        }
        else{

            cout << "Digite el nombre de su archivo(sin extension): ";
            cin >> nombre;
            nombre+=".txt";
            cout << "Digite el nombre del archivo a guardar(sin extension): ";
            cin >> guardar;
            guardar+=".dat";
            cout << "Ingrese que semilla desea usar para la codificacion:";
            cin >> semi;

            codificacion(semi,nombre,guardar);


        }
       break;
    case 2:
        //Decodificacion


        cout << "Eliga el metodo de decodificacion del archivo: ";
        cin >> metodo;

        if(metodo==1){

            cout << "Digite el nombre del archivo (con extension): ";
            cin >> name;
            cout << "Digite el nombre del archivo a guardar(con extension): ";
            cin >> save;
            cout << "Ingrese que semilla desea usar para la codificacion:";
            cin >> semi;

            decodificar(semi,name,save);
        }
        else{

            cout << "Digite el nombre de su archivo(sin extension): ";
            cin >> nombre;
                nombre+=".dat";
            cout << "Digite el nombre del archivo a guardar(sin extension): ";
            cin >> guardar;
                guardar+=".txt";
            cout << "Ingrese que semilla desea usar para la codificacion:";
            cin >> semi;

             decodificacion(semi,nombre,guardar);

        }

        break;
    case 3:
        //Aplicacion

        cout << "1.Ingresar como administrador"<<endl;
        cout << "2.Ingresar como usuario "<<endl;
        cin >> op;

        if(op==1){

            //Admin
            cout << "Digite el id: ";
            cin >> user;
            cout << "Digite la clave de acceso: ";
            cin >> clave;

            acess = true;

            if(acceso(user, clave, acess)){
                cout << "Ha ingresado como Administrador"<< endl;
                ingreso();

            }
            else{
                cout << "Clave incorrecta";
            }

        }

        //Usuarios
        else if(op==2){

            cout << "Digite el id: ";
            cin >> user;
            cout << "Digite la clave de acceso: ";
            cin >> clave;
            acess = false;

            if(acceso(user,clave,acess)){
                cout << "Ha ingresado correctamente"<<endl;
                user_op(user);
            }
            else{
                cout << "Clave incorrecta"<<endl;
            }

        }
        else cout << "La transaccion ha sido cancelada...";
        break;

    }


    return 0;
}
