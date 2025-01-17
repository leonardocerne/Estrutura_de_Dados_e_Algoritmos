/*
Faça uma função que verifica se uma TAB é estritamente zigzag, ou seja, cada nó só pode ter um filho(exceto a raiz), e se um nó
tem filho a esquerda, seu filho precisa ter um filho a direita, e vice versa.
*/

#include "TAB.c"

int aux(TAB *a, int dir){
    if(!a) return 1;
    if(a->esq && a->dir) return 0;
    if(dir == 0){
        if(a->esq) return 0;
        return aux(a->dir, 1);
    }
    else{
        if(a->dir) return 0;
        return aux(a->esq, 0);
    }
}

int estzz(TAB *a){
    if(!a) return 0;
    return (aux(a->esq, 0) && aux(a->dir, 1));
}

int main(void){
    int opcao, x,resp, k;
    TAB* raiz = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Verificar estritamente zigzag\n");
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
            resp = estzz(raiz);
            if(resp) printf("\neh est zigzag ");
            else printf("\nnao eh est zigzag");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    TAB_libera(raiz);
    return 0;
}