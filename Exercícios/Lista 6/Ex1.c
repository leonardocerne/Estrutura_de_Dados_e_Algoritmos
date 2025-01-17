/*
Escreva um programa em C que leia dois arquivos binários “a.bin” e “b.bin” contendo
palavras distintas descritas por 10 caracteres e produza um terceiro arquivo c.bin. No arquivo
“c.bin”, cada um de seus registros contém um par ordenado de palavras, onde a primeira palavra é
proveniente de “a.bin” e a segunda de “b.bin”. Como resultado do processamento, o arquivo
“c.bin” deve conter todos os pares ordenados formados por palavras dos dois arquivos de entrada
(o resultado é o produto cartesiano dos dois conjuntos). Obs.: todo processamento deve ser feito em
memória secundária.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pares(char *ArqA, char *ArqB, char *ArqC){
    FILE *fpA = fopen(ArqA, "rb"), *fpB = fopen(ArqB, "rb"), *fpC = fopen(ArqC, "wb");
    if((!fpA) || (!fpB) || (!fpC)) exit(1);
    char pA[11], pB[11];
    int r1 = fread(pA, sizeof(char), 11, fpA);
    int r2 = fread(pB, sizeof(char), 11, fpB);
    while(r1 == 11){
        fwrite(pA, sizeof(char), 11, fpC);
        fwrite(pB, sizeof(char), 11, fpC);
        fputc('\n', fpC);
        r1 = fread(pA, sizeof(char), 11, fpA);
        r2 = fread(pB, sizeof(char), 11, fpB);
    }
    fclose(fpA); fclose(fpB); fclose(fpC);
}

int main(void){
    pares("ArqA.bin", "ArqB.bin", "ArqC.bin");
    return 0;
}