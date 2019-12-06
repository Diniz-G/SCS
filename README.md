# SCS
SCS - Sistema de Controle de Softwares

# SCS - Manual

O projeto **Sistema de Cadastramento de Softwares** consiste num programa que tem por objetivo cadastrar os softwares instalados nos computadores de um laboratório, visando uma aplicação dentro do IFPB. Neste programa é possível cadastrar novos softwares, bem como excluí-los, editá-los e salvá-los.

# Como utilizar?

O SCS exibe essa tela inicial:

![Tela Inicial](https://github.com/Diniz-G/SCS/blob/master/imagens/1.png?raw=true)

## Definindo o laboratório

Primeiramente, deve-se definir o laboratório em questão inserindo seu nome, quantidade de computadores que o mesmo comporta e o espaço de memória dos computadores:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/2cadastro_lab.png?raw=true)

## Adicionando programas

Para adicionar os programas basta preencher todos os campos com informações válidas e clicar no botão **Adicionar Programa**.

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/4add_prog1.png?raw=true)

Se tudo ocorrer bem a seguinte mensagem será exibida:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/5add_prog_ok.png?raw=true)

## Status da memória

A seguinte barra de progresso será preenchida à medida que os programas forem adicionados:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/6barra_de_progresso.png?raw=true)

## Onde posso ver os programas inseridos?

A aba gerenciamento irá exibir os programas inseridos e a barra de progresso exibirá a porcentagem de memória utilizada:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/7progs_inseridos.png?raw=true)

## E se algum programa exceder o espaço disponível?

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/8prog_enorme.png?raw=true)

O programa não será inserido e a seguinte mensagem de erro será exibida:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/9prog_enorme_erro.png?raw=true)

## E se eu inserir dados inválidos?

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/10ex_erro.png?raw=true)

Será exibida uma mensagem informando que o programa não foi inserido, seguida de uma mensagem informando qual foi o dado inválido:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/11msg_erro1.png?raw=true)
![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/12msg_erro2.png?raw=true)


## No SCS é possível ordenar os programas por 3 critérios

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/13tabela1.png?raw=true)

### Por exemplo:

### Ordenando por nome

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/14tabelanome.png?raw=true)

### Ordenando por tamanho

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/15tabela_tamanho.png?raw=true)

## Excluir Programas

Para excluir um programa cadastrado basta clicar no botão "Excluir Programa" e inserir seu nome.

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/16botao_excluir_prog.png?raw=true)
![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/17excluindo_prog.png?raw=true)

Se tudo ocorrer bem, a seguinte mensagem será exibida:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/18excluido_ok.png?raw=true)

## E se algum programa for atualizado e passar a ocupar mais espaço?

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/19alterar_valor1.png?raw=true)

Simples! Basta um duplo clique na tabela, na coluna "Tamanho" do programa que se deseja alterar.

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/20alterar_valor.png?raw=true)

A barra de Status da memória será atualizada de acordo com as alterações feitas.

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/21alterar_valor3.png?raw=true)

Esse mesmo método pode ser utilizado para alterar qualquer outro parâmetro do programa na tabela.

## Salvando o arquivo

Basta clicar na barra "Arquivo" e selecionar a opção "Salvar" ou pode-se utilizar o atalho CTRL+S :

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/22salvar_melhoresse.png?raw=true)

O programa automaticamente atribuirá o nome do laboratório ao arquivo .csv:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/23salvar_csv.png?raw=true)

Caso o processo seja bem sucedido, será exibida a mensagem:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/24salvar_ok.png?raw=true)

## Carregando um arquivo

Basta clicar na barra "Arquivo" e selecionar a opção "Carregar" ou pode-se utilizar o atalho CTRL+A :

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/25carregar.png?raw=true)

O programa irá procurar por arquivos com a terminação .csv:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/26carregando_csv.png?raw=true)

Caso o processo seja bem sucedido, será exibida a mensagem:

![enter image description here](https://github.com/Diniz-G/SCS/blob/master/imagens/27carregar_ok.png?raw=true)

## Observações:
> Ao carregar um arquivo apenas os programas serão carregados, ou seja, a barra de status não será alterada;

> Para adicionar mais programas, deve-se criar um laboratório com o espaço adicional, e a barra de status será referente ao espaço adicional, assim como os programas que serão inseridos, respeitarão apenas o novo valor de espaço inserido.

> O projeto foi desenvolvido utilizando o Windows como Sistema Operacional, por esse motivo as quebras de linha para salvamento dos arquivos .csv foram feitas com \r\n.



## Para dúvidas e sugestões

### Email: diniz.gabriel@academico.ifpb.edu.br
