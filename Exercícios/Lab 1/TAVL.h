#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int info;
    struct avl *esq, *dir;
    int alt;
}TAVL;

TAVL *rse(TAVL *p);
TAVL *rsd(TAVL *p);