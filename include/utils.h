#pragma once

#include <vector>
#include <string>
#include <chrono> //medicao de tempo

namespace ArrayGen {
    std::vector<int> gerarArrayAleatorio(int tamanho);
    std::vector<int> gerarArrayParcialmenteOrdenado(int tamanho, int numTrocas);
    std::vector<int> gerarArrayOrdenado(int tamanho);
    std::vector<int> gerarArrayOrdenadoReverso(int tamanho);
}

namespace Metricas{
    //Variaveis globais para armazenar as métricas
    extern long long comparacoes;
    extern long long trocas;
    extern std::chrono::high_resolution_clock::time_point startTime;

    //Gerenciamento de tempo
    void startTimer();
    double stopTimer(); //Retorna o tempo em milissegundos ou segundos

    void resetMetricas(); //Reseta as métricas de comparações e trocas
    bool isSorted(const std::vector<int>& arr); //Verifica se o array está ordenado
    void printArray(const std::vector<int>& arr); //Imprime o array no console
    void printMetricas(); //Imprime as métricas de comparações e trocas


    static long long getComparacoes();
    static long long getTrocas();
}