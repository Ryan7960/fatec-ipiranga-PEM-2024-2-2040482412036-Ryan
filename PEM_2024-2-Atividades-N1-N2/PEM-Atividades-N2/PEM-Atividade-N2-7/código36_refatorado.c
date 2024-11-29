/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: CRUD de produtos refatorado (Código 36)*
*                                                              *
* Data: 28/11/2024                                             * 
* Autor:  Ryan Almeida Silva                                   *
*--------------------------------------------------------------*/

// Bibliotecas necessárias para o funcionamento do programa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição de constantes

#define MAXPRODUTOS 500 
#define CARACTERES 100 
#define INICIO 0 

// Variável global para auxiliar na limpeza do buffer
int ch;

// Estrutura para representar um produto no sistema
struct produto {
    int codigo;             
    char nome[CARACTERES];  
    int quantidade;         
    float preco;            
};

// Protótipos de funções para organização do código
void alterarProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos);
void venderProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos);
int checarCodigoValido(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int codVenda);
void consultarProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos);
int confirmarResposta();
void excluirProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int *ponteiroProdutosExcluidos);
void executarPrograma();
void incluirProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int *ponteiroProdutosExcluidos);
void listarProdutos(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int inicio);
int menuOpcoes();
void mudarProdutos(struct produto *ponteiroProdutos, int i);

// Função principal
int main() {
    executarPrograma();
    return 0;
}

// Função que encapsula o loop principal do programa
void executarPrograma(){
    
    // Declaração de variáveis
    int loop = 0, numeroDeProdutos, produtosExcluidos;
    int *ponteiroNumeroDeProdutos = &numeroDeProdutos;         
    int *ponteiroProdutosExcluidos = &produtosExcluidos;       
    struct produto produtos[MAXPRODUTOS];                     
    struct produto *ponteiroProdutos = produtos;               

    // Loop principal do programa
    while (loop == 0) {
        switch (menuOpcoes()) {
            case 0: // Encerra o programa
                printf("Obrigado por utilizar nosso programa!\n");
                fflush(stdin);
                return;
            case 1: // Adiciona um novo produto
                if (numeroDeProdutos == MAXPRODUTOS) {
                    printf("Não é possível cadastrar mais produtos no momento!\n");
                    printf("Exclua um produto e tente novamente!\n");
                    break;
                }
                incluirProduto(ponteiroProdutos, ponteiroNumeroDeProdutos, ponteiroProdutosExcluidos);
                break;
            case 2: // Altera informações de um produto existente
                alterarProduto(ponteiroProdutos, ponteiroNumeroDeProdutos);
                break;
            case 3: // Exclui um produto da lista
                excluirProduto(ponteiroProdutos, ponteiroNumeroDeProdutos, ponteiroProdutosExcluidos);
                break;
            case 4: // Simula uma venda de produto
                venderProduto(ponteiroProdutos, ponteiroNumeroDeProdutos);
                break;
            case 5: // Consulta detalhes de um produto específico
                consultarProduto(ponteiroProdutos, ponteiroNumeroDeProdutos);
                break;
            case 6: // Lista todos os produtos cadastrados
                listarProdutos(ponteiroProdutos, ponteiroNumeroDeProdutos, INICIO);
                break;
        }
    }
}

// Função que exibe o menu de opções e retorna a escolha do usuário
int menuOpcoes()
{
    int resposta;  // Variável para armazenar a resposta do usuário
    
    // Exibe as opções do menu para o usuário
    printf("\nO que deseja fazer?\n");
    printf("0 - Finalizar venda\n");
    printf("1 - Incluir um produto\n");
    printf("2 - Alterar um produto\n");
    printf("3 - Excluir um produto\n");
    printf("4 - Vender um produto\n");
    printf("5 - Consultar um produto\n");
    printf("6 - Ver lista de produtos\n");
    printf("\nDigite aqui a opção desejada:");
    
    // Lê a resposta do usuário
    scanf("%i", &resposta);
    
    // Limpa o buffer do teclado, garantindo que a entrada do usuário seja válida
    while((ch = getchar()) != '\n' && ch != EOF);
    
    // Verifica se a resposta está dentro do intervalo válido de opções
    if(resposta < 0 || resposta > 6)
    {
        // Se a resposta for inválida, exibe uma mensagem de erro
        printf("Resposta inválida!\n");
        printf("Digite o numero ao lado da ação que deseja tomar\n");
        
        // Chama novamente a função para mostrar o menu e obter uma resposta válida
        menuOpcoes();
    }
    else
    {
        // Se a resposta for válida, retorna o valor escolhido
        return resposta;
    }
}

