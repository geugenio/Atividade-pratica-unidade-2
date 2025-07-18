#include "selection_sort.h"
#include "utils.h"
using namespace std;


void selection_sort(vector<int>& arr){
    int tamanho = arr.size(); //obtem o tamanho do vetor

    if (tamanho <=1 ){
        Metricas::setMemoriaAuxiliarBytes(0);
        return; //Caso o vetor tenha tamanho 0 ou 1, ele já estará ordenado
    }

    for (int i = 0; i < tamanho-1; i++){
        int minIndice = i; // Assume o primeiro elemento como o menor
        //Faz a busca pelo menor elemento no restante do vetor
        for (int j = i + 1; j < tamanho; j++){
            Metricas::comparacoes++; // Incrementa o contador de comparações
            if (arr[j] < arr[minIndice]){
                // Atualiza o índice do menor elemento se um menor for encontrado
                minIndice = j;
            }
        }
        // Se o menor elemento não for o primeiro, troca os elementos. Evita troca desnecessária
        if (minIndice != i) {
            int aux = arr[i];
            arr[i] = arr[minIndice];
            arr[minIndice] = aux;
            Metricas::trocas++; // Incrementa o contador de trocas
        }
    }

    Metricas::setMemoriaAuxiliarBytes(0);
}