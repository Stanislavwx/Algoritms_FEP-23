
#include "Sort.h"
#include <cstdlib>
#include <ctime>

namespace Sort {
    static bool seeded = false;
    static void ensure_seeded() {
        if (!seeded) { std::srand((unsigned)std::time(nullptr)); seeded = true; }
    }

    int Partition(int* a, int l, int r) {
        int x = a[r];              // опорний
        int i = l - 1;             // позиція для елементів ≤ x
        for (int j = l; j <= r - 1; ++j) {
            if (a[j] <= x) {
                ++i;
                iswap(a[i], a[j]);
            }
        }
        iswap(a[i + 1], a[r]);
        return i + 1;              // індекс опорного після розбиття
    }

    int RandomizedPartition(int* a, int l, int r) {
        ensure_seeded();
        int pivotIndex = l + std::rand() % (r - l + 1);
        iswap(a[pivotIndex], a[r]);
        return Partition(a, l, r);
    }

    void QuickSort(int* a, int l, int r) {
        if (l < r) {
            int q = Partition(a, l, r);
            QuickSort(a, l, q - 1);
            QuickSort(a, q + 1, r);
        }
    }

    void QuickSortRandomized(int* a, int l, int r) {
        if (l < r) {
            int q = RandomizedPartition(a, l, r);
            QuickSortRandomized(a, l, q - 1);
            QuickSortRandomized(a, q + 1, r);
        }
    }

    int RandomizedSelect(int* a, int l, int r, int i) {
        // i — 1-базований номер всередині a[l..r]
        if (i <= 0 || i > (r - l + 1)) return 0; // перевірка меж
        ensure_seeded();
        while (true) {
            if (l == r) return a[l];
            int pivotIndex = l + std::rand() % (r - l + 1);
            iswap(a[pivotIndex], a[r]);
            int q = Partition(a, l, r);
            int k = q - l + 1; // кількість елементів у лівій частині + опорний
            if (i == k) return a[q];
            else if (i < k) r = q - 1;     // шукаємо зліва
            else { l = q + 1; i -= k; }    // справа
        }
    }
}