// Função para adicionar um novo produto ao sistema
void incluirProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int *ponteiroProdutosExcluidos) {
    
    // Gera um código único para o produto
    (ponteiroProdutos + *ponteiroNumeroDeProdutos)->codigo = *ponteiroNumeroDeProdutos + (*ponteiroProdutosExcluidos + 1);
    
    // Looping para a defnição do nome
    while (1) {
        printf("\nQual o nome do produto %i?\n", *ponteiroNumeroDeProdutos + 1);
        fgets((ponteiroProdutos + *ponteiroNumeroDeProdutos)->nome, 100, stdin);
        if ((ponteiroProdutos + *ponteiroNumeroDeProdutos)->nome[0] == '\0' || strspn((ponteiroProdutos + *ponteiroNumeroDeProdutos)->nome, " \n") == strlen((ponteiroProdutos + *ponteiroNumeroDeProdutos)->nome)) {
            printf("O nome do produto não pode estar vazio!\n");
        } else {
            break; // Nome válido, sai do loop
        }
    }
    
    // Pergunta o preço até que seja válido
    while (1) {
    printf("Qual o preço desse produto?\n");
        if (scanf("%f", &(ponteiroProdutos + *ponteiroNumeroDeProdutos)->preco) != 1 || (ponteiroProdutos + *ponteiroNumeroDeProdutos)->preco < 0) {
        while((ch = getchar()) != '\n' && ch != EOF);
        printf("Preço inválido! O preço deve ser um igual a zero ou positivo. Tente novamente.\n");
    } else {
        break;
        }
    }
    
    while (1) {
    printf("Qual a quantidade desse produto?\n");
    // Verifica se o preço inserido é válido e positivo
    if (scanf("%d", &(ponteiroProdutos + *ponteiroNumeroDeProdutos)->quantidade) != 1 || (ponteiroProdutos + *ponteiroNumeroDeProdutos)->quantidade <= 0) {
        while((ch = getchar()) != '\n' && ch != EOF); // Limpa o buffer
        printf("Quantidade inválida! O quantidade deve ser um número positivo maior do que zero. Tente novamente.\n");
    } else {
        break; // Quantidade válida, sai do loop
    }
}
    
    // Solicita confirmação do usuário antes de salvar o produto
    printf("Deseja confirmar a inclusão do produto?\n");
    printf("ID: %i\n",(ponteiroProdutos + *ponteiroNumeroDeProdutos)->codigo);
    printf("Nome: %s", (ponteiroProdutos + *ponteiroNumeroDeProdutos)->nome);
    printf("Preço: %.2f\n", (ponteiroProdutos + *ponteiroNumeroDeProdutos)->preco);
    printf("Quantidade: %i", (ponteiroProdutos + *ponteiroNumeroDeProdutos)->quantidade);

    if (confirmarResposta() == 0) {
        printf("Inclusão de produto cancelada.\n");
        return;
    }
    
    (*ponteiroNumeroDeProdutos)++; // Incrementa o número de produtos
}

