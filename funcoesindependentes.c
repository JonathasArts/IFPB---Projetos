#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <conio2.h>
#include "tree.h"

#define ESC 27
#define NUM_NOMES 19        /* define a quantidade de nomes no array */
#define NUM_VAR 7
#define TAM    11       	/* define o tamanho maximo do nome */
#define NUM_IMP 4
#define TAMIMP   5      	/* define o tamanho maximo do nome */


/* FUNÇÃO PARA EXIBIR/IMPRIMIR O CABEÇALHO DO PROGRAMA
PARAMETROS: - void
RETORNO: - void */
void cabecalho(void){
	normvideo();system("CLS");		//  Limpa e Normaliza a tela
	textbackground(DARKGRAY);
	textcolor(BLACK);
	printf(" ------------------------------------------------------------------------------ ");
	printf("\tV1.0 - Interpretador de Comandos para Manipulacao de Arvores Binarias\t"		 );
	printf("\tAlunos: JONATHAS ART'S e NATACHA TARGINO\t\t\t\t"								 );
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
}/* FIM FUNÇÃO */  



/* FUNÇÃO PARA ...
PARAMETROS: - ...
RETORNO: - .... */
int isNumeric (const char* str)   
{  
    char *stop = 0;  
    strtoul (str, &stop, 10);   
    return (stop - str == strlen (str));  
}/* FIM FUNÇÃO */ 


/* FUNÇÃO PARA ...
PARAMETROS: - ...
RETORNO: - .... */
void comandocerto(int *i, int *option, int *tokenint){  
  
	char frase[64];
    char *token = NULL;
    char *tokenvar;
    char *help;
    int certo = 0, comvalor = 0, valida = 0, c;
 
    char comandos[NUM_NOMES][TAM] = {
		"croot", 
		"cleft",
		"cright",
		"goleft",
		"goright",
		"back",
		"goroot",
        "search",
 		"tree",
	    "deltree",
        "height",
		"size",
		"cnextleft",
        "cnextright",
		"leafs",
		"quit",
        "help",
        "whereami",
        "clear"
	};  
                                      
    char possuivar[NUM_VAR][TAM] = {
        "croot", 
		"cleft",
	    "cright",
        "search",
        "tree",
	   	"cnextleft",
        "cnextright"
	}; 
                                                                    
    char tipoimprime[NUM_IMP][TAMIMP] = {
        "/pre", 
		"/pos",
		"/in",
		"/arv"
	};                                     
   
    
	while(valida == 0){											// Laço para validação da expressão												
		fflush(stdin);
		
		printf("\n\n Digite um comando valido:\n >> "); 
        scanf("%[^\n]s", &frase);
   
        token= strtok(frase, " " );  
                          
        if( token != NULL){
           if(!isNumeric(token)){           
        	   strlwr(token);                            
        	   tokenvar = token;
        	   for(*i = 0; *i < NUM_NOMES; *i += 1){
                 	if(!strcmp(comandos[*i], tokenvar)){
                    	certo = 1;
            		    break;
            	     }//  
                }  //
            }//
        }        
        
        if(certo == 1){          
        	token = strtok( NULL, " " );
        	
   
    		if(token != NULL){
            	if(isNumeric(token)){
                	for(c = 0; c < NUM_VAR; c++){                      
                    	if(!strcmp(possuivar[c], tokenvar) && strcmp("tree", tokenvar)) {                    
                        	*tokenint = atoi(token);
                          	*option = 1;						// 
                          	valida = 1;
                       	}
                	}
            	}
                 
                if(!strcmp(token, "/?") ){
                    help = token;
                    *option = 2;								// 
                	valida = 1;
                }//
                 
                else{
                	for(c = 0; c < NUM_IMP; c++){ 
                    	if(!strcmp(tipoimprime[c], token)){
                        	*tokenint = ++c;
                         	*option = 1;
                          	valida = 1;
						}
                    }
                }//                 
            }//
      

            if (token == NULL){ 
            	for(c = 0; c < NUM_VAR; c++){                      
                	if(!strcmp(possuivar[c], tokenvar)) {                                        
                    	valida = 0;
                      	c = NUM_VAR;
                 	}//
                 	else{
                    	valida = 1;
                      	*option = 1;
					}
                }
        	}//               
        }  
        
		if(valida == 0){               							// Caso Expressão invalida continua no while
	    	if(certo==1){
	    		textcolor(RED);
            	printf("\n Erro de sintaxe! Digite Comando /? para ajuda\n\a");	// Mensagem de aviso para o Usuário
		    	textcolor(LIGHTGRAY);
		    	certo=0;
	    	}
			else{
			 	textcolor(RED);
            	printf("\n Comando Invalido! Digite Novamente.\n\a");
				textcolor(LIGHTGRAY); 
			} 		
	    }//   
        
        if (valida == 1){
          token = strtok( NULL, " " );               
             if(token != NULL){
               	if(isNumeric(token)){ 
                	textcolor(RED);     
                 	printf("\n Excesso de parametros! Digite Novamente\n\a");
                 	textcolor(LIGHTGRAY); 
                 	valida = 0;
				}
               	else{
                 	textcolor(RED);     
                 	printf("\n Comando Invalido! Digite um comando por vez!\n\a");
                 	textcolor(LIGHTGRAY); 
                 	valida = 0;
				} 
             }   
        }       
    }//
    ++*i;														// 
}/* FIM FUNÇÃO */ 


