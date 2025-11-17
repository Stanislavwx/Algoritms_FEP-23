#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(&cout);

    cout << "=== Частина 2: Черги з пріоритетами ===\n";
    cout << "Введіть n: " << flush;
    int n; if(!(cin>>n) || n<0){ cerr<<"Некоректне n\n"; return 1; }
    vector<int> data(n);
    cout << "Введіть " << n << " цілих: " << flush;
    for(int i=0;i<n;i++) cin>>data[i];

    // MAX-черга
    vector<int> A(1,0); A.insert(A.end(), data.begin(), data.end());
    size_t heap_size; BuildMaxHeap(A, heap_size);
    cout << "\nMAX-heap:\n"; PrintHeapTree(A, heap_size);
    cout << "Максимум: " << HeapMax(A, heap_size) << "\n";
    cout << "ExtractMax: " << HeapExtractMax(A, heap_size) << "\n";
    PrintHeapTree(A, heap_size);
    MaxHeapInsert(A, heap_size, 100);
    cout << "Після Insert(100):\n"; PrintHeapTree(A, heap_size);

    // MIN-черга
    vector<int> B(1,0); B.insert(B.end(), data.begin(), data.end());
    size_t heap_size2; BuildMinHeap(B, heap_size2);
    cout << "\nMIN-heap:\n"; PrintHeapTree(B, heap_size2);
    cout << "Мінімум: " << HeapMin(B, heap_size2) << "\n";
    cout << "ExtractMin: " << HeapExtractMin(B, heap_size2) << "\n";
    PrintHeapTree(B, heap_size2);
//    MinHeapInsert(B, heap_size2, -100);
//    cout << "Після Insert(-100):\n"; PrintHeapTree(B, heap_size2);

    return 0;
}