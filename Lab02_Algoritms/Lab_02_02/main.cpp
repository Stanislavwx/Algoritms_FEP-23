#include <cstdio>
#include <cstdlib>
#include "Sort/Sort.h"

int main() {
    int n;
    if (std::scanf("%d", &n) != 1 || n <= 0) {
        std::fprintf(stderr, "Некоректний розмір масиву.\n");
        return 1;
    }

    int* a = (int*)std::malloc(sizeof(int) * n);
    if (!a) { std::fprintf(stderr, "Немає пам'яті.\n"); return 1; }

    for (int i = 0; i < n; ++i) std::scanf("%d", &a[i]);

    // Мін/макс/медіана(и) через RandomizedSelect (без повного сортування)
    int mn = Sort::RandomizedSelect(a, 0, n - 1, 1);
    int mx = Sort::RandomizedSelect(a, 0, n - 1, n);

    if (n % 2 == 1) {
        int med = Sort::RandomizedSelect(a, 0, n - 1, (n + 1) / 2);
        std::printf("min=%d, max=%d, median=%d\n", mn, mx, med);
    } else {
        int m1 = Sort::RandomizedSelect(a, 0, n - 1, n / 2);
        int m2 = Sort::RandomizedSelect(a, 0, n - 1, n / 2 + 1);
        std::printf("min=%d, max=%d, lower_median=%d, upper_median=%d\n", mn, mx, m1, m2);
    }

    int q; // кількість запитів i-тої порядкової статистики
    if (std::scanf("%d", &q) != 1 || q < 0) {
        std::fprintf(stderr, "Некоректна кількість запитів.\n");
        std::free(a); return 1;
    }

    for (int t = 0; t < q; ++t) {
        int i;
        if (std::scanf("%d", &i) != 1) { std::fprintf(stderr, "Очікувалось i.\n"); std::free(a); return 1; }
        if (i <= 0 || i > n) {
            std::printf("i=%d поза межами [1..%d]\n", i, n);
        } else {
            int val = Sort::RandomizedSelect(a, 0, n - 1, i);
            std::printf("%d-та порядкова статистика: %d\n", i, val);
        }
    }

    std::free(a);
    return 0;
}
