// Aqui a gente chama as "caixas de ferramentas" do C para nos ajudar.
#include <stdio.h>    // Essa é para as funções de entrada e saída, como o printf (para mostrar texto) e o fgets (para ler texto).
#include <string.h>   // Essa é para trabalhar com textos (strings), como a função strcspn que usamos para remover o "Enter".
#include <stdlib.h>   // E esta aqui é para algumas utilidades gerais, incluindo a função atoi, que transforma texto em número.

// Agora, vamos criar um "molde" para os nossos territórios.
struct Territorio {
    char nome[30];    // Um espaço na memória para guardar o nome do território (até 29 letras + o terminador).
    char cor[10];     // Um espaço menor para a cor do exército que domina ali.
    int tropas;       // E aqui guardamos a quantidade de soldados, que é um número inteiro.
};

// É aqui que a mágica do nosso programa acontece, a função principal.
int main() {
    // Definimos que nosso jogo terá exatamente 5 territórios. Usar uma constante assim facilita se um dia quisermos mudar esse número.
    const int NUM_TERRITORIOS = 5;

    // Agora criamos nossa "pasta de arquivos", um vetor que pode guardar as fichas de 5 territórios, seguindo o molde que criamos ali em cima.
    struct Territorio listaTerritorios[NUM_TERRITORIOS];

    // Essa variável 'i' vai ser nosso "dedo", nos ajudando a apontar para cada território da lista, um de cada vez.
    int i;

    // Precisamos de um pequeno "bloco de rascunho" para anotar o número de tropas que o usuário digitar, antes de converter para número de verdade.
    char buffer_tropas[10];

    // Imprimimos um título para o usuário saber o que ele vai fazer.
    printf("--- CADASTRO DE TERRITORIOS DO JOGO WAR ---\n\n");

    // Vamos começar um loop, uma repetição, para cadastrar os 5 territórios. O 'i' começa em 0 e vai até 4.
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        // A cada repetição, pedimos as informações de um novo território. O "i + 1" é só pra mostrar "Território 1", "Território 2", etc.
        printf("Digite as informacoes para o Territorio %d:\n", i + 1);

        // Pedimos o nome do território.
        printf("Nome: ");
        // Usamos o fgets para ler o que o usuário digitar, incluindo espaços. É mais seguro que o scanf para textos.
        fgets(listaTerritorios[i].nome, 30, stdin);
        // O fgets guarda também a tecla "Enter" (\n) no final. Essa linha mágica encontra e apaga esse "Enter" para não atrapalhar depois.
        listaTerritorios[i].nome[strcspn(listaTerritorios[i].nome, "\n")] = 0;

        // Agora pedimos a cor.
        printf("Cor do exercito: ");
        // Lemos a cor da mesma forma que lemos o nome, para manter o padrão e a segurança.
        fgets(listaTerritorios[i].cor, 10, stdin);
        // E, claro, limpamos o "Enter" do final do texto da cor também.
        listaTerritorios[i].cor[strcspn(listaTerritorios[i].cor, "\n")] = 0;

        // Por último, a quantidade de tropas.
        printf("Quantidade de tropas: ");
        // Lemos o número como se fosse um texto e guardamos no nosso "rascunho".
        fgets(buffer_tropas, 10, stdin);
        // A função atoi pega o texto do nosso rascunho (ex: "12") e transforma no número inteiro 12, guardando na ficha do território.
        listaTerritorios[i].tropas = atoi(buffer_tropas);

        // Um espacinho em branco para o cadastro não ficar todo grudado. Fica mais organizado.
        printf("\n");
    }

    // Ok, o cadastro acabou! Hora de mostrar o resultado.
    printf("\n--- TERRITORIOS CADASTRADOS ---\n");

    // Vamos repetir a mesma lógica de antes, passando por cada ficha de território guardada...
    for (i = 0; i < NUM_TERRITORIOS; i++) {
        // ...só que desta vez, em vez de pedir dados, vamos mostrar os dados que já temos.
        printf("----------------------------------\n"); // Uma linha para separar e organizar.
        printf("Territorio: %s\n", listaTerritorios[i].nome);      // Mostra o nome do território atual.
        printf("Cor do Exercito: %s\n", listaTerritorios[i].cor);      // Mostra a cor do exército.
        printf("Quantidade de Tropas: %d\n", listaTerritorios[i].tropas); // Mostra o número de tropas.
    }
    // Uma última linha para fechar a lista de forma bonita.
    printf("----------------------------------\n");

    // Se chegamos até aqui, deu tudo certo! Retornamos 0 para avisar o sistema operacional que o programa terminou sem problemas.
    return 0;
}