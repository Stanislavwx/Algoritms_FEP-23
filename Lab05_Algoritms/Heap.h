#ifndef HEAP_LIB_H
#define HEAP_LIB_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cmath>
#include <functional>
#include <string>

// 1-based купа: A[1..heap_size], A[0] не використовується
inline size_t Parent(size_t i){ return i/2; }
inline size_t Left(size_t i){ return 2*i; }
inline size_t Right(size_t i){ return 2*i+1; }

void MaxHeapify(std::vector<int>& A, size_t heap_size, size_t i);
void MinHeapify(std::vector<int>& A, size_t heap_size, size_t i);
void BuildMaxHeap(std::vector<int>& A, size_t& heap_size);
void BuildMinHeap(std::vector<int>& A, size_t& heap_size);

// Сортування: зростання/спадання
void HeapSortAsc(std::vector<int>& arr);
void HeapSortDesc(std::vector<int>& arr);

// Принтер зверху вниз (тільки "/" і "\")
void PrintHeapTree(const std::vector<int>& A, size_t heap_size, std::ostream& os = std::cout);

// MAX-черга
int  HeapMax(const std::vector<int>& A, size_t heap_size);
int  HeapExtractMax(std::vector<int>& A, size_t& heap_size);
void HeapIncreaseKey(std::vector<int>& A, size_t i, int key);
void MaxHeapInsert(std::vector<int>& A, size_t& heap_size, int key);

// MIN-черга
int  HeapMin(const std::vector<int>& A, size_t heap_size);
int  HeapExtractMin(std::vector<int>& A, size_t& heap_size);
void HeapDecreaseKey(std::vector<int>& A, size_t i, int key);
void MinHeapInsert(std::vector<int>& A, size_t& heap_size, int key);

#endif