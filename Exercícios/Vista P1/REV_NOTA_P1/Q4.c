#include <string.h>
#include "TAB.c"

/*
Meu código está com a lógica perfeita, porém o único erro foi a chamada da função nível, que por descuido esqueci de colocar o parâmetro (TAB *raiz)
mas, quando corrijo esse pequeno erro, a função teste funciona perfeitamente
*/

int nivel(TAB *a, TAB *raiz){
  if((!a) || (raiz->info == a->info)) return 0;
  if(TAB_busca(raiz->esq, a->info)){
    return 1 + nivel(a, raiz->esq);
  }else return 1 + nivel(a, raiz->dir);
}

// int testeaux(TAB *a, int flag, int n){
int testeaux(TAB *a, TAB *raiz, int flag, int n){
  if(!a) return 1;
  if(!(a->esq) && !(a->dir)){
    // if((nivel(a) != n) || (nivel(a) % 2 != 0)) return 0;
    if((nivel(a, raiz) != n) || (nivel(a, raiz) % 2 != 0)) return 0;

  }
  //if(nivel(a) % 2 == 0){
  if(nivel(a, raiz) % 2 == 0){
    if((!a->esq && a->dir) || (a->esq && !a->dir)) return 0;
    // return (testeaux(a->esq, 0, n) && testeaux(a->dir, 1, n));
    return (testeaux(a->esq, raiz, 0, n) && testeaux(a->dir, raiz, 1, n));
  }
  else{
    if(flag == 0){
      if(!(a->esq && !a->dir)) return 0;
      // return testeaux(a->esq, 0, n);
      return testeaux(a->esq, raiz, 0, n);
    } else{
      if(!(a->dir && !a->esq)) return 0;
      // return testeaux(a->dir, 1, n);
      return testeaux(a->dir, raiz, 1, n);
    }
  }
}

TAB *achafolha(TAB *a){
  if((!a) || (!a->esq && !a->dir)) return a;
  if(a->esq) return achafolha(a->esq);
  return achafolha(a->dir);
}

int teste(TAB *a){
  if(!a) return 0;
  TAB *f = achafolha(a);
  // int n = nivel(f);
  int n = nivel(f, a);
  //return testeaux(a, 0, n);
  return testeaux(a, a, 0, n);
}

int main(void){
  int no, pai;
  printf("Digite a raiz da arvore... ");
  scanf("%d", &no);
  TAB *a = TAB_cria(no, NULL, NULL), *resp;
  char repete;
  do{
    char lado[2];
    printf("Quer continuar inserindo nos na árvore (digite N ou n para parar)? ");
    scanf(" %c", &repete);
    if((repete == 'N') || (repete == 'n')) break;
    printf("Digite o pai (que deve existir), o filho a ser inserido e a posição E(ESQ) ou D(DIR)... ");
    scanf("%d%d%s", &pai, &no, lado);
    resp = TAB_busca(a, pai);
    if(!resp){
      TAB_libera(a);
      return 0;
    }
    if(strcmp(lado, "E") == 0) resp->esq = TAB_cria(no, NULL, NULL);
    else resp->dir = TAB_cria(no, NULL, NULL);
  }while(1);
  TAB_imp_ident(a);
  printf("\n");
  
  printf("Segue o padrao? %d\n", teste(a));
  TAB_libera(a);
  return 0;
}
