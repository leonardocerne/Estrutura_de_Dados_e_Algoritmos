/*
Escreva um programa em C que receba como entrada um arquivo binário de clientes
“clientes.bin” e, sem ler todos os registros para memória, permita a consulta dos dados de um
cliente em função do seu CPF. Considere que o formato de cada registro é dado pelos seguintes
campos: nome – char (40), CPF – char(11), conta_corrente (int), agencia
(int), saldo (float).

Escreva um programa em C que receba o arquivo de clientes do exercício Q2 e produza um
arquivo binário de índices “indices.bin”, onde a sequência dos índices descreve os registros do
arquivo de clientes ordenados pelo saldo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cliente{
    float saldo;
    int in;
}CLI;

int comp(const void *a, const void *b){
    CLI *pa = (CLI*)a, *pb = (CLI*)b;
    if(pa->saldo > pb->saldo) return -1;
    return 1;
}

void indices(char *ArqEnt, char *ArqSaida){
    FILE *fp1 = fopen(ArqEnt, "rb"), *fp2 = fopen(ArqSaida, "wb");
    if((!fp1) || (!fp2)) exit(1);
    int tamcliente = (sizeof(char) * 51) + (sizeof(int) * 2) + sizeof(float);
    int tamsemfloat = (sizeof(char) * 51) + (sizeof(int) * 2);
    float x;
    int tam = 0;
    fseek(fp1, tamsemfloat, SEEK_SET);
    int r = fread(&x, sizeof(float), 1, fp1);
    while(r == 1){
        tam++;
        fseek(fp1, (tamcliente * tam) + tamsemfloat, SEEK_SET);
        r = fread(&x, sizeof(float), 1, fp1);
    }
    CLI *vet = (CLI*)malloc(sizeof(CLI) * tam);
    int ind = 1;
    rewind(fp1);
    for(int i = 0; i < tam; i++){
        fseek(fp1, tamsemfloat + (tamcliente * i), SEEK_SET);
        fread(&x, sizeof(float), 1, fp1);
        vet[i].saldo = x;
        vet[i].in = ind;
        ind++;
    }
    qsort(vet, tam, sizeof(CLI), comp);
    for(int j = 0; j < tam; j++){
        fwrite(&vet[j].in, sizeof(int), 1, fp2);
        fwrite(&vet[j].saldo, sizeof(float), 1, fp2);
    }
    fclose(fp1); fclose(fp2);
    free(vet);
}

void cpf(char *Arq){
    FILE *fp = fopen(Arq, "rb");
    if(!fp) exit(1);
    printf("insira qual cliente voce quer saber os dados:");
    int c;
    scanf("%d", &c);
    char cpf[11], nome[40];
    int conta, agencia;
    float saldo;
    int tamcliente = (sizeof(char) * 51) + sizeof(int) + sizeof(int) + sizeof(float);
    fseek(fp, (tamcliente * (c - 1)), SEEK_SET);
    fread(nome, sizeof(char), 40, fp);
    printf("Cliente nome:%s\n", nome);
    fread(cpf, sizeof(char), 11, fp);
    printf("CPF:%s\n", cpf);
    fread(&conta, sizeof(int), 1, fp);
    printf("Conta:%d\n", conta);
    fread(&agencia, sizeof(int), 1, fp);
    printf("Agencia:%d\n", agencia);
    fread(&saldo, sizeof(float), 1, fp);
    printf("Saldo:%.2f\n", saldo);
    fclose(fp);
}

void cria_binario(char* Arq_Saida){
    FILE* fs = fopen(Arq_Saida,"wb");
    if(!fs) exit(1);
    char nome[40], cpf[11];
    int ver = 1, conta_corrente, agencia;
    float saldo;
    do{
        printf("Digite o nome: ");
        scanf("%s",nome);
        printf("Digite o CPF: ");
        scanf("%s", cpf);
        printf("Digite o numero da conta corrente: ");
        scanf("%d", &conta_corrente);
        printf("Digite o numero da agencia: ");
        scanf("%d", &agencia);
        printf("Digite o saldo da conta");
        scanf("%f",&saldo);
        fwrite(nome, sizeof(char), 40, fs);
        fwrite(cpf, sizeof(char), 11, fs);
        fwrite(&conta_corrente, sizeof(int), 1, fs);
        fwrite(&agencia, sizeof(int), 1, fs);
        fwrite(&saldo, sizeof(float), 1, fs);
        printf("Deseja inserir mais uma pessoa? Digite 1 para sim e 0 para nao: ");
        scanf("%d",&ver);
        if(!ver) break;
    }while(ver == 1);
    fclose(fs);
}

void lebinario(char *Arq){
    FILE *fp = fopen(Arq, "rb");
    if(!fp) exit(1);
    int in; float saldo;
    int r1 = fread(&in, sizeof(int), 1, fp);
    int r2 = fread(&saldo, sizeof(saldo), 1, fp);
    printf("Indice: %d, Saldo:%f \n", in, saldo);
    while(r1 && r2){
        r1 = fread(&in, sizeof(int), 1, fp);
        r2 = fread(&saldo, sizeof(saldo), 1, fp);
        if(r1 && r2) printf("Indice: %d, Saldo:%.1f \n", in, saldo);
    }
}

int main(void){
    printf("preencha seu arquivo:\n");
    cria_binario("entrada.bin");
    indices("entrada.bin", "saida.bin");
    lebinario("saida.bin");
    return 0;
}