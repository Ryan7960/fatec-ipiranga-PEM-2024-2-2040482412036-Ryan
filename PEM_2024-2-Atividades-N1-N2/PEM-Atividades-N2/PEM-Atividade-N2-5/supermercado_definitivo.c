/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: PONTEIROS                              *
*                                                              *
* Data: 06/11/2024                                             * 
* Autor: Letícia Sudan Gauy, Fernando Palmieri e Ryan Almeida  *
*--------------------------------------------------------------*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXPRODUTOS 500

struct Produto {
    int id;
    char nomeProduto[50];
    int quantidadeEstoque;
    float valorProduto;
};

void exibirProduto(struct Produto* ponteiroProdutos, int i) {
    printf("\nID do produto: %d\n", (ponteiroProdutos + i)->id);
    printf("Nome do produto: %s\n", (ponteiroProdutos + i)->nomeProduto);
    printf("Quantidade do produto: %d\n", (ponteiroProdutos + i)->quantidadeEstoque);
    printf("Valor do produto: %.2f\n", (ponteiroProdutos + i)->valorProduto);
}

void incluirProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos, int* ponteiroProdutosExcluidos) {
    
    //ID automatico
    (ponteiroProdutos + *ponteiroContadorProdutos)->id = *ponteiroContadorProdutos+(*ponteiroProdutosExcluidos+1);
    
    printf("Insira o nome do produto: \n");
    scanf("%49s", (ponteiroProdutos + *ponteiroContadorProdutos)->nomeProduto);
    printf("Insira a quantidade no estoque desse produto: \n");
    while (scanf("%i", &(ponteiroProdutos + *ponteiroContadorProdutos)->quantidadeEstoque) != 1) {
       printf("Erro: valor inválido! Por favor, insira um número.\n");
        // Limpar o buffer caso uma entrada inválida seja inserida
        while (getchar() != '\n');
    } 
     printf("Informe o valor do produto: \n");
    while (scanf("%f", &(ponteiroProdutos + *ponteiroContadorProdutos)->valorProduto) != 1) {
        printf("Erro: valor inválido! Por favor, insira um número.\n");
        // Limpar o buffer caso uma entrada inválida seja inserida
        while (getchar() != '\n');
    }

    printf("O produto adicionado foi : %s\n", (ponteiroProdutos + *ponteiroContadorProdutos)->nomeProduto);
    printf("O ID do produto atual : %d\n", (ponteiroProdutos + *ponteiroContadorProdutos)->id);
    printf("O valor do produto atual : R$ %.2f\n", (ponteiroProdutos + *ponteiroContadorProdutos) -> valorProduto);
    printf("A quantidade em estoque: %d\n", (ponteiroProdutos + *ponteiroContadorProdutos) -> quantidadeEstoque);
    printf("--------------------------------------");
    
    *ponteiroContadorProdutos = *ponteiroContadorProdutos+1;
}

void consultarProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos){
    
    int busca;
    
    printf("Informe o ID do produto que voce deseja consultar: ");
    scanf("%i", &busca);
    
    for(int i = 0; i < *ponteiroContadorProdutos; i++){
        if(busca == (ponteiroProdutos + i)->id){
            exibirProduto(ponteiroProdutos, i);
            printf("----------------------------------");
            return;
        }
    }
    printf("Produto inexistente\n");
    printf("----------------------------------");
    return;
}

void listarProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos){
    printf("\nLista de todos os produtos:\n");
    for (int i= 0; i < *ponteiroContadorProdutos;i ++){
        exibirProduto(ponteiroProdutos, i);
    }
}

void alterarProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos){
    int busca;
    
    printf("Informe o ID do produto que voce deseja alterar: ");
    scanf("%i", &busca);
    
    for(int i = 0; i < *ponteiroContadorProdutos; i++){
        if(busca == (ponteiroProdutos + i)->id){
            printf("Esse e o produto correspondente: ");
            exibirProduto(ponteiroProdutos, i);
            
            printf("Insira o novo nome do produto: ");
            scanf("%s", (ponteiroProdutos + i)->nomeProduto);
            printf("Insira a nova quantidade no estoque desse produto: ");
            scanf("%i", &(ponteiroProdutos + i)->quantidadeEstoque);
            printf("Informe o novo valor do produto: ");
            scanf("%f", &(ponteiroProdutos + i)->valorProduto);
            printf("----------------------------------");
            return;
        }
    }
    printf("Produto inexistente\n");
    printf("----------------------------------");
    return;
}
void mudarProdutos(struct Produto *ponteiroProdutos, int i)
{
    int intTemporario;
    float fltTemporario;
    char stringTemporaria[50];
    
    strcpy(stringTemporaria, (ponteiroProdutos + i)->nomeProduto);
    strcpy((ponteiroProdutos + i)->nomeProduto, (ponteiroProdutos + i+1)->nomeProduto);
    strcpy((ponteiroProdutos + i+1)->nomeProduto, stringTemporaria);
    
    fltTemporario = (ponteiroProdutos + i)->valorProduto;
    (ponteiroProdutos + i)->valorProduto = (ponteiroProdutos + i+1)->valorProduto;
    (ponteiroProdutos + i+1)->valorProduto = fltTemporario;
    
    intTemporario = (ponteiroProdutos + i)->quantidadeEstoque;
    (ponteiroProdutos + i)->quantidadeEstoque = (ponteiroProdutos + i+1)->quantidadeEstoque;
    (ponteiroProdutos + i+1)->quantidadeEstoque = intTemporario;
    
    intTemporario = (ponteiroProdutos + i)->id;
    (ponteiroProdutos + i)->id = (ponteiroProdutos + i+1)->id;
    (ponteiroProdutos + i+1)->id = intTemporario;
    
    return;
}

void excluirProduto(struct Produto* ponteiroProdutos, int* ponteiroContadorProdutos, int *ponteiroProdutosExcluidos){
    
    int busca,resposta;
    
    printf("Informe o ID do produto que voce deseja excluir: ");
    scanf("%i", &busca);
    
    
    for(int i = 0; i < *ponteiroContadorProdutos; i++){
        if(busca == (ponteiroProdutos + i)->id){
            exibirProduto(ponteiroProdutos, i);
        printf("Deseja mesmo excluir este registro? ('1') para excluir ('2') para manter\n");
        scanf("%i",&resposta);
        if (resposta == 1){
            (ponteiroProdutos + i)->id = 0;
            strcpy((ponteiroProdutos + i)->nomeProduto, " ");
            (ponteiroProdutos + i)->quantidadeEstoque = 0;
            (ponteiroProdutos + i)->valorProduto = 0;
            for (int i = 0; i < *ponteiroContadorProdutos - 1; i++) {
            mudarProdutos(ponteiroProdutos, i);
            }
            *ponteiroContadorProdutos = *ponteiroContadorProdutos - 1;
            *ponteiroProdutosExcluidos = *ponteiroProdutosExcluidos+1;
            printf("Registro exluido com sucesso!\n");
            printf("----------------------------------");
            return;
            }
        } 
    }
    printf("Produto inexistente\n");
    printf("----------------------------------");
    return;
}



int main() {
    struct Produto produtos[MAXPRODUTOS];
    struct Produto* ponteiroProdutos = produtos;
    int contador, produtosExcluidos;
    int* ponteiroContadorProdutos = &contador;
    int opcao;
    int *ponteiroProdutosExcluidos = &produtosExcluidos;
    
    
    
    
    do{
        printf("\nBEM-VINDO(A) AO SUPERMERCADO VERISSIMO\n");
        printf("Digite 1 para Incluir um produto\n");
        printf("Digite 2 para Consultar um produto\n");
        printf("Digite 3 para Listar todos os produtos\n");
        printf("Digite 4 Alterar um produto\n");
        printf("Digite 5 para Excluir um produto\n");
        printf("Digite 6 para Finalizar o programa\n");
        scanf("%i", &opcao);
        
        
        switch (opcao) {
        case 1:
            incluirProduto(ponteiroProdutos, ponteiroContadorProdutos, ponteiroProdutosExcluidos);
            break;
        case 2:
            consultarProduto(ponteiroProdutos, ponteiroContadorProdutos);
            break;
        case 3:
        // listar os produtos
            listarProduto(ponteiroProdutos, ponteiroContadorProdutos);
            break;
        case 4:
        // alterar
        alterarProduto(ponteiroProdutos, ponteiroContadorProdutos);
            break;
        case 5:
        //excluir
        excluirProduto(ponteiroProdutos, ponteiroContadorProdutos, ponteiroProdutosExcluidos);
            break;
        case 6:
        //finalizar
        return 0;
        }
    }while(opcao != 6);

    return 0;
}
