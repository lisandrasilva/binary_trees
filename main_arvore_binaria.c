/**
@file main.c
Ficheiro que tem a função principal (main) sobre árvores binárias
*/
#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria_1.h"

/**
\brief 
Função principal
*/

int main()
{
int a[10];
int b[10];
int tamanho, tamanho_2, res_procura, res_procura_2 = 0;
ABin arv1;

printf("-> Insira separado por um espaço os elementos do array (máx 10 elems): ");

scanf("%d %d %d %d %d %d %d %d %d %d",a,a+1,a+2,a+3,a+4,a+5,a+6,a+7,a+8,a+9);

printf("\n");

// Teste da função fromArray
arv1 = fromArray (a,8);

// Teste da função size
tamanho = size(arv1);

// Teste da função toarray
toArray(arv1,b,6);

// Teste da procura_recursiva
res_procura = procura_recursiva(4,arv1);

// Teste da procura_iterativa
res_procura_2 = procura_iterativa(4,arv1);

// Teste da inserção
arv1 = insere(arv1,7);

tamanho_2 = size(arv1);

printf("-> Tamanho arv1 (antes da inserção): %d",tamanho); 
printf("\n-> Resultado da procura recursiva : %d",res_procura);
printf("\n-> Resultado da procura iterativa: %d", res_procura_2); 
printf("\n-> Tamanho arv1 após a inserção %d\n", tamanho_2);

return 0;
}