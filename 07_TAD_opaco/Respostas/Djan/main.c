#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main(){

    float valores[5];
    int i;

    for(i = 0; i < 5; i++){
        scanf("%f",&valores[i]);
    }

    tCirculo c = Circulo_Cria(valores[0],valores[1],valores[2]);
    tPonto p = Pto_Cria(valores[3],valores[4]);
    int resultado = Circulo_Interior(c,p);

    printf("%d\n",resultado);

    Pto_Apaga(p);
    Circulo_Apaga(c);


    return 0;
}