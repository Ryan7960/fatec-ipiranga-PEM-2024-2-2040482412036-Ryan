/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Calcular as notas de uma bateria de testes excluindo os extremos*
* Data - 23/08/2024* 
* Autor: Ryan Almeida Silva*
*--------------------------------------------------------*/

#include <stdio.h>

int main() {
    int NumCategorias, NumProvas, index, index2, index3;
    float MaiorNota, MenorNota, NotaFinalParcial, NotaMin, NotaMax, NotaFinalTotal, Soma;

    printf("Digite a quantidade de categorias: ");
    scanf("%d", &NumCategorias);

    NotaFinalTotal = 0.0;

    for (index = 0; index < NumCategorias; ++index) {
        printf("Digite a quantidade de provas: ");
        printf("OBS: Coloque um número de três ou mais provas\n");
        scanf("%d", &NumProvas);

        if (NumProvas < 3) {
            printf("Por favor, digite um número igual ou maior do que três provas para prosseguir\n");
            index--;
            continue;
        }

        float Notas[NumProvas];

        printf("Qual a maior nota possível de se tirar?\n");
        scanf("%f", &NotaMax);
        printf("Qual a menor nota possível de se tirar?\n");
        scanf("%f", &NotaMin);

        if (NotaMin > NotaMax) {
            printf("A menor nota não pode ser maior que a maior nota\n");
            index--;
            continue;
        }

        printf("Digite as notas das provas:\n");
        printf("Notas: ");

        for (index2 = 0; index2 < NumProvas; index2++) {
            while (1) {
                scanf("%f", &Notas[index2]);
                if (Notas[index2] > NotaMax || Notas[index2] < NotaMin) {
                    printf("As notas devem respeitar os limites colocados anteriormente!\n");
                } 
                else {
                    break;
                }
            }
        }

        MaiorNota = MenorNota = Notas[0];
        Soma = 0.0;

        for (index3 = 0; index3 < NumProvas; index3++) {
            if (Notas[index3] < MenorNota) MenorNota = Notas[index3];
            if (Notas[index3] > MaiorNota) MaiorNota = Notas[index3];
            Soma += Notas[index3];
        }

        NotaFinalParcial = Soma - MaiorNota - MenorNota;
        NotaFinalTotal += NotaFinalParcial;

        printf("Nota final da categoria: %.2f\n", NotaFinalParcial);
    }

    printf("A nota final geral de todas as categorias é %.2f\n", NotaFinalTotal);

    return 0;
}

