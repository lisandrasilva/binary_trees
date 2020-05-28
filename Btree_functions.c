#include <stdio.h>
#include <stdlib.h>
#include "Btree_functions.h"

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
while (a != NULL && a->valor != x)
{
     if  (a->valor > x) a = a->esq;
     else a = a->dir;
}

return (a != NULL); // se a for NULL quer dizer que não encontrei o elemento e a desigualdade será falsa, devolvendo 0
}

/*Obs: nas árvores binárias de procura não preciso me preocupar em conectar nada na hora de inserir algo. Basta eu ir descendo por ela conforme o item for maior ou menor. No fundo sempre vou inseir algo o mais embaixo de tudo , pois senão poderia quebrar o padrão das árvores de procura*/

ABin insere_recursiva (ABin a, int x)
{

if (!a) // !a será True se a for NULL
	a = newABin (x,NULL,NULL);
else if (a->valor > x)
	a->esq = insere_recursiva(a->esq,x);
     else 
	a->dir = insere_recursiva(a->dir,x);
        
return a;
}

ABin insere_iterativa (ABin a,int x)
{
ABin ant,novo,pt = a;

novo  = newABin (x,NULL,NULL);

while (pt)
{
	ant = pt; // Sem isso, sairia do ciclo com a = NULL e se eu modificasse "a" não mudaria
	//nada a nivel da árvore, pois ele é uma cópia mas acima de tudo o que estava a apontar para
	// "a" continua a apontar para NULL.
	if (pt->valor > x)
		pt = pt->esq;
	else
		pt = pt->dir;
} 

if (!a) // se a árvore original for vazia 
	a = novo;
else 
{
	if (ant->valor > x)
		ant->esq = novo;
	else 
		ant->dir = novo;
}

return a;
}

/*Aqui eu consigo mudar exatamente o local que está NULL, ou seja, o local que está um suposto endereço de árvore binária 
(um endereço no qual há um "* ABin" ). Não estou a lidar com o valor NULL como variável, e sim com o endereço em que ele 
está, endereço o qual é aquele representado por "&(a->esq)" por exemplo . Assim mudando o conteúdo desse pointer, mudarei 
o conteúdo no qual está alocado no endereço &(e->esq), fazendo realmente mudança na árvore. Sem me preocupar em guardar o 
anterior ou retornar algo. Uma coisa é ter como várivel numa função auxiliar o endereço de uma árvore binária que foi passada
 como argumento. Se esta variável for "a" por exemplo, ao igualar "a" a algo, estarei a mudar a variável em si e mais nada 
 a nivel de árvore. Aqui só fazendo a->esq por exemplo para mudar algo. Mas se tiver como variável &a, por exemplo representado 
 pela variável "b", ao fazer *b e igualar a algo estarei a mudar realmente a árvore, pois estarei acessando o conteúdo de 
 "b". Como b é uma coṕia do endereço em que está o endereço de uma árvore, ao fazer *b estarei deixando de modificar a copia 
 (variavel local) e estarei acessando o conteúdo do endereço que b armazena, e nesse caso tal conteúdo é o endereço da 
 árvore binária  e, ao mudar tal conteúdo, estarei mudando o conteúdo de algo que está alocado no endereço dado como argumento 
 que é o endereço original que está armazenado o endereço da árvore original (apesar do endereço dado ser uma cópia, fazer *ele 
 muda mesmo pois a cópia tem o mesmo valor do endereço que precisávamos. Ao fazer ele = algo é que não muda nada mesmo, 
 pois ai estaria a mudar a variável local que é apenas uma cópia. Aqui não há muita preocupação de casos especiais, não há 
 preocupação de ligar os anteriores ao criados (dado que já estarei a alterar o conteúdo no qual pertence o anterior, ou seja, 
 esatrei já a alterar o valor do anterior, poid tenho acesso ao &anterior, o anterior é um Abin como o argumento) */
void insere_2 (ABin * a,int x)
{
	
while (*a)
{       
        if ((*a)->valor > x)
                a = &((*a)->esq);
        else
                a = &((*a)->dir);
}

*a = newABin (x,NULL,NULL);

}

ABin removeRaiz (ABin a)
{
ABin tmp;

if (a->esq == NULL)
       {
	tmp = a;
	a = a->dir;
	free (tmp);// "eu não preciso mais dessa posição de memória (mas nada é feito lá - é só questão de educação)"
       }
       else if (a->dir == NULL)
	      {
	       tmp = a;
	       a = a->esq;
	       free (tmp);
	      }
             else;   // Ambas as sub-árvores são NÃO NULAS
             /* Uma das formas de fazer é colocar toda a sub-árvora da esquerda pendurada no lado esquerdo do menor nodo da direita 
			 (mais a esquerda possível)- ou o contrário, colocar toda a sub-árvore direita pendurada do lado direito do maior nodo da 
			 direita (mais a direita possível). Ora, essas soluções não seriam muito boas porque a árvore ficaria demasiada profunda*/
             /* Uma boa solução é pegar no maior elemento da sub-árvore esquerda e meter ele como raíz, pois ele é maior que toda a 
			 sub-árvore da esquerda e menor que toda a sub-árvore da direita - características de uma raíz*/ 
            // Então agora vou a sub-árvore da esquerda, reitro seu maior elemento (é aquele que está mais a direita possível) e promovo 
			//ele a raíz da nova árvore.
	    	 
return a;
}

