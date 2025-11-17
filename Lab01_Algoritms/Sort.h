#pragma once
#include <vector>

// Зливає дві відсортовані частини масиву a: [left..mid] і [mid+1..right]
void Merge(std::vector<int>& a, int left, int mid, int right);

// Рекурсивне сортування злиттям діапазону [left..right]
void MergeSort(std::vector<int>& a, int left, int right);
