#include <stdio.h>

// Definindo a estrutura do Produto
typedef struct {
    char nome[50];
    double custo;
    double venda;
    double gastos;
} Produto;

// Função para calcular o lucro de um produto
double calcularLucro(Produto produto) {
    return produto.venda - produto.custo - produto.gastos;
}

// Função para listar todos os produtos com suas informações financeiras
void listarProdutos(Produto produtos[], int tamanho) {
    printf("Lista de Produtos e Informacoes Financeiras:\n");
    printf("%-15s %-10s %-10s %-10s %-10s\n", "Produto", "Custo", "Venda", "Gastos", "Lucro");

    for (int i = 0; i < tamanho; i++) {
        printf("%-15s %-10.2f %-10.2f %-10.2f %-10.2f\n", 
            produtos[i].nome, produtos[i].custo, produtos[i].venda, produtos[i].gastos, calcularLucro(produtos[i]));
    }
}

// Função para exibir o relatório financeiro
void exibirRelatorioFinanceiro(Produto produtos[], int tamanho) {
    double totalCusto = 300.0;
    double totalVenda = 500.0;
    double totalGastos = 180.0;
    double totalLucro = 40.0;

    for (int i = 0; i < tamanho; i++) {
        totalCusto += produtos[i].custo;
        totalVenda += produtos[i].venda;
        totalGastos += produtos[i].gastos;
        totalLucro += calcularLucro(produtos[i]);
    }

    printf("\nRelatorio Financeiro Atual:\n");
    printf("Total de Custos: %.2f\n", totalCusto);
    printf("Total de Vendas: %.2f\n", totalVenda);
    printf("Total de Gastos: %.2f\n", totalGastos);
    printf("Total de Lucros: %.2f\n", totalLucro);
}

int main() {
    Produto produtos[] = {
        {"ProdutoA", 20.0, 25.0, 5.0},
        {"ProdutoB", 20.0, 30.0, 5.0},
        {"ProdutoC", 5.0, 10.0, 1.0}
    };
    int tamanho = sizeof(produtos) / sizeof(produtos[0]);

    listarProdutos(produtos, tamanho);
    exibirRelatorioFinanceiro(produtos, tamanho);

    return 0;
}