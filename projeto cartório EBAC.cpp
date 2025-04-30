#include <stdio.h> // biblioteca de texto (comunicação com o úsuario)
#include <stdlib.h> // biblioteca que permite a ultilização de variaveis
#include <locale.h> // biblioteca que adapta o programa para o idioma ou local
#include <string.h>// biblioteca responsavel por cuidar dos stings

int registro ()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	
	printf ("Digite seu CPF: ");
	scanf ("%s", cpf);
	
	strcpy(arquivo, cpf); // faz a cópia da ultima variavel para a primeira variavel
	
	FILE *file; // FILE é uma função do sistema que serve para chamar um arquivo. E "file" é o arquivo que criamos
	file = fopen (arquivo, "w"); // fopen abri o o que colocamos dentro de "()". "w" cria o arquivo
	fprintf (file, cpf); // fprintf salva no arquivo a variavel
	fclose(file); // fecha o arquivo

	file = fopen(arquivo, "a"); // "a" atualiza a informação
	fprintf (file, ", ");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, " ");
	fclose (file);
		
	
	printf ("Digite seu sobrenome: ");
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ", ");
	fclose (file);
	
	
	printf ("Digite o cargo a ser cadrastrado: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a");
	fprintf (file, cargo);
	fclose  (file);
	
	file = fopen (arquivo, "a");
	fprintf (file, ".");
	fclose (file);
	
	system("pause");
	
	}

int consultar ()
{
	setlocale (LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); // "r" -> usamos para ser feita a leitura da variavel
	
	if (file == NULL)
	{
		printf ("não existe esse arquivo. \n");	
	}

	while(fgets(conteudo, 200, file) != NULL)// while(enquanto)(fgets(busca no arquivo)(conteudo(variavel), 200(quantidade max. de variaveis), file (até o fim de file)) != (parar) NULL (quando for nulo))
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf ("\n\n");
	}
	
	system("pause");
}

int deletar ()
{
	char cpf [40];
	
	printf ("Digite o CPF que deseja remover: ");
	scanf ("%s", cpf, "\n");
	
	remove (cpf);
	
	FILE * file;
	file = fopen (cpf, "r");
	fclose (file);
	
	printf ("CPF removido com Sucesso!");
	system ("pause");
}

int main ()
{
	int opcao = 0; //tipo de variavel e sua identificação
	int loop = 1;
	
	for(loop=1; loop=1;) // não se coloca ;, pois não estamos executando um comando, mas sim, fazendo ele "pensar"
{
	
		system ("cls");
		
		setlocale (LC_ALL,"portuguese"); // LC_ALL -> é uma variavel para a localidade do sistema
	
		printf ("Cartório da EBAC \n\n");
		printf ("Escolha a opção desejada no menu:\n\n");
		printf("\t1- Registrar nomes\n");
		printf("\t2- consultar nomes\n");
		printf("\t3- deletar nomes\n\n");
		printf("\t qual o opção que você deseja? ");

		scanf ("%d",&opcao); // o & pode ser entendido como: armazene no endereço opcao

		system("cls");// system é algo que vai mexer algo no funcionamento do sistema. cls -> limpar a tela

		switch (opcao)
		{
			case 1:
				registro ();
			break;
			 	
			case 2:
				consultar ();
			break;
			
			case 3:
				deletar ();
			break;
			
			default:
					printf ("seu numero escolhido não está entre as opções do menu!\n ");
					system ("pause");
		}

	}
}


