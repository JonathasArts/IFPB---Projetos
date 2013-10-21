
typedef struct stnoarvore {
	int dado;
	struct stnoarvore *esq;
	struct stnoarvore *dir;
	struct stnoarvore *ant;
}noarv;

typedef noarv* arvore;

void inicializa(arvore *arv);
noarv* inicializa2(void);
noarv* constroi(int info);
int constroiRaiz(arvore *arv, int info);
int criafilhoesquerdo(arvore arv, int info);
int criafilhodireito(arvore arv, int info);
int vazia(arvore arv);
int temFilhoEsquerdo(arvore arv);
int temFilhoDireito(arvore arv);
void preordem(arvore arv );
void posordem(arvore arv);
void inordem(arvore arv);
noarv* filhoesq(arvore arv) ;
noarv* filhodir(arvore arv);
noarv* back(noarv* arv);
noarv* voltaRaiz(noarv* arv);
int exibe(noarv* arv);
int busca( arvore arv, int info );
int altura( arvore arv); 
int nos(arvore arv);
int folhas(arvore arv);
int remover(noarv* arv);
void imprime(arvore arv, int nivel);
void clear(void);
void imprimehelp(void);
