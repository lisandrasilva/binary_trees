/**
@file arvore_binaria_1.h
Funções de manuseamento de árvores binárias (algumas de procura)*/

#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

/**
\brief Dada 2 árvores binárias, cria uma nova árvore sendo
o valor da nova raíz aquele que foi dado como argumento e 
cada nodo (esq e dir) uma das árvores dadas como argumento.
Não há preocupação nenhuma se a árvore é de procura, apenas 
é acrescentado uma nova raíz principal. Devolve o apontador 
(endereço que a nova árvore começa) para a nova árvore.

@param r valor a inserir na raíz da nova  árvore
@param e árvore que será a subárvore da esquerda
@param d árvore que será a subárvore da direita
*/
ABin newABin (int r, ABin e, ABin d);

/**
\brief Conta o número de elementos de uma árvore binária (e o devolve).
@param a árvore que será contado os elementos
*/
int size (ABin a);

/**
\brief Recebe uma árvore binária de procura, um array (que será formado), a quantidade
de elementos N que vamos inserir no array e preenche o array dado no argumento, a partir da 
árvore binária de procura, com no máximo N elementos. Retorna o número de elementos escritos no array.
Escreve o array em ordem crescente, caso a árvore binária dada for de procura.

@param a árvore que será buscado os elementos
@param v array que será formado
@param quantidade de elementos a preencher no array
*/

int toArray (ABin a, int v[],int N);

/**
\brief 
Faz uma árvore a partir de um array com N elementos.
O elemento que está no meio do array será o que está na raíz.
Desse jeito, se o array esttiver ordenado, então, na árvore, todos os elementos que estão
a esquerda é menor que a raíz que por conseguinte é menor do que os elementos a direita,
por tanto se o array estiver ordenado, a árvore será de procura. Retorna um apontador
para a árvore criada.
Obs: sempre que eu quiser saber quantos elementos há entre 
as posições A e B, devo fazer (A - B + 1)

@param v array que  será buscado os elementos para formar a árvore
@param quantidade de elementos que irei buscar do array
*/

ABin fromArray (int v[],int N);

/**
\brief Procura o elemento "x" na árvore de Procura "a". Devolve 1 se "x" existe na árvore "a".Obs: algorítmo recursivo.
@param x elemento a ser procurado 
@param a árvore em que vamos  procurar o elemento x
*/

int procura_recursiva(int x, ABin a)

/**
\brief Procura o elemento "x" na árvore de Procura "a". Devolve 1 se "x" existe na árvore "a".Obs: algorítmo iterativo.
@param x elemento a ser procurado 
@param a árvore em que vamos  procurar o elemento x
*/

int procura_iterativa(int x, ABin a)

ABin removeMaior (ABin *sitio);

// em projeto
ABin removeRaiz (ABin a)
