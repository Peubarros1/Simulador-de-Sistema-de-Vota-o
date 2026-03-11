#include <stdio.h>

int main() {
    FILE *arquivo;
    
    // Abre o arquivo para escrita (modo "w")
    arquivo = fopen("votos.txt", "w");
    
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1; // Retorna 1 para indicar um erro
    }
    
    // Escreve no arquivo os votos(mude para qual desejar)
    fprintf(arquivo, "1");
   //Para uma lista, basta repetir a linha acima
    
    // Fecha o arquivo após a escrita
    fclose(arquivo);

    
    return 0; 
}