int maiorAB_Deprocura (ABin a)
{
while (a->dir != NULL)
	a = a->dir;
return a->valor;
}

int maior_elemento (ABin a, int x)
{
int res = 0;

if (!a) return 1;
else if (x > a->valor)
        {
        	res = maior_elemento (a->esq,x);
            if (res != 0)
            	res = maior_elemento (a->dir,x);
        }
     else if (x < a->valor)
           		res =  0;
return res;
}

int menor_elemento (ABin a, int x)
{
int res = 0;

if (!a) return 1;
else if (x < a->valor)
        {
        	res = menor_elemento (a->esq,x);
            if (res != 0)
            	res = menor_elemento (a->dir,x);
        }
      else if (x > a->valor)
             	return 0;
return res;
}

ABin removeMaior_1 (ABin a)
{
// CONFIRMAR SE NÃO DÁ MERDA QUANDO RECEBO UMA ÁRVORE QUE SÓ TENHA UMA RAÍZ OU QUE NEM SEQUER TENHA LADO DIREITO
// ,Sim, realmente dá merda, devo corrigir- a próx função virá corrigida
ABin ant,pt;
pt = a;
while (pt->dir != NULL)
{
	ant = pt ;
	pt = pt->dir;
}
// pt tem o elemento a remover
// pt está a direita do ant
// ant->dir = NULL;// Isto é radical demais, não devo colocar NULL porque se tiver conteudo na sub-árvore esquerda, esta assumirá a 
//posição daquele que vou retirar. Se colocasse NULL iria exluir possíveis partes da árvore.
ant->dir = pt->esq;
free (pt);

return a;
}

ABin removeMaior_2 (ABin *sitio)
{
ABin pt;

while ((*sitio)->dir != NULL)
{
sitio = &((*sitio)->dir);
}
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
do antigo nodo. &sitio é um valor aleatória qualquer aqui. */
pt = *sitio; // *sitio tem o nodo com maior elemento dado que (*sitio)->dir = NULL
*sitio = pt->esq; // Mesmo que *sitio = (*sitio)->esq // Processo de desligar o nodo com maior elemento

return pt;
}

/* Remove (libertando o espaço respectivo) todos os elementos da árvore *a que estão a uma profundidade superior a l, 
retornando o número de elementos removidos. Assuma que a profundidade da raíz da árvore é 1, e por isso a invocação de 
pruneAB(&a,0) corresponde a remover todos os elementos da árvore a.*/

int pruneAB (ABin *a, int l)
{
int elem_removidos  = 0;

if (l > 0 && *a != NULL)
{
       elem_removidos =  pruneAB (&((*a)->esq), l - 1) +  pruneAB (&((*a)->dir), l - 1);

}

// Sei que estou num nodo que posso libertar se for diferente de NULL.
else if (*a != NULL && l <= 0)
{
elem_removidos = 1 +  pruneAB (&((*a)->esq),l - 1) //remove todos os elementos da sub-árvore esquerda
                   +  pruneAB (&((*a)->dir),l - 1); // remove todos os elementos da sub-árvore direita
free (*a);
*a = NULL;
}
return elem_removidos;
}

int nivelV (ABin a, int n, int v[])
{
	int res = 0;

	if (!n || !a) return res;

	else if (n == 1 && a)
	     {
			 v[res] = a->valor;
			 res++;
		 }
		 else if (a)
		 	  {
				  res = nivelV ( a->esq, n - 1, v);
				  res += nivelV ( a->dir, n - 1, v + res);
			  }
	return res;
}

int quantosMaiores (ABin a, int x)
{
int res = 0;

if (!a) return res;
 	else if (a->valor < x || a->valor == x)
		res = quantosMaiores (a->dir, x);
		else if (a->valor > x)
			{
			res++;
			res += quantosMaiores (a->esq, x);
			res += quantosMaiores (a->dir, x);
			}
return res;
}

int deProcura (ABin a)
{
int res = 0;

if (!a) 
	return 1;
else if (maior_elemento (a->esq, a->valor)
         && menor_elemento (a->dir, a->valor))
        {
         	res = deProcura (a->esq);
            if (res != 0)
                    res = deProcura (a->dir);
        }
        else res = 0;
return res;
}

