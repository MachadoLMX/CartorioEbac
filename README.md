# Desafio de Programação

Este repositório contém um projeto que envolve a criação de um script de shell e um programa Python. Abaixo, você encontrará explicações detalhadas sobre como executar o script `.sh` e também uma explicação sobre o código Python desenvolvido.

## Como Executar o Arquivo `.sh`

### Passo 1: Abra o terminal no seu sistema Linux ou Windows Subsystem for Linux (WSL).

### Passo 2: Navegue até o diretório onde o arquivo `executar_calculadora.sh` está localizado.

Use o comando `cd` para navegar para o diretório onde você salvou o arquivo.

cd /caminho/para/o/diretório



1. Criação do script:
nano calculadora.sh

2. Tornando o script executável:
chmod +x calculadora.sh

3. Execução do script:
./calculadora.sh


Fluxo do Código da calculadora Python:

1. O programa exibe o título da calculadora.
2. Em seguida, entra no loop principal.
3. Solicita o primeiro número, o operador e o segundo número.
4. Realiza a operação selecionada (soma, subtração, multiplicação ou divisão).
5. Exibe o resultado ou exibe uma mensagem de erro caso o operador seja inválido ou o usuário insira valores inválidos.
6. O programa continua repetindo este processo até que o usuário o interrompa manualmente.

Exemplos de Execução:

1. Entrada Válida:
  Usuário entra com 2, operador + e 3.
  O programa exibe: 2 + 3 = 5.
2. Divisão por Zero:
  Usuário entra com 10, operador / e 0.
  O programa exibe: Erro: Divisão por zero não permitida!.
3. Operador Inválido:
  Usuário entra com 2, operador ^ e 3.
  O programa exibe: Operador inválido! Digite uma operação válida (+, -, *, /)..
4. Entrada Não Numérica:
  Usuário entra com abc, o programa exibe: Por favor, digite um número válido.

Conclusão:

Esse código implementa uma calculadora simples, com tratamento de erros para entradas inválidas e divisões por zero. Ele oferece uma experiência de uso interativa, permitindo ao usuário continuar realizando cálculos até que decida interromper o programa manualmente.
