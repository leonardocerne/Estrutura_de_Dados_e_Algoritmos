/*
-> Escrever uma função em C que, dada uma árvore binária qualquer, retorne, num vetor, todos os elementos maiores que N. A função deve ter o seguinte protótipo: int* mN(TABB*a, int N, int *tam)
*/
#include "TABB.c"

int tamanho(TABB *a, int N){
    if(!a) return 0;
    if(a->info > N) return 1 + tamanho(a->esq, N) + tamanho(a->dir, N);
    return tamanho(a->esq, N) + tamanho(a->dir, N);
}

void percorre(int *vet, TABB *a, int N, int *in){
    if(!a) return;
    percorre(vet, a->esq, N, in);
    if(a->info > N){
        vet[(*in)++] = a->info;
    }
    percorre(vet, a->dir, N, in);
}

int* mN(TABB*a, int N, int *tam){
    if(!a) return 0;
    (*tam) = tamanho(a, N);
    int *vet = (int*)malloc(sizeof(int) * (*tam));
    int in = 0;
    percorre(vet, a, N, &in);
    return vet;
}

int main(void){
    //Para facilitar o meu processo de criação da árvore, colocarei ela numa lógica binaria de busca, pois o foco aqui é a verificação da função copia
    int opcao, x, n, tam;
    TABB* raiz = NULL;
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
            raiz = TABB_insere(raiz,x);
            break;
        
        case 2:
            printf("\tA arvore eh: ");
            TABB_imp_sim(raiz);
            printf("\n");
            break;

        case 3:
            printf("\tDigite o valor de N: ");
            scanf("%d",&n);
            printf("\n");
            resp = mN(raiz,n,&tam);
            printf("\tAqui esta o vetor com valores maiores que N: ");
            for(int i = 0; i < tam; i++) printf("%d ", resp[i]);
            break;

        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TABB_libera(raiz);
    return 0;
}