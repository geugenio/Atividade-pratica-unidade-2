#include "utils.h"
#include <algorithm> // sort, reverse, random_shuffle
#include <random> //mt19937, random_device, uniform_int_distribution
#include <iostream> //printArray
#include <numeric>
using namespace std;

namespace Metricas{
    long long comparisons = 0;
    long long trocas = 0;
    chrono::time_point<chrono::high_resolution_clock> startTime;

    void startTimer() {
        startTime = chrono::high_resolution_clock::now();
    }
    double stopTimer(){
        auto endTime = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> duration = endTime - startTime; // Tempo em milissegundos
        return duration.count(); // Retorna o tempo em milissegundos

    }

    void resetMetricas(){
        comparisons = 0;
        trocas = 0;
    }
    void printArray(const vector<int>& arr){
        for (const auto& elem : arr) {
            cout << elem << " ";
        }
        cout << endl;
    }
    bool isSorted(const vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false; // Se encontrar um elemento menor que o anterior, não está ordenado
            }
        }
        return true; // Se não encontrou nenhum elemento fora de ordem, está ordenado
    }
}

namespace ArrayGen{
    vector<int> gerarArrayAleatorio(int tamanho, int min, int max){
        vector<int> arr(tamanho);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(min, max);
        // Preenche o vetor com valores aleatórios dentro do intervalo [min, max]
         // Utiliza o gerador de números aleatórios para preencher o vetor
        for(int i = 0; i <tamanho; ++i){
            arr[i] = dis(gen); 
        }
        return arr;
    }

    vector<int> gerarArrayOrdenado(int tamanho, int min, int max) {
        vector<int> arr(tamanho);
        // Gera valores sequenciais dentro do intervalo [min, max]
        int step = (max - min) / std::max(1, tamanho - 1);
        for(int i = 0; i < tamanho; ++i) {
            arr[i] = min + (i * step);
            if(arr[i] > max) arr[i] = max;  // Garante que não ultrapasse o máximo
        }
        return arr;  // Adicionado o return que faltava
    }

    vector<int> gerarArrayParcialmenteOrdenado(int tamanho, int numTrocas, int min, int max){
        vector<int> arr = gerarArrayOrdenado(tamanho, min, max);
        random_device rd;
        mt19937 gen(rd());
        //Realiza um numero limitado de trocar, para "desordenar" o array de forma controlada
        for (int i = 0; i < numTrocas;++i){
            uniform_int_distribution<> dis(0, tamanho - 1);
            int idx1 = dis(gen);
            int idx2 = dis(gen);
            if(idx1 != idx2){
                swap(arr[idx1], arr[idx2]);
            }
        }
        return arr;
    }

    vector<int> gerarArrayOrdenadoReverso(int tamanho, int min, int max) {
        vector<int> arr = gerarArrayOrdenado(tamanho, min, max);
        reverse(arr.begin(), arr.end());
        return arr;
    }
}
