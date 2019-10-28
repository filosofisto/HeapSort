//
// Created by Eduardo Ribeiro da Silva on 28/10/19.
//

#ifndef HEAPSORT_HEAPSORT_H
#define HEAPSORT_HEAPSORT_H

#include <iostream>
#include <cstdio>

using namespace std;

template <typename T>
class HeapSort {
public:
    HeapSort(T* array, size_t size);
    ~HeapSort();

    void sort();

private:
    void build_max_heap();
    void max_heapify(int i);
    int  parent(int i);
    int  left(int i);
    int  right(int i);
    void exchange(int from, int to);
    int _(int i);

    void _log();

    size_t size;
    size_t heap_size;

    T* array;
};

template<typename T>
HeapSort<T>::HeapSort(T* array, size_t size): array(array), size(size) {

}

template<typename T>
HeapSort<T>::~HeapSort() = default;

template<typename T>
void HeapSort<T>::sort() {
    build_max_heap();
    for (int i = size-1; i > 0; i--) {
        exchange(0, i);
        heap_size--;
        max_heapify(0);
    }
}

template<typename T>
void HeapSort<T>::build_max_heap() {
    heap_size = size;
    for (int i = size/2; i > 0; i--) {
        max_heapify(i);
    }
}

template<typename T>
void HeapSort<T>::max_heapify(int i) {
    int largest;
    int l = left(i);
    int r = right(i);

    if (l <= heap_size && array[_(l)] > array[_(i)]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r <= heap_size && array[_(r)] > array[_(largest)]) {
        largest = r;
    }

    if (largest != i) {
        exchange(i, largest);
        max_heapify(largest);
    }
}

template<typename T>
int HeapSort<T>::parent(int i) {
    return i/2-1;
}

template<typename T>
int HeapSort<T>::left(int i) {
    return 2*i;
}

template<typename T>
int HeapSort<T>::right(int i) {
    return 2*i+1;
}

template<typename T>
void HeapSort<T>::exchange(int from, int to) {
    cout << "exchange => from: " << array[_(from)] << " to: " << array[_(to)] << " ==> ";
    T tmp = array[_(from)];
    array[_(from)] = array[_(to)];
    array[_(to)] = tmp;
    _log();
}

template<typename T>
inline int HeapSort<T>::_(int i) {
    return i-1;
}

template<typename T>
void HeapSort<T>::_log() {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}


#endif //HEAPSORT_HEAPSORT_H
