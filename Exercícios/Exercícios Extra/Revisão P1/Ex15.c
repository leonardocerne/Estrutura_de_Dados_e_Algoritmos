
/*
Escreva uma func ¸˜ ao que retorne o elemento menor ou igual (floor) que um de referˆ encia
 x emumaABB.
*/
#include "TABB.c"

int aux(TABB *a, int x, int resp){
    if((!a)) return resp;
    if(a->info == x) return a->info;
    if(a->info < x){
        resp = a->info;
        return aux(a->dir, x, resp);
    }
    return aux(a->esq, x, resp);
}

int kfloor(TABB *a, int x){
    if(!a) return 0;
    return aux(a, x, 0);
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
            printf("\tDigite o k:\n");
            scanf("%d", &k);
            resp = kfloor(raiz, k);
            printf("%d", resp);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    TABB_libera(raiz);
    return 0;
}