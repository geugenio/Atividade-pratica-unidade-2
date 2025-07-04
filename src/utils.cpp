#include "utils.h"
#include <algorithm> // sort, reverse, random_shuffle
#include <random> //mt19937, random_device, uniform_int_distribution
#include <iostream> //printArray
#include <numeric>
using namespace std;

namespace Metricas{
    long long comparacoes = 0;
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
        comparacoes = 0;
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
    void printMetricas() {
        cout << "Comparações: " << comparacoes << endl;
        cout << "Trocas: " << trocas << endl;
    }

    static long long Metricas::getComparacoes() {
        return comparacoes;
    }

    static long long Metricas::getTrocas() {
        return trocas;
    }
}

namespace ArrayGen{
    vector<int> gerarArrayAleatorio(int tamanho){
        vector<int> arr(tamanho);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, tamanho - 1);
        for(int i = 0; i < tamanho; ++i){
            arr[i] = dis(gen); 
        }
        return arr;
    }
    std::vector<int> gerarArrayOrdenado(int tamanho) {
        std::vector<int> arr(tamanho);
        std::iota(arr.begin(), arr.end(), 0); // Fills with 0, 1, 2, ...
        return arr;
    }

    vector<int> gerarArrayParcialmenteOrdenado(int tamanho, int numTrocas){
        vector<int> arr = gerarArrayOrdenado(tamanho);
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

    vector<int> gerarArrayOrdenadoReverso(int tamanho) {
        vector<int> arr = gerarArrayOrdenado(tamanho);
        reverse(arr.begin(), arr.end());
        return arr;
    }
}
