#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void exibirMenu(int opcaoEscolhida) {
    for (int i = 1; i <= 5; i++) {
        if (i == opcaoEscolhida) continue;
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
}

float obterValor(int opcao, unsigned long int populacao, float area, float pib, int pontos, float densidade, char *nomeAttr) {
    switch (opcao) {
        case 1: strcpy(nomeAttr, "População"); return populacao;
        case 2: strcpy(nomeAttr, "Área"); return area;
        case 3: strcpy(nomeAttr, "PIB"); return pib;
        case 4: strcpy(nomeAttr, "Pontos Turísticos"); return pontos;
        case 5: strcpy(nomeAttr, "Densidade Demográfica"); return densidade;
        default: printf("Opção inválida. Encerrando.\n"); exit(1);
    }
}

int main() {
    // Carta 1
    char estado1, nome1[50], codigo1[5];
    int codigoNum1, pontos1;
    unsigned long int populacao1;
    float area1, pib1, densidade1, pibpercapita1;

    // Carta 2
    char estado2, nome2[50], codigo2[5];
    int codigoNum2, pontos2;
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibpercapita2;

    // Entrada Carta 1
    printf("Carta 1:\n");
    printf("Insira uma letra de 'A' a 'H': "); scanf(" %c", &estado1);
    printf("Insira um número de 1 a 4: "); scanf("%d", &codigoNum1); getchar();
    printf("Insira o nome da cidade: "); fgets(nome1, sizeof(nome1), stdin); nome1[strcspn(nome1, "\n")] = '\0';
    printf("Insira o número de habitantes: "); scanf("%lu", &populacao1);
    printf("Insira a área (em km²): "); scanf("%f", &area1);
    printf("Insira o valor do PIB (em bilhões de reais): "); scanf("%f", &pib1);
    printf("Insira a quantidade de pontos turísticos: "); scanf("%d", &pontos1);
    sprintf(codigo1, "%c%02d", estado1, codigoNum1);

    // Entrada Carta 2
    printf("\nCarta 2:\n");
    printf("Insira uma letra de 'A' a 'H': "); scanf(" %c", &estado2);
    printf("Insira um número de 1 a 4: "); scanf("%d", &codigoNum2); getchar();
    printf("Insira o nome da cidade: "); fgets(nome2, sizeof(nome2), stdin); nome2[strcspn(nome2, "\n")] = '\0';
    printf("Insira o número de habitantes: "); scanf("%lu", &populacao2);
    printf("Insira a área (em km²): "); scanf("%f", &area2);
    printf("Insira o valor do PIB (em bilhões de reais): "); scanf("%f", &pib2);
    printf("Insira a quantidade de pontos turísticos: "); scanf("%d", &pontos2);
    sprintf(codigo2, "%c%02d", estado2, codigoNum2);

    // Cálculos
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;
    pibpercapita1 = (pib1 * 1e9) / populacao1;
    pibpercapita2 = (pib2 * 1e9) / populacao2;

    // Escolha de atributos
    int opcao1, opcao2;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    char nomeAttr1[30], nomeAttr2[30];

    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    scanf("%d", &opcao1);
    valor1_c1 = obterValor(opcao1, populacao1, area1, pib1, pontos1, densidade1, nomeAttr1);
    valor1_c2 = obterValor(opcao1, populacao2, area2, pib2, pontos2, densidade2, nomeAttr1);

    printf("\nEscolha o segundo atributo para comparação:\n");
    exibirMenu(opcao1);
    scanf("%d", &opcao2);

    if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5) {
        printf("Opção inválida. Encerrando.\n");
        return 1;
    }

    valor2_c1 = obterValor(opcao2, populacao1, area1, pib1, pontos1, densidade1, nomeAttr2);
    valor2_c2 = obterValor(opcao2, populacao2, area2, pib2, pontos2, densidade2, nomeAttr2);

    // Comparação e resultado
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\n--- Resultado da Comparação ---\n");
    printf("%s vs %s\n", nome1, nome2);
    printf("%s: %.2f vs %.2f\n", nomeAttr1, valor1_c1, valor1_c2);
    printf("%s: %.2f vs %.2f\n", nomeAttr2, valor2_c1, valor2_c2);
    printf("Soma dos atributos: %.2f (Carta 1) vs %.2f (Carta 2)\n", soma1, soma2);

    if (soma1 > soma2) printf("Resultado: Carta 1 venceu!\n");
    else if (soma2 > soma1) printf("Resultado: Carta 2 venceu!\n");
    else printf("Resultado: Empate!\n");

    return 0;
}