/*
 Dada uma árvore binária de busca, escreva uma função que
 verifique se existe algum par de nós na árvore cuja soma de
 seus valores seja igual a um número S fornecido. int
 temPar(TABB* arv, int S)
*/
#include "TABB.c"

int aux(TABB *a, TABB *raiz, int S){
    if(!a) return 0;
    if(TABB_busca(raiz, S - a->info)) return 1;
    return (aux(a->esq, raiz, S) || aux(a->dir, raiz, S));
}

int temPar(TABB *a, int S){
    if(!a) return 0;
    return aux(a, a, S);
}

int main(void){
    int opcao, x, resp;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Ver se e AVL\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao){
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
            printf("\n\tDigite o valor S:");
            scanf("%d", &x);
            printf("\n");
            resp = temPar(raiz, x);
            if(resp) printf("\nTem par");
            else printf("\nNao tem par");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}