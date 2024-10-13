Implemente uma estrutura de dados pilha, utilizando encadeamento de nós, para implementar um inventário de itens em um jogo digital.
A estrutura deve possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens, verificação do item no topo da pilha e limpeza do inventário (remoção de todos os elementos da pilha).
O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"), quando a pilha já estiver vazia.
Os itens do inventários possuem os seguintes atributos: nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
r: para retirar um item do inventário
l: para limpar (remover todos) os itens do inventário
e: para espiar o topo do inventário (escreve o topo sem removê-lo)
f: para finalizar a execução do programa
