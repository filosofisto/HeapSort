#include <iostream>
#include "HeapSort.h"

using namespace std;

int main() {
    cout << "Heap Sort Sample" << endl;

    int array[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };

    cout << "Original Array: ";
    for (int value: array) {
        cout << value << " ";
    }

    cout << endl;

    HeapSort<int> sorter = HeapSort<int>(array, size(array));
    sorter.sort();

    cout << "After HeapSort: ";
    for (int value: array) {
        cout << value << " ";
    }

    cout << endl;

    return EXIT_SUCCESS;
}