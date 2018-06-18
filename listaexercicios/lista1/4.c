#include <stdio.h>
/* Faça um programa que leia o número do funcionário, o número de horas
trabalhadas mensais, o valor que recebe por hora e o número de filhos com
idade menor de 14 anos. Calcular e escrever o salário deste funcionário, sendo
que cada filho menor de 14 anos acrescenta 10% do salário.
*/

int main(){
	int nfun,nfilhos;
	float salhora,hmensais;
	printf("Informe o seu numero de indentificação: ");
	scanf("%i",&nfun);
	printf("Informe quantas horas voce trabalhou no mes: ");
	scanf("%f",&hmensais);
	printf("Informe quanto voce recebe por hora: ");
	scanf("%f",&salhora);
	printf("Informe quantos filhos tem com menos de 14 anos: ");
	scanf("%i",&nfilhos);
	printf("O funcionario %i, teve um salario de %.2f\n",nfun,((salhora * hmensais)*(1+(0.10 * nfilhos))));

}
