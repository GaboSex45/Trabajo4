#include <iostream>



#ifndef FRACCION_H
#define FRACCION_H


using namespace std;
class Fraccion
{
    private:
    int Numerador;
    int Denominador;
    float Resultado;
    
    public:
    Fraccion(){
        Numerador = 0;
        Denominador = 1;
        Resultado = (float)Numerador / (float)Denominador;
    }
    
    Fraccion(int num,int den){
        if (Verificador(den)){
            Numerador = num;
            Denominador = den;
            Resultado = (float)Numerador / (float)Denominador;
        }
        else{
            cout<<"No se puede dividir por 0"<<endl;
        }
        
    }
    
    //getters
    float getResultado(){return Resultado;}
    int getNumerador(){return Numerador;}
    int getDenominador(){return Denominador;}
    
    bool Verificador(int num){
        bool respuesta = (num != 0) ? true : false;
        return respuesta;
        
    }
    bool Menor(){
        bool respuesta = (Numerador < Denominador) ? true : false;
        return respuesta;
        
    }
    void verFraccion(){
        cout<< Numerador << "/" << Denominador;
    }
};
#endif
