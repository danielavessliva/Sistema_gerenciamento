#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_EXPENSES 100

typedef struct {
    char tipo[50];
    char nome[50];
    float custo;
    float preco_venda;
    int quantidade;
} Produto;

typedef struct {
    char descricao[50];
    float valor;
} Despesa;

Produto produtos[MAX_PRODUCTS];
int total_produtos = 0;
Despesa despesas[MAX_EXPENSES];
int total_despesas = 0;

void adicionar_produto() {
    if (total_produtos >= MAX_PRODUCTS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;
    printf("Digite o tipo do produto: ");
    scanf("%s", p.tipo);
    printf("Digite o nome do produto: ");
    scanf("%s", p.nome);
    printf("Digite o custo do produto: ");
    scanf("%f", &p.custo);
    printf("Digite o preco de venda do produto: ");
    scanf("%f", &p.preco_venda);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &p.quantidade);

    produtos[total_produtos] = p;
    total_produtos++;
}

void listar_produtos() {
    for (int i = 0; i < total_produtos; i++) {
        Produto p = produtos[i];
        printf("Produto %d:\n", i + 1);
        printf("Tipo: %s\n", p.tipo);
        printf("Nome: %s\n", p.nome);
        printf("Custo: %.2f\n", p.custo);
        printf("Preco de Venda: %.2f\n", p.preco_venda);
        printf("Quantidade: %d\n", p.quantidade);
    }
}

void excluir_produto(int index) {
    if (index < 0 || index >= total_produtos) {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = index; i < total_produtos - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    total_produtos--;
}

void adicionar_despesa() {
    if (total_despesas >= MAX_EXPENSES) {
        printf("Limite de despesas atingido!\n");
        return;
    }

    Despesa d;
    printf("Digite a descricao da despesa: ");
    scanf("%s", d.descricao);
    printf("Digite o valor da despesa: ");
    scanf("%f", &d.valor);

    despesas[total_despesas] = d;
    total_despesas++;
}

void listar_despesas() {
    for (int i = 0; i < total_despesas; i++) {
        Despesa d = despesas[i];
        printf("Despesa %d:\n", i + 1);
        printf("Descricao: %s\n", d.descricao);
        printf("Valor: %.2f\n", d.valor);
    }
}

float calcular_custo_total() {
    float total_custo = 0.0;
    for (int i = 0; i < total_produtos; i++) {
        total_custo += produtos[i].custo * produtos[i].quantidade;
    }
    return total_custo;
}

float calcular_despesas_totais() {
    float total_despesas_valor = 0.0;
    for (int i = 0; i < total_despesas; i++) {
        total_despesas_valor += despesas[i].valor;
    }
    return total_despesas_valor;
}

float calcular_lucro_total() {
    float lucro_total = 0.0;
    for (int i = 0; i < total_produtos; i++) {
        lucro_total += (produtos[i].preco_venda - produtos[i].custo) * produtos[i].quantidade;
    }
    lucro_total -= calcular_despesas_totais();
    return lucro_total;
}

void exibir_relatorio() {
    printf("Relatorio Financeiro:\n");
    printf("Custo Total dos Produtos: %.2f\n", calcular_custo_total());
    printf("Despesas Totais: %.2f\n", calcular_despesas_totais());
    printf("Lucro Total: %.2f\n", calcular_lucro_total());
    listar_produtos();
    listar_despesas();
}

void calcular_gastos_fixos_variaveis() {
    float agua, energia, telefone, internet, aluguel, total_gastos_fixos = 0, preco_adicional;
    char adicional[50];
    int adicionar_custo_ou_nao;

    printf("AGORA VAMOS CALCULAR SEUS GASTOS FIXOS E VARIAVEIS\n\n");
    printf("Qual o custo de sua agua?: ");
    scanf("%f", &agua);
    printf("Qual o custo de sua energia?: ");
    scanf("%f", &energia);
    printf("Qual o custo do seu telefone?: ");
    scanf("%f", &telefone);
    printf("Qual o custo da sua internet?: ");
    scanf("%f", &internet);
    printf("Qual o custo do seu aluguel?: ");
    scanf("%f", &aluguel);

    total_gastos_fixos = agua + energia + telefone + internet + aluguel;

    printf("\nDeseja adicionar outro custo?\nDigite (1) para adicionar ou (2) para prosseguir:\n");
    scanf("%d", &adicionar_custo_ou_nao);

    while(adicionar_custo_ou_nao == 1) {
        printf("Qual o nome do custo adicional?(digite 1 palavra): ");
        scanf("%s", adicional);
        printf("Qual o custo %s?: ", adicional);
        scanf("%f", &preco_adicional);

        total_gastos_fixos += preco_adicional;
        printf("\nDeseja adicionar outro custo?\nDigite (1) para adicionar ou (2) para prosseguir:\n");
        scanf("%d", &adicionar_custo_ou_nao);
    }

    printf("\n\nTotal de gastos fixos R$: %.2f\n", total_gastos_fixos);
}

int main() {
    int opcao;

    do {
        printf("\nSistema de Gestao Financeira\n");
        printf("1. Calcular Gastos Fixos e Variaveis\n");
        printf("2. Adicionar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Excluir Produto\n");
        printf("5. Adicionar Despesa\n");
        printf("6. Listar Despesas\n");
        printf("7. Exibir Relatorio Financeiro\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                calcular_gastos_fixos_variaveis();
                break;
            case 2:
                adicionar_produto();
                break;
            case 3:
                listar_produtos();
                break;
            case 4: {
                int index;
                printf("Digite o indice do produto a ser excluido: ");
                scanf("%d", &index);
                excluir_produto(index - 1);
                break;
            }
            case 5:
                adicionar_despesa();
                break;
            case 6:
                listar_despesas();
                break;
            case 7:
                exibir_relatorio();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
