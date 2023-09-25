
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 32

// Struct Contato
typedef struct Contato {
    char nome[50];
    char email[50];
    long telefone;
} Contato;

Contato tabela[SIZE];

// Função para ler um número inteiro do usuário
int lerInt() {
    int numero;
    bool entradaValida = false;

    do {        
        // Tente ler um número inteiro
        if (scanf("%d", &numero) == 1) {
            entradaValida = true;
        } else {
            // Limpar o buffer de entrada em caso de entrada inválida
            while (getchar() != '\n');
            printf("Entrada inválida. Tente novamente.\n");
        }
    } while (!entradaValida);

    return numero;
}

int lerlongInt() {
    long numero;
    bool entradaValida = false;

    do {        
        // Tente ler um número inteiro
        if (scanf("%ld", &numero) == 1) {
            entradaValida = true;
        } else {
            // Limpar o buffer de entrada em caso de entrada inválida
            while (getchar() != '\n');
            printf("Entrada inválida. Tente novamente.\n");
        }
    } while (!entradaValida);

    return numero;
}

// Função HASH 1
int hash1(long telefone) {
    return telefone % SIZE;
}

// Função HASH 2
int hash2(long telefone) {
    return 8 - (telefone % 8);
}

// Insere o contato em uma lista de contatos
void inserirContato() {

    // Variáveis
    char nome[50];
    char email[50];
    long telefone;
    
    // Inserção de dados pelo usuário
    printf("\nDigite o nome: ");  
    scanf("%s", nome);
    printf("Digite o email: ");
    scanf("%s", email);
    printf("Digite o telefone: ");
    telefone = lerlongInt();
    
    // Inplementação das funções HASH
    int index = hash1(telefone);
    int step = hash2(telefone);
    while (tabela[index].telefone != 0) {
        index = (index + step) % SIZE;
    }
    
    // Inserção dos dados inseridos pelo usuário na lista de contatos
    strcpy(tabela[index].nome, nome);
    strcpy(tabela[index].email, email);
    tabela[index].telefone = telefone;
    printf("Contato inserido com sucesso!\n");
}

// Busca um contato na lista de contatos
void buscarContato() {

    // Variável
    long telefone;

    // Inserção de dados
    printf("\nDigite o telefone do contato:\n: ");
    telefone = lerlongInt();

    // Funções HASH
    int index = hash1(telefone);
    int step = hash2(telefone);

    // Imprime dados de um contato se ele estiver cadastrado
    while (tabela[index].telefone != 0) {
        if (tabela[index].telefone == telefone) {
            printf("\nO contato foi encontrado!\n\n");
            printf("Nome: %s\n", tabela[index].nome);
            printf("Email: %s\n", tabela[index].email);
            printf("Telefone: %ld\n", tabela[index].telefone);
            return;
        }
        index = (index + step) % SIZE;
        if (index == hash1(telefone)) {
            break;
        }
    }
    printf("\nContato não foi encontrado!\n\n");
}

// Lista todos os contato em uma lista de contatos
void listarContatos() {

    // Imprime os contatos
    printf("\n------Lista de Contatos-------\n\n");
    for (int i = 0; i < SIZE; i++) {
        if (tabela[i].telefone != 0) {
            printf("\nNome: %s\n", tabela[i].nome);
            printf("Email: %s\n", tabela[i].email);
            printf("Telefone: %ld\n", tabela[i].telefone);
        }
    }
    printf("\n------------------------------\n\n");
}

// Exporta os contatos em uma lista de contatos para um arquivo .txt
void exportarContatos(){

    // Variáveis da função e arquivo da lista de contatos é aberto
    int i;
    FILE *export = fopen("lista-de-contatos.txt", "a+");
    if (export == NULL) {
        printf("\nNão foi possível abrir o arquivo.\n\n");
        exit(1);
    }

    // Lista de contatos é imprimida no arquivo "lista-de-contatos.txt"
    fprintf(export, "LISTA DE CONTATOS\n\n");
    for (int i = 0; i < SIZE; i++) {
        if (tabela[i].telefone != 0) {
            fprintf(export, "Nome: %s\n", tabela[i].nome);
            fprintf(export, "Email: %s\n", tabela[i].email);
            fprintf(export, "Telefone: %ld\n\n", tabela[i].telefone);
        }
    }
    printf("\nUm arquivo com os seus contatos foi criado com sucesso!\n\n");  
}

// Apaga o contato da lista de contatos
void apagarContato(){

    int i;
    int rec;
    long telefone;

    printf("Digite o nome do telefone a ser apagado:\n: ");
    telefone = lerlongInt();

    for (i = 0 ; i < 32; i++) {
        if (tabela[i].telefone == telefone) {
            tabela[i].telefone = 0;
            rec = i;
        }
    }

    if (tabela[rec].telefone == 0) {
            printf("\nContato apagado com sucesso!\n\n");
        }
    else {
        printf("\nContato nao existe!\n\n");
    }
}

// Função principal, implementação
int main() {

    Contato *contato;
    Contato dados;
    int sair = 0;
    int opcao;
    for (int i = 0; i < SIZE; i++) {
        tabela[i].telefone = 0;
    }

    while (sair != 6) {
        printf("\n--------CONTATOS--------\n\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato\n");
        printf("4 - Exportar contato\n");
        printf("5 - Excluir contato\n");
        printf("6 - Sair do programa\n\n");
        printf("Digite uma opcao:\n: ");
        opcao = lerInt();
        switch (opcao) {
            case 1:
                inserirContato();
                break;
            case 2: 
                listarContatos();
                break;
            case 3:
                buscarContato();
                break;
            case 4:
                exportarContatos();
                break;
            case 5:
                apagarContato();
                break;
            case 6:
                printf("\nObrigado por usar nosso programa!\n\n");
                exit(1);
                break;
            default:
                printf("\nOpcao invalida\n");
        }
    }
    return 0;
}
