#include "TARVB.c"

void percorre(TARVB *a, int N, int M, int *resp, int *ind){
    if(!a) return;
    for(int i = 0; i <= a->nchaves; i++){
        if(i == a->nchaves){
            percorre(a->filho[i], N, M, resp, ind);
        }
        else{
            if((a->chave[i] % N == 0) && (a->chave[i] % M == 0)) resp[(*ind)++] = a->chave[i];
            percorre(a->filho[i], N, M, resp, ind);
        }
    }
}

int tam(TARVB *a, int N, int M){
    if(!a) return 0;
    int c = 0, i;
    for(i = 0; i <= a->nchaves; i++){
        if(i == a->nchaves){
            c += tam(a->filho[i], N, M);
        }
        else{
            if((a->chave[i] % N == 0) && (a->chave[i] % M == 0)) c++;
            c += tam(a->filho[i], N, M);
        }
    }
    return c;
}

int *multNM(TARVB *a, int N, int M, int *tam_vet){
    if(!a){
        (*tam_vet) = 0;
        return NULL;
    }
    (*tam_vet) = tam(a, N, M);
    int ind = 0;
    int *resp = (int*)malloc(sizeof(int) * (*tam_vet));
    percorre(a, N, M, resp, &ind);
    return resp;
}

int main(void){
  TARVB *arvore = TARVB_Inicializa();
  int t, x, y;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num = 0, from, to;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVB_Imprime(arvore);
      break;
    }
    else if(!num){
      printf("\n");
      TARVB_Imprime(arvore);
    }
    else arvore = TARVB_Insere(arvore, num, t);
    printf("\n\n");
  }
  printf("Digite o valor n e m: ");
  scanf("%d%d", &x, &y);
  int *vet, tam_vet;
  vet = multNM(arvore,x, y, &tam_vet);
  printf("A lista de multiplos de %d e %d eh: ",x, y);
  printf("\n");
  for(int i = 0; i < tam_vet; i++){
    printf("%d ", vet[i]);
  }
  TARVB_Libera(arvore);
  return 0;
}