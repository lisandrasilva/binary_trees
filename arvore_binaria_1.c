#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_1.h"

ABin newABin (int r, ABin e, ABin d)
{
	ABin a = malloc (sizeof (struct nodo));

	a->valor = r;
	a->esq = e; a->dir = d;

	return a;
}

int size (ABin a)
{
int r = 0;

if (a!=NULL)
{
	r = 1 + size(a->esq) + size(a->dir);
}
return r;
}

int toArray (ABin a, int v[],int N)
{
int r = 0;
if (a != NULL && N > 0)
{

	r += toArray(a->esq,v+r,N-r);//escreve os elementos da esquerda
	// tenho que saber até que o índice o array v está preenchido.
	// Temos de arranjar uma forma da função toArray retornar
	// quantos elementos já preencheu (a solução é o tal r que a funçãop devolve)

	if (r < N) v[r++] = a->valor; // escreve no array v a raíz da árvore
	// primeiro faz v[r] e depois soma  1 ao r

	r += toArray(a->dir,v+r,N-r);//escreve os elementos da direita
}
return r;
}

/* Obs: sempre que eu quiser saber quantos elementos há entre 
as posições A e B, devo fazer ( A - B + 1)*/

ABin fromArray (int v[],int N)
{ 
ABin r = NULL,e,d;

int m = N/2;

if (N>0)
{
	// v[m] raíz
	// na árvore esquerda v[0...m-1]
	// na árvore direita v[m+1 ...N-1]
	// Calculo: N - 1 - m - 1 + 1 = N - m -1
        e = fromArray (v,m);
        d = fromArray ( v + m + 1, N - m - 1 );
        r = newABin (v[m],e,d);
}
return r;
}

/*Em árvores de procura, todos os elementos que estão a esquerda são menores ou iguais a raíz e a raíz por sua vez é menor ou igual a todos os elementos que estão a direita*/ 
/*Obs: algorítmo de procura altamente eficiente*/

int procura_recursiva(int x, ABin a)
{
int r = 0; // ainda não encontrei

if (a == NULL);
else if (a->valor == x) r = 1;
     else if (a->valor > x)
	     r = procura_recursiva(x,a->esq);
     	  else 
	      r = procura_recursiva(x,a->dir);// a->valor < x
		
return r;
}

/* Como no caso na "procura" não precisamos voltar atrás na árvore,nem ir para ver coisas nos 2 lados dela ao mesmo tempo (o percurso de tal algorítmo é único), nem precisamos percorrer a árvore toda (por se tratar de uma
árvore de procura)  ela é um dos poucos casos em que é razoável (compensa mais)
fazer uma versão iterativa (posa anterior era recursiva). Sendo assim uma
função ainda mais eficiente*/

int procura_iterativa (int x, ABin a)
{
int r = 0;
while (a != NULL && a->valor != x)
{
     if  (a->valor > x) a = a->esq;
     else a = a->dir;
}

return (a != NULL); // se a for NULL quer dizer que não encontrei o elemento e a desigualdade será falsa, devolvendo 0
}

/*Obs: nas árvores binárias de procura não preciso me preocupar em conectar nada na hora de inserir algo. Basta eu ir descendo por ela conforme o item for maior ou menor. No fundo sempre vou inseir algo o mais embaixo de tudo , pois senão poderia quebrar o padrão das árvores de procura*/

ABin insere (ABin a, int x)
{

if (!a) // !a será True se a for NULL
	a = newABin (x,NULL,NULL);
else if (a->valor > x)
	a->esq = insere(a->esq,x);
     else 
	a->dir = insere(a->dir,x);


return a;
}

/*Retira o maior elemento de uma árvore binária de procura e reajusta ela com as devidas modificações. Retorna o nodo no qual está o 
maior elemento*/
ABin removeMaior (ABin *sitio)
{
ABin pt;

while ((*sitio)->dir != NULL)
{
	sitio = &((*sitio)->dir);
}
pt = *sitio;
/* Sei que "*sitio" é um apontador para uma árvore binária,isto é, é o endereço de uma árvore 
binária. Ao fazer (*sitio)->dir estou acessando outro apontador para uma árvore binária, isto é, 
um outro endereço de uma árvore binária. Porém, ao fazer &((*sitio)->dir) estou acessando o endereço 
no qual está esse apontador, ou seja, é o endereço do endereço de uma árvore binária. Acontece que 
esse &((*sitio)->dir) é exatamente o local em que está armazenado o endereço do nodo direito, por 
exemplo, da árvore "*sitio" inicial. Por tanto, ao eu fazer sitio = &((*sitio)->dir) estou a fazer 
a variável "sitio" (que é o endereço do local que está armazenado o endereço de uma árvore local) 
obter o endereço do local que está armazenado o endereço do nodo direito. Assim, ao fazer agora 
(*sitio) = "algo" estarei a modificar algo que está no local no qual o endereço do nodo direito 
está guardado. Por tanto, se eu igualar (*sitio) a um novo endereço de árvore binária, estarei a 
trocar o nodo direito do primeiro "*sitio" mencionado.
// Caso tivesse dado apenas sitio como argumento, estaria dando o endereço de uma árvore binária. 
Ao fazer (sitio = sitio->dir) estaria trocando o valor de sitio para outro endereço e por tanto 
isso não modifica nada na árvore em si, apenas estou a trocar o valor de uma variável.Nesse caso 
apenas fazendo sitio->valor = "algo" ou sitio->dir = "algo" estaria realmente a mudar algo da árvore. 
A limitação aqui é que, supomos que eu estou andando nodo a nodo na árvore e de repende estou perante 
um nodo que quero retirar, teria de alguma forma modificar o valor no qual o antigo nodo aponta num 
dos seus ramos (que é o que eu estou atualmente) - e não adianta fazer sitio = 2 por exemplo porque 
o antigo ramo estaria a apontar para sito e também não adiantaria fazer  &sitio porque nesse caso 
estou perante uma nova variável de uma outa função, ou seja, &sitio não é exatamente o endereço do 
local no qual está armazenado o valor do ramo (dir ou esque) sitio - que é um endereço de árvore binária - 
do antigo nodo. &sitio é um valor aleatória qualquer aqui.  */
*sitio = pt->esq;
return pt;
}

/* Recebe uma árvore binária de procura NÃO NULA e retorna essa
árvore (de procura) sem a raíz*/
ABin removeRaiz (ABin a)
{
ABin tmp;

if (a->esq == NULL)
{
	tmp = a;
	a = a->dir;
	free (tmp);
}
else if (a->dir == NULL) 
      {
      	tmp = a;
	a = a->esq;
	free(tmp);
      }
      else 
      {
      // Ambas as sub-árvores são NÃO NULAS
      }
return a;
}

