/*
2. Com base na biblioteca de heap binária implementada em 
sala, refaça a função void max_heapfy_k(int *vet, int n, int 
ind, int k) para uma heap k-nária em memória principal. Ou 
seja, cada nó pode ter no máximo k filhos. 
*/

int filhoi(int ind, int k, int i){
    return (ind * k) + i;
}

void maxheapfy_k(int *vet, int n, int ind, int k){
    int maior = ind, x;
    for(int i = 1; i <= k; i++){
        x = filhoi(ind, k, i);
        if((x < n) && (vet[x] > vet[maior])) maior = x;
    }
    if(maior != ind){
        x = vet[maior];
        vet[maior] = vet[ind];
        vet[ind] = x;
        maxheapfy_k(vet, n, maior, k);
    }
}
