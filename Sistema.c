#include <stdio.h>

main(){
	/*Olá vamos começar nosso projeto!!!*/
	
	/*Criando a parte de gastor fixos e variáveis*/
	
	float agua, energia, telefone, internet, aluguel, total_gastos_fixos;
	
	printf("Qual o custo de sua água?: \n"); scanf("%f", &agua);
	printf("Qual o custo de sua energia?: \n"); scanf("%f", &energia);
	printf("Qual o custo do seu telefone?: \n");scanf("%f",&telefone);
	printf("Qual o custo da sua internet?: \n");scanf("%f", &internet);
	printf("Qual o custo do seu aluguel?: \n\n");scanf("%f", &aluguel);
	
	/*Calculando o total dos gastor fixos*/
	total_gastos_fixos = agua + energia + telefone + internet + aluguel;
	printf("Total de gastos fixos R$:%.2f", total_gastos_fixos);
	
}
