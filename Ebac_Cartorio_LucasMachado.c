#include <stdio.h> // biblioteca de comunicação com o usuário.
#include <stdlib.h> // biblioteca de alocaçãod e espaço de memória.
#include <locale.h> // biblioteca de alocações de texto por região.
#include <string.h> // biblioteca responsável por cuidar das string.

int registro() // Fun;'ao respons[avel por cadastrar os usu[arios no sistema.
{
	// inicio criação de variavéis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", cpf); // %s refere-se a string - salvando strings.
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string.
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria arquivo - "W" write em inglês significa escrever.
	fprintf(file,cpf); // Salva o valor da veriavel.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de adição.
	fprintf(file,","); // Adiciona uma vírgula ao arquivo.
	fclose(file); // Fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); // Solicita o nome ao usuário.
	scanf("%s", nome); // Lê o nome inserido.
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	printf("Usuário cadastrado com sucesso!\n");
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem - IDIOMA
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	 } 
	 
	 system("pause");
}

int deletar() 
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);

	remove(cpf);
	
    // Verifica se o arquivo existe antes de tentar deletá-lo
    FILE *file;
	file = fopen(cpf,"r");
    
    if(file == NULL) 
	{
        printf("O CPF do usuário não foi localizado no Sistema!\n");
        system("pause");
    }
    else
    {
    	remove(cpf);
    	printf("Usu[ario deletado com sucesso!!!\n");
    	system("pause");
	}
}

int main()	
{
	int opcao=0; //Definindo variáveis.
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem.
		
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu.
		printf("Escolha a opção desejada no menu:\n\n"); //Opções do Menu.
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do Menu
			
		scanf("%d", &opcao); // armazenando a escoha do usuário.
	
		system("cls"); // responsável por limpar a tela.
		
		switch(opcao) // inicio da seleção das opções - registro - consulta e deletar e nulo (caso selecione uma opção invalida/que não existe.
		{
			case 1:
			registro(); // Chamada de funções
			break;

			case 2:
			consultar(); // Chamada de funções
			break;

			case 3:
			deletar(); // Chamada de funções
			break;
			
			default:
			printf("Essa opcão não esta disponível!\n");
			system("pause");
			break;
		} // Fim da seleção
	}
}

