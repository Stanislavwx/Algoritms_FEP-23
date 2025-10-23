#pragma once

// Бібліотека Sort рівно під методичку.
// A — вхідний масив 0..n-1
// B — вихідний масив 1..n (виділяти n+1)
// n — кількість елементів
// k — максимум у масиві (0..k)

void CountingSort(int* A, int* B, int n, int k);

// RadixSort (LSD) через стабільний counting за цифрою.
// Тут n не передається — поклади B[0] = n перед викликом.
void RadixSort(int* A, int* B, int k);

// Утиліти для main (необов'язкові, але зручні):
int GetMaxA(const int* A, int n);
void Show(const int* B, int from, int to);
