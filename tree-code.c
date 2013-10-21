#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio2.h>
#include <math.h>
#include "tree.h"

#define NUM_HELP 19
#define TAMHELP   86       /* define o tamanho maximo do nome */



void inicializa(arvore *arv) {
	*arv = NULL;
}/* FIM FUNÇÃO */



noarv* inicializa2(void) {
	return NULL;
}/* FIM FUNÇÃO */



noarv* constroi(int info){
	noarv *novo;

	if ((novo = (noarv*)malloc(sizeof(noarv))) == NULL)
		return NULL;
	novo->dado = info;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->ant = NULL;
	return(novo);
}/* FIM FUNÇÃO */



int vazia(arvore arv) {
	return (arv == NULL);
}/* FIM FUNÇÃO */



int temFilhoEsquerdo(arvore arv) {
	return(arv->esq == NULL);
}/* FIM FUNÇÃO */



int temFilhoDireito(arvore arv) {
	return(arv->dir == NULL);
}/* FIM FUNÇÃO */



int constroiRaiz(arvore *arv, int info){

    noarv *novo;  

    if( *arv = NULL )
        return 0;
	if ((novo = (noarv*)malloc(sizeof(noarv))) == NULL)
		return 0;
	novo->dado = info;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->ant = NULL;
	*arv = novo;
	return(1);
}/* FIM FUNÇÃO */



int criafilhoesquerdo(arvore arv, int info){
	noarv *novo;

	if (arv == NULL){ 
		return 0;
	}
	else if (arv->esq != NULL){    
        return 0;
	}
	else {
		novo = constroi(info);
		novo->ant = arv;
		arv->esq = novo;
	}
	return 1;
}/* FIM FUNÇÃO */



int criafilhodireito(arvore arv, int info){
	noarv *novo;

	if (arv == NULL){
		return 0;
	}
	else if (arv->dir != NULL){    
        return 0;
	}
	else {
		novo = constroi(info);
		novo->ant = arv;
		arv->dir = novo;
	}
	return 1;
}/* FIM FUNÇÃO */



noarv*  filhoesq(arvore arv) {
   if (vazia(arv))
      return NULL;
	return ( arv->esq );
}/* FIM FUNÇÃO */



noarv* filhodir(arvore arv) {
   if (vazia(arv))
      return NULL;
	return (arv->dir);
}/* FIM FUNÇÃO */



noarv* back(noarv* arv){
	  return arv->ant;      
}/* FIM FUNÇÃO */



noarv* voltaRaiz(noarv* arv){
	if(arv->ant!= NULL){
		voltaRaiz(arv = back(arv));
	}
	else
		return arv;
}/* FIM FUNÇÃO */



int exibe(noarv* arv){
	if(arv == NULL)
    	return 0;
    return arv->dado;
}/* FIM FUNÇÃO */



void preordem(arvore arv ) {
	if (!vazia(arv)) {
		printf(" %i ", arv->dado); // Imprime o noh raiz
		preordem(arv->esq);
		preordem(arv->dir);
	}
}/* FIM FUNÇÃO */



void inordem(arvore arv) {
	if (!vazia(arv)) {
		inordem(arv->esq);
		printf(" %d ", arv->dado);
		inordem(arv->dir);
	}
}/* FIM FUNÇÃO */



void posordem(arvore arv) {
	if (!vazia(arv)) {
		posordem(arv->esq);
		posordem(arv->dir);
		printf(" %d ", arv->dado);
	}
}/* FIM FUNÇÃO */



int busca( arvore arv, int info ) {
	if (vazia(arv))
		return 0; // Nao encontrou o nodo
	if ( info == arv->dado)
		return 1;
	else if (busca(arv->esq, info))
		return 1;
	else
		return busca(arv->dir, info);
}/* FIM FUNÇÃO */


