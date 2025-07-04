#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream> //manipulação de arqvs
#include "locale"
#include "iomanip"


#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

#include "utils.h"

using namespace std;

int main() {

    //Configurações base para acentuação no console
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    vector<int> tamanhos = {100, 250, 500, 1000, 2500, 5000, 10000, 25000}; // Tamanhos do array para teste

    enum TipoOrdenacao {
        ALEATORIO,
        PARCIALMENTE_ORDENADO,
        ORDENADO,
        ORDENADO_REVERSO
    };
    vector<TipoOrdenacao> tiposOrdenacao = {
        ALEATORIO,
        PARCIALMENTE_ORDENADO,
        ORDENADO,
        ORDENADO_REVERSO
    };
    vector<string> nomesTipos = {
        "Aleatório",
        "Parcialmente Ordenado",
        "Ordenado",
        "Ordenado Reversamente"
    };
    vector<pair<string, void(*)(vector<int>&)>> algoritmos = {
        {"Bubble Sort", bubble_sort},
        {"Insertion Sort", insertion_sort},
        {"Selection Sort", selection_sort},
        {"Merge Sort", merge_sort},
        {"Quick Sort", quick_sort}
    };

    ofstream arquivo_csv("resultados_ordenacao.csv");
    if(!arquivo_csv.is_open()){
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }

    arquivo_csv << "Tipo_Dado,Tamanho_Array,Algoritmo,Tempo_ms,Tempo_s,Comparacoes,Trocas" << endl;

    cout << "===============================================================" << endl;
    cout << "||     Análise comparativa de algorítmos de ordenação         ||" << endl;
    cout << "===============================================================" << endl;

    for(TipoOrdenacao tipo : tiposOrdenacao) {
        cout << "----| Tipo de dado: " << nomesTipos[tipo] << " |----" << endl;
        for(int tamanho : tamanhos){
            cout << "----| Tamanho do array: " << tamanho <<" |----" <<endl;
            for (const auto& algoritmo_pair : algoritmos){
                const string& nome = algoritmo_pair.first;
                auto algoritmo = algoritmo_pair.second;

                // Gerar o array de acordo com o tipo
                vector<int> arrayOriginal;
                if(tipo == ALEATORIO){
                    arrayOriginal = ArrayGen::gerarArrayAleatorio(tamanho);
                } else if(tipo == PARCIALMENTE_ORDENADO){
                    arrayOriginal = ArrayGen::gerarArrayParcialmenteOrdenado(tamanho, tamanho /100); //1% de trocas
                } else if(tipo == ORDENADO){
                    arrayOriginal = ArrayGen::gerarArrayOrdenado(tamanho);
                } else if(tipo == ORDENADO_REVERSO){
                    arrayOriginal = ArrayGen::gerarArrayOrdenadoReverso(tamanho);
                }

                vector<int> arr = arrayOriginal; // Copia o array original para o array a ser ordenado

                Metricas::resetMetricas(); // Reseta as métricas antes de cada ordenação
                Metricas::startTimer(); // Inicia o cronômetro
                algoritmo(arr); // Chama o algoritmo de ordenação

                double tempoMs = Metricas::stopTimer(); // Para o cronômetro e obtém o tempo gasto

                long long comparacoes = Metricas::getComparacoes();
                long long trocas = Metricas::getTrocas();

                //Verifica se o array está ordenado
                if(!Metricas::isSorted(arr)){
                    cout << "Erro: O array não esta ordenado corretamente pelo algoritmo." << nome << endl;
                } else{
                    cout << "Algoritmo: " << nome << endl;
                    double tempoS = tempoMs/ 1000.0;

                    cout << "Tempo: " << fixed << setprecision(3) << tempoMs << " ms ("; // 3 casas decimais para ms
                    cout << fixed << setprecision(6) << tempoS << " segundos)" << endl; // 6 casas decimais para segundos
                    Metricas::printMetricas(); // Imprime as métricas de comparações e trocas
                    cout << endl;

                    //escrevendo no arquivo csv
                    arquivo_csv << nomesTipos[tipo] << ","
                                << tamanho << ","
                                << nome << ","
                                << fixed << setprecision(6) << tempoMs << ","
                                << fixed << setprecision(6) << tempoS << ","
                                << comparacoes << ","
                                << trocas << endl;
                }
            }
        }
    }

    //fechando arquivo csv
    arquivo_csv.close();

    cout << "===============================================================" << endl;
    cout << "||     Fim da análise comparativa de algoritmos de ordenação  ||" << endl;
    cout << "===============================================================" << endl;
    cout << "\nDados foram exportados para 'resultados_ordenacao.csv'." << endl;
    return 0;
}