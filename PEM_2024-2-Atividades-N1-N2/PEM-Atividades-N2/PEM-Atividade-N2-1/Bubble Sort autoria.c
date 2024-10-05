/*------------------------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                                 *
*          Prof. Carlos Veríssimo                                               *
*-------------------------------------------------------------------------------*
* Objetivo do Programa: Solicitar números e ordenar com o Bubble Sort 		* 
* Data: 04/09/2024                                                              * 
* Autor: Ryan Almeida Silva                                                     *
/*------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

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

// Função para inserir os números do usuário
int* inserirNum(int n) {
    int *array = (int *)malloc(n * sizeof(int)); // Aloca memória para o array dinâmico
    if (array == NULL) {
        printf("Erro ao alocar memória.\n"); // Verifica se a alocação de memória foi bem-sucedida
        exit(1); // Encerra o programa se a alocação de memória falhar
    }

// Solicita que o usuário que digite os números
    printf("Digite %d numeros (OBS: separados por espaço):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]); // Executa a leitura de cada número do usuário
    }
    return array; // Retorna o ponteiro para o array armazenando os elementos
}

// Função para realizar a ordenação Bubble Sort
void bubbleSort(int *array, int n) {
    int trocou; // Variável para verificar se houve troca

    for (int i = 0; i < n - 1; i++) { // Loop para cada elemento
        trocou = 0; // Inicializa a verificação de troca

        for (int j = 0; j < n - i - 1; j++) { // Loop para comparação e troca
            if (array[j] > array[j + 1]) { // Se o elemento atual for maior que o próximo
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
    int n;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &n); // Lê a quantidade de elementos que o usuário deseja inserir

    // Verifica se n é positivo
    if (n <= 0) {
        printf("Por favor, insira um numero positivo.\n"); // Mensagem de erro se n não for positivo
        return 1; // Encerra o programa
    }

    // Insere elementos e aloca memória para o array
    int *array = inserirNum(n); // Chama a função de alocação de memória e inserção de elementos

    // Exibe o array original
    printf("Array original: ");
    imprimirArray(array, n); // Imprime o array não ordenado

    // Classifica o array usando Bubble Sort
    bubbleSort(array, n); // Chama a função de ordenação

    // Exibe o array ordenado
    printf("Array ordenado: ");
    imprimirArray(array, n); // Imprime o array ordenado

    // Libera a memória alocada
    free(array); // Libera a memória do array dinâmico
    return 0;
}
