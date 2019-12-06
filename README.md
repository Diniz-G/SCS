# SCS
SCS - Sistema de Controle de Softwares

# SCS - Manual

O projeto **Sistema de Cadastramento de Softwares** consiste num programa que tem por objetivo cadastrar os softwares instalados nos computadores de um laboratório, visando uma aplicação dentro do IFPB. Neste programa é possível cadastrar novos softwares, bem como excluí-los, editá-los e salvá-los.

# Como utilizar?

O SCS exibe essa tela inicial:
(1telainicial)

## Definindo o laboratório

Primeiramente, deve-se definir o laboratório em questão inserindo seu nome, quantidade de computadores que o mesmo comporta e o espaço de memória dos computadores:
(2cadastro_lab)

## Adicionando programas

Para adicionar os programas basta preencher todos os campos com informações válidas e clicar no botão **Adicionar Programa**.
(4add_prog)

Se tudo ocorrer bem a seguinte mensagem será exibida:
(5add_prog_ok)

## Status da memória

A seguinte barra de progresso será preenchida à medida que os programas forem adicionados:
(6barra_de_progresso)

## Onde posso ver os programas inseridos?

A aba gerenciamento irá exibir os programas inseridos e a barra de progresso exibirá a porcentagem de memória utilizada:
(7progs_inseridos)

## E se algum programa exceder o espaço disponível?

(8prog_enorme)

O programa não será inserido e a seguinte mensagem de erro será exibida:

(9)

## E se eu inserir dados inválidos?

(10)

Será exibida uma mensagem informando que o programa não foi inserido, seguida de uma mensagem informando qual foi o dado inválido:

(11)
(12)

## No SCS é possível ordenar os programas por 3 critérios

(13)

### Por exemplo:

### Ordenando por nome

(14)

### Ordenando por tamanho

(15)


## Excluir Programas

Para excluir um programa cadastrado basta clicar no botão "Excluir Programa" e inserir seu nome.
(16)
(17)

Se tudo ocorrer bem, a seguinte mensagem será exibida:
(18)


## E se algum programa for atualizado e passar a ocupar mais espaço?

(19)

Simples! Basta um duplo clique na tabela, na coluna "Tamanho" do programa que se deseja alterar.

(20)

A barra de Status da memória será atualizada de acordo com as alterações feitas.

(21)

## Salvando o arquivo

Basta clicar na barra "Arquivo" e selecionar a opção "Salvar" ou pode-se utilizar o atalho CTRL+S :

(22)

O programa automaticamente atribuirá o nome do laboratório ao arquivo .csv:

(23)

Caso o processo seja bem sucedido, será exibida a mensagem:

(24)

## Carregando um arquivo

Basta clicar na barra "Arquivo" e selecionar a opção "Carregar" ou pode-se utilizar o atalho CTRL+A :

(25)

O programa irá procurar por arquivos com a terminação .csv:

(26)

Caso o processo seja bem sucedido, será exibida a mensagem:

(27)

## Observações:
> Ao carregar um arquivo apenas os programas serão carregados, ou seja, a barra de status não será alterada;

> Para adicionar mais programas, deve-se criar um laboratório com o espaço adicional, e a barra de status será referente ao espaço adicional, assim como os programas que serão inseridos, respeitarão apenas o novo valor de espaço inserido.



## Para dúvidas e sugestões

### Email: diniz.gabriel@academico.ifpb.edu.br
