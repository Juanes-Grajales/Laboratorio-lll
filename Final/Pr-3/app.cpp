#include<Met2_Archivos.h>
#include<app.h>


// Ordenar los includes
string txt;

bool acceso(string user, string clave, bool acess)
{
    bool result = false;
    string texto, binario, limitador = ",";


    try {
        texto = leer(type(acess),false);
        binario = texto_bin(texto);
        binario = reglas_codificacion(binario,4,false);
        texto = bin_texto(binario);
        txt=texto;
        result = verificar(texto,user,clave,acess);

    }  catch (...){
        cout << "Ha ocurrido una excepcion";
    }

   return result;
}

bool verificar(string texto, string user, string pass, bool f)
{
    string limit;
    char limitador[] = ",.\n";
    char *c, *cadena;
    int pos=0;
    bool result = false;
    // Version 1.3- Administrador
    if(f){
        limit = texto.substr(0, texto.find(','));
        if(user==limit){
            texto.erase(0, texto.find(',')+1);
            limit = texto.substr(0, texto.find(','));
            if(pass==limit)result = true;

        }
    }
    //Usuarios
    else{


         c = &texto[0]; // Convertimos el string
         cadena = strtok(c,limitador);
         if(cadena !=NULL){
             while (cadena !=NULL){
                 if(cadena==user){
                    pos++;
                  }
                 else if (cadena==pass)pos++;
                 if(pos==2){
                     result =  true;
                     break;
                 }
                 cadena = strtok(NULL, limitador);
             }
         }
    }

    return result;
}

void ingreso()
{

    string id,pass,money,data,texto;

        cout << "Digite el id de usuario: ";
        cin >>id;
        cout << "Digite la clave: ";
        cin >> pass;
        cout << "Digite el saldo: ";
        cin >> money;


        //Version 1.2

        id+=",";
        id.append(pass+",");
        data = id.append(money+".");

        data.insert(0,1,'\n');

        //Codificar
        texto = texto_bin(data);
        texto = reglas_codificacion(texto,4,true);
        string binario = bin_texto(texto);

        escribir(binario,"prueba.dat",false);
        cout << "Usuario registrado."<<endl;
}


void user_op(string user){

    unsigned int op, rest=0, saldo;

    cout << "1.Consultar saldo"<<endl;
    cout << "2.Retirar dinero"<<endl;
    cin >> op;

    if(op==1){
        rest = 1000;
        saldo = consult_sa(user,txt,rest);

        if(saldo==0){
          cout <<"No tienes fondos."<<endl;
        }
        else if(saldo!=0){
            cout <<"Se han descontado 1000$"<<endl;
            cout <<"Saldo total: "<<saldo<<"$"<<endl;
        }

    }
    else if (op==2){

        cout << "Cantidad a retirar: "<<endl;
        cin >> rest;

        saldo = consult_sa(user,txt,rest);

        if(saldo==0){
          cout <<"No tienes fondos."<<endl;
        }
        else if(saldo!=0){
            cout <<"Saldo total: "<<saldo<<"$"<<endl;
        }

    }

}

unsigned int consult_sa(string user, string texto, unsigned int rest){


        string limit, copy, sec;
        unsigned int saldo=0,x=0;


        limit = texto.substr(texto.find(user),texto.find("."));
        copy = limit;
        //Version 1.2

        int r = copy.find(",")+1;
        copy.erase(0,copy.find(",",r)+1);

        //Actualizar y guardar saldo
        saldo = stoi(copy);
        if(saldo==0 || saldo<rest){
            x = 0;
        }
        else if(saldo>=rest){
            x = saldo - rest;
            finish(user,limit,txt,x);

        }

    return x;
}


//Actualizacion de datos.
void finish(string user, string limit, string texto, int saldo){

    string scopy;
    scopy = to_string(saldo);
    try {
        //Actualizacion del usuario segun el saldo.

        int r = limit.find(",")+1;
        limit.replace(limit.find(",",r)+1,limit.find("."),scopy);
        limit.append(".");

        //Actualizar los datos del texto
        texto.erase(texto.find(user),limit.length()+1);
        limit.insert(0,1,'\n');
        texto.append(limit);

        //Codificar la informacion del usuario.
        texto = texto_bin(texto);
        texto = reglas_codificacion(texto,4,true);
        string binario = bin_texto(texto);

        escribir_info(binario,"prueba.dat");

    }  catch (...) {
       cout << "La transaccion ha sido cancelada.";
    }

}

void escribir_info(string texto, string nombre){

    fstream text(nombre, fstream::out | fstream::binary);
    text << texto;
    text.close();


}

//Switch
string type(bool acess)
{
   string name;
   if(acess){
       //adminstrador
        name= "sudo.dat";
   }
   else{
       //usuarios
       name= "prueba.dat";
   }
   return name;
}
