#include "Heap.h"
#include <algorithm>
#include <functional>

static inline void swapv(int& a, int& b){ int t=a; a=b; b=t; }
// підтримка властивості MAX-heap
void MaxHeapify(std::vector<int>& A, size_t heap_size, size_t i){
    while(true){
        size_t l=Left(i), r=Right(i), m=i;
        if(l<=heap_size && A[l]>A[m]) m=l;
        if(r<=heap_size && A[r]>A[m]) m=r;
        if(m==i) break;
        swapv(A[i], A[m]); i=m;
    }
}
// Мін-версія MaxHeapify
void MinHeapify(std::vector<int>& A, size_t heap_size, size_t i){
    while(true){
        size_t l=Left(i), r=Right(i), m=i;
        if(l<=heap_size && A[l]<A[m]) m=l;
        if(r<=heap_size && A[r]<A[m]) m=r;
        if(m==i) break;
        swapv(A[i], A[m]); i=m;
    }
}
// побудова MAX-heap
void BuildMaxHeap(std::vector<int>& A, size_t& heap_size){
    if (A.empty() || A[0]!=0){ A.insert(A.begin(), 0); }
    heap_size = A.size()-1;
    for(size_t i=heap_size/2; i>=1; --i){ MaxHeapify(A, heap_size, i); if(i==1) break; }
}
// побудова MIN-heap
void BuildMinHeap(std::vector<int>& A, size_t& heap_size){
    if (A.empty() || A[0]!=0){ A.insert(A.begin(), 0); }
    heap_size = A.size()-1;
    for(size_t i=heap_size/2; i>=1; --i){ MinHeapify(A, heap_size, i); if(i==1) break; }
}
// сортування за зростанням
void HeapSortAsc(std::vector<int>& arr){
    std::vector<int> A; A.reserve(arr.size()+1); A.push_back(0);
    for(int v: arr) A.push_back(v);
    size_t heap_size; BuildMaxHeap(A, heap_size);
    for(size_t i=heap_size; i>=2; --i){
        swapv(A[1], A[i]); --heap_size; MaxHeapify(A, heap_size, 1);
        if(i==2) break;
    }
    for(size_t i=0;i<arr.size();++i) arr[i]=A[i+1];
}
// Сортування за спаданням
void HeapSortDesc(std::vector<int>& arr){
    std::vector<int> A; A.reserve(arr.size()+1); A.push_back(0);
    for(int v: arr) A.push_back(v);
    size_t heap_size; BuildMinHeap(A, heap_size);
    for(size_t i=heap_size; i>=2; --i){
        swapv(A[1], A[i]); --heap_size; MinHeapify(A, heap_size, 1);
        if(i==2) break;
    }
    for(size_t i=0;i<arr.size();++i) arr[i]=A[i+1];
}

// вивід купи у вигляді дерева"
void PrintHeapTree(const std::vector<int>& A, size_t heap_size, std::ostream& os){
    if (heap_size==0){ os<<"[порожньо]\n"; return; }

    auto digits = [](long long x){ return (int)std::to_string(x).size(); };
    int maxw=1; for(size_t i=1;i<=heap_size;i++) maxw=std::max(maxw, digits(A[i]));
    int cell = std::max(3, maxw+2);
    int h = (int)std::floor(std::log2((double)heap_size));
    int width = ((int)1<<(h+1))*cell;
    int rows = h*2+1;
    std::vector<std::string> canvas(rows, std::string(width,' '));

    auto place_center = [&](int r,int c,const std::string& t){
        int start=c-(int)t.size()/2; if(start<0) start=0;
        for(size_t k=0;k<t.size() && start+(int)k<width;k++) canvas[r][start+(int)k]=t[k];
    };

    std::function<void(size_t,int,int,int)> draw = [&](size_t i,int depth,int cx,int span){
        if(i>heap_size) return;
        place_center(depth*2, cx, std::to_string(A[i]));
        int child_span = std::max(cell, span/2);
        size_t li=Left(i), ri=Right(i);
        int y = depth*2+1;
        if(li<=heap_size){
            int lx = cx - child_span;
            int sx = (lx + cx)/2;
            if(y<rows && sx>=0 && sx<width) canvas[y][sx]='/';
            draw(li, depth+1, lx, child_span/2);
        }
        if(ri<=heap_size){
            int rx = cx + child_span;
            int sx = (cx + rx)/2;
            if(y<rows && sx>=0 && sx<width) canvas[y][sx]='\\';
            draw(ri, depth+1, rx, child_span/2);
        }
    };

    int root_x = width/2;
    draw(1,0,root_x, ((int)1<<h)*(cell/2));
    for(auto& line: canvas) os<<line<<"\n";
}

// MAX
int HeapMax(const std::vector<int>& A, size_t heap_size){ if(heap_size<1) throw std::runtime_error("Черга порожня"); return A[1]; }

int HeapExtractMax(std::vector<int>& A, size_t& heap_size){
    if(heap_size<1) throw std::runtime_error("Черга порожня");
    int v=A[1]; A[1]=A[heap_size]; --heap_size; if(heap_size>=1) MaxHeapify(A, heap_size, 1); return v;
}
void HeapIncreaseKey(std::vector<int>& A, size_t i, int key){
    if(key<A[i]) throw std::runtime_error("Новий ключ менший за поточний");
    A[i]=key; while(i>1 && A[Parent(i)]<A[i]){ std::swap(A[i],A[Parent(i)]); i=Parent(i); }
}
void MaxHeapInsert(std::vector<int>& A, size_t& heap_size, int key){
    if(A.empty() || A[0]!=0){ A.insert(A.begin(),0); heap_size=A.size()-1; }
    if(heap_size+1>=A.size()) A.push_back(INT_MIN); else A[heap_size+1]=INT_MIN;
    ++heap_size; HeapIncreaseKey(A, heap_size, key);
}

// MIN
int HeapMin(const std::vector<int>& A, size_t heap_size){ if(heap_size<1) throw std::runtime_error("Черга порожня"); return A[1]; }
int HeapExtractMin(std::vector<int>& A, size_t& heap_size){
    if(heap_size<1) throw std::runtime_error("Черга порожня");
    int v=A[1]; A[1]=A[heap_size]; --heap_size; if(heap_size>=1) MinHeapify(A, heap_size, 1); return v;
}
void HeapDecreaseKey(std::vector<int>& A, size_t i, int key){
    if(key>A[i]) throw std::runtime_error("Новий ключ більший за поточний");
    A[i]=key; while(i>1 && A[Parent(i)]>A[i]){ std::swap(A[i],A[Parent(i)]); i=Parent(i); }
}
void MinHeapInsert(std::vector<int>& A, size_t& heap_size, int key){
    if(A.empty() || A[0]!=0){ A.insert(A.begin(),0); heap_size=A.size()-1; }
    if(heap_size+1>=A.size()) A.push_back(INT_MAX); else A[heap_size+1]=INT_MAX;
    ++heap_size; HeapDecreaseKey(A, heap_size, key);
}