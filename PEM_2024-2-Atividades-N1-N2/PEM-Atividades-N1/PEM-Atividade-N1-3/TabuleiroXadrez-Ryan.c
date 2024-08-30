/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Exibir um tabuleiro de xadrez*
* Data - 30/08/2024* 
* Autor: Ryan Almeida Silva*
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

int main() {
    
    char linha1[50], linha2[50], linha3[50], linha4[50], linha5[50], linha6[50], linha7[50], linha8[50];
    char linha[50], linhaletras[50];
    
    strcpy(linha1, "8 | PT1 PC2 PB3 PD4 PR5 PB6 PC7 PT8");
    strcpy(linha2, "7 | PP1 PP2 PP3 PP4 PP5 PP6 PP7 PP8");
    strcpy(linha3, "6 |  X   X   X   X   X   X   X   X ");
    strcpy(linha4, "5 |  X   X   X   X   X   X   X   X ");
    strcpy(linha5, "4 |  X   X   X   X   X   X   X   X ");
    strcpy(linha6, "3 |  X   X   X   X   X   X   X   X ");
    strcpy(linha7, "2 | BP1 BP2 BP3 BP4 BP5 BP6 BP7 BP8");
    strcpy(linha8, "1 | BT1 BC2 BB3 BD4 BR5 BB6 BC7 BT8");
    strcpy(linha, "  ---------------------------------");
    strcpy(linhaletras, "     a   b   c   d   e   f   g   h");
    
    printf("%s",linhaletras);
    printf("\n%s",linha);
    printf("\n%s",linha1);
    printf("\n%s",linha2);
    printf("\n%s",linha3);
    printf("\n%s",linha4);
    printf("\n%s",linha5);
    printf("\n%s",linha6);
    printf("\n%s",linha7);
    printf("\n%s",linha8);


    return (0);
}