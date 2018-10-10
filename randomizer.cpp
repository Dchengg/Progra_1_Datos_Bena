#include <iostream>
#include <cstdlib>
#include <time.h>

template<class T>
T getRandomNum(int desde, int hasta){
    T resultado;
    resultado = rand() % (hasta - desde + 1);
    resultado += desde;
    return resultado;
}

template<class E,class T>
void llenarTDA(T TDA, int tam, int desde, int hasta){
    E num;
    for(int i = 0; i <= tam;i++){
        num = getRandomNum<E>(desde,hasta);
        TDA->insertarNodo(num);
     }
}

