// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
#include <stdio.h>
#include <string.h>

struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    const int NUM_TERRITORIOS = 5;
    struct Territorio listaTerritorios[NUM_TERRITORIOS];
    int i; 

    printf("--- CADASTRO DE TERRITORIOS DO JOGO WAR ---\n\n");
    for (i = 0; i < NUM_TERRITORIOS; i++) {
       
        printf("Digite as informacoes para o Territorio %d:\n", i + 1);

        printf("Nome: ");
        fgets(listaTerritorios[i].nome, 30, stdin);
        
        listaTerritorios[i].nome[strcspn(listaTerritorios[i].nome, "\n")] = 0;


        printf("Cor do exercito: ");
        scanf("%s", listaTerritorios[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &listaTerritorios[i].tropas);

        while (getchar() != '\n');

        printf("\n");
    }

    // --- Documentação: Exibição de Dados ---
    printf("\n--- TERRITORIOS CADASTRADOS ---\n");
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("----------------------------------\n");
        printf("Territorio: %s\n", listaTerritorios[i].nome);
        printf("Cor do Exercito: %s\n", listaTerritorios[i].cor);
        printf("Quantidade de Tropas: %d\n", listaTerritorios[i].tropas);
    }
    printf("----------------------------------\n");

    return 0;
}