int altura( arvore arv) {
   if (arv == NULL) 
      return -1; // altura de árvore vazia é -1
   else {
      int he = altura(arv->esq);
      int hd = altura(arv->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}/* FIM FUNÇÃO */



int nos(arvore arv) {
    if (vazia(arv)) return 0;
    return nos(arv->esq) + nos(arv->dir) + 1;
}/* FIM FUNÇÃO */



void imprime(arvore arv, int nivel){
     int i;
     if(arv == NULL)
        return;
     imprime(arv->dir, nivel+1);
     for(i=0;i<nivel;i++)
        printf("      ");
     printf("%6d\n\n",arv->dado);
     imprime(arv->esq,nivel+1);
      
}/* FIM FUNÇÃO */



int folhas(arvore arv) {
    if (vazia(arv))
       return 0;
    if ((arv->esq == NULL) && (arv->dir == NULL))
                return 1; 
    else            
    return folhas(arv->esq) + folhas(arv->dir);
}/* FIM FUNÇÃO */



noarv* localiza( arvore arv, int info ) {
    noarv* aux;

	if (vazia(arv))
		return NULL; // Nao encontrou o nodo
	if ( info == arv->dado)
		return arv;
	else if ( (aux = (noarv*) busca(arv->esq, info)) )
		return aux;
	else
		return (noarv*) busca(arv->dir, info);
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA EXIBIR/IMPRIMIR O AJUDA ("HELP") DO PROGRAMA
PARAMETROS: - void
RETORNO: - void */
int remover(noarv* arv){
   if (!vazia(arv)) {
        remover(arv->esq); 
        remover(arv->dir);
        
		if(arv->ant!=NULL){ 			// Se não está na Raiz ajustar links
        	if(arv->ant->esq==arv)
        		arv->ant->esq=NULL;
        	if(arv->ant->dir==arv)
        		arv->ant->dir=NULL;
        }
        free(arv);
   }
   return 0;
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA LIMPAR A TELA
PARAMETROS: - void
RETORNO: - void */
void clear(void){
	system("cls");
}/* FIM FUNÇÃO */


/* FUNÇÃO PARA EXIBIR/IMPRIMIR O AJUDA ("HELP") DO PROGRAMA
PARAMETROS: - void
RETORNO: - void */                                     
void imprimehelp(void){
    int i;																					// Variavel para o for
    
    char comandos[NUM_HELP][TAMHELP] = {													// Array com o HELP
		" 1 croot       | Cria raiz da arvore                                      |",
        " 2 cleft       | Cria filho esquerdo                                      |",
        " 3 cright      | Cria filho direito                                       |",
        " 4 goleft      | Caminha para o filho esquerdo                            |",
        " 5 goright     | Caminha para o filho direito                             |",
        " 6 back        | Volta para o no ancestral                                |",
        " 7 goroot      | Volta para a raiz da arvore                              |",
        " 8 search      | Pesquisa pela existencia de um no                        |",
        " 9 tree        | Exibe os elem. da arv. em PRE, POS ,IN-ordem ou ARVORE   |",
        "10 deltree     | Remove todos os nos da arvore ou uma subarvore de um no  |",
        "11 height      | Exibe a altura relativa da arvore                        |",
        "12 size        | Exibe a quantidade de nos da arvore                      |",
        "13 cnextleft   | Criar proximo filho disponivel a esquerda                |",
        "14 cnextright  | Criar proximo filho disponivel a direita                 |",
        "15 leafs       | Exibe a quantidade de nos folhas                         |",
        "16 quit        | Sair do interpretador de comandos                        |",
        "17 help        | Exibe a lista de todos os comandos disponivel            |",
        "18 whereami    | Exibe o local (conteudo) onde se encontra o no relativo  |",
        "19 clear       | Limpa a tela                                             |"
	};

	/* ---------- Cabeçalho do HELP ---------- */
    textcolor(BROWN);
    printf("\n");
    printf(" ============================================================================== ");
	printf(" |  ");textcolor(YELLOW);printf("COMANDOS");textcolor(BROWN);
	printf("       | ");textcolor(YELLOW);printf("OBJETIVOS");textcolor(BROWN);
	printf("                                                |");printf("\n");
	printf(" ============================================================================== ");
    /* ---------- FIM Cabeçalho do HELP ---------- */
    
	for(i = 0; i < NUM_HELP; i += 1){														// for para impressão dos comandos e objetivos
    	printf(" |  %s", comandos[i]);
        printf("\n");
    }
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
}/* FIM FUNÇÃO */


   



