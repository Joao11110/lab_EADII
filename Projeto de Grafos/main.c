#include <stdio.h>

int main(){

    // Colocar o caminho completo de onde o arquivo está
    char *nome_arquivo = "fb-pages-company.edges"; 

    // Arquivo é aberto
    FILE * arquivo = fopen(nome_arquivo, "r");

    // Verficação se não foi aberto
    if (arquivo == NULL) {
        printf("\n\nErro ao abrir o arquivo.\n");
        return 1;
    }

    // Arquivo foi aberto som sucesso
    else {
        printf("\n\nArquivo foi aberto.\n");
    }

    // Leitura dos dados do arquivo
    int vertice1, vertice2, contador = 0;
    while (fscanf(arquivo, "%d, %d", &vertice1, &vertice2) != EOF) {
        contador += 1; 
    }
    printf("\nQuantidade de linhas lidas: %d\n\n", contador);

    // Arquivo é fechado
    fclose(arquivo);

    return 0;
}
