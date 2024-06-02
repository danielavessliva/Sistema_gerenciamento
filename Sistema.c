#include <stdio.h>

main(){
	/*Olá vamos começar nosso projeto!!!*/
	
	/*Criando a parte de gastor fixos e variáveis*/
	
	float agua, energia, telefone, internet, aluguel, total_gastos_fixos, preco_adicional;
	char adicional[20]= "";
	int adicionar_custo_ou_nao;
	int i=0;
	
	printf("Qual o custo de sua água?: \n"); scanf("%f", &agua);
	printf("Qual o custo de sua energia?: \n"); scanf("%f", &energia);
	printf("Qual o custo do seu telefone?: \n");scanf("%f",&telefone);
	printf("Qual o custo da sua internet?: \n");scanf("%f", &internet);
	printf("Qual o custo do seu aluguel?: \n");scanf("%f", &aluguel);
	
	/*Condição para saber se o usuário deseja adicionar mais itens*/
	printf("\nDeseja adicionar outro custo?\nDigite (1) para adicionar ou (2) para prosseguir:\n");
	scanf("%d", &adicionar_custo_ou_nao);
	adicionar_custo_ou_nao;
	total_gastos_fixos = agua + energia + telefone + internet + aluguel;
	while(adicionar_custo_ou_nao==1){
	if(adicionar_custo_ou_nao == 1){
	printf("Qual o nome do custo adicional?:\n");
	scanf("%s", &adicional);
	
	printf("Qual o custo %s?: \n", adicional);scanf("%f", &preco_adicional);
	total_gastos_fixos += preco_adicional;
	printf("\nDeseja adicionar outro custo?\nDigite (1) para adicionar ou (2) para prosseguir:\n");
	scanf("%d", &adicionar_custo_ou_nao);
	i++;
	}
	}		
	/* Calculando o total dos gastor fixos*/
	
	printf("\n\nTotal de gastos fixos R$:%.2f", total_gastos_fixos);


}
