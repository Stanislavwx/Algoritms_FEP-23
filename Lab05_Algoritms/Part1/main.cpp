#include <bits/stdc++.h>
#include "Heap.h"
using namespace std;

static void print_vec(const vector<int>& a){
    cout << "[ ";
    for(size_t i=0;i<a.size();++i) cout<<a[i]<<(i+1==a.size()?"":" ");
    cout << " ]\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(&cout);

    cout << "=== Частина 1: Купа та сортування ===\n";
    cout << "Введіть n: " << flush;
    int n; if(!(cin>>n) || n<0){ cerr<<"Некоректне n\n"; return 1; }
    vector<int> a(n);
    cout << "Введіть " << n << " цілих: " << flush;
    for(int i=0;i<n;i++) cin>>a[i];

    // Будуємо MAX-heap і показуємо дерево
    vector<int> A(1,0); A.insert(A.end(), a.begin(), a.end());
    size_t heap_size; BuildMaxHeap(A, heap_size);
    cout << "\nMAX-heap:\n";
    PrintHeapTree(A, heap_size);

    // HeapSort
    auto asc = a; HeapSortAsc(asc);
    cout << "\nПісля HeapSort (зростання): "; print_vec(asc);

    auto desc = a; HeapSortDesc(desc);
    cout << "Після HeapSort (спадання): "; print_vec(desc);
    return 0;
}