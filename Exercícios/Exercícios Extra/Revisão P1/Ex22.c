/*
Q2 - Verificar se as condições estabelecidas no enunciado são respeitadas, caso sim, retore 1, caso não, retorne 0. int teste(TABB* a);

1 - Todos os nós folhas devem estar no mesmo nivel.
2 - Todos os nós de altura {0, 3, 6, 9 ...} devem ser ou folha ou pai de dois filhos.
3 - Todos os nós de altura {1, 4, 7, 10 ...} devem ter somente um filho a esquerda.
4 - Todos os nós de altura {2, 5, 8, 11 ...} devem ter somente um filho a direita.
*/

#include "TABB.c"

int nivel(TABB *raiz, TABB *x){
    if((raiz->info == x->info) || !raiz) return 0;
    if(raiz->info > x->info) return 1 + nivel(raiz->esq, x);
    return 1 + nivel(raiz->dir, x);
}

int teste2(TABB *a,TABB *raiz, int n){
    if(!a) return 1;
    if(TABB_altura(a) % 3 == 0) {
        if((a->esq && !a->dir) || (!a->esq && a->dir)) return 0;
        if(!a->esq && !a->dir){
            if(nivel(raiz, a) != n) return 0;
        }
    }
    else if((TABB_altura(a) - 1) % 3 == 0) {
        if(a->dir || (!a->dir && !a->esq)) return 0;
    }
    else if((TABB_altura(a) - 2) % 3 == 0) {
        if(a->esq || (!a->dir && !a->esq)) return 0;
    }
    return (teste2(a->esq,raiz, n) && teste2(a->dir,raiz, n));
}


TABB *achafolha(TABB *a){
    if(!a->esq && !a->dir) return a;
    if(a->esq) return achafolha(a->esq);
    return achafolha(a->dir);
}


int teste(TABB *a){
    if(!a) return 0;
    TABB *f = achafolha(a);
    int n = nivel(a, f);
    return teste2(a, a, n);
}

int main(void){
    int opcao, x,resp, k;
    TABB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar o floor de k\n");
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
            resp = teste(raiz);
            if(resp) printf("\nSim");
            else printf("\nnao");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    TABB_libera(raiz);
    return 0;
}