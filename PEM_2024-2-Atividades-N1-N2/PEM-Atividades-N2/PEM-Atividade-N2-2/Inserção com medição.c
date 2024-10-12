/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Ordenação por inserção com objetivo de mostrar tempo de execução, quantidade de trocas e ciclos*
*                                                              *
* Data: 11/10/2024                                             * 
* Autor: Ryan Almeida Silva                                    *
*--------------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ordena um array usando o algoritmo de ordenação por inserção
void ordenacaoInsercao(int numeros[], int quantidade, int *trocas, int *ciclos) {
    int i, elemento, posicao;
    for (i = 1; i < quantidade; i++) {
        elemento = numeros[i]; // Elemento a ser inserido
        posicao = i - 1;
        // Move elementos maiores para a direita
        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
            (*trocas) += 1;
        }
        numeros[posicao + 1] = elemento; // Insere o elemento na posição correta
	(*ciclos) += 1;
    }
}

// Imprime o array
void imprimirArray(int numeros[], int quantidade) {
    for (int i = 0; i < quantidade; i++)
        printf("%d ", numeros[i]);
    printf("\n");
}

int main() {
    int trocas = 0;
    int ciclos = 0;
    int numeros[] = {5, 3, 8, 4, 2,
        115, 113, 118, 114, 112,
        125, 123, 128, 124, 122,
        35, 33, 38, 34, 32,
        45, 43, 48, 44, 42,
        55, 53, 58, 54, 52,
        65, 63, 68, 64, 62,
        75, 73, 78, 74, 72,
        85, 83, 88, 84, 82,
        95, 93, 98, 94, 92,
        15, 13, 18, 14, 12,
        25, 23, 28, 24, 22
       
    };
    int quantidadeNumeros = sizeof(numeros) / sizeof(int);

    printf("Array original: \n");
    imprimirArray(numeros, quantidadeNumeros);
    
    clock_t start = clock();
    
    ordenacaoInsercao(numeros, quantidadeNumeros, &trocas, &ciclos); // Ordena o array
    
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Array ordenado: \n");
    imprimirArray(numeros, quantidadeNumeros);

    printf("\nTempo de execução: %f segundos\n", cpu_time_used);
    printf("\nQuantidade de trocas: %d\n", trocas);
    printf("\nQuantidade de ciclos: %d\n", ciclos);
     
    return 0;
}
