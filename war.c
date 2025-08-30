// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Necessária para a função atoi

// --- Documentação: Criação da Struct ---
// A struct 'Territorio' é uma estrutura de dados composta que agrupa
// diferentes tipos de informações sobre um território do jogo.
// Ela armazena o nome do território, a cor do exército que o ocupa
// e a quantidade de tropas presentes.
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    // --- Manutenibilidade: Nomes Claros ---
    // Declaração de um vetor de structs. O nome 'listaTerritorios' é
    // claro e indica que a variável armazenará múltiplos territórios.
    const int NUM_TERRITORIOS = 5;
    struct Territorio listaTerritorios[NUM_TERRITORIOS];
    int i; // Variável de controle para os laços

    // Buffer temporário para ler a quantidade de tropas como texto
    char buffer_tropas[10];

    // --- Documentação: Entrada de Dados ---
    // Este laço 'for' é usado para percorrer o vetor 'listaTerritorios'
    // e preencher os dados de cada um dos 5 territórios.
    printf("--- CADASTRO DE TERRITORIOS DO JOGO WAR ---\n\n");
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        // --- Usabilidade: Interface Clara ---
        // As mensagens para o usuário são claras e diretas.
        printf("Digite as informacoes para o Territorio %d:\n", i + 1);

        printf("Nome: ");
        // Usamos fgets para todas as leituras para evitar problemas de buffer.
        fgets(listaTerritorios[i].nome, 30, stdin);
        // A linha abaixo remove o caractere '\n' que o fgets captura.
        listaTerritorios[i].nome[strcspn(listaTerritorios[i].nome, "\n")] = 0;

        printf("Cor do exercito: ");
        fgets(listaTerritorios[i].cor, 10, stdin);
        listaTerritorios[i].cor[strcspn(listaTerritorios[i].cor, "\n")] = 0;

        printf("Quantidade de tropas: ");
        fgets(buffer_tropas, 10, stdin);
        // A função atoi() (ASCII to Integer) converte a string lida para um número inteiro.
        listaTerritorios[i].tropas = atoi(buffer_tropas);

        printf("\n"); // Adiciona uma linha em branco para melhor legibilidade
    }

    // --- Documentação: Exibição de Dados ---
    // Após o cadastro, este laço 'for' exibe na tela os dados de cada
    // território que foi armazenado na struct.
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