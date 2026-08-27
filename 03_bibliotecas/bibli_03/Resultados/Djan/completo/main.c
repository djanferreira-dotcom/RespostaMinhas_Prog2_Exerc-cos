#include <stdio.h>
#include "data.h"

int main(){

    int dia1, dia2, mes1, mes2, ano1, ano2;

    scanf("%i/%i/%i",&dia1,&mes1,&ano1);
    printf("\n");
    scanf("%i/%i/%i",&dia2,&mes2,&ano2);

    if((verificaDataValida(dia1,mes1,ano1) && verificaDataValida(dia2,mes2,ano2)) == 1){

        imprimeDataExtenso(dia1,mes1,ano1);
        imprimeDataExtenso(dia2,mes2,ano2);
        if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == 1){
            printf("A primeira data eh mais antiga\n");
        }else if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == -1){
            printf("A segunda data eh mais antiga\n");
        }else{
            printf("As datas sao iguais\n");
        }
        printf("A diferenca em dias entre as datas eh: %i dias",calculaDiferencaDias(dia1,mes1,ano1,dia2,mes2,ano2));
    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}