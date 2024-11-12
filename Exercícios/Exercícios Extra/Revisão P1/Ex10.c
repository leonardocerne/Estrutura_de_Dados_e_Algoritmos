/*
Retornar todos os ancestrais de um nó na árvore de busca binária, da raiz da árvore até o elemento passado como parâmetro, usando a biblioteca de lista encadeada - TLSE* ancestrais(TABB *a, int elem);
*/

#include "TABB.c"
#include "TLSE.c"

TLSE *aux(TABB *a, int elem, TLSE *l){
    if((a->info == elem) || (!a)) return l;
    l = TLSE_insere(l, a->info);
    if(a->info > elem) return aux(a->esq, elem, l);
    if(a->info < elem) return aux(a->dir, elem, l);
}

TLSE *ancestrais(TABB *a, int elem){
    TLSE *resp = NULL;
    resp = aux(a, elem, resp);
    return resp;
}

int main(void){
    int opcao, x, N;
    TABB* raiz = NULL;
    TLSE* resp = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar Estritamente Binaria\n");
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
            printf("Digite o N: ");
            scanf("%d", &N);
            resp = ancestrais(raiz, N);
            TLSE_imp_rec(resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    TLSE_libera(resp);
    TABB_libera(raiz);
    return 0;
}