#include <string.h>
#include "TABB.h"

//int abbeAVL(TABB* a){}

int main(void){
  int n, m;
  TABB *a = NULL;
  while(1){
    scanf("%d", &n);
    if(n < 0) break;
    a = TABB_insere(n, a);
  }
  TABB_imprime(a);
  
  //printf("a e AVL? %d\n", abbeAVL(a));
  TABB_libera(a);
  return 0;
}
