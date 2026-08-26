#include <stdio.h>
#include "esfera_utils.h"

int main(){

    float R;

    scanf("%f",&R);

    calcula_area(R);
    calcula_volume(R);

    printf();

    return 0;
}