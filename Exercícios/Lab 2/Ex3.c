/*
(Q2) Retornar todas as informações ancestrais de um nó na árvore binária, da raiz da árvore até o elemento passado como parâmetro,
 usando a biblioteca de lista encadeada - TLSEINT* misc(TAB *a, int elem)
*/
#include "TAB.c"
#include "TLSEINT.c"
#include <limits.h>

TLSEINT* aux(TAB *a, int elem, TLSEINT *resp){
    if(!a) return NULL;
    if(a->info < elem){
        resp = TLSEINT_insere(resp, a->info, INT_MAX);
        if(TAB_busca(a->esq, elem)) return aux(a->esq, elem, resp);
        return aux(a->dir, elem, resp);
    }
    else if(a->info > elem){
        resp = TLSEINT_insere(resp, INT_MIN, a->info);
        if(TAB_busca(a->esq, elem)) return aux(a->esq, elem, resp);
        return aux(a->dir, elem, resp);
    }
    resp = TLSEINT_insere(resp, INT_MIN, INT_MAX);
    return resp;
}

TLSEINT *misc(TAB *a, int elem){
    if((!a) || (!TAB_busca(a, elem))) return NULL;
    TLSEINT *resp = TLSEINT_inicializa();
    resp = aux(a, elem, resp);
    return resp;
}

int main(void){
    int opcao, x,ver, N;
    TAB* raiz = NULL;
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
            raiz = insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TAB_imp_ident(raiz);
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


    TAB_libera(raiz);
    return 0;
}