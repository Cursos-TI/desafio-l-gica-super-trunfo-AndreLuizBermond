#include <stdio.h>

// Simulação de movimentos das peças de xadrez
// Desafio nível novato: Torre, Bispo e Rainha

#define MOVE_TORRE 5      // Número de casas que a Torre se move para a direita
#define MOVE_BISPO 5      // Número de casas que o Bispo se move na diagonal (cima e direita)
#define MOVE_RAINHA 8     // Número de casas que a Rainha se move para a esquerda

int main() {
    int torrePassos;
    int bispoPassos;
    int rainhaPassos;

    // 1) Torre: usa loop "for" para mover 5 casas para a direita
    printf("Movimento da Torre (5 casas para a direita):\n");
    for (torrePassos = 1; torrePassos <= MOVE_TORRE; torrePassos++) {
        // A cada iteração, imprime a direção do movimento
        printf("Passo %d: Direita\n", torrePassos);
    }
    printf("\n");

    // 2) Bispo: usa loop "while" para mover 5 casas na diagonal (cima e direita)
    printf("Movimento do Bispo (5 casas diagonal cima-direita):\n");
    bispoPassos = 1;
    while (bispoPassos <= MOVE_BISPO) {
        // Imprime combinação de direções para simular a diagonal
        printf("Passo %d: Cima, Direita\n", bispoPassos);
        bispoPassos++;
    }
    printf("\n");

    // 3) Rainha: usa loop "do-while" para mover 8 casas para a esquerda
    printf("Movimento da Rainha (8 casas para a esquerda):\n");
    rainhaPassos = 1;
    do {
        // Imprime a direção do movimento
        printf("Passo %d: Esquerda\n", rainhaPassos);
        rainhaPassos++;
    } while (rainhaPassos <= MOVE_RAINHA);

    return 0;
}
