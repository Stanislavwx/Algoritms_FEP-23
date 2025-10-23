#include <iostream>
#include "Sort/Sort.h"
using namespace std;

int main() {
    cout << "Choose a method of sort:\n";
    cout << "1) CountingSort\n";
    cout << "2) RadixSort\n";
    cout << "3) Exit\n";

    int choice;
    cin >> choice;
    if (choice == 3) return 0;
    if (choice != 1 && choice != 2) return 0;

    int N;
    cout << "\nEnter the length of the array N = ";
    cin >> N;
    cout << endl;

    int* A = new int[N]; //поточний масив (ми його поступово впорядковуємо по розрядах).
    int* B = new int[N + 1];
    B[0] = N;                     // для RadixSort (як у методичці)

    for (int i = 0; i < N; ++i) {
        cout << "Enter the array element below the index " << i << ": ";
        cin >> A[i];
    }
    cout << endl;

    int k = GetMaxA(A, N);        // максимум у масиві (0..k)

    if (choice == 1) {
        CountingSort(A, B, N, k); // стабільний підрахунок
        Show(B, 1, N);            // "Result: ..."
    } else { // choice == 5
        RadixSort(A, B, k);       // LSD через підрахунок по цифрі
        Show(B, 1, N);
    }

    delete[] A;
    delete[] B;
    return 0;
}
