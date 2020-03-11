#include <iostream>
using namespace std;

int main(){
    int n;
    //int k;
    double aux=0;
    int menu=1;

    do{
    cout<<"\nIngrese el numero de ecuaciones: ";
    cin>>n;
    cout<<"Ingrese la matriz "<<n<<"x"<<n<<endl;
    double x[n+1]={0};
    double matriz[n][n+1]={0};
    double var[n]={0};

    //LEER MATRIZ------------------------------------------------------------------------------------------
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            if(j<n){
                cout<< "Ingrese x"<<j+1<<" de la ecuacion "<<i+1<<": ";
            }else{
                cout<< "Ingrse el lado derecho de la ecuacion"<<i+1<< ": ";
            }
            cin>>matriz[i][j];
        }
    }


    //ORDENAR----------------------------------------------------------------------------------------
    
    for(int i=0;i<n;i++){
        if(matriz[i][i]==0){
            for(int j=0;j<n;j++){
                x[j]=matriz[i][j];
            }
            if(i+1<n){
                for(int j=0;j<n;j++){
                    matriz[i][j]=matriz[i+1][j];
                    matriz[i+1][j]=x[j];
                }
            }else{
                for(int j=0;j<n;j++){
                    matriz[i][j]=matriz[i-1][j];
                    matriz[i-1][j]=x[j];
                }
            }
        }
    }

    cout<<"\nLa Matriz se resolvera con la siguiente forma\n";
    
    //IMPRIME MATRICES--------------------------------------------------------------------------------------------
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n+1;j++){
            if(j==n){
                cout<<"| ";
            }
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //RESOLUCION---------------------------------------------------------------------------------------------------
    
    for(int i=0;i<n;i++){
        aux=matriz[i][i];
        for(int j=0;j<n+1;j++){
            matriz[i][j]=matriz[i][j]/aux;
        }
        for(int j=0;j<n;j++){
            if(j!=i){
                aux=matriz[j][i];
                for(int k=0;k<2*n;k++){
                    matriz[j][k]=matriz[j][k]-matriz[i][k]*aux;
                }
            }
        }
    }
    
    //IMPRIME-------------------------------------------------------------------------------------------
    
    cout<<"\nLa matriz es:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n+1;j++){
                if(j==n){
                    cout<<"|\t";
                }
                if(i==j){
                    cout<<1<<"\t";
                }else{
                    if(j==n){
                        cout<<matriz[i][j]<<"\t";
                    }else{
                        cout<<0<<"\t";
                    }
                }
            }
            cout<<endl;
        }


/*
        for(int i=0; i<n;i++){
            fflush(stdin);
            cout<<"X"<<i+1<<"="<<matriz[n][i];
        }
    */
    cout<<"\nDesea ingresar otra matriz(1.-SI/2.-NO): ";
    cin>>menu;
    system("cls");
    }while(menu==1);
   
    system("pause");
}
