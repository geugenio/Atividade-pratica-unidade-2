#include "quick_sort.h"

//Escolhe um pivô e coloca todos os elementos menores que o pivô à esquerda e todos os elementos maiores que o pivô à direita. Retorna o índice do pivô após a partição.
int particao(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            int aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    int aux = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = aux;
    return (i + 1); // Retorna o índice do pivô
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        //indicePart é o índice do pivô após a partição, divide o vetor em duas partes
        int indicePart = particao(arr, low, high);

        // Ordena recursivamente os elementos antes e depois do pivô
        quick_sort(arr, low, indicePart - 1);
        quick_sort(arr, indicePart + 1, high);
    }
}