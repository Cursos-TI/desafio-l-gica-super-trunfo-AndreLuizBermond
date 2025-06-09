#include <stdio.h>
#include <string.h>

/*
   logicaSuperTrunfo.c
   -------------------
   Desafio Super Trunfo — Países
   Tema 2 – Comparação das Cartas

   ▸ Este programa cadastra duas cartas de cidades, calcula densidade populacional
     e PIB per capita, escolhe um atributo (definido em código) e determina a vencedora.
   ▸ Para trocar o atributo de comparação, altere a constante COMPARE_ATTR abaixo.

   Como compilar (GCC):
       gcc -Wall -Wextra -std=c11 logicaSuperTrunfo.c -o logicaSuperTrunfo
   Como executar:
       ./logicaSuperTrunfo
*/

/* ---------- ENUMERAÇÃO DOS ATRIBUTOS DISPONÍVEIS ----------------------- */
typedef enum {
    POPULATION,          /* População */
    AREA,                /* Área (km²) */
    GDP,                 /* PIB (milhões de R$) */
    TOURIST_SPOTS,       /* Pontos turísticos */
    DENSITY,             /* População / Área  (MENOR vence) */
    GDP_PER_CAPITA       /* PIB / População   (MAIOR vence) */
} Attribute;

/* Troque aqui para comparar outro atributo ------------------------------ */
#define COMPARE_ATTR POPULATION
/* ---------------------------------------------------------------------- */

/* --------------------------- ESTRUTURA DA CARTA ------------------------ */
typedef struct {
    char  state[3];          /* UF                   */
    char  code[16];          /* Código da carta      */
    char  city[50];          /* Nome da cidade       */
    int   population;        /* Habitantes           */
    float area;              /* km²                 */
    float gdp;               /* Milhões de R$        */
    int   tourist_spots;     /* Pontos turísticos    */

    /* Campos derivados */
    float density;           /* hab/km²              */
    float gdp_per_capita;    /* R$ milhões / hab.    */
} Card;

/* --------------------------- PROTÓTIPOS -------------------------------- */
void  read_card(Card *c, int n);
void  calc_derived(Card *c);
float get_value(const Card *c, Attribute a);
const char* attr_name(Attribute a);
/* ---------------------------------------------------------------------- */

int main(void)
{
    Card carta1, carta2;

    /* ------------------ Cadastro das Cartas (leitura do usuário) -------- */
    puts("=== Cadastro da Carta 1 ===");
    read_card(&carta1, 1);
    puts("\n=== Cadastro da Carta 2 ===");
    read_card(&carta2, 2);

    /* ------------ Cálculo de densidade populacional e PIB per capita ---- */
    calc_derived(&carta1);
    calc_derived(&carta2);

    /* -------------------- Comparação de Cartas -------------------------- */
    Attribute cmp = COMPARE_ATTR;
    float v1 = get_value(&carta1, cmp);
    float v2 = get_value(&carta2, cmp);

    printf("\n== Comparação de cartas (Atributo: %s) ==\n\n", attr_name(cmp));
    printf("Carta 1 - %s (%s): %.2f\n", carta1.city, carta1.state, v1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.city, carta2.state, v2);

    int carta1_win;
    if (cmp == DENSITY)              /* Para densidade, o MENOR vence        */
        carta1_win = (v1 < v2);
    else                             /* Demais atributos: MAIOR vence        */
        carta1_win = (v1 > v2);

    printf("\nResultado: ");
    if (v1 == v2) {
        puts("Empate!");
    } else if (carta1_win) {
        printf("Carta 1 (%s) venceu!\n", carta1.city);
    } else {
        printf("Carta 2 (%s) venceu!\n", carta2.city);
    }

    return 0;
}

/* ========================= FUNÇÕES AUXILIARES ========================== */

/* Leitura interativa de uma carta --------------------------------------- */
void read_card(Card *c, int n)
{
    printf("Digite o código da carta %d: ", n);
    scanf("%15s", c->code);

    printf("Digite a UF (ex.: SP): ");
    scanf("%2s", c->state);

    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", c->city);          /* lê até fim de linha */

    printf("População (habitantes): ");
    scanf("%d", &c->population);

    printf("Área (km2): ");
    scanf("%f", &c->area);

    printf("PIB (milhões de R$): ");
    scanf("%f", &c->gdp);

    printf("Número de pontos turísticos: ");
    scanf("%d", &c->tourist_spots);
}

/* Calcula densidade populacional e PIB per capita ----------------------- */
void calc_derived(Card *c)
{
    c->density        = (c->area       > 0) ? c->population / c->area : 0.0f;
    c->gdp_per_capita = (c->population > 0) ? c->gdp        / c->population : 0.0f;
}

/* Retorna o valor numérico do atributo escolhido ----------------------- */
float get_value(const Card *c, Attribute a)
{
    switch (a) {
        case POPULATION:      return (float)c->population;
        case AREA:            return c->area;
        case GDP:             return c->gdp;
        case TOURIST_SPOTS:   return (float)c->tourist_spots;
        case DENSITY:         return c->density;
        case GDP_PER_CAPITA:  return c->gdp_per_capita;
        default:              return 0.0f;
    }
}

/* Nome legível do atributo --------------------------------------------- */
const char* attr_name(Attribute a)
{
    switch (a) {
        case POPULATION:      return "População";
        case AREA:            return "Área";
        case GDP:             return "PIB";
        case TOURIST_SPOTS:   return "Pontos Turísticos";
        case DENSITY:         return "Densidade Populacional";
        case GDP_PER_CAPITA:  return "PIB per capita";
        default:              return "Desconhecido";
    }
}
