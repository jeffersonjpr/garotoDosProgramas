/*
10) Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os
entrevistados: sexo, idade e quantidade de livros que leu no ano de 2010. Faça um programa
que leia os dados digitados pelo usuário, sendo que deverão ser solicitados dados até que a
idade digitada seja um valor negativo.
Depois, calcule e imprima:
1. A quantidade total de livros lidos pelos entrevistados menores de 10 anos.
2. A quantidade de mulheres que leram 5 livros ou mais.
3. A média de idade dos homens que leram menos que 5 livros.
4. O percentual de pessoas que não leram livros.

*/

#include <stdio.h>
int main(){
	int mdhct=0,sexo,idade=1,qtn_livro,tota10=0,totalmulher=0,regra = 0;
	float mdh = 0,ctpessoas=0,ctnotlivro=0;

	while(idade > 0){
		if(regra) printf("Voce digitou algum dado incorretamente !\n");

		printf("Digite a sua idade: ");
		scanf("%i",&idade);
		if(idade < 0) break;

		printf("Escolha o seu sexo, 1 para homem e 2 para mulher.");
		scanf("%i",&sexo);
		if(sexo != 1 && sexo != 2){
			regra=1;
			continue;
		}

		printf("Digite quantos livros voce leu em 2010: ");
		scanf("%i",&qtn_livro);
		if(qtn_livro < 0){
			regra=1;
			continue;
		}
		if(idade < 10) tota10 += qtn_livro; // livros lidos por ciranças com menos dd 10
		if(qtn_livro >= 5 && sexo == 2) totalmulher++; //total de mulheres que leram 5 livroso u mais
		if(sexo == 1 && qtn_livro < 5){ // amrz a qnt total de homens que leram menos de 5 livros e soma a idade deles
			mdhct++;
			mdh += idade;
		}
		if(qtn_livro == 0) ctnotlivro++;
		ctpessoas++;
	}
	printf("%i livros foram lidos por crianças com menos de 10 anos\n",tota10);
	printf("%i mulheres leram 5 livros ou mais\n",totalmulher);
	printf("%.2f é a media de idade dos homens que leram menos que 5 livros\n",mdh/(float)mdhct);
	printf("%.2f é a porcentagem de pessoas que nao leram nenhum livro\n",ctnotlivro*100.0/ctpessoas);

}
