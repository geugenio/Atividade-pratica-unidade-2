#include "bubble_sort.h"
#include "utils.h"

using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n-1; i++){
        bool trocas = false;

        for (int j = 0; j < n-i-1; j++){
            Metricas::comparacoes++; // Incrementa o contador de comparações
            if (arr[j] > arr[j+1]){
                int temporario = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temporario;
                trocas = true;
                Metricas::trocas++; // Incrementa o contador de trocas

            }
        }

        if(!trocas){ // vetor já ordenado
            break;
        }
    }
}