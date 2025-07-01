#include <iostream>
#include <vector>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "selection_sort.h"

using namespace std;

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Bubble Sort
    bubble_sort(arr);
    cout << "Sorted array using Bubble Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Reset array
    arr = {64, 34, 25, 12, 22, 11, 90};

    // Insertion Sort
    insertion_sort(arr);
    cout << "Sorted array using Insertion Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Reset array
    arr = {64, 34, 25, 12, 22, 11, 90};

    // Merge Sort
    merge_sort(arr);
    cout << "Sorted array using Merge Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Reset array
    arr = {64, 34, 25, 12, 22, 11, 90};

    // Quick Sort
    quick_sort(arr);
    cout << "Sorted array using Quick Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Reset array
    arr = {64, 34, 25, 12, 22, 11, 90};

    // Selection Sort
    selection_sort(arr);
    cout << "Sorted array using Selection Sort: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}