// Função para alterar informações de um produto existente
void alterarProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos) {
    int codVenda, resposta, i;

    // Solicita ao usuário o código do produto que deseja alterar
    printf("Digite o codigo do produto que deseja alterar: ");
    scanf("%i", &codVenda);

    // Verifica se o código informado é válido chamando a função checarCodigoValido
    if (checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda) < 0) {
        return;
    }

    // Se o código for válido, obtém o índice do produto na lista de produtos
    i = checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda);

    retorno:
    // Exibe as opções de alteração para o produto selecionado
    printf("\nO que deseja alterar no produto %s?\n", (ponteiroProdutos + i)->nome);
    printf("0 - Encerrar alterações\n");
    printf("1 - Alterar nome\n");
    printf("2 - Alterar preço\n");
    printf("3 - Alterar quantidade em estoque\n");
    printf("Digite a opção escolhida:");
    scanf("%i", &resposta);

    // Limpa o buffer após o scanf
    while (getchar() != '\n'); // Limpa o buffer de entrada

    // Processa a escolha do usuário usando um switch
    switch (resposta) {
        case 0: // Encerra as alterações
            return;
            break;
        case 1: // Alteração do nome do produto
        {
            char novoNome[CARACTERES];
            while (1) {
                printf("Qual nome deseja colocar?\n");
                printf("(Nome atual: '%s')\n", (ponteiroProdutos + i)->nome);
                fgets(novoNome, sizeof(novoNome), stdin);

                // Verifica se o nome é válido
                if (novoNome[0] == '\0' || strspn(novoNome, " \n") == strlen(novoNome)) {
                    printf("O nome do produto não pode estar vazio! Tente novamente.\n");
                } else {
                    // Remove o '\n' da string, se houver
                    size_t len = strlen(novoNome);
                    if (novoNome[len - 1] == '\n') {
                        novoNome[len - 1] = '\0';
                    }
                    strcpy((ponteiroProdutos + i)->nome, novoNome);
                    break;
                }
            }
            break;
        }
        case 2: // Alteração do preço do produto
        {
            float novoPreco;
            while (1) {
                printf("Qual preço deseja colocar?\n");
                printf("(Preço atual: '%.2f')\n", (ponteiroProdutos + i)->preco);
                if (scanf("%f", &novoPreco) != 1 || novoPreco < 0) {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Preço inválido! O preço deve ser um número positivo. Tente novamente.\n");
                } else {
                    (ponteiroProdutos + i)->preco = novoPreco;
                    break;
                }
            }
            break;
        }
        case 3: // Alteração da quantidade em estoque
        {
            int novaQuantidade;
            while (1) {
                printf("Qual quantidade deseja colocar?\n");
                printf("(Quantidade atual: '%i')\n", (ponteiroProdutos + i)->quantidade);
                if (scanf("%i", &novaQuantidade) != 1 || novaQuantidade < 0) {
                    while (getchar() != '\n'); // Limpa o buffer
                    printf("Quantidade inválida! A quantidade deve ser um número positivo ou zero. Tente novamente.\n");
                } else {
                    (ponteiroProdutos + i)->quantidade = novaQuantidade;
                    break;
                }
            }
            break;
        }
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    // Pergunta ao usuário se deseja continuar alterando o mesmo produto
    printf("Deseja alterar mais algo nesse produto?\n");

    // Chama a função confirmarResposta para obter a confirmação do usuário
    if (confirmarResposta() == 0) {
        // Se o usuário escolher não, a função é encerrada
        return;
    } else {
        // Se o usuário escolher continuar, volta para o ponto "retorno"
        goto retorno;
    }
}


