#include <stdio.h> // biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // biblioteca de aloca��od e espa�o de mem�ria.
#include <locale.h> // biblioteca de aloca��es de texto por regi�o.
#include <string.h> // biblioteca respons�vel por cuidar das string.

int registro() // Fun;'ao respons[avel por cadastrar os usu�rios no sistema.
{
	// inicio cria��o de variav�is/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio.
	scanf("%s", cpf); // %s refere-se a string - salvando strings.
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string.
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); // cria arquivo - "W" write em ingl�s significa escrever.
	fprintf(file,cpf); // Salva o valor da veriavel.
	fclose(file); // Fecha o arquivo.
	
	file = fopen(arquivo, "a"); // Abre o arquivo no modo de adi��o.
	fprintf(file,","); // Adiciona uma v�rgula ao arquivo.
	fclose(file); // Fecha o arquivo.
	
	printf("Digite o nome a ser cadastrado: "); // Solicita o nome ao usu�rio.
	scanf("%s", nome); // L� o nome inserido.
	
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
	printf("Usu�rio cadastrado com sucesso!\n");
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem - IDIOMA
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //recebendo qual usu�rio vai ser consultado.
	scanf("%s",cpf); //L� o CPF inserido.
	
	FILE *file; 
	file = fopen(cpf,"r"); //Abre o arquivo no modo de leitura.
	
	if(file == NULL) //Verifica se o arquivo foi encontrado.
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n"); //Exibe mensagem de erro se o arquivo n�o for encontrado.
	}
	
	while(fgets(conteudo, 200, file) != NULL) //L� o conte�do do arquivo at� o final.
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // Exibe as informa��es do usu�rio.
		printf("%s", conteudo); //Exibe o conte�do lido.
		printf("\n\n"); 
	 } 
	 
	 system("pause");
}

int deletar() //Fun��o respons�vel por deletar os dados do usu�rio.
{
    char cpf[40];
    
    printf("Digite o CPF do usu�rio a ser deletado: "); //Solicita o CPF ao usu�rio.
    scanf("%s",cpf); //L� o CPF inserido.

	remove(cpf); //Tenta deletar o arquivo.
	
    // Verifica se o arquivo existe antes de tentar delet�-lo
    FILE *file;
	file = fopen(cpf,"r"); //Verifica se o arquivo ainda existe.
    
    if(file == NULL) //Se o arquivo n�o foi localizado.
	{
        printf("O CPF do usu�rio n�o foi localizado no Sistema!\n"); //Exibe mensagem de erro.
        system("pause"); //Pausa o sistema antes de continuar.
    }
    else //Se o arquivo foi localizado.
    {
    	remove(cpf); //Deleta o arquivo.
    	printf("Usu�rio deletado com sucesso!!!\n"); //Exibe mensagem de sucesso.
    	system("pause"); //Pausa o sistema antes de continuar.
	}
}

int main()	//Fun��o principal do sistema.
{
	int opcao=0; //Definindo vari�veis.
	int laco=1;
	char senhadigitada[]="a"; //diginindo variav�l senha
	int comparacao; //compara��o para a senha
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin"); //compara��o de v�riaveis // deini��o da senha de administra��o
	
	if(comparacao == 0) //valida��o
	{
		system ("cls");
		for(laco=1;laco=1;)
		{
		
				system("cls");
		
				setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem.
		
				printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu.
				printf("Escolha a op��o desejada no menu:\n\n"); //Op��es do Menu.
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n\n");
				printf("\t4 - Sair do Sistema.\n\n"); //op��o de sair do Sistema.
				printf("Op��o: "); //Fim do Menu
			
				scanf("%d", &opcao); //armazenando a escoha do usu�rio.
	
				system("cls"); //respons�vel por limpar a tela.
		
				switch(opcao) //inicio da sele��o das op��es - registro - consulta e deletar e nulo (caso selecione uma op��o invalida/que n�o existe.
				{
					case 1:
					registro(); //Chamada de fun��es
					break;
		
					case 2:
					consultar(); //Chamada de fun��es
					break;
	
					case 3:
					deletar(); //Chamada de fun��es
					break;
			
					case 4:
					printf("Obrigado por utilizar nosso sistema!\n"); // adicionado op��o de sair do sistema.
					return 0;
					break;
			
					default:
					printf("Essa opc�o n�o esta dispon�vel!\n"); //Exibe mensagem para op��es inv�lidas.
					system("pause"); //Pausa o sistema antes de continuar.
					break;
				} //Fim da sele��o
		}
	}
	
	else
		printf("Senha incorreta!");
}

	
