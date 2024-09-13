/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo          *
*--------------------------------------------------------*
* Objetivo do Programa: Simular e Exibir um Xeque Pastor(Programa refatorado e modularizado*
* Data - 13/09/2024* 
* Autor: Ryan Almeida Silva*
*--------------------------------------------------------*/

#include <stdio.h>

// Criação da função responsável por imprimir o tabuleiro
// A função foi em void porquê não retorna valor nenhum
// O paramêtro dentro da função foram apenas o vetor bidimensional declarado dentro do "int main()"
void imprimirTabuleiro (char tabuleiroXadrez[8][8]) {
    
    // Laço que percorre e imprime as linhas do tabuleiro
    for (int i = 0; i < 8; i++) {
        
        // Laço que percorre e imprimi as colunas, colocando peças e locais vazios no tabuleiro
        for (int j = 0; j < 8; j++) { 
            printf("%c ", tabuleiroXadrez[i][j]);
            
        }
        printf("\n");
        
    }
    printf("\n");
    
}

// Criação da função responsável pelo movimento das peças e esvaziamento das casas
// A função foi em void porque não retorna valor
// Os paramêtros utilizados foram o tabuleiro de xadrez novamente
// Declaração de variáveis responsaveis por mostrar o movimento
void movimentoPeca (char tabuleiroXadrez[8][8], int linhaOrigem, int colunaOrigem, int linhaDestino,int colunaDestino){
    
    // A linha e coluna de destino deveem ter o mesmo valor que a linha e coluna de origem
    // passando assim os valores da origem para o destino
    tabuleiroXadrez[linhaDestino][colunaDestino] = tabuleiroXadrez[linhaOrigem][colunaOrigem];
    // Esvazia a casa que foi movida substituindo a peça por um '.' que significa que a casa está vazia
    tabuleiroXadrez[linhaOrigem][colunaOrigem] = '.';
}

int main() {

    // Declaração de um vetor bidimensional
    char tabuleiroXadrez[8][8] = {
        {'t', 'c', 'b', 'd', 'r', 'b', 'c', 't'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'T', 'C', 'B', 'D', 'R', 'B', 'C', 'T'}    };
    
        // Exibição do tabuleiro inicial chamando a função imprimirTabuleiro
        printf("Tabuleiro inicial\n");
        imprimirTabuleiro(tabuleiroXadrez);
        
        // A realização será feito pelas funções movimentoPeca e imprimirTabuleiro
        // Move Peão do Rei e2 para e4
        movimentoPeca(tabuleiroXadrez, 6, 4, 4, 4);
        printf("Após jogada #1 das Brancas (Peão do Rei e2 para e4):\n");
        imprimirTabuleiro(tabuleiroXadrez);
        
        // Move Peão do Rei e7 para e5
        movimentoPeca(tabuleiroXadrez, 1, 4, 3, 4);
        printf("Após jogada #1 das Pretas (Peão do Rei e7 para e5):\n");
        imprimirTabuleiro(tabuleiroXadrez);
        
        // Move Bispo do Rei f1 para c4
        movimentoPeca(tabuleiroXadrez, 7, 5, 4, 2);
        printf("Após jogada #2 das Brancas (Bispo do Rei f1 para c4):\n");
        imprimirTabuleiro(tabuleiroXadrez);
    
        // Move Cavalo da Dama b8 para c6
        movimentoPeca(tabuleiroXadrez, 0, 1, 2, 2);
        printf("Após jogada #2 das Pretas (Cavalo da Dama b8 para c6):\n");
        imprimirTabuleiro(tabuleiroXadrez);
        
        // Move Dama d1 para h5
        movimentoPeca(tabuleiroXadrez, 7, 3, 3, 7);
        printf("Após jogada #3 das Brancas (Dama d1 para h5):\n");
        imprimirTabuleiro(tabuleiroXadrez);
    
        // Move Cavalo do Rei g8 para f6
        movimentoPeca(tabuleiroXadrez, 0, 6, 2, 5);
        printf("Após jogada #3 das Pretas (Cavalo do Rei g8 para f6):\n");
        imprimirTabuleiro(tabuleiroXadrez);
        
        // Move Dama h5 captura Peão f7
        movimentoPeca(tabuleiroXadrez, 3, 7, 1, 5);
        printf("Após jogada #4 das Brancas (Dama h5 captura Peão f7 - Xeque Mate):\n");
        imprimirTabuleiro(tabuleiroXadrez);
        
        return 0;
}