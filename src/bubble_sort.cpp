#include "bubble_sort.h"

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int temporario, trocas;

    for (int i = 0; i < n-1; i++){
        trocas = 0;
        for (int j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temporario = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temporario;
                trocas = 1;
            }
        }

        if(trocas==0){ // vetor já ordenado
            break;
        }
    }
}