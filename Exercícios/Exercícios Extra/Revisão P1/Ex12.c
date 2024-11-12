// Testar se duas árvores possuem as mesmas informações - int mi(TAB *a1, TAB *a2).

#include "TAB.c"

int mi(TAB *a, TAB *b){
    if(!a) return 1;
    if(!TAB_busca(b, a->info)) return 0;
    return mi(a->esq, b) && mi(a->dir, b);
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x,ver;
    TAB* raiz = NULL;
    TAB* outra = NULL;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir na primeira\n\t2 - Imprimir\n\t3 - Inserir na segunda\n\t4 - Imprimir a segunda\n\t5 - Verificar infos\n");
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
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf("%d", &x);
            printf("\n");
            outra = insere(outra,x);
            break;

        case 4:
            printf("\tA arvore eh: ");
            TAB_imp_sim(outra);
            printf("\n");
            break;

        case 5:
            ver = mi(raiz,outra);
            if(ver) printf("\n\tAs infos sao iguais");
            else printf("\n\tAs infos NAO sao iguais");
            printf("\n");
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TAB_libera(raiz);
    TAB_libera(outra);
    return 0;
}