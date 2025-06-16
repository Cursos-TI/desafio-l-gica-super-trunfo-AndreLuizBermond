#include <stdio.h>
#include <stdlib.h>

// Batalha Naval - Nível Novato
// Simulação de posicionamento de dois navios em um tabuleiro 10x10
// Navio horizontal e navio vertical de tamanho fixo 3

#define BOARD_SIZE 10      // Tamanho do tabuleiro (10x10)
#define SHIP_SIZE 3        // Tamanho dos navios (3 posições)

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int i, j;

    // 1) Inicializar tabuleiro com água (0)
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // 2) Definir coordenadas iniciais dos navios (0-based)
    // Navio horizontal iniciado em (linhaH, colH)
    int linhaH = 2;
    int colH   = 4;
    // Navio vertical iniciado em (linhaV, colV)
    int linhaV = 5;
    int colV   = 7;

    // 3) Validar limites do tabuleiro
    if (colH + SHIP_SIZE - 1 >= BOARD_SIZE) {
        printf("Erro: navio horizontal ultrapassa limites do tabuleiro.\n");
        return 1;
    }
    if (linhaV + SHIP_SIZE - 1 >= BOARD_SIZE) {
        printf("Erro: navio vertical ultrapassa limites do tabuleiro.\n");
        return 1;
    }

    // 4) Posicionar navio horizontal (valor 3)
    for (j = 0; j < SHIP_SIZE; j++) {
        // Verificar sobreposição
        if (board[linhaH][colH + j] != 0) {
            printf("Erro: sobreposição detectada ao posicionar navio horizontal.\n");
            return 1;
        }
        board[linhaH][colH + j] = 3;
    }

    // 5) Posicionar navio vertical (valor 3)
    for (i = 0; i < SHIP_SIZE; i++) {
        // Verificar sobreposição
        if (board[linhaV + i][colV] != 0) {
            printf("Erro: sobreposição detectada ao posicionar navio vertical.\n");
            return 1;
        }
        board[linhaV + i][colV] = 3;
    }

    // 6) Exibir tabuleiro
    printf("Tabuleiro Batalha Naval (0=água, 3=navio):\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
