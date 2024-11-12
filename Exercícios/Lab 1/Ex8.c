#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct seguidores{
    char nome[20];
    int idade;
    struct seguidores *prox;
}SEG;

typedef struct grafo_insta{
    char nome[20];
    int idade;
    struct grafo_insta *prox;
    SEG *prim_seg;
}TGIG;

TGIG* TGIG_inicializa(){
  return NULL;
}


void TGIG_imprime(TGIG *g){
  while(g){
    printf("Nome: %s,", g->nome);
    printf("Idade: %d\nSeguidores:\n", g->idade);
    SEG *v = g->prim_seg;
    while(v){
      printf("%s ", v->nome);
      v = v->prox;
    }
    printf("\n\n");
    g = g->prox;
  }
}

void TGIG_libera_seg(SEG *s){
  while(s){
    SEG *temp = s;
    s = s->prox;
    free(temp);
  }
}

void TGIG_libera(TGIG *g){
  while(g){
    TGIG_libera_seg(g->prim_seg);
    TGIG *temp = g;
    g = g->prox;
    free(temp);
  }
}

TGIG* TGIG_busca_no(TGIG* g, char *x){
  if((!g) || (strcmp(g->nome, x) == 0)) return g;
  return(TGIG_busca_no(g->prox, x));
}

SEG* SEG_busca(TGIG *g, char *no1, char *no2){
  TGIG *p1 = TGIG_busca_no(g,no1), *p2 = TGIG_busca_no(g,no2);
  if((!p1) || (!p2)) return NULL;
  SEG *resp = p1->prim_seg;
  while((resp) && (strcmp(resp->nome, no2) != 0)) resp = resp->prox;
  return resp;
}

TGIG* TGIG_insere(TGIG *g, char *nome, int idade){
  TGIG *p = TGIG_busca_no(g, nome);
  if(!p){
    p = (TGIG*) malloc(sizeof(TGIG));
    strcpy(p->nome, nome);
    p->idade = idade;
    p->prox = g;
    p->prim_seg = NULL;
    g = p;
  }
  return g;
}

void TGIG_ins_um_sentido(TGIG *g, char *no1, char *no2){
  TGIG *p = TGIG_busca_no(g, no1);
  SEG *nova = (SEG *) malloc(sizeof(SEG));
  strcpy(nova->nome, no2);
  nova->prox = p->prim_seg;
  p->prim_seg = nova;
}

int numero_seguidos(TGIG *g, char *nome){
  TGIG *ig = g;
  int i = 0;
  while(ig){
    if(SEG_busca(g, ig->nome, nome)) i++;
    ig = ig->prox;
  }
  return i;
}

int seguidores(TGIG *g, char *nome, int imprime){
  TGIG *ig = TGIG_busca_no(g, nome);
  SEG *s = ig->prim_seg;
  int i = 0;
  while(s){
    i++;
    if(imprime == 1) printf("%s ", s->nome);
    s = s->prox;
  }
  return i;
}

TGIG *mais_popular(TGIG *g){
  TGIG *ig = g, *resp;
  int maior = 0, x;
  while(ig){
    x = seguidores(g, ig->nome, 0);
    if(x > maior){
      maior = x;
      resp = ig;
    }
    ig = ig->prox;
  }
  return resp;
}

int segue_mais_velho(TGIG *g, int imprime){
  TGIG *ig = g;
  int c = 0, x;
  while(ig){
    TGIG *temp = g;
    x = 1;
    while(temp){
      if(SEG_busca(g, temp->nome, ig->nome)){
        if(ig->idade >= temp->idade) x = 0;
      }
      temp = temp->prox;
    }
    if(!numero_seguidos(g, ig->nome)) x = 0;
    if(x == 1){
      c++;
      if(imprime) printf("%s ", ig->nome);
    }
    ig = ig->prox;
  }
  return c;
}

int main(void){
    int opcao, y, flag;
    char x[20], z[20];
    TGIG* insta = NULL, *mp;
    do{
        printf("\n\t0 - Sair\n\t1 - Inserir Pessoa\n\t2 - Inserir Seguidor\n\t3 - Imprimir Instagram\n\t4 - Descobrir seguidos\n\t5 - Descobrir seguidores\n\t6 - Mais popular\n\t7 - Quem so segue mais velhos\n");
        printf("\n");
        printf("\tDigite uma das opcoes acima: ");
        scanf("%d", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite o nome da pessoa que voce quer inserir: ");
            scanf("%s", &x);
            printf("\n");
            printf("\n\tDigite a idade da pessoa: ");
            scanf("%d", &y);
            printf("\n");
            insta = TGIG_insere(insta, x, y);
            break;
        
        case 2:
            printf("\n\tDigite a pessoa que vai ser seguida:");
            scanf("%s", &x);
            printf("\n");
            printf("\n\tDigite o seguidor: ");
            scanf("%s", &z);
            printf("\n");
            TGIG_ins_um_sentido(insta, x, z);
            break;

        case 3:
            printf("\n\tSeu instagram esta assim:\n ");
            TGIG_imprime(insta);
            printf("\n");
            break;
        case 4:
            printf("\n\tDigite a pessoa que quer descobrir quantas pessoas ela segue:");
            scanf("%s", &x);
            y = numero_seguidos(insta, x);
            printf("\n%s ", x);
            printf(" segue %d pessoas.\n", y);
            break;
        case 5:
            printf("\n\tQuer saber somente a quantidade ou os nomes tambem? Digite 0 para somente a quantidade e 1 para saber os nomes.\n");
            scanf("%d", &flag);
            printf("\nDe quem voce quer saber?\n");
            scanf("%s", &x);
            y = seguidores(insta, x, flag);
            printf("\n Essa pessoa tem %d seguidores\n", y);
            break;
        case 6:
            printf("\n\tA pessoa mais popular do instagram e: ");
            mp = mais_popular(insta);
            printf("%s", mp->nome);
            y = seguidores(insta, mp->nome, 0);
            printf(" com %d seguidores\n", y);
            break;
        case 7:
            printf("\n\tQuer saber somente a quantidade ou os nomes tambem? Digite 0 para somente a quantidade e 1 para saber os nomes.\n");
            scanf("%d", &flag);
            printf("\n");
            y = segue_mais_velho(insta, flag);
            printf("\n%d pessoas so seguem mais velhos", y);
            break;
        default:
            if(opcao != 0) printf("Opcao invalida!!!\n");
            break;
        }
    } while (opcao);


    TGIG_libera(insta);
    return 0;
}