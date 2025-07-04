#include "merge_sort.h"
#include "utils.h"
using namespace std;

void merge(vector<int>& arr, int esq, int meio, int dir){
    int n1 = meio - esq+1;
    int n2 = dir - meio;

    vector<int> E(n1), D(n2); //vetores temporários para armazenar os subarrays

    //Copiando os elementos pro subarray da esquerda e direita
    for(int i = 0; i < n1; i++){
        E[i] = arr[esq + i];
    }
    for(int j = 0; j < n2; j++){
        D[j] = arr[meio + 1 + j];
    }
    int i = 0, j = 0, k = esq;

    while(i < n1 && j < n2){
        Metricas::comparacoes++; // Incrementa o contador de comparações
        //Compara os elementos dos subarrays e coloca o menor no array original
        if(E[i] <= D[j]){
            arr[k] = E[i];
            i++;
        } else {
            arr[k] = D[j];
            j++;
        }
        Metricas::trocas++;
        k++;
    }

    while (i < n1){
        arr[k] = E[i];
        Metricas::trocas++;
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = D[j];
        Metricas::trocas++;
        j++;
        k++;
    }
}
void recursao_merge_sort(vector<int>& arr, int esq, int dir){
    if (esq>= dir){
        return; //Caso o vetor tenha tamanho 0 ou 1, ele já estará ordenado
    }
    int meio = esq + (dir - esq) / 2; //encontra o meio do vetor
    recursao_merge_sort(arr, esq, meio); //ordena a primeira metade
    recursao_merge_sort(arr, meio + 1, dir); //ordena a segunda metade
    merge(arr, esq, meio, dir); //mescla as duas metades
}


void merge_sort(vector<int>& arr) {
    if(arr.size() <= 1) {
        return; // Se o vetor tiver tamanho 0 ou 1, ele já está ordenado
    } else{
        recursao_merge_sort(arr, 0, arr.size() - 1); // Chama a função de merge_sort com os índices iniciais
    }
}