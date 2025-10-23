#include "Sort.h"
#include <iostream>

int GetMaxA(const int* A, int n) {
    int mx = A[0];
    for (int i = 1; i < n; ++i) if (A[i] > mx) mx = A[i];
    return mx;
}

void Show(const int* B, int from, int to) {
    std::cout << "Result: ";
    for (int i = from; i <= to; ++i) std::cout << B[i] << ' ';
    std::cout << '\n';
}

// ---------------- CountingSort ----------------
void CountingSort(int* A, int* B, int n, int k)
{
    int* C = new int[k + 1]; //створюєм лічильник C[0..k]

    for (int i = 0; i <= k; i++) C[i] = 0; //обнуляєм лічильник
    for (int j = 0; j < n;  j++) C[A[j]] = C[A[j]] + 1; //Рахуємо частоти: скільки разів кожне значення зустрічається в A
    for (int i = 1; i <= k; i++) C[i] = C[i] + C[i - 1]; //Префіксні суми (накопичення зліва направо).

    for (int j = n - 1; j >= 0; j--) { //Стабільне розкладання (йдемо з кінця A):
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    delete[] C;
}

// ------------- Внутрішній counting за однією цифрою (LSD) ----------------
static void CountingSortByDigit(int* A, int* B, int n, int exp)
{
    int C[10]; for (int i = 0; i < 10; ++i) C[i] = 0;// створюю і обнуляю лічильник C[0..9]

    for (int j = 0; j < n; ++j) { //Рахуємо, скільки елементів має кожну цифру в поточному розряді напр. (137/10)%10=3 exp=10
        int d = (A[j] / exp) % 10;
        C[d] = C[d] + 1;
    }
    for (int i = 1; i < 10; ++i) C[i] += C[i - 1]; //Префіксні суми C[d] = скільки елементів має цифру <= d

    for (int j = n - 1; j >= 0; --j) { //Стабільне розкладання по цифрі (йдемо з кінця A)
        int d = (A[j] / exp) % 10;
        B[C[d]] = A[j];
        C[d] = C[d] - 1;
    }
    // B[1..n] -> A[0..n-1]
    for (int i = 1; i <= n; ++i) A[i - 1] = B[i]; //копіюємо назад у A, щоб наступний розряд читати з A
}

// ------------------------------- RadixSort (LSD) ---------------------------
void RadixSort(int* A, int* B, int k)
{
    // n передаємо через B[0], як у методичці
    int n = B[0];

    // класичний LSD: по розрядах 1, 10, 100, ...
    for (int exp = 1; k / exp > 0; exp *= 10) { 
        CountingSortByDigit(A, B, n, exp);
    }
    // Записати у B[1..n] для виводу, якщо потрібно
    for (int i = 0; i < n; ++i) B[i + 1] = A[i];
}
