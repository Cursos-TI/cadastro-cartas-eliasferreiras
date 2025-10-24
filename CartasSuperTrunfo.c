#include <stdio.h>
#include <string.h>

// Declaracoes:

typedef struct {
    char estado[30], codigo[4], nome_cidade[40];
    unsigned long int populacao;
    int pontos_turisticos;
    float area, pib, dens_pop, pib_per_capta;
    float poder;
} Carta;

Carta le_carta(void);
void imprime_carta(Carta carta);
int le_qtd_cartas(void);
float calcula_dens_pop(Carta carta);
float calcula_pib_per_capta(Carta carta);
float calcula_poder(Carta carta);
void compara_cartas(Carta c1, Carta c2);
void printa_resultado(float a, float b);

// Main:

int main(void) {
    int qtd_cartas = le_qtd_cartas();

    Carta cartas[qtd_cartas];

    // Le as cartas
    for (int i = 0; i < qtd_cartas; i++) {
        printf("Adicione os dados da Carta %d:\n", i + 1);
        cartas[i] = le_carta();
        // Calcula Dados
        cartas[i].dens_pop = calcula_dens_pop(cartas[i]);
        cartas[i].pib_per_capta = calcula_pib_per_capta(cartas[i]);
        cartas[i].poder = calcula_poder(cartas[i]);
    }

    // Imprime as cartas
    for (int i = 0; i < qtd_cartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        imprime_carta(cartas[i]);
    }

    if (qtd_cartas > 1) {
        compara_cartas(cartas[0], cartas[1]);
    }

    return 0;
}

// Funcoes:

Carta le_carta(void) {
    Carta carta;

    printf("Digite o estado da cidade:\n");
    scanf(" %s", carta.estado);

    char numero[3];
    printf("Digite o código da cidade (Um número de 01 a 04):\n");
    scanf("%2s", numero);

    sprintf(carta.codigo, "%c%s", carta.estado[0], numero);

    getchar(); // consumir ENTER

    printf("Digite o nome da cidade:\n");
    fgets(carta.nome_cidade, sizeof(carta.nome_cidade), stdin);
    carta.nome_cidade[strcspn(carta.nome_cidade, "\n")] = '\0';

    printf("Digite a populacao da cidade:\n");
    scanf("%lu", &carta.populacao);

    printf("Digite a area da cidade:\n");
    scanf("%f", &carta.area);

    printf("Digite o pib da cidade:\n");
    scanf("%f", &carta.pib);

    printf("Digite a quantidade de pontos turisticos:\n");
    scanf("%d", &carta.pontos_turisticos);

    return carta;
}

void imprime_carta(Carta carta) {
    printf("Estado: %s\n", carta.estado);
    printf("Codigo: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("Populacao: %lu\n", carta.populacao);
    printf("Area: %.2f km² \n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos turisticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.dens_pop);
    printf("PIB per Capita: %.6f bilhões de reais por hab.\n", carta.pib_per_capta);
    printf("Poder: %.2f\n", carta.poder);
}

int le_qtd_cartas(void) {
    int qtd;
    printf("Digite a quantidade de cartas:\n");
    scanf("%d", &qtd);

    return qtd;
}

float calcula_dens_pop(Carta carta) {
    return carta.populacao / carta.area;
}

float calcula_pib_per_capta(Carta carta) {
    return carta.pib / carta.populacao; // PIB per capta em bilhoes de reais.
}

float calcula_poder(Carta carta) {
    return carta.pontos_turisticos +
           carta.populacao +
           carta.area +
           carta.pib +
           carta.pib_per_capta -
           carta.dens_pop;
}

void compara_cartas(Carta c1, Carta c2) {
    printf("\n\nComparando Cartas...\n\n");
    printf("População: ");
    printa_resultado((float) c1.populacao, (float) c2.populacao);
    printf("Área: ");
    printa_resultado(c1.area, c2.area);
    printf("PIB: ");
    printa_resultado(c1.pib, c2.pib);
    printf("Pontos Turísticos: ");
    printa_resultado((float) c1.pontos_turisticos, (float) c2.pontos_turisticos);
    printf("Densidade Populacional: ");
    printa_resultado(c2.dens_pop, c1.dens_pop);
    printf("PIB per Capita: ");
    printa_resultado(c1.pib_per_capta, c2.pib_per_capta);
    printf("Super Poder: ");
    printa_resultado(c1.poder, c2.poder);
}

void printa_resultado(float a, float b) {
    if (a > b) {
        printf("Carta 1 venceu (%d)\n", a > b);
    } else {
        printf("Carta 2 venceu (%d)\n", a > b);
    }
}
