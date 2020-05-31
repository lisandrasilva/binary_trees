/**
@file Btree_functions.h
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
\brief estrutura de uma lista ligada
*/

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

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
\brief Cria uma lista ligada dado um elemento e a próxima lista a apontar.
@param x elemento a inserir
@param l próxima lista a apontar
*/

LInt newlligada (int x, LInt l); 

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

/**
\brief Liberta todos os nodos com profundidade superior a profundidade dada. Retorna o número de elementos tirados.
@param a endereço de um ABin
@param profundidade nível máximo em que os elementos vão se manter
*/

int pruneAB (ABin *a,int profundidade);

/**
\brief Preenche o vector v com os elementos de a que se encontram no nível (profundidade) n. Considere que a raíz da árvore se encontra no nível 1. A função deverá retornar o número de posições preenchidas do array.
@param a árvore binária que servirá para buscar os elementos
@param n profundidade
@param v array em que se vai inserir os elementos
*/

int nivelV (ABin a, int n, int v[]);

/**
\brief Dada uma árvore binária de procura de inteiros e um inteiro, conta quantos elementos da árvore são
maiores que o inteiro dado. Devolve o número de elementos contado.
@param a árvore binária de procura
@param x inteiro a considerar
*/

int quantosMaiores (ABin a, int x);

/**
\brief Dada uma árvore a (não necessariamente de procura) avalia se o inteiro x dado no argumento é maior que todos os elementos da árvore. Devolve 1 caso for, zero caso contrário.
@param a árvore binária (não necessariamente de procura)
@param x elemento que vamos ver se é maior que todos os elementos da árvore
*/

int maior_elemento (ABin a, int x);

/**
\brief Dada uma árvore a (não necessáriamente de procura) avalia se o inteiro x dado no argumento é menor que todos os elementos da árvore. Devolve 1 caso for, zero caso contrário.
@param a árvore binária (não necessariamente de procura)
@para, x elemento que vamos ver se é menor que todos os elementos da árvore
*/

int menor_elemento (ABin a , int x);

/**
\brief Testa se uma árvore é de procura (isto é, se dado um nodo, todos os elementos na sub-árvore da esquerda são menores que a raíz enquanto todos os elementos da sub-árvore direita são maiores que a raíz.
@param a árvore binária que vamos testar se é de procura
*/

int deProcura (ABin a);

/**
\brief Calcula o nível (profundidade) a que um elemento está numa arvore binária de procura. Devolve -1 caso não existir.
Obs: considere-se a ráiz nível 1.
@param a árvore binária de procura
@param x elementos que vamos ver o nível
*/

int depthOrd (ABin a, int x);

/**
\brief Dada uma árvore binária de inteiros (não necessariamente nula), conta quantos dos seus nodos são folhas, i.e., que não têm nenhum descendente.
Devolve o número de folhas.
@param a árvore binária não necessariamente de procura
*/

int contaFolhas (ABin a);

/**
\brief Cria uma árvore nova, com o resultado de inverter a árvore dada no argumento (efeito espelho)
Devolve a árvore criada.
@param a árvore a inverter (não necessariamente de procura)
*/

ABin cloneMirror (ABin a);

/**
\brief Dada uma árvore de inteiros, calcula a árvore das somas acumuladas dessa árvore.
A árvore calculada deve ter a mesma forma da árvore recebida como argumento e em cada 
nodo deve conter a soma dos elementos da sub-árvore que aí se inicia.
Devolve a sub-árvore criada.
@param a árvore (não necessariamente de procura)
*/

ABin somasAcA (ABin a);

/**
\brief Dada uma árvore, não necessariamente de procura, retorna a soma de todos os seus elementos.
@param a árvore binária
*/

int somaElementos (ABin a);

/**
\brief Dada uma  ́arvore binária (não necessariamente de procura), constrói uma lista 
com os valores dos elementos que estão armazenados na árvore ao nível n (assuma que a 
raiz da árvore está ao nível 1).
@param a árvore binária
@param n nível
*/

LInt nivelL (ABin a, int n);

/**
\brief  Dada uma lista l1 e uma l2, junta l2 no fim de l1. Devolve l2 apenas quando l1 for nula.
@param l1 lista ligada
@param l2 lista ligada
*/

LInt concatLligadas (LInt l1, LInt l2);

/** 
\brief Liberta o espaço ocupado por uma arvore binária, retornando o número de nodos libertados.
@param a árvore binária não necessariamente de procura
*/

int freeAB (ABin a);

/**
\brief Calcula o nível-profundidade- (menor) a que um elemento está numa arvore binária, não necessariamente de procura (-1 caso não exista). 
Considere a raíz o nível 1 da árvore
@param a árvore binária
@param elemento que vamos ver o menor nível
*/

int depth (ABin a, int x);

/**
\brief que inverte uma árvore  (sem  criar  uma  nova ́arvore).
@param a pointer para ABin
*/

void mirror (ABin * a);

/**
\brief Cria uma cópia de uma ́arvore. 
@para a árvore binária a ser copiada
*/

ABin cloneAB (ABin a );

/** 
\brief Calcula a altura de uma ́arvore binária. Distância da raíz até o nodo mais fundo.
@param a árvore binária
*/

int altura (ABin a);

/* em projeto
ABin removeRaiz (ABin a);
*/


#endif
