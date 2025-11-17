#include <cstdio>
#include <cstdlib>
#include "Sort/Sort.h"

static void print_arr(const int* a, int n) {
    for (int i = 0; i < n; ++i) {
        if (i) std::printf(" ");
        std::printf("%d", a[i]);
    }
    std::printf("\n");
}

int main() {
    int n;
    std::printf("Введіть к-сть елементів:\n");
    if (std::scanf("%d", &n) != 1 || n < 0) {
        std::fprintf(stderr, "Некоректний розмір масиву.\n");
        return 1;
    }
    std::printf("Введіть масив:\n");
    int* a = (int*)std::malloc(sizeof(int) * (n > 0 ? n : 1));
    if (!a) { std::fprintf(stderr, "Немає пам'яті.\n"); return 1; }

    for (int i = 0; i < n; ++i) std::scanf("%d", &a[i]);

    //if (n > 1) Sort::QuickSort(a, 0, n - 1);

    if (n > 1) Sort::QuickSortRandomized(a, 0, n - 1);

    std::printf("Відсортований масив:\n");
    print_arr(a, n);

    std::free(a);
    return 0;
}
