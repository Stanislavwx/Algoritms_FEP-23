// =========================
// File: Sort/Sort.h
// =========================
#ifndef SORT_SORT_H
#define SORT_SORT_H

#include <cstddef>

namespace Sort {
    // Обов'язково БЕЗ STL-контейнерів: працюємо з сирим масивом int*

    // Обмін значень (власна реалізація, не std::swap)
    inline void iswap(int& a, int& b) {
        int t = a; a = b; b = t;
    }

    // Partition за схемою Ломуто (опорний = a[r])
    int Partition(int* a, int l, int r);

    // RandomizedPartition: випадковий опорний у [l, r]
    int RandomizedPartition(int* a, int l, int r);

    // Рекурсивне швидке сортування (детерміноване)
    void QuickSort(int* a, int l, int r);

    // Рекурсивне швидке сортування з випадковим опорним
    void QuickSortRandomized(int* a, int l, int r);

    // RandomizedSelect: i-та порядкова статистика (1-базовано) у підмасиві a[l..r]
    int RandomizedSelect(int* a, int l, int r, int i);
}

#endif // SORT_SORT_H
