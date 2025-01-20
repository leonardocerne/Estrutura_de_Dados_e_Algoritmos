/*
(Q7) Refaça as bibliotecas de heap para funcionar com heaps ternárias. Assim, no lugar de termos funções de esquerda e direita, teremos funções que retornam os três possíveis filhos de um nó (isto é, escreva as funções filho_1, filho_2 e filho3);
(Q8) Refaça as bibliotecas de heap para funcionar com n filhos. Assim, no lugar de termos funções de esquerda e direita, teremos uma função que retorna o filho i (0 < i < n);
(Q9) Refaça a operação max_heapfy de heap binária de máximo para a de mínimo (min_heapfy)
(Q10) Refaça a operação max_heapfy de heap binária de máximo (max_heapfy) para heaps ternárias.
(Q11) Refaça a operação max_heapfy de heap binária de máximo (max_heapfy) para heaps com n filhos.
*/

//(Q7)
int paiTernario(int ind){
    if(ind <= 0) return -1;
    return (ind - 1) / 3; 
}

int filho1(int ind){
    return (ind * 3) + 1;
}

int filho2(int ind){
    return (ind * 3) + 2;
}

int filho3(int ind){
    return (ind * 3) + 3;
}

//(Q8)

int paiNfilhos(int ind, int n){
    if(ind <= 0) return -1;
    return (ind - 1) / n;
}

int filhoI(int ind, int n, int i){
    return (ind * n) + i;
}

//(Q9)

int pai(int ind){
        if(ind <= 0) return -1;
        return (ind - 1) / 2;
    }
int esq(int ind){
        return ind*2 + 1;
    }
int dir(int ind){
        return ind*2 + 2;
    }

void minheapfy(int *vet, int pos, int n){
    int menor = pos, e, d;
    e = esq(pos);
    d = dir(pos);
    if((e < n) && (vet[e] < vet[menor])) menor = e;
    if((d < n) && (vet[d] < vet[menor])) menor = d;
    if(menor != pos){
        int tmp = vet[pos];
        vet[pos] = vet[menor];
        vet[menor] = tmp;
        minheapfy(vet, menor, n);
    }
}

//(Q10)

void maxheapfyTernario(int *vet, int pos, int n){
    int maior = pos, f1, f2, f3;
    f1 = filho1(pos);
    f2 = filho2(pos);
    f3 = filho3(pos);
    if((f1 < n) && (vet[f1] > vet[maior])) maior = f1;
    if((f2 < n) && (vet[f2] > vet[maior])) maior = f2;
    if((f3 < n) && (vet[f3] > vet[maior])) maior = f3;
    if(maior != pos){
        int tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        maxheapfyTernario(vet, maior, n);
    }
}

//(Q11)

void maxheapfyNfilhos(int *vet, int pos, int n, int k){
    int maior = pos, tmp, i;
    for(i = 1; i <= k; i++){
        tmp = filhoI(pos, k, i);
        if((tmp < n) && (vet[tmp] > vet[maior])) maior = tmp;
    }
    if(maior != pos){
        tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        maxheapfyNfilhos(vet, maior, n, k);
    }
}

// funções basicas heap

void maxheapfy(int *vet, int pos, int n){
    int maior = pos, e, d;
    e = esq(pos);
    d = dir(pos);
    if((e < n) && (vet[e] > vet[maior])) maior = e;
    if((d < n) && (vet[d] > vet[maior])) maior = d;
    if(maior != pos){
        int tmp = vet[pos];
        vet[pos] = vet[maior];
        vet[maior] = tmp;
        minheapfy(vet, maior, n);
    }
}

void buildmaxheap(int *vet, int n){
    int ultpai = n-1, i;
    for(i = ultpai; i >= 0; i--) maxheapfy(vet, i, n);
}

void heapsort(int *vet, int n){
    buildmaxheap(vet,n);
    int i;
    for(i = n-1; i > 0; i--){
        int tmp = vet[0];
        vet[0] = vet[i];
        vet[i] = tmp;
        maxheapfy(vet, i, 0);
    }
}

