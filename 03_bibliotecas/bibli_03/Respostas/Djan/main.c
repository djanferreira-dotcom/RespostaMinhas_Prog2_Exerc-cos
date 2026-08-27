#include <stdio.h>
#include "data.h"

int main(){

    int dia1, dia2, mes1, mes2, ano1, ano2;

    scanf("%i/%i/%i",&dia1,&mes1,&ano1);
    printf("\n");
    scanf("%i/%i/%i",&dia2,&mes2,&ano2);

    if((verificaDataValida(dia1,mes1,ano1) && verificaDataValida(dia2,mes2,ano2)) == 1){

        

    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }

    return 0;
}