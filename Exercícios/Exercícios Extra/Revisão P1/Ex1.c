//Faça uma função que recebe uma TAB e retorna uma lista simplesmente encadeada ordenada
#include "TAB.c"
#include "TLSE.c"

TLSE *insere_ord(TLSE *l, int x){
    if((!l) || (x < l->info)) l = TLSE_insere(l, x);
    if(x > l->info) l->prox = insere_ord(l->prox, x);
    return l;
}

TLSE* AtoL(TAB *a, TLSE *l){
    if(!a) return l;
    l = insere_ord(l, a->info);
    l = AtoL(a->esq, l);
    l = AtoL(a->dir, l);
    return l;
}

TLSE *lista_ord(TAB *a){
    TLSE *l = TLSE_inicializa();
    l = AtoL(a, l);
    return l;
}

int main(void){
    int opcao, x;
    TAB* raiz = NULL;
    TLSE* lista = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Lista ordenada\n");
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
            TAB_imp_sim(raiz);
            printf("\n");
            break;
        
        case 3:
            lista = lista_ord(raiz);
            printf("\n\tA lista ordenada com os elementos da arvore eh: ");
            if(!lista) printf("se fudeu");
            TLSE_imp_rec(lista);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TAB_libera(raiz);
    TLSE_libera(lista);
    return 0;
}