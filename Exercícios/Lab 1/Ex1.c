#include "TAB.c"

int tamanho(TAB *a, int N){
    if(!a) return 0;    
    if(a->info > N) return 1 + tamanho(a->esq, N) + tamanho(a->dir, N);
    return tamanho(a->esq, N) + tamanho(a->dir, N);
}

void percorre(TAB *a, int N, int *in, int *resp){
    if(!a) return;
    percorre(a->esq, N, in, resp);
    if(a->info > N) resp[(*in)++] = a->info;
    percorre(a->dir, N, in, resp); 
}

int *mN(TAB *a, int N, int *tam){
    if(!a) return 0;
    (*tam) = tamanho(a, N);
    int *resp = (int*)malloc(sizeof(int) * (*tam));
    int in = 0;
    percorre(a, N, &in, resp);
    return resp;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, n, tam;
    TAB* raiz = NULL;
    int *resp;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Imprimir\n\t3 - Lista de valores maiores que N\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf(" %d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o valor a ser inserido na arvore: ");
            scanf(" %d", &x);
            printf("\n");
            raiz = insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TAB_imp_sim(raiz);
            printf("\n");
            break;

        case 3:
            printf("\tDigite o valor de N: ");
            scanf("%d",&n);
            printf("\n");
            resp = mN(raiz,n,&tam);
            printf("\tAqui esta o vetor com valores menores que N: ");
            for(int i = 0; i < tam; i++) printf("%d ", resp[i]);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);

    free(resp);
    TAB_libera(raiz);
    return 0;
}