
# 📊 Análise Comparativa de Algoritmos de Ordenação

Este projeto realiza uma análise experimental dos principais algoritmos de ordenação — **Bubble Sort**, **Insertion Sort**, **Selection Sort**, **Merge Sort** e **Quick Sort** — aplicados a diferentes tipos de arrays, medindo e comparando métricas como **tempo de execução**, **número de comparações**, **número de trocas** e **uso de memória auxiliar**.

---

## 📁 Estrutura do Projeto

```
├── include/                # Arquivos de cabeçalho (.h)
├── src/                    # Implementações dos algoritmos (.cpp)
├── test/                   # Arquivo principal (main.cpp)
├── build/                  # Arquivos objetos (.o)
├── resultados_ordenacao.csv  # Saída com os resultados em CSV
├── Makefile                # Script de compilação e execução
└── README.md               # Este arquivo
```

---

## 🧠 Algoritmos Implementados

- 🔁 **Bubble Sort**
- 🔧 **Insertion Sort**
- 🔍 **Selection Sort**
- 🔀 **Merge Sort**
- ⚡ **Quick Sort**

---

## 📊 Tipos de Dados Testados

- 🔀 **Aleatório**
- 🟡 **Parcialmente Ordenado** (com 1% de trocas)
- 🟢 **Ordenado**
- 🔴 **Ordenado Reversamente**

---

## ⚙️ Como Executar

### 1. Compilação
Use o comando abaixo para compilar o projeto:

```bash
make
```

### 2. Execução

```bash
make run
```

### 3. Limpeza dos arquivos compilados

```bash
make clean
```

---

## 📦 Dependências

- Compilador `g++` (C++17)
- Sistema Unix-like (Linux/macOS) ou Windows com suporte a `Makefile`

---

## 📈 Saída

Os resultados da execução são salvos no arquivo:

```
resultados_ordenacao.csv
```

Cada linha do CSV contém:

```
Tipo_Dado, Tamanho_Array, Algoritmo, Tempo_ms, Tempo_s, Comparacoes, Trocas, Memoria_Auxiliar_Bytes
```

Exemplo:
```
Aleatório,1000,Bubble Sort,12.345000,0.012345,9876,6543,0
```

---

## 🧪 Métricas Coletadas

- **Tempo de execução** (ms e s)
- **Número de comparações**
- **Número de trocas**
- **Memória auxiliar utilizada (bytes)**

---

## 🔍 Objetivo

Avaliar e comparar o desempenho prático de diferentes algoritmos de ordenação sob cenários diversos, de forma a identificar:

- Eficiência em diferentes contextos de entrada
- Algoritmos mais indicados para cada situação
- Impacto no uso de memória auxiliar

---

## 📝 Licença

Este projeto está licenciado sob a licença MIT. Sinta-se livre para usar e modificar.

---

## 👨‍💻 Autor

Gabriel Eugenio  
UFRN / BTI
