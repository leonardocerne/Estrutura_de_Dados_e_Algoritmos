/*
(Q2) Retornar todas as informações ancestrais de um nó na árvore binária, da raiz da árvore até o elemento passado como parâmetro,
 usando a biblioteca de lista encadeada - TLSEINT* misc(TABB *a, int elem)
*/
#include "TABB.c"
#include "TLSEINT.c"
#include <limits.h>
TLSEINT * percorre(TABB *a, TLSEINT *resp, int elem){
    if((!a) || (a->info == elem)) return resp;
    if(a->info > elem) {
        resp = TLSEINT_insere(resp, INT_MIN, a->info);
        return percorre(a->esq, resp, elem);
    }
    if(a->info < elem) {
        resp = TLSEINT_insere(resp, a->info, INT_MAX);
        return percorre(a->dir, resp, elem);
    }
    return resp = TLSEINT_insere(resp, INT_MIN, INT_MAX);
}

TLSEINT *misc(TABB *a, int elem){
    if(!a) return NULL;
    TLSEINT *resp = TLSEINT_inicializa();
    resp = percorre(a, resp, elem);
    return resp;
}

int main(void){
    int opcao, x,ver, N;
    TABB* raiz = NULL;
    TLSEINT *resp = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Lista com caminho ate N\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf("%d", &x);
            printf("\n");
            raiz = TABB_insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TABB_imp_ident(raiz);
            printf("\n");
            break;

        case 3:
            printf("\t\n Digite o N:");
            scanf("%d", &N);
            resp = misc(raiz, N);
            TLSEINT_imprime(resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}