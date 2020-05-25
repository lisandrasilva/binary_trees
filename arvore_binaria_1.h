/**
@file arvore_binaria_1.h
Funções de manuseamento de árvores binárias (algumas de procura)*/

#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

/**
\brief estrutura de uma árvore binária 
*/

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

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

int procura_recursiva(int x, ABin a);

/**
\brief Procura o elemento "x" na árvore de Procura "a". Devolve 1 se "x" existe na árvore "a".Obs: algorítmo iterativo.
@param x elemento a ser procurado 
@param a árvore em que vamos  procurar o elemento x
*/

int procura_iterativa(int x, ABin a);

/**
\brief Dada uma árvore binária de procura, acrescenta um elemento, continuando uma árvore de procura.
Devolve uma árvore de procura com os elementos de "a" e "x".
Obs: algorítimo recrusivo.
@param a árvore que vamos inserir um elemento 
@param x elemento a ser inserido na árvore a
*/

ABin insere_recursiva (ABin a, int x);

/**
\brief Dada uma árvore binária de procura, acrescenta um elemento, continuando uma árvore de procura.
Devolve uma árvore de procura com os elementos de "a" e "x".
Obs: algorítimo iterativo.
@param a árvore que vamos inserir um elemento
@param x elemento a ser inserido na árvore a
*/

ABin insere_iterativa (ABin a, int x);

/**
\brief Dado o endereço do endereço de uma árvore binária de procura e um elemento, insere esse elemento x na árvore dada. 
@param a endereço do endereço da árvore que vamos inserir um elemento
@param x elemento a ser inserido na árvore *a
*/

void insere_2 (ABin * a, int x);

/**
\brief recebe uma árvore binária NÃO NULA de PROCURA e retorna essa árvore sem a raíz
@param a árvore  que vamos tirar a raíz.
*/

ABin removeRaiz (ABin a);

/**
\brief Diz qual é o maior elemento de uma árvore binária de procura não nula. Devolve tal elemento.
@param a árvore no qual vamos procurar o maior elemento
*/

int maiorAB (ABin a);

/**
\brief Retira o maior elemento de uma árvore binária de procura e reajusta ela com as devidas modificações. Retorna a árvore sem o maior elemento . Recebe uma árvore de Procura NÃO NULA.
@param a árvore não nula a qual vamos retirar o maior elemento.
*/

ABin removeMaior_1 (ABin a);

/**
\brief Retira o maior elemento de uma árvore binária de procura e reajusta ela com as devidas modificações. Retorna o nodo no qual está o maior elemento. Servepara árvores binárias de Procura NÃO NULA.
Obs: recebe o endereço do endereço de uma árvore binária de procura. Isto porque iremos devolver algo que não é a árvore e vamos querer modificar ela também, então passa-se o pointer do ABin para fazer 2 em 1 (diferente da função anterior que até modificava a árvore, mas devolvia ela mesma.
@param sitio
*/

ABin removeMaior_2 (ABin *sitio);

// em projeto
ABin removeRaiz (ABin a);

#endif
