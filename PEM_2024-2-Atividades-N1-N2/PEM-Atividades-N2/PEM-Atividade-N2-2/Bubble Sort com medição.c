/*------------------------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                                 *
*          Prof. Carlos Veríssimo                                               *
*-------------------------------------------------------------------------------*
* Objetivo do Programa: Ordenar com o Bubble Sort com objetivo de mostrar tempo, quantidade de trocas e ciclos* 
* Data: 11/10/2024                                                              * 
* Autor: Ryan Almeida Silva                                                     *
/*------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para imprimir o array
void imprimirArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(", "); // Adiciona uma vírgula antes de imprimir o próximo número, exceto o primeiro.
        }
        printf("%d", array[i]); // Imprime o número atual
    }
    printf("\n");
}

// Função para realizar a ordenação Bubble Sort
void bubbleSort(int *array, int n, int *trocas, int *ciclos) {
    int trocou; // Variável para verificar se houve troca

    for (int i = 0; i < n - 1; i++) { // Loop para cada elemento
        (*ciclos) += 1;
        trocou = 0; // Inicializa a verificação de troca

        for (int j = 0; j < n - i - 1; j++) { // Loop para comparação e troca
            if (array[j] > array[j + 1]) { // Se o elemento atual for maior que o próximo
            (*trocas) += 1;
                // Troca os elementos
                int temp = array[j]; // Armazena o valor atual
                array[j] = array[j + 1]; // Troca com o próximo
                array[j + 1] = temp; // Finaliza a troca
                trocou = 1; // Define se houve uma troca
            }
        }
        // Se não houve troca, o array já está ordenado
        if (trocou == 0) {
            break; // Encerra o loop
        }
    }
}

// Função principal
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
    
    int quantidadeNumeros = sizeof(numeros) / sizeof(numeros[0]);
    
    // Exibe o array original
    printf("Array original: ");
    imprimirArray(numeros, quantidadeNumeros);

    clock_t start = clock();
    
    bubbleSort(numeros, quantidadeNumeros, &trocas, &ciclos); 
    
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Exibe o array ordenado
    printf("Array ordenado: ");
    imprimirArray(numeros, quantidadeNumeros); 

    printf("\nTempo de execução: %f segundos\n", cpu_time_used);
    printf("\nQuantidade de trocas: %d\n", trocas);
    printf("\nQuantidade de ciclos: %d\n", ciclos);
     
    return 0;
}
