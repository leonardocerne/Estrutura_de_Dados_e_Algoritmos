#include <stdio.h>
#include <stdlib.h>

#define TAM_TAB_HASH 101

typedef struct aluno{
    int mat;
    float cr;
    struct aluno *prox;
}TA;

typedef struct alunoarq{
    int mat;
    float cr;
    int status;
    int prox;
}TAarq;

typedef TA*THASH[TAM_TAB_HASH];
int hash(int mat, int n);

