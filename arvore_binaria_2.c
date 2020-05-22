#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

typedef struct lista {
    int valor;
    struct lista *prox;
} *LInt;

typedef struct dlista {
	int valor;
	struct dlista *prox,*ant;
} *DLInt;

/*Calcula o tamanho (número de elementos) de uma lista duplamente ligada.
 Assumimos receber um elemento qualquere não obrigatoriamente a cabeça*/
int DLLength (DLInt l)
{
int r = 0;
DLInt e = l;

if (l)
{
while (l)
{
	l = l->prox;
	r++;
	l = l->prox;
}
while (e)
{
	r++;
	e = e->ant;
}
}


return r;
}


/* Testa se 2 árvores binárias são iguais. Devolve 1 se forem*/
int AIguais (ABin a, ABin b)
{
int r = 0;
if (!a && !b)
	r = 1;

if (a && b)
{
	if (a->valor == b->valor)
	{
		if (AIguais (a->esq,b->esq)
		  && AIguais(a->dir,b->dir))
			r = 1;
	}
}
return r;
}

/* Constroi uma lista ordenada a apartir dos elementos de uma árvore de procura a.
Travessia inorder*/
DLInt inorderDL (ABin a) {
    DLInt e=NULL, d=NULL, r=NULL, e2=NULL;
    if (a) {
        e = inorderDL(a->esq);
        e2 = e;
        r = newDLInt(a->valor, NULL, NULL);
        if (e) {
            while (e->prox) {
                e = e->prox;
            }
            e->prox = r;
            r->ant = e;
        }
        else
            e2 = r;
        d = inorderDL(a->dir);
        r->prox = d;
        if (d)
            d->ant = r;
    }
    
    return e2;
}

// COM LISTAS DUPLAMENTE LIGADAS TEMOS DE PERGUNTAR SEMPRE SE RECERBEMOS A CABEÇA OU NÃO
// Sempre por omissão assumir o caso mais complicado

/*Assumindo que não recemos as cabeças das listas*/
/*Acrescenta a antes de *d*/
void concatAntes (DLInt a, DLInt *d)
{
if (a)
{
while (a->prox)
    a = a->prox;
if (*d)
{
while ((*d)->ant)
    d = &((*d)->ant);
(*d)->ant = a;
a->prox = *d;
}
else *d = a;
}
}  

/*Acrescenta d depois de *a*/
// se der for vazia não acontece nada,se a vor vazia, coloco d lá
void concatDepois (DLInt *a, DLInt d){
    if (d) {
        while (d->ant)
            d = d->ant;
        if (*a) {
            while ((*a)->prox)
                a = &((*a)->prox);
            (*a)->prox = d;
            d->ant = *a;
        }
        else
            *a = d;
    }
}