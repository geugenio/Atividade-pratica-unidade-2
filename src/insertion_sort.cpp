#include "insertion_sort.h"
#include "utils.h"



void insertion_sort(vector<int>& arr) {
    int tamanho = arr.size();
    Metricas::resetMetricas(); // Reseta as métricas de comparações e trocas
    Metricas::startTimer(); // Inicia o cronômetro para medir o tempo de execução
    if (tamanho <= 1) {
        return; // Se o vetor tiver tamanho 0 ou 1, ele já está ordenado
    }
    for(int i = 1; i < tamanho; i++){
        int chave = arr[i];
        int j = i -1;

        while (j>= 0 ){
            Metricas::comparacoes++; // Incrementa o contador de comparações
            if(arr[j] > chave){
                arr[j+1] = arr[j]; // Move o elemento maior para a direita
                j--; // Move para o próximo elemento à esquerda
            } else{
                break; // Se o elemento atual não for maior que a chave, sai do loop
            }
        }
        arr[j+1] = chave;
    }
}