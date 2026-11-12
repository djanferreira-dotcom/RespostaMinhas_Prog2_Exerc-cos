#include <stdio.h>
#include "dado.h"

// Gerador congruente linear com semente fixa: a sequência é sempre a mesma

int RolaDado() {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % FACES_DADO) + 1;
}