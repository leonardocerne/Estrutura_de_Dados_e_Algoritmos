/*
Desenvolva um procedimento que receba o nome de um arquivo texto e retire deste texto
palavras consecutivas repetidas. O seu programa deve retornar, no arquivo de saída, informado
como parâmetro dessa função, a resposta desta questão. Por exemplo, se o conteúdo de um arquivo
texto for: "Isto e um texto texto repetido repetido repetido . Com as repeticoes
repeticoes fica fica sem sem sentido . Sem elas elas elas melhora melhora um um
pouco .", a saída do seu programa será um arquivo com o seguinte texto: "Isto e um texto
repetido . Com as repeticoes fica sem sentido . Sem elas melhora um um pouco ."
- void RetRepet(char *ArqEnt, char *ArqSaida).
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RetRepet(char *ArqEnt, char *ArqSaida){
    FILE *fp1 = fopen(ArqEnt, "r"), *fp2 = fopen(ArqSaida, "w");
    if((!fp1) || (!fp2)) exit(1);
    char ant[30], atual[30];
    int r = fscanf(fp1, "%s", ant);
    fprintf(fp2, "%s ", ant);
    while(r == 1){
        r = fscanf(fp1, "%s", atual);
        if(strcmp(atual, ant) != 0) fprintf(fp2, "%s ", atual);
        strcpy(ant, atual);
    }
    fclose(fp1); fclose(fp2); 
}

int main(void){
    RetRepet("entrada.txt", "saida.txt");
    return 0;
}