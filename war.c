#include <stdio.h>
#include <string.h>

// A struct permanece a mesma
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// Função para limpar o buffer de entrada
// Essencial para usar depois de um scanf para garantir que a próxima leitura funcione
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    const int NUM_TERRITORIOS = 5;
    struct Territorio listaTerritorios[NUM_TERRITORIOS];
    int i;

    printf("--- CADASTRO DE TERRITORIOS DO JOGO WAR ---\n\n");

    for (i = 0; i < NUM_TERRITORIOS; i++) {
        printf("Digite as informacoes para o Territorio %d:\n", i + 1);

        // Para ler o nome (pode conter espaços)
        printf("Nome: ");
        // Usamos %[^\n] para ler tudo até o usuário pressionar Enter.
        // O ' ' no início do formato limpa o buffer do Enter anterior.
        scanf(" %[^\n]", listaTerritorios[i].nome);
        limpar_buffer(); // Limpa o buffer após a leitura

        // Para ler a cor (assumindo uma única palavra)
        printf("Cor do exercito: ");
        scanf("%s", listaTerritorios[i].cor);
        limpar_buffer(); // Limpa o buffer após a leitura

        // Para ler a quantidade de tropas
        printf("Quantidade de tropas: ");
        scanf("%d", &listaTerritorios[i].tropas);
        limpar_buffer(); // Limpa o buffer após a leitura

        printf("\n");
    }

    // A parte de exibição não muda, pois ela já estava correta.
    // Se a entrada falha, os dados ficam corrompidos e a exibição parece vazia.
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