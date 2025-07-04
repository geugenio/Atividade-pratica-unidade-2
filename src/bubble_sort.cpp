#include "bubble_sort.h"
#include "utils.h"

using namespace std;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();

    if (n<=1){
        Metricas::setMemoriaAuxiliarBytes(0);
        return;
    }

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
    //Bubble sort é um algoritmo inplace, usando só um num constante de variaveis extras, ou seja
    //seu espaço auxiliar é O(1), que representamos aqui com 0 bytes.
    Metricas::setMemoriaAuxiliarBytes(0);
}