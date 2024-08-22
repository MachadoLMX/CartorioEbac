#include <stdio.h> // biblioteca de comunicação com o usuário.
#include <stdlib.h> // biblioteca de alocaçãod e espaço de memória.
#include <locale.h> // biblioteca de alocações de texto por região.
#include <string.h> // biblioteca responsável por cuidar das string.

int registro() // Fun;'ao respons[avel por cadastrar os usuários no sistema.
{
	// inicio criação de variavéis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string.
	
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
	
	printf("Digite o CPF a ser consultado: "); //recebendo qual usuário vai ser consultado.
	scanf("%s",cpf); //Lê o CPF inserido.
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo no modo de leitura.
	
	if(file == NULL) //Verifica se o arquivo foi encontrado.
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n"); //Exibe mensagem de erro se o arquivo não for encontrado.
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Lê o conteúdo do arquivo até o final.
	{
		printf("\nEssas são as informações do usuário: "); // Exibe as informações do usuário.
		printf("%s", conteudo); //Exibe o conteúdo lido.
		printf("\n\n"); 
	 } 
	 
	 system("pause");
}

int deletar() //Função responsável por deletar os dados do usuário.
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: "); //Solicita o CPF ao usuário.
    scanf("%s",cpf); //Lê o CPF inserido.

	remove(cpf); //Tenta deletar o arquivo.
	
    // Verifica se o arquivo existe antes de tentar deletá-lo
    FILE *file;
	file = fopen(cpf,"r"); //Verifica se o arquivo ainda existe.
    
    if(file == NULL) //Se o arquivo não foi localizado.
	{
        printf("O CPF do usuário não foi localizado no Sistema!\n"); //Exibe mensagem de erro.
        system("pause"); //Pausa o sistema antes de continuar.
    }
    else //Se o arquivo foi localizado.
    {
    	remove(cpf); //Deleta o arquivo.
    	printf("Usuário deletado com sucesso!!!\n"); //Exibe mensagem de sucesso.
    	system("pause"); //Pausa o sistema antes de continuar.
	}
}

int main()	//Função principal do sistema.
{
	int opcao=0; //Definindo variáveis.
	int laco=1;
	char senhadigitada[]="a"; //diginindo variavél senha
	int comparacao; //comparação para a senha
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //comparação de váriaveis // deinição da senha de administração
	
	if(comparacao == 0) //validação
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		
				system("cls");
		
				setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem.
		
				printf("### Cartório da EBAC ###\n\n"); //Início do Menu.
				printf("Escolha a opção desejada no menu:\n\n"); //Opções do Menu.
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n");
				printf("\t4 - Sair do Sistema.\n\n"); //opção de sair do Sistema.
				printf("Opção: "); //Fim do Menu
			
				scanf("%d", &opcao); //armazenando a escoha do usuário.
	
				system("cls"); //responsável por limpar a tela.
		
				switch(opcao) //inicio da seleção das opções - registro - consulta e deletar e nulo (caso selecione uma opção invalida/que não existe.
				{
					case 1:
					registro(); //Chamada de funções
					break;
		
					case 2:
					consultar(); //Chamada de funções
					break;
	
					case 3:
					deletar(); //Chamada de funções
					break;
			
					case 4:
					printf("Obrigado por utilizar nosso sistema!\n"); // adicionado opção de sair do sistema.
					return 0;
					break;
			
					default:
					printf("Essa opcão não esta disponível!\n"); //Exibe mensagem para opções inválidas.
					system("pause"); //Pausa o sistema antes de continuar.
					break;
				} //Fim da seleção
		}
	}
	
	else
		printf("Senha incorreta!");
}

	
