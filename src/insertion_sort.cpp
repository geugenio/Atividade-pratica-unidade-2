#include "insertion_sort.h"

void insertion_sort(vector<int>& arr) {
    int tamanho = arr.size();

    for(int i = 1; i < tamanho; i++){
        int chave = arr[i];
        int j = i -1; // posição do elemento anterior
        // Move os elementos de arr[0..i-1], que são maiores que chave, para uma posição à frente de sua posição atual
        while(j >= 0 && arr[j] > chave){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave; // Coloca a chave na posição correta
    }
}