#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    char texto[]="01000001";
    short binario[8];
    int semilla=0;
    int metodo=0;
    int aux=0;
    int x=0;
    int iteraciones=0;
    int auxchar[50];
    int codificado[50];
    int bloques=0;
    int pos=0;
    int ceros=0;
    int unos=0;
    int modo=0;
    int posaux=0;

    ifstream archivo;
    string texto1;
    archivo.open("codigo.txt", ios::in); //abrimos en modo lectura
    if(archivo.is_open())
    {
        cout<<"Abierto correctamente"<<endl;
        while(!archivo.eof())
        {
            getline(archivo,texto1);
            cout<<texto1<<endl;
        }
        archivo.close();
    }
    else
    {
        cout<<"el archivo no pudo ser abierto"<<endl;
    }



    cout<<"ingrese el modo deseado"<<endl;
    cout<<"1)codificacion"<<endl;
    cout<<"2)Decodificacion"<<endl;
    cin>>modo;

    if(modo==1)
    {

        cout<<"ingrese en metodo deseado"<<endl;
        cin>>metodo;
        cout<<"ingrese en la semilla"<<endl;
        cin>>semilla;
        if(metodo==1)
        {            
            for(int k=0;k>=0;k++)
            {
                aux=texto[k];
                if(aux>31 and aux<127)
                {
                    for(int i=0;i<8;i++)
                    {
                        binario[i]= aux %2;
                        aux /= 2;
                    }

                    for(int i=7;i>=0;i--)
                    {
                        cout<<binario[i];
                        x=binario[i];
                        auxchar[iteraciones]=x;
                        iteraciones=iteraciones+1;

                    }

                }

                else
                {
                    k=-2;
                }

            }

            cout<<endl;

            bloques=iteraciones/semilla;

            if(iteraciones%semilla!=0)
            {
                bloques=bloques+1;
            }

            for(int k=0;k<bloques;k++)
            {
                if(k==0)
                {
                    for(int j=0;j<semilla;j++)
                    {
                        if(auxchar[j]==0)
                        {
                            codificado[j]=1;
                        }

                        else
                        {
                            codificado[j]=0;
                        }
                    }
                }
                else
                {
                    pos=(semilla*k)-semilla;
                    for(int i=0;i<semilla;i++)
                    {
                        if(auxchar[pos]==0)
                        {
                            ceros=ceros+1;
                        }
                        else
                        {
                            unos=unos+1;
                        }
                        pos=pos+1;
                    }

                    pos=semilla*k;
                    if(unos==ceros)
                    {
                        for(int j=0;j<semilla;j++)
                        {
                            if(auxchar[pos]==0)
                            {
                                codificado[pos]=1;
                            }

                            else
                            {
                                codificado[pos]=0;
                            }
                            pos=pos+1;
                        }
                    }
                    else if(ceros>unos)
                    {
                        for(int j=1;j<=semilla;j++)
                        {
                            if(j%2==0)
                            {
                                if(auxchar[pos]==0)
                                {
                                    codificado[pos]=1;
                                }

                                else
                                {
                                    codificado[pos]=0;
                                }
                            }
                            else
                            {
                                codificado[pos]=auxchar[pos];
                            }
                            pos=pos+1;
                        }
                    }
                    else if(unos>ceros)
                    {
                        for(int j=1;j<=semilla;j++)
                        {
                            if(j%3==0)
                            {
                                if(auxchar[pos]==0)
                                {
                                    codificado[pos]=1;
                                }

                                else
                                {
                                    codificado[pos]=0;
                                }
                            }
                            else
                            {
                                codificado[pos]=auxchar[pos];
                            }
                            pos=pos+1;
                        }
                    }
                    ceros=0;
                    unos=0;
                }

            }
        for(int i=0;i<iteraciones;i++)
        {
            cout<<codificado[i];
        }
        cout<<endl;

        }

        else if(metodo==2)
        {


            for(int k=0;k>=0;k++)
            {
                aux=texto[k];
                if(aux>31 and aux<127)
                {
                    for(int i=0;i<8;i++)
                    {
                        binario[i]= aux %2;
                        aux /= 2;
                    }

                    for(int i=7;i>=0;i--)
                    {
                        cout<<binario[i];
                        x=binario[i];
                        auxchar[iteraciones]=x;
                        iteraciones=iteraciones+1;

                    }

                }

                else
                {
                    k=-2;
                }

            }
            cout<<endl;

            bloques=iteraciones/semilla;

            if(iteraciones%semilla!=0)
            {
                bloques=bloques+1;
            }

            for(int k=0;k<bloques;k++)
            {
                if(iteraciones%semilla!=0)
                {
                    if(k<bloques-1)
                    {
                        pos=(semilla*k)+(semilla-1);

                        for(int i=0;i<semilla;i++)
                        {
                            if(i==0)
                            {
                                codificado[posaux]=auxchar[pos];
                            }
                            else
                            {
                                codificado[posaux]=auxchar[posaux-1];
                            }
                            pos=pos-1;
                            posaux=posaux+1;
                        }
                     }

                      else
                        {
                            int cifras=iteraciones%semilla;
                            pos=iteraciones-cifras;
                            for(int i=1;i<cifras;i++)
                            {
                                if(i==1)
                                {
                                    codificado[posaux]=auxchar[pos];
                                }
                                else
                                {
                                    codificado[posaux]=auxchar[posaux-1];
                                }
                                pos=pos-1;
                                posaux=posaux+1;
                            }
                        }
                  }

                else
                {
                    if(k<bloques)
                    {
                        pos=(semilla*k)+(semilla-1);

                        for(int i=0;i<semilla;i++)
                        {
                            if(i==0)
                            {
                                codificado[posaux]=auxchar[pos];
                            }
                            else
                            {
                                codificado[posaux]=auxchar[posaux-1];
                            }
                            pos=pos-1;
                            posaux=posaux+1;
                        }
                     }
                }
            }
            for(int i=0;i<iteraciones;i++)
            {
                cout<<codificado[i];
            }
            cout<<endl;

        }

    }

    else if(modo==2)
    {
        cout<<"ingrese en metodo deseado"<<endl;
        cin>>metodo;
        cout<<"ingrese la semilla"<<endl;
        cin>>semilla;

        if (metodo==1)
        {
            for(int k=0;k>=0;k++)
            {
                aux=texto[k];

                if(aux==48 or aux==49 or aux==32)
                {
                        iteraciones=iteraciones+1;
                        auxchar[k]=aux;
                }

                else
                {
                    k=-2;
                }
            }
            bloques=iteraciones/semilla;

            if(iteraciones%semilla!=0)
                {
                    bloques=bloques+1;
                }

            for(int k=0;k<bloques;k++)
            {
                if(k==0)
                {
                    for(int j=0;j<semilla;j++)
                    {
                        if(texto[j]==0)
                        {
                            codificado[j]=1;
                        }

                        else
                        {
                            codificado[j]=0;
                        }
                    }
                }

                else
                {
                    pos=(semilla*k)-semilla;
                    for(int i=0;i<semilla;i++)
                    {
                        if(codificado[pos]==0)
                        {
                            ceros=ceros+1;
                        }
                        else
                        {
                            unos=unos+1;
                        }
                        pos=pos+1;
                    }

                    pos=semilla*k;
                    if(unos==ceros)
                    {
                        for(int j=0;j<semilla;j++)
                        {
                            if(texto[pos]==0)
                            {
                                codificado[pos]=1;
                            }

                            else
                            {
                                codificado[pos]=0;
                            }
                            pos=pos+1;
                        }
                    }
                    else if(ceros>unos)
                    {
                        for(int j=1;j<=semilla;j++)
                        {
                            if(j%2==0)
                            {
                                if(texto[pos]==0)
                                {
                                    codificado[pos]=1;
                                }

                                else
                                {
                                    codificado[pos]=0;
                                }
                            }
                            else
                            {
                                codificado[pos]=texto[pos];
                            }
                            pos=pos+1;
                        }
                    }
                    else if(unos>ceros)
                    {
                        for(int j=1;j<=semilla;j++)
                        {
                            if(j%3==0)
                            {
                                if(texto[pos]==0)
                                {
                                    codificado[pos]=1;
                                }

                                else
                                {
                                    codificado[pos]=0;
                                }
                            }
                            else
                            {
                                codificado[pos]=texto[pos];
                            }
                            pos=pos+1;
                        }
                    }
                    ceros=0;
                    unos=0;
                }

            }

            for(int i=0;i<iteraciones;i++)
            {
                cout<<texto[i];
            }
            cout<<endl;
            for(int i=0;i<iteraciones;i++)
            {
                cout<<codificado[i];
            }
            cout<<endl;
        }

    }
}


