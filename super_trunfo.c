#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os atributos de uma carta de Super Trunfo
typedef struct {
    char estado[50];            // Estado
    char codigo[20];            // Código da carta
    char nome[50];              // Nome da cidade
    int populacao;              // População
    float area;                 // Área (km²)
    float pib;                  // PIB (R$ milhões)
    int pontos_turisticos;      // Número de pontos turísticos
    float densidade;            // Densidade populacional (população / área)
    float pib_per_capita;       // PIB per capita (pib / população)
} Carta;

// Defina aqui o atributo a ser comparado:
// 1 = População
// 2 = Área
// 3 = PIB
// 4 = Densidade Populacional (menor vence)
// 5 = PIB per capita
#define ATRIBUTO_COMPARAR 1

int main() {
    // Criação de duas cartas com valores pré-definidos
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11f, 699000.0f, 25, 0.0f, 0.0f};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1182.30f, 310000.0f, 18, 0.0f, 0.0f};

    // Cálculo de densidade e PIB per capita
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;
    carta1.pib_per_capita = carta1.pib * 1e6f / carta1.populacao;
    carta2.pib_per_capita = carta2.pib * 1e6f / carta2.populacao;

    // Variáveis para armazenar nome e valores a comparar
    char nome_atributo[30];
    float valor1, valor2;
    int vencedor = 0; // 1 = carta1, 2 = carta2

    // Seleção do atributo e comparação
    switch (ATRIBUTO_COMPARAR) {
        case 1:
            strcpy(nome_atributo, "População");
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            vencedor = (valor1 > valor2) ? 1 : 2;
            break;
        case 2:
            strcpy(nome_atributo, "Área");
            valor1 = carta1.area;
            valor2 = carta2.area;
            vencedor = (valor1 > valor2) ? 1 : 2;
            break;
        case 3:
            strcpy(nome_atributo, "PIB");
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            vencedor = (valor1 > valor2) ? 1 : 2;
            break;
        case 4:
            strcpy(nome_atributo, "Densidade Populacional");
            valor1 = carta1.densidade;
            valor2 = carta2.densidade;
            // Para densidade, menor valor vence
            vencedor = (valor1 < valor2) ? 1 : 2;
            break;
        case 5:
            strcpy(nome_atributo, "PIB per capita");
            valor1 = carta1.pib_per_capita;
            valor2 = carta2.pib_per_capita;
            vencedor = (valor1 > valor2) ? 1 : 2;
            break;
        default:
            printf("Atributo de comparação inválido!\n");
            return 1;
    }

    // Exibição dos resultados
    printf("Comparação de cartas (Atributo: %s):\n\n", nome_atributo);
    printf("Carta 1 - %s (%s): ", carta1.nome, carta1.estado);
    if (ATRIBUTO_COMPARAR == 1)       printf("%d\n", (int)valor1);
    else                               printf("%.2f\n", valor1);

    printf("Carta 2 - %s (%s): ", carta2.nome, carta2.estado);
    if (ATRIBUTO_COMPARAR == 1)       printf("%d\n", (int)valor2);
    else                               printf("%.2f\n", valor2);

    printf("\nResultado: Carta %d (%s) venceu!\n", vencedor,
           (vencedor == 1 ? carta1.nome : carta2.nome));

    return 0;
}