// Função para realizar a exclusão de um produto
void excluirProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int *ponteiroProdutosExcluidos)
{
    int codVenda, i;
    
    // Solicita ao usuário o código do produto que deseja excluir
    printf("Digite o codigo do produto que deseja excluir: ");
    scanf("%i",&codVenda);
    
    // Verifica se o código informado é válido; se não for, retorna da função    
    if(checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda)<0)
    {
        return;
    }
    
    // Recupera o índice do produto correspondente ao código informado    
    i = checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda);

    // Confirma com o usuário se realmente deseja excluir o produto    
    printf("Tem certeza que deseja excluir o produto %s?\n",(ponteiroProdutos + i)->nome);
    if(confirmarResposta() == 0)
    {
        return;
    }

    // "Remove" o produto apagando seus dados
    strcpy((ponteiroProdutos + i)->nome, " ");
    (ponteiroProdutos + i)->codigo = 0;
    (ponteiroProdutos + i)->preco = 0;
    (ponteiroProdutos + i)->quantidade = 0;
    
    // Ajusta os produtos restantes no array para ocupar o espaço do produto removido
    for(i=i;i<*ponteiroNumeroDeProdutos;i++)
    {
        mudarProdutos(ponteiroProdutos, i);
    }

    // Atualiza o número total de produtos e incrementa o contador de produtos excluídos
    *ponteiroNumeroDeProdutos = *ponteiroNumeroDeProdutos-1;
    *ponteiroProdutosExcluidos = *ponteiroProdutosExcluidos+1;
    
    // Notifica o usuário sobre o sucesso da exclusão
    printf("Produto excluído com sucesso!\n");
    return;
}

// Função para vender um produto
void venderProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos){
    int codVenda, quantidadeVenda, i;
    float precoVenda;
    
    // Solicita ao usuário o código do produto que deseja vender
    printf("Digite o codigo do produto que deseja vender: ");
    scanf("%i",&codVenda);

    // Verifica se o código informado é válido; se não for, retorna da função    
    if(checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda)<0){
        return;
    }
    
    // Recupera o índice do produto correspondente ao código informado    
    i = checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda);
    
    // Confirma com o usuário se realmente deseja vender o produto
    printf("Tem certeza que deseja vender o produto %s?\n",(ponteiroProdutos + i)->nome);
    if(confirmarResposta() == 0)
    {
        return;
    }

    // Solicita a quantidade desejada do produto e exibe o estoque disponível    
    printf("Quantos(as) '%s' deseja vender?\n",(ponteiroProdutos + i)->nome);
    printf("(Quantidade em estoque: %i)\n",(ponteiroProdutos + i)->quantidade);
    scanf("%i",&quantidadeVenda);

    // Verifica se a quantidade desejada está disponível no estoque
    if(quantidadeVenda > (ponteiroProdutos + i)->quantidade)
    {
        printf("Quantidade insuficiente em estoque\n");
        return;
    }
    
    // Verifica se a quantidade informada é válida (não pode ser menor que 1)
    if(quantidadeVenda < 1)
    {
        printf("Impossível vender menos de 1 unidade\n");
        return;
    }

    // Calcula o preço total da Venda
    precoVenda = (ponteiroProdutos + i)->preco*quantidadeVenda;
    
    // Confirma o valor total da Venda com o usuário
    printf("Deseja mesmo vender %i unidade(s) do produto '%s'?\n",quantidadeVenda, (ponteiroProdutos + i)->nome);
    printf("A Venda irá custar R$%.2f\n",precoVenda);
    if(confirmarResposta() == 0)
    {
        return; // Cancela a Venda caso o usuário não confirme
    }

    // Atualiza o estoque do produto subtraindo a quantidade Vendada
    (ponteiroProdutos + i)->quantidade = (ponteiroProdutos + i)->quantidade - quantidadeVenda;
    
    // Notifica o sucesso da Venda
    printf("Venda realizada com sucesso!\n");
    return;
}

// Função para consultar os detalhes de um produto específico
void consultarProduto(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos){
    int codVenda, i;
    int *ponteiroIndex = &i;

    // Solicita ao usuário o código do produto que deseja consultar
    printf("Digite o codigo do produto que deseja consultar: ");
    scanf("%i",&codVenda);

    // Verifica se o código informado é válido; se não for, retorna da função
    if(checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda)<0)
    {
        return;
    }

    // Recupera o índice do produto correspondente ao código informado
    i = checarCodigoValido(ponteiroProdutos, ponteiroNumeroDeProdutos, codVenda);

    // Incrementa o valor apontado pelo ponteiroIndex (não tem impacto prático nesse contexto)
    *ponteiroIndex = *ponteiroIndex+1;

    // Lista os detalhes do produto consultado
    listarProdutos(ponteiroProdutos, ponteiroIndex, i-1);
    
    return;
}

