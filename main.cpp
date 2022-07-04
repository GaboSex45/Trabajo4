//LINK DEL VIDEO
//LINK DEL VIDEO
//        https://youtu.be/hQKQik-TMdg
//        https://youtu.be/hQKQik-TMdg
//        https://youtu.be/hQKQik-TMdg
//        https://youtu.be/hQKQik-TMdg
//LINK DEL VIDEO
//LINK DEL VIDEO


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Fraccion.h"

#include <list>


using namespace std;



 struct Nodo{
    Fraccion Fracc;
    struct Nodo *siguiente;
    
};

 struct Lista{
    Nodo * Cabeza;
};




    
Nodo* CrearNodo(Fraccion N){
    Nodo* nodo = new Nodo();
    nodo -> Fracc = N;
    nodo -> siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    free(nodo);
}

void InsertarPrincipio(Lista* lista,Fraccion N){
    Nodo* nodo = CrearNodo(N);
    nodo -> siguiente = lista ->Cabeza;
    lista -> Cabeza = nodo;
}


void InsetarFinal(Lista* lista,Fraccion N){
    Nodo* nodo = CrearNodo(N);
    
    if(lista -> Cabeza == NULL){
        lista -> Cabeza == nodo;
    }
    else{
        Nodo* Aux = lista -> Cabeza;
        
        while(Aux -> siguiente){
            Aux = Aux -> siguiente;
        }
        Aux -> siguiente = nodo;
    }
}

void InsertarDespues(Fraccion P,Lista* lista,Fraccion N){
   Nodo* nodo = CrearNodo(N); 
   
    if(lista -> Cabeza == NULL){
    lista -> Cabeza == nodo;
    }
    else{
        Nodo* Aux = lista -> Cabeza;
        while(Aux -> Fracc.getResultado() != P.getResultado()){
        Aux = Aux -> siguiente;    
        }
        nodo -> siguiente = Aux -> siguiente;
        Aux -> siguiente = nodo;
    }
    
}


Fraccion* Obtener(Fraccion N,Lista* lista){
    
    if(lista -> Cabeza == NULL){
    return 0;
    }
    else{
       Nodo* Aux = lista -> Cabeza;
       
       while(Aux -> Fracc.getResultado() != N.getResultado()){
           Aux = Aux -> siguiente;
       }
       return &Aux -> Fracc;
    }
    
}


Lista* MiLista = (Lista*) new Lista ();



//Funciones

void AgregarFraccionesALista(){
int auxnumerador,auxdenominador;

cout <<"ingrese un Numerador: ";
cin>>auxnumerador;

cout <<"ingrese un Denominador: ";
cin>>auxdenominador;

Fraccion Faux(auxnumerador,auxdenominador);

InsertarPrincipio(MiLista,Faux);
    
}

void MostarListaDeFracciones(){
    Nodo* Aux = MiLista -> Cabeza;
    while(Aux != NULL){
        Fraccion Faux = Aux -> Fracc;
        Faux.verFraccion();
        Aux = Aux -> siguiente;
        (Aux != NULL) ? cout<< "->" : cout<< "->//"<<endl;
    }
    
    
}

void ContarNumeradoresMenores(){
    int auxnumerador,auxdenominador;
    int auxiliares1,auxiliares2;
    int contador=0;
    Fraccion Faux(auxnumerador,auxdenominador);
    Nodo* Aux = MiLista -> Cabeza;
    
    while(Aux != NULL){
        Fraccion Faux = Aux -> Fracc;
        auxiliares2 = (int)Faux.getDenominador();
        auxiliares1 = (int)Faux.getNumerador();

    
        if(auxiliares2 > auxiliares1){
            contador++;
        }
    
    Aux = Aux -> siguiente;
    }
    
    cout<<"La Cantidad de nodos con su Numerador menor a su Denominador es: "<<contador<<endl;
    
    
}

    

    
    


void RetornarFraccionMayor(){
    int auxnumerador = 1,auxdenominador = 1;
    float res = 0;
    float auxiliares;
    Fraccion Faux;
    
    Nodo* Aux = MiLista -> Cabeza;
    

    
    while(Aux != NULL){
        Faux = Aux -> Fracc;
        auxiliares = (float)Faux.getResultado();
       
        if(auxiliares > res){
            res = auxiliares;
        auxdenominador = (int)Faux.getDenominador();
        auxnumerador = (int)Faux.getNumerador();  
        }
    Aux = Aux -> siguiente;
    
    }
cout<<"La Fraccion Mayor Ingresada es: "<<auxnumerador<<"/"<<auxdenominador<<endl;
      
}



void PromedioDeLosNumeraodres(){
    
    int auxnumerador = 1;
    int i;
    Fraccion Faux;
    int contador = 0;
    int sumando = 0;
    int divisor = 0;
    float PromedioNumeradores = 0;
    
    Nodo* Aux = MiLista -> Cabeza;
    while(Aux != NULL){
        Faux = Aux -> Fracc;
        auxnumerador = (int)Faux.getNumerador();
        contador = 0;
        
        for(i=1 ;i <= auxnumerador; i++){
            if(auxnumerador%i==0){
            contador++;
            }
        }
        if (contador<=2){
            sumando = sumando + auxnumerador;
            divisor++;
        }
        
        
        Aux = Aux -> siguiente;
    }
       
    PromedioNumeradores = (float)sumando / (float)divisor;       
    cout<<"El Promedio de los Numeradores Primos es: "<<PromedioNumeradores<<endl;
    }




int main()
{


int opcion;
    bool repetir = true;
    
    do {
        
        // Texto del menú que se verá cada vez
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Agregar una fraccion a la lista" << endl;
        cout << "2. Muestra todas la fraciones ingresadasa la lista" << endl;
        cout << "3. Cuenta cuantas fraciones tienen el numerador menor que el denominador" << endl;
        cout << "4. Muestra la fraccion de mayor valor ingresada a la lista" << endl;
        cout << "5. Promedio de los numeradores primos ingresados a la lista" << endl;
        cout << "0. SALIR DE EL PROGRAMA" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                system("cls||clear");
                AgregarFraccionesALista();                
                
                
                break;
                
            case 2:
                system("cls||clear");
                MostarListaDeFracciones();                
                
                
                break;
                
            case 3:
                system("cls||clear");
                ContarNumeradoresMenores();                
                
                         
                break;
                
            case 4:
                system("cls||clear");
                RetornarFraccionMayor();                
                
                                
                break;
        
            case 5:
                system("cls||clear");
                PromedioDeLosNumeraodres();                
                
                                
                break;

            
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);


    return 0;
}






