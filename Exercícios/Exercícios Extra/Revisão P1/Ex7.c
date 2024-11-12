/*
Escreva uma função que verifica se uma TABB é zig zag ou não, ou seja, um nó que não seja a raiz nunca terá dois filhos
*/
#include "TABB.c"

int aux(TABB *a){
    if(!a) return 1;
    if(a->esq && a->dir) return 0;
    if(a->esq) return aux(a->esq);
    return aux(a->dir); 
}

int zigzag(TABB *a){
    if(!a) return 0;
    if(!a->esq && !a->dir) return 1;
    if(!a->esq) return aux(a->dir);
    else if(!a->dir) return aux(a->esq);
    return (aux(a->esq) && aux(a->dir)); 
}


int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
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
            resp = zigzag(raiz);
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