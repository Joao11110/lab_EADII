#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó em uma lista de adjacência
struct Node {
    int destino;
    struct Node* proximo;
};

// Estrutura para representar um grafo
struct Grafo {
    int num_vertices;
    struct Node** listaAdj;
};

// Função que cria um novo nó em uma lista de adjacência
struct Node* criarNode(int destino) {
    struct Node* novo_node = (struct Node*)malloc(sizeof(struct Node));
    novo_node->destino = destino;
    novo_node->proximo = NULL;
    return novo_node;
}

// Função para criar um grafo com um número específico de vértices
struct Grafo* criarGrafo(int num_vertices) {
    struct Grafo* grafo = (struct Grafo*)malloc(sizeof(struct Grafo));
    grafo->num_vertices = num_vertices;
    grafo->listaAdj = (struct Node**)malloc(num_vertices * sizeof(struct Node*));

    for (int i = 0; i < num_vertices; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}

// Função para adicionar uma aresta ao grafo
void criarAresta(struct Grafo* grafo, int origem, int destino) {

    // Adicione a aresta à lista de adjacência de ambos os vértices
    struct Node* novo_node = criarNode(destino);
    novo_node->proximo = grafo->listaAdj[origem];
    grafo->listaAdj[origem] = novo_node;

    novo_node = criarNode(origem);
    novo_node->proximo = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novo_node;
}

// Função para imprimir o grafo
void imprimirGrafo(struct Grafo* grafo) {
    printf("\n\n");
    for (int i = 0; i < grafo->num_vertices; i++) {
        struct Node* temp = grafo->listaAdj[i];
        printf("Vertice %d:", i);
        while (temp != NULL) {
            printf(" -> %d", temp->destino);
            temp = temp->proximo;
        }
        printf("\n");
    }
}

int main() {

    // Caminho do arquivo
    char *nome_arquivo = "/home/joao/BTI/3º SEMESTRE/LABORATÓRIO DE ESTRUTURA DE DADOS II/Projetos LD2/file.txt"; 

    // Arquivo é aberto
    FILE * arquivo = fopen(nome_arquivo, "r");

    // Verifica se o arquivo não foi aberto
    if (arquivo == NULL) {
        printf("\n\nErro ao abrir o arquivo!\n");
        exit(1);
    }

    // Arquivo foi aberto com sucesso
    else {
        printf("\n\nArquivo foi lido com sucesso!\n");
    }

    // Definição do número de vertices para criar grafo
    int num_vertices = 7;
    struct Grafo* meuGrafo = criarGrafo(num_vertices);

    // Os dados do arquivo são lidos
    int origem, destino;
    while (fscanf(arquivo, "%d, %d", &origem, &destino) == 2) {
        criarAresta(meuGrafo, origem, destino);
    }

    // Fecha o arquivo após sua leitura
    fclose(arquivo);  

    // Imprime o grafo com os dados do arquivo
    printf("\n\n------ Grafo ------\n");
    imprimirGrafo(meuGrafo);
    printf("\n\n-------------------\n");
    printf("\n\n");

    return 0;
}