// Função para listar produtos a partir de um índice inicial
void listarProdutos(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int inicio)
{
    // Imprime o cabeçalho da tabela de produtos
    printf("\n----------------------------------------------------\n");
    printf("|                TABELA DE PRODUTOS                |\n");
    printf("----------------------------------------------------\n");
    printf("|  ID  |        NOME        |   PREÇO   |QUANTIDADE|\n");
    
    // Percorre a lista de produtos começando do índice 'inicio' até o número total de produtos
    for(int i=inicio;i<*ponteiroNumeroDeProdutos;i++)
    {
        // Remove o caractere de nova linha (\n) do final do nome do produto (se existir)
        (ponteiroProdutos + i)->nome[strcspn((ponteiroProdutos + i)->nome, "\n")] = '\0';
        
        // Imprime uma linha separadora para organização da tabela
        printf("----------------------------------------------------\n");
        
        // Imprime os detalhes de cada produto (ID, nome, preço, quantidade) formatados
        printf("|%-6i|%-20s|%11.2f|%10i|\n",(ponteiroProdutos + i)->codigo, (ponteiroProdutos + i)->nome, (ponteiroProdutos + i)->preco, (ponteiroProdutos + i)->quantidade);
    }

    // Imprime uma linha final para fechar a tabela
    printf("----------------------------------------------------\n"); 
    return;
}

// Função para trocar as posições de dois produtos adjacentes em uma lista
void mudarProdutos(struct produto *ponteiroProdutos, int i)
{
    int intTemporario;
    float fltTemporario;
    char stringTemporaria[CARACTERES];

    // Troca os nomes dos produtos
    strcpy(stringTemporaria, (ponteiroProdutos + i)->nome);
    strcpy((ponteiroProdutos + i)->nome, (ponteiroProdutos + i+1)->nome);
    strcpy((ponteiroProdutos + i+1)->nome, stringTemporaria);
    
    // Troca os preços dos produtos
    fltTemporario = (ponteiroProdutos + i)->preco;
    (ponteiroProdutos + i)->preco = (ponteiroProdutos + i+1)->preco;
    (ponteiroProdutos + i+1)->preco = fltTemporario;
    
    // Troca as quantidades dos produtos
    intTemporario = (ponteiroProdutos + i)->quantidade;
    (ponteiroProdutos + i)->quantidade = (ponteiroProdutos + i+1)->quantidade;
    (ponteiroProdutos + i+1)->quantidade = intTemporario;
    
    // Troca os códigos dos produtos
    intTemporario = (ponteiroProdutos + i)->codigo;
    (ponteiroProdutos + i)->codigo = (ponteiroProdutos + i+1)->codigo;
    (ponteiroProdutos + i+1)->codigo = intTemporario;
    
    return;
}

// Função para verificar se um código de produto é válido e retornar seu índice
int checarCodigoValido(struct produto *ponteiroProdutos, int *ponteiroNumeroDeProdutos, int codVenda)
{
    // Percorre a lista de produtos
    for(int i=0;i<*ponteiroNumeroDeProdutos;i++)
    {
        // Verifica se o código do produto atual é igual ao código fornecido
        if((ponteiroProdutos + i)->codigo == codVenda)
        {
            return i;
        }
    }

    // Caso o código não seja encontrado, exibe uma mensagem de erro
    printf("Produto inexistente ou código inválido\n");
    return -1;
}

// Função para solicitar e validar uma resposta do usuário
int confirmarResposta()
{
    int resposta; // Armazena a resposta do usuário
    
    // Exibe as opções disponíveis
    printf("\n0 - Não / 1 - Sim\n");
    printf("Digite a sua escolha:");
    scanf("%i",&resposta);

    // Verifica se a resposta está fora do intervalo válido
    if(resposta < 0 || resposta > 1)
    {
        printf("Resposta inválida!\n");
        printf("Digite o numero ao lado da opção que deseja\n");
        confirmarResposta();
    }
    return resposta; // Retorna a resposta válida do usuário
}