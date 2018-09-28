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

template<class T>
void llenarTDA(T TDA, int tam, int desde, int hasta){
    int num;
    for(int i = 0; i <= tam;i++){
        num = getRandomNum<int>(desde,hasta);
        TDA->insertarNodo(num);
     }
}
