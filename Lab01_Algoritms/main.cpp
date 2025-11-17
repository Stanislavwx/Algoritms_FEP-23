#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

int main() {

    int n;
    cout << "Введіть кількість елементів: ";
    if (!(cin >> n) || n < 0) {
        cout << "Некоректне n\n";
        return 0;
    }

     cout << "Введіть " << n << " цілих чисел: ";
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n > 0) MergeSort(a, 0, n - 1);

    cout << "Відсортований масив: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i + 1 < n) cout << " ";
    }
    cout << "\n";

    return 0;
}
