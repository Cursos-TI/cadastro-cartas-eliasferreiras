#include <stdio.h>
#include <string.h>

// Declaracoes:

typedef struct {
    char estado[30], codigo[4], nome_cidade[40];
    int populacao, pontos_turisticos;
    float area, pib;
} Carta;

Carta le_carta(void);
void imprime_carta(Carta carta);
int le_qtd_cartas(void);

// Main:

int main(void) {
    int qtd_cartas = le_qtd_cartas();

    Carta cartas[qtd_cartas];

    // le as cartas
    for (int i = 0; i < qtd_cartas; i++) {
        printf("Adicione os dados da Carta %d:\n", i + 1);
        cartas[i] = le_carta();
    }

    // imprime as cartas
    for (int i = 0; i < qtd_cartas; i++) {
        printf("\nCarta %d:\n", i + 1);
        imprime_carta(cartas[i]);
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

    // Consumir o ENTER que sobrou do scanf anterior
    getchar();

    printf("Digite o nome da cidade:\n");
    fgets(carta.nome_cidade, sizeof(carta.nome_cidade), stdin);

    // Remove o '\n' do final (adicionado pelo fgets)
    carta.nome_cidade[strcspn(carta.nome_cidade, "\n")] = '\0';

    printf("Digite o populacao da cidade:\n");
    scanf("%d", &carta.populacao);

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
    printf("Populacao: %d\n", carta.populacao);
    printf("Area: %.2f km² \n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos turisticos: %d\n", carta.pontos_turisticos);
}

int le_qtd_cartas(void) {
    int qtd;
    printf("Digite a quantidade de cartas:\n");
    scanf("%d", &qtd);

    return qtd;
}