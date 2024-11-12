#include <stdio.h>
#include <stdlib.h>

typedef struct arvbinbusca{
    int info;
    struct arvbinbusca *esq, *dir;
}TABB;

TABB *TABB_inicializa(void);
TABB *TABB_cria(int raiz, TABB *esq, TABB *dir);

void TABB_imp_pre(TABB *a);
void TABB_imp_pos(TABB *a);
void TABB_imp_sim(TABB *a);
void TABB_imp_ident(TABB *a);

void TABB_libera(TABB *a);
int maior(int x, int y);
TABB *TABB_busca(TABB *a, int elem);

TABB *TABB_insere(TABB *a, int elem);

int TABB_altura(TABB *a);

int fb(TABB *a);