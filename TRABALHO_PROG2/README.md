# Jogo da Void - Template de implementação do Trabalho Prático 2026/2

Neste repositório você encontra o template de código para implementação do Trabalho Prático - Etapa 1 da disciplina de Programação II.

Informações relevantes:

- O funcionamento deste repositório é idêntico ao fornecido nos [exercícios gerais](https://github.com/prog-II-ufes/exercicios-gerais). Para mais detalhes, consulte as instruções contida no [README daquele repositório](https://github.com/prog-II-ufes/exercicios-gerais).

- A descrição do projeto está disponível no Clasroom e [neste link para o Drive](https://docs.google.com/document/d/1-viNMOQYeEN5PsWwslaDAKRR-K7MmUXXgnGWwk2NfVA/edit?usp=sharing).

- Instruções de submissão estão disponíveis no Classroom da disciplina.

- É altamente recomendado que vocês criem seus próprios casos para garantir que o código está funcionando corretamente.

- Caso algo seja atualizado no template, vocês serão notificados.



## Implementação de `RolaDado()`
A funçao que executa a rolagem do dado tem que ser realizada da seguinte forma:

```
#include "dado.h"

#define FACES_DADO 4

// Gerador congruente linear com semente fixa: a sequência é sempre a mesma
static unsigned int semente = 2026;

int RolaDado() {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente / 65536u) % FACES_DADO) + 1;
}
```
Isso garante que todos tenham a mesma sequência de jogas. Crie um TAD `dado.c` e `dado.h` e coloque a função nele.

Qualquer dúvida ou problema, entre em contato com os monitores e/ou professores.


