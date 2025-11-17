#include "Sort.h"
#include <climits>  // для INT_MAX

void Merge(std::vector<int>& a, int left, int mid, int right) {
    //допоміжні вектори
    std::vector<int> L;
    std::vector<int> R;

    for (int i = left; i <= mid; ++i) L.push_back(a[i]);
    for (int j = mid + 1; j <= right; ++j) R.push_back(a[j]);

    //сторожовий елемент
    L.push_back(INT_MAX);
    R.push_back(INT_MAX);

    // індекси по допоміжних масивах
    int i = 0;
    int j = 0;

    // зливаємо назад у a[left..right]
    for (int k = left; k <= right; ++k) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++i;
        } else {
            a[k] = R[j];
            ++j;
        }
    }
}

void MergeSort(std::vector<int>& a, int left, int right) {
    if (left >= right) return; // база: 0 або 1 елемент — вже відсортовано
    int mid = left + (right - left) / 2;

    // сортуємо ліву і праву половини
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);

    // зливаємо дві відсортовані частини
    Merge(a, left, mid, right);
}
