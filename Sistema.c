#include <stdio.h>

// Função para calcular o lucro total
float calcular_lucro_total(float gastos_fixos, float precos_venda[], int quantidades[], int total_produtos) {
    float lucro_total = 0.0;
    for (int i = 0; i < total_produtos; i++) {
        lucro_total += (precos_venda[i] * quantidades[i]) - gastos_fixos;
    }
    return lucro_total;
}

// Função para calcular gastos fixos e variáveis e solicitar lucros
void calcular_gastos_fixos_variaveis_lucros() {
    float agua, energia, telefone, internet, aluguel, total_gastos_fixos = 0, preco_adicional;
    float precos_venda[100];
    char adicional[50];
    int adicionar_custo_ou_nao;
    int total_produtos;
    int quantidades[100];

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

    printf("\nTotal de gastos R$: %.2f\n", total_gastos_fixos);

    // Solicitar a adição de mais custos
    printf("\nDeseja adicionar outro custo?\nDigite (1) para adicionar ou (2) para prosseguir:\n");
    scanf("%d", &adicionar_custo_ou_nao);

    while (adicionar_custo_ou_nao == 1) {
        printf("Qual o nome do custo adicional? (digite 1 palavra): ");
        scanf("%s", adicional);
        printf("Qual o custo de %s?: ", adicional);
        scanf("%f", &preco_adicional);

        total_gastos_fixos += preco_adicional;

        printf("\nDeseja adicionar outro custo?\nDigite (1) para adicionar ou (2) para prosseguir:\n");
        scanf("%d", &adicionar_custo_ou_nao);
    }

    int numFuncionarios;
    //quantos funcionarios tem a empresa
    printf("Quantos funcionários a empresa possui?(inclui você proprio): ");
    scanf("%d", &numFuncionarios);
//solicita o numero de salarios da empresa
    float salarios[numFuncionarios];
    
    float somaSalarios = 0.0;
//soma de cada salario
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Digite o salário do funcionário %d: ", i + 1);
        scanf("%f", &salarios[i]);
        somaSalarios += salarios[i];
        // Acumula o salário na soma total
    }

    printf("\nSalários dos funcionários:\n");
    //repetição da digitação de salarios
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Funcionário %d: R$%.2f\n", i + 1, salarios[i]);
    }
//impressão da soma
    printf("\nSoma de todos os salários: R$%.2f\n", somaSalarios);
      //Soma dos Salarios com gastos fixos
  total_gastos_fixos = total_gastos_fixos + somaSalarios;
  printf("total de gastos até agora é de %.2f\n", total_gastos_fixos);

    printf("\nQuantos produtos diferentes voce tem?: ");
    scanf("%d", &total_produtos);

    // Solicitar informações sobre os produtos
    for (int i = 0; i < total_produtos; i++) {
        printf("\nQual o preco de venda do produto %d?: ", i + 1);
        scanf("%f", &precos_venda[i]);
        printf("Qual a quantidade vendida do produto %d?: ", i + 1);
        scanf("%d", &quantidades[i]);
    }

    // Calcular o lucro total
    float lucro_total = calcular_lucro_total(total_gastos_fixos, precos_venda, quantidades, total_produtos);

    // Exibir o lucro total
    printf("\nTotal lucro obtido R$: %.2f\n", lucro_total);

    // Exibir mensagem de balanço
    if (lucro_total - total_gastos_fixos < 0) {
        printf("\nAtencao: O balanco final e negativo.\n");
    } else {
        printf("\nBalanco final: R$ %.2f\n", lucro_total - total_gastos_fixos);
    }
}

int main() {
    calcular_gastos_fixos_variaveis_lucros();
    return 0;
}
