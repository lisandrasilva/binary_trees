/**
@file main.c
Ficheiro que tem a função principal (main) sobre árvores binárias
*/
#include <stdio.h>
#include <stdlib.h>
#include "Btree_functions.h"

/**
\brief 
Função principal
*/

int main()
{
int a[10];
int b[10];
int tamanho, tamanho_2, res_procura, res_procura_2, 
    Nelementos,Nelementos_2, elemProcura_rec, elemProcura_ita, elem_insercao = 0;
ABin arv1;

printf("->>> Insira separado por um espaço os elementos do array (máx 10 elems): ");
scanf("%d %d %d %d %d %d %d %d %d %d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);

printf ("-> Introduza a quantidade de elementos do array que preencherá a árvore: ");
scanf ("%d",&Nelementos);

printf ("-> Introduza a quantidade de elementos do árvore que preencherá o array: ");
scanf ("%d",&Nelementos_2);

printf ("-> Insira o elemento que queres procurar na árvore na procura_recursiva: ");
scanf ("%d",&elemProcura_rec);

printf ("-> Insira o elemento que queres procurar na árvore na procura_iterativa: ");
scanf ("%d",&elemProcura_ita);

printf ("-> Insira o elemento que queres inserir na árvore: ");
scanf ("%d",&elem_insercao);

// Teste da função fromArray
arv1 = fromArray (a,Nelementos);

// Teste da função size
tamanho = size(arv1);

// Teste da função toarray.
toArray(arv1,b,Nelementos_2);

// Teste da procura_recursiva
res_procura = procura_recursiva(elemProcura_rec,arv1);

// Teste da procura_iterativa
res_procura_2 = procura_iterativa(elemProcura_ita,arv1);

// Teste da inserção
insere_2(&arv1,elem_insercao);

tamanho_2 = size(arv1);

printf ("\nRESULTADOS:\n\n");

printf("-> Tamanho arv1 (antes da inserção): %d",tamanho); 
printf("\n-> Resultado da procura recursiva : %d",res_procura);
printf("\n-> Resultado da procura iterativa: %d", res_procura_2); 
printf("\n-> Tamanho arv1 após a inserção %d\n", tamanho_2);

return 0;
}
