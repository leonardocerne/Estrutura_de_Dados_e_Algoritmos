#include "TG.h"
#include "TLSE.c"
#include <limits.h>

/*
Erro da minha questão foi que não retornei o maior caminho, retornei apenas um caminho qualquer, mas segue meu código corrigido

int aux(TG *g, int origem, int destino, TLSE **vis, TG *gr){
  if(!g) return 0;
  if(TG_busca_aresta(g, g->id_no, destino)){
    TVIZ *x = TG_busca_aresta(g, g->id_no, destino);
    return x->custo;
  }
  *vis = TLSE_insere(&vis, g->id_no);
  TVIZ *v = g->prim_viz;
  while((v) && (!TLSE_busca(*vis, v->id_viz))){
    v = v->prox_viz;
  }
  if(v) return v->custo + aux(TG_busca_no(gr, v->id_viz), origem, destino, vis);
  return 0;
}

int mdk(TG *g, int origem, int destino, int k, int *tam_real_caminho){
  if(!g){
    *(tam_real_caminho) = INT_MAX;
    return INT_MAX;
  }
  TG *gr = TG_busca_no(g, origem);
  TLSE *viz = NULL;
  viz = TLSE_insere(viz, gr->id_no);
  int tam = aux(gr, origem, destino, &viz, g), tamr = 0;
  while(viz){
    tamr++;
    viz = viz->prox;
  }
  if(tamr > k){
    *(tam_real_caminho) = INT_MAX;
    return INT_MAX;
  }
  *(tam_real_caminho) = tamr;
  return tam;
}
*/

int max(TG*g){
  TG *pont = g;
  int m = 0;
  while (pont) {
    if (pont->id_no>m)m=pont->id_no;
    pont = pont->prox_no;
  }
  return m;
}

void teste(TG* g, int k_atual, int k,int dest, int atual, int caminho_atual,int* caminho,int* vis,int* menor_k){
  vis[atual] = 1;
  k_atual++;
  if(k_atual> k)caminho_atual = INT_MAX;
  if(atual == dest){
    if (caminho_atual < *caminho){
      *menor_k = k_atual;
      *caminho = caminho_atual;
    }
  }
  else{
    TG* a = TG_busca_no(g,atual);
    TVIZ* viz = a->prim_viz;
    while(viz){
      if(!vis[viz->id_viz]){
        teste(g, k_atual,k,dest,viz->id_viz,caminho_atual+viz->custo,caminho,vis,menor_k);
      }
      viz = viz->prox_viz;
    }
  }
  vis[atual] = 0;
}

int mdk(TG *g, int origem, int destino, int k, int *tam_real_caminho){
  if(!g)return 0;
  int* vis= calloc(max(g)+1,sizeof(int));
  int* menor_k = malloc(sizeof(int));
  *menor_k = INT_MAX;
  *tam_real_caminho= INT_MAX;
  teste(g,-1,k,destino,origem,0,tam_real_caminho,vis,menor_k);
  int resultado = *menor_k;
  free(menor_k);
  free(vis);
  return resultado;
}

int main(void){
  TG *g = TG_inicializa();
  int n;
  do{
    scanf("%d", &n);
    if(n <= 0) break;
    g = TG_ins_no(g, n);
  }while(1);
  
  int m, custo;
  do{
    scanf("%d%d%d", &n, &m, &custo);
    if((n <= 0) || (m <= 0)) break;
    TG_ins_aresta(g, n, m, custo);
  }while(1);
  TG_imprime(g);
  
  int k;
  scanf("%d%d%d", &n, &m, &k);
  
  int tam_real = 0;
  custo = mdk(g, n, m, k, &tam_real);
  printf("no %d alcanca o no %d em %d arestas: %d (%d)\n", n, m, k, custo, tam_real);
  
  TG_libera(g);
  return 0;
}