/* FUNÇÃO PARA ...
PARAMETROS: - ...
RETORNO: - .... */
void executandocomandos (int *comando, int *opcao, int *valor){ 
	arvore arv, aux, auxdel;
    noarv* local;
    int L=0, R=0, passos=0;
    inicializa(&arv);
    
    char x;
    int cont = 0, i=0;
    
	do{  
    	comandocerto(comando, opcao, valor);
 
		switch (*comando){
        	case 1:{
				if(*opcao == 1){
                    if(i==0){      
	                	if(constroiRaiz(&arv,*valor)){
	                		textcolor(BROWN);printf("\n Raiz da arvore criada com valor [%d]!\n", exibe(arv));textcolor(LIGHTGRAY); 
	                	}
	                	aux = arv;
	                	i++;
					}
                	else{
                         textcolor(RED);
                         printf("\n A arvore ja possui raiz!\n\a");
                         textcolor(LIGHTGRAY);}
                  	break;
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Cria raiz da arvore\n"); 
                   	printf("\n Sintaxe:\n  croot (valor)");textcolor(LIGHTGRAY); 
                 	break;
				}
           }

            case 2:{
		   		if(*opcao == 1){
				   if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
				   if(L){
                		if(!criafilhoesquerdo(aux, *valor)){
                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho esquerdo\n\a");textcolor(LIGHTGRAY);
                		}
                		else{
                			textcolor(BROWN);printf("\n Filho esquerdo criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
                		}
                		break;
                	}
					else{
						if(!criafilhoesquerdo(arv, *valor)){
                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho esquerdo\n\a");textcolor(LIGHTGRAY);
                		}
                		else{
                			textcolor(BROWN);printf("\n Filho esquerdo criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
                		}
                		break;
					}	
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Cria filho esquerdo\n");
                   	printf("\n Sintaxe:\n  cleft (valor)");textcolor(LIGHTGRAY);  
                   	break;
				}
		    }
                
            case 3:{
		   	    if(*opcao == 1){
                	if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(R){
                		if(!criafilhodireito(aux, *valor)){
                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho direito\n\a");textcolor(LIGHTGRAY);
                		}
                		else{
                			textcolor(BROWN);printf("\n Filho direito criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
                		}
                		break;
                	}
					else{
						if(!criafilhodireito(arv, *valor)){
                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho direito\n\a");textcolor(LIGHTGRAY);
                		}
                		else{
                			textcolor(BROWN);printf("\n Filho direito criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
                		}
                		break;
					}
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Cria filho direito\n");
                   	printf("\n Sintaxe:\n  cright (valor)");textcolor(LIGHTGRAY); 
                   	break;
				}
    	    }
           
		    case 4:{
				if(*opcao == 1){
					if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(!temFilhoEsquerdo(aux)){
						aux = (arvore)filhoesq(aux);
						L++;R++;
		                textcolor(BROWN);printf("\n Caminhou para o filho esquerdo [%d]", exibe(aux));textcolor(LIGHTGRAY);
		                break;
		            }
		            else{
                  		textcolor(RED);printf("\n Nao existe filho esquerdo\n\a");textcolor(LIGHTGRAY);
                  		break;
                  	}
				}
				else if(*opcao == 2){
	               	textcolor(BROWN);printf("\n Caminha para o filho esquerdo\n");
	               	printf("\n Sintaxe:\n  goleft");textcolor(LIGHTGRAY);
	               	break;
				}
            }
                
            case 5:{
				if(*opcao == 1){
					if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(!temFilhoDireito(aux)){
						aux = (arvore)filhodir(aux);
						R++;L++;
		                textcolor(BROWN);printf("\n Caminhou para o filho direito [%d]", exibe(aux));textcolor(LIGHTGRAY);
		                break;
		            }
		            else{
                  		textcolor(RED);printf("\n Nao existe filho direito\n\a");textcolor(LIGHTGRAY);
                  		break;
                  	}
				}
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Caminha para o filho direito\n");
                   	printf("\n Sintaxe:\n  goright");textcolor(LIGHTGRAY);  
                   	break;
				}                   
            }
           
            case 6:{
				if(*opcao == 1){
					if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
                	if(exibe(aux)==exibe(arv)){
		                textcolor(RED);printf("\n Voce ja esta na raiz =P\n\a");textcolor(LIGHTGRAY);
						break;
					}                          
		            else{
		                aux = back(aux);
		                textcolor(BROWN);printf("\n Voltou para o no [%d]\n", exibe(aux));textcolor(LIGHTGRAY);
						break;
		            }
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Volta para o no ancestral\n");
                   	printf("\n Sintaxe:\n  back");textcolor(LIGHTGRAY); 
                   	break;
				}
            }     	

            case 7:{
				if(*opcao == 1){
                	if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(aux==arv){
                		textcolor(RED);printf("\n Voce ja esta no no raiz [%d]\n\a", exibe(aux));textcolor(LIGHTGRAY);
                		break;
                	}	
					else{
						aux = voltaRaiz(aux);
						textcolor(BROWN);printf("\n Voltou para o no raiz [%d]\n", exibe(aux));textcolor(LIGHTGRAY);
	                  	break;
					}
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Volta para a raiz da arvore\n");
                   	printf("\n Sintaxe:\n  goroot");textcolor(LIGHTGRAY); 
                	break;
				}                   
            }
                
            case 8:{
				if(*opcao == 1){
                	if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(busca (arv, *valor)){
                       textcolor(BROWN);      
                       printf("\n A arvore possui o valor procurado");
                       textcolor(LIGHTGRAY);
					} 
                    else{
                        textcolor(RED); 
                        printf("\n A arvore nao possui o valor procurado\n\a");
                        textcolor(LIGHTGRAY);
					}   
                  	break;
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Pesquisa pela existencia de um no\n");
                   	printf("\n Sintaxe:\n  search (valor)");textcolor(LIGHTGRAY); 
                   	break; 
				}                  
            }
           
        	case 9:{
				if(*opcao == 1){
                    if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(*valor == 1){
                    	printf("\n");
                        textcolor(BROWN);preordem(arv);textcolor(LIGHTGRAY);
                    }
                    else if(*valor == 2){
                    	printf("\n");
						textcolor(BROWN);posordem(arv);textcolor(LIGHTGRAY);
                    }
                    else if(*valor == 3){
                    	printf("\n");
                    	textcolor(BROWN);inordem(arv);textcolor(LIGHTGRAY); 
                    }    
                    else if(*valor == 4){
                    	printf("\n");
                    	textcolor(BROWN);imprime(aux, 0);textcolor(LIGHTGRAY); 
                    }   
                  	break;
				}
				else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Exibe a sequencia de elementos da arvore em PRE, POS ,IN-ordem ou no formato da ARV\n");
                   	printf("\n Sintaxe:\n  tree (argumento)");textcolor(LIGHTGRAY); 
                   	break;
				}                   
            }  
            
        	case 10:{
				if(*opcao == 1){
                	if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					else{
						if(aux==arv){
							int dado; dado = exibe(arv);
							auxdel = back(arv);
							remover(arv);
							arv = auxdel; i=0;
							textcolor(BROWN);printf("\n Removeu a sub-arvore a partir da raiz [%d]\n", dado);textcolor(LIGHTGRAY);
							break;
						}
						else{
							int dado; dado = exibe(aux);
							auxdel = back(aux);
							remover(aux);
							aux = auxdel;
							textcolor(BROWN);printf("\n Removeu a sub-arvore a partir do no [%d]\n", dado);textcolor(LIGHTGRAY);
							break;
						}
					}
				}
                else if(*opcao == 2){
                   	textcolor(BROWN);printf("\n Remove todos os nos da arvore ou uma sub-arvore de um no\n");
                   	printf("\n Sintaxe:\n  deltree");textcolor(LIGHTGRAY); 
                   	break;
				}                  
			}
                
        	case 11:{
				if(*opcao == 1){
					cont = altura(aux); 
                    if(cont < 0){
                            textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
					}
                	else{
                            textcolor(BROWN);      
                	        printf("\n A arvore possui altura: %i\n", cont);
                	        textcolor(LIGHTGRAY);
					}       
                  	break;
				}
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Exibe a altura relativa da arvore\n");
                   	printf("\n Sintaxe:\n  height");textcolor(LIGHTGRAY);
                   	break;
				}                  
        	}
           
        	case 12:{
  		        if(*opcao == 1){
					cont = nos(arv); 
                    if(cont == 0){
                            textcolor(RED);      
                	        printf("\n A Arvore nao possui raiz\n\a");
                	        textcolor(LIGHTGRAY);
					}
                	else{
                            textcolor(BROWN);      
                	        printf("\n A arvore possui %i nos\n\a", cont);
                	        textcolor(LIGHTGRAY);
					}       
                  	break;
				}
                else if(*opcao == 2){
                   	textcolor(BROWN);printf("\n Exibe a quantidade de nos da arvore\n");
                  	printf("\n Sintaxe:\n  size");textcolor(LIGHTGRAY); 
                   	break;
				}                   
            }
                
            case 13:{
				if(*opcao == 1){
                	if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					else{
						passos=0;
						while(!temFilhoEsquerdo(aux)){
							aux = (arvore)filhoesq(aux);
							L++;R++;passos++;
						}
	                  	if(L){
	                		if(!criafilhoesquerdo(aux, *valor)){
	                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho esquerdo\n\a");textcolor(LIGHTGRAY);
	                		}
	                		else{
	                			textcolor(BROWN);printf("\n Filho esquerdo criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
	                		}
	                	}
						else{
							if(!criafilhoesquerdo(arv, *valor)){
	                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho esquerdo\n\a");textcolor(LIGHTGRAY);
	                		}
	                		else{
	                			textcolor(BROWN);printf("\n Filho esquerdo criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
	                		}
						}
						while(passos>0){
							aux = back(aux);
							passos--;
						}
						break;
					}
				}
                else if(*opcao == 2){
                  	textcolor(BROWN);printf("\n Criar proximo filho disponivel a esquerda\n");
                   	printf("\n Sintaxe:\n  cnextleft (valor)");textcolor(LIGHTGRAY);
                   	break;
				}                   
            }
                
        	case 14:{
		   		if(*opcao == 1){
					if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n");textcolor(LIGHTGRAY);
                  		break;
					}
					else{
						passos=0;
						while(!temFilhoDireito(aux)){
							aux = (arvore)filhodir(aux);
							R++;L++;passos++;
						}
	                  	if(R){
	                		if(!criafilhodireito(aux, *valor)){
	                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho direito\n\a");textcolor(LIGHTGRAY);
	                		}
	                		else{
	                			textcolor(BROWN);printf("\n Filho direito criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
	                		}
	                	}
						else{
							if(!criafilhodireito(arv, *valor)){
	                			textcolor(RED);printf("\n Arvore Binaria ja possui um filho direito\n\a");textcolor(LIGHTGRAY);
	                		}
	                		else{
	                			textcolor(BROWN);printf("\n Filho direito criado com valor [%d]\n", *valor);textcolor(LIGHTGRAY);  
	                		}
						}
						while(passos>0){
							aux = back(aux);
							passos--;
						}
						break;
					}
                }
                else if(*opcao == 2){
                   	textcolor(BROWN);printf("\n Criar proximo filho disponivel a direita\n");
                  	printf("\n Sintaxe:\n  cnextright (valor)");textcolor(LIGHTGRAY); 
                   	break;
				}                  
            }

        	case 15:{
  		        if(*opcao == 1){
                    if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}                   
                	else{  
						cont = folhas(arv);             
                        textcolor(BROWN);      
                	    printf("\n A arvore possui %i folhas\n", cont);
                	    textcolor(LIGHTGRAY);
					}     
                  	break;
				}
                else if(*opcao == 2){
                   	textcolor(BROWN);printf("\n Exibe a quantidade de nos folhas\n");
                   	printf("\n Sintaxe:\n  leafs");textcolor(LIGHTGRAY); 
                	break;
				}                 
            }
                
        	case 16:{
				if(*opcao == 1){
                      cont = 0;
                      textcolor(BROWN);printf("\n (S = SIM, N = Nao ou ESC para desistir da saida!)");textcolor(LIGHTGRAY);
					  textcolor(BROWN);printf("\n Deseja realmente fechar o interpretador de Arvores Binarias? [ ]");textcolor(LIGHTGRAY);
					  do{													// Laço para tratamento de erros
						fflush(stdin);
						gotoxy(64,wherey());
						x = toupper(getch());								// Tratamento de erros
						textcolor(YELLOW);
						putchar(toupper(x));								// Captura do valor
						textcolor(LIGHTGRAY);
						if(x!='N' && x!='S' && x!=ESC){						
							printf("\a");
						}
					  }while(x!='N' && x!='S' && x!=ESC);					// Saida do laço apenas com 'S', ESC ou 'N'
						if(x == 'S'){
							gotoxy(2,wherey()+2);							// Ajuste de impressão
							break;											// Saida do laço
						}	
		                else{
		                    *comando = 0;
		                    break;
						}                     
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Sair do interpretador de comandos\n");
                   	printf("\n Sintaxe:\n  quit");textcolor(LIGHTGRAY); 
                   	break;
				}
            }

            case 17:{
				if(*opcao == 1){
                	imprimehelp();
                  	break;
                }
                else if(*opcao == 2){
                   	textcolor(BROWN);printf("\n Exibe a lista de todos os comandos disponiveis\n");
                   	printf("\n Sintaxe:\n  help");textcolor(LIGHTGRAY); 
                   	break;
				}              
            }                 

        	case 18:{
		   		if(*opcao == 1){
					if(vazia(arv)){
						textcolor(RED);printf("\n A Arvore nao possui raiz\n\a");textcolor(LIGHTGRAY);
                  		break;
					}
					if(arv==aux){
						textcolor(BROWN);printf("\n Voce esta no no Raiz [%d]", exibe(aux));textcolor(LIGHTGRAY);
                  		break;
					}  
					else{
						textcolor(BROWN);printf("\n Voce esta no no [%d]", exibe(aux));textcolor(LIGHTGRAY);
                  		break;
					}
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Exibe o local (conteúdo) onde se encontra o no relativo\n");
                   	printf("\n Sintaxe:\n  whereami");textcolor(LIGHTGRAY); 
                   	break;
				}
            }
			case 19:{
		   		if(*opcao == 1){
					clear();
					cabecalho();
                  	break;
                }
                else if(*opcao == 2){
                	textcolor(BROWN);printf("\n Limpa a tela\n");
                   	printf("\n Sintaxe:\n  clear");textcolor(LIGHTGRAY); 
                   	break;
				}
            }                                                                  	

        }    
  }while(*comando!=16);

}/* FIM FUNÇÃO */ 


/* FUNÇÃO PARA EXIBIR/IMPRIMIR TELA DE DESPEDIDA DO PROGRAMA
PARAMETROS: - void
RETORNO: - void */
void sairdoSistema(void){
    fflush(stdin);normvideo();
	system("CLS");											//  Limpa e Normaliza a tela
	textcolor(BROWN);
	printf(" ------------------------------------------------------------------------------ ");
	printf(" ------------------------------------------------------------------------------ ");
    gotoxy(28,wherey()+4);
    printf("OBRIGADO PELA PREFERENCIA!!!");					// Imprime mensagem para o usuario
    gotoxy(22,12);
    printf(" BY JONATHAS ALMEIDA E NATACHA TARGINO");		// Direitos autorais =P #ÉNóis \0/\õ/
    gotoxy(54,22);
    textcolor(YELLOW);
	printf("ELES MERECEM NOTA 10,0 !!!");					// SUGESTÃO (vai que cola) kkkkkk...
    gotoxy(1,20);
	textcolor(BROWN);
	printf(" ------------------------------------------------------------------------------ ");
	textcolor(LIGHTGRAY);
	gotoxy(80,22);
}/* FIM FUNÇÃO */










