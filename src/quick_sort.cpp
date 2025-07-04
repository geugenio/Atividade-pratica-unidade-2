#include "quick_sort.h"
#include "utils.h"
//Escolhe um pivô e coloca todos os elementos menores que o pivô à esquerda e todos os elementos maiores que o pivô à direita. Retorna o índice do pivô após a partição.
int particao(vector<int>& arr, int low, int high) {
    int pivo = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        Metricas::comparacoes++;
        if (arr[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            Metricas::trocas++;
        }
    }
    Metricas::trocas++;
    int aux = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = aux;
    return (i + 1); // Retorna o índice do pivô
}

void recursao_quick_sort(vector<int>& arr, int low, int high, bool primeiraChamada=true) {
    if (primeiraChamada) { // Se for a primeira chamada, reseta as métricas e inicia o cronômetro
        Metricas::resetMetricas();
        Metricas::startTimer();
    }
    if (low < high) {
        //indicePart é o índice do pivô após a partição, divide o vetor em duas partes
        int indicePart = particao(arr, low, high);
        // Ordena recursivamente os elementos antes e depois do pivô
        recursao_quick_sort(arr, low, indicePart - 1,false);
        recursao_quick_sort(arr, indicePart + 1, high, false);
    }
}

void quick_sort(vector<int>& arr) {
    if (arr.size() <= 1){
        return;
    } else{
        recursao_quick_sort(arr, 0, arr.size() - 1);
    }
}