#pragma once

#include <vector>
#include <string>
#include <chrono> //medicao de tempo

using namespace std;
namespace ArrayGen {
    vector<int> gerarArrayAleatorio(int tamanho, int min, int max);
    vector<int> gerarArrayParcialmenteOrdenado(int tamanho, int numTrocas, int min, int max);
    vector<int> gerarArrayOrdenado(int tamanho);
    vector<int> gerarArrayOrdenadoReverso(int tamanho);
}

namespace Metricas{
    //Variaveis globais para armazenar as métricas
    extern long long comparacoes;
    extern long long trocas;

    //Gerenciamento de tempo
    void startTimer();
    double stopTimer(); //Retorna o tempo em milissegundos ou segundos

    void resetMetricas(); //Reseta as métricas de comparações e trocas
    bool isSorted(const vector<int>& arr); //Verifica se o array está ordenado
    void printArray(const vector<int>& arr); //Imprime o array no console
}