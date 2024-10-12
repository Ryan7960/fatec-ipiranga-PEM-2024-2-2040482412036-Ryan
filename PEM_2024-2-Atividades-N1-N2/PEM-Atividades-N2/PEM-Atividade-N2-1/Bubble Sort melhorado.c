/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Bubble Sort com código melhorado       *
* Data: 04/10/2024                                             * 
* Autor: Ryan Almeida Silva                                    *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h> // Biblioteca necessária para alocação dinâmica.

void bubbleSort(int arr[], int n) {
    int i, j, temp; 
    int verificacaoTroca; // Variável adicionada para verificar se houve troca.

    for (i = 0; i < n - 1; i++) {
        verificacaoTroca = 0; // Reinicia a verificação.

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; 
                verificacaoTroca = 1; // Indica que houve troca.
            }
        }

        if (verificacaoTroca == 0) { // Se não houve troca, já está ordenado.
            break;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]); 
        if (i < size - 1) {
            printf(", "); // Adiciona uma vírgula entre os números.
        }
    }
    printf("\n");
}

int main() {
    int n;
    int *arr; // Ponteiro para armazenar o array dinamicamente.

    // Solicitação do tamanho do array.
    printf("Quantos números você deseja digitar? ");
    scanf("%d", &n); // O usuário define o tamanho do array.
    
    // Verificação do tamanho do array.
    if (n <= 0) { // Verifica se o número é válido.
        printf("Número inválido. Deve ser maior que 0.\n");
        return 1; // Retorna erro.
    }

    // Aloca memória para o array de acordo com o tamanho especificado pelo usuário.
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) { // Verifica se a alocação foi bem-sucedida.
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Solicitação dos números.
    printf("Digite os números:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Lê os números.
    }

    printf("Array original:\n");
    printArray(arr, n); // Imprime o array original.

    bubbleSort(arr, n); // Ordena o array.

    printf("Array ordenado:\n");
    printArray(arr, n); // Imprime o array ordenado.

    // Libera a memória alocada dinamicamente.
    free(arr);

    return 0;
}
