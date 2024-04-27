#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BubbleSort(int* arr, int n) {
    if (n == 1) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BucketSort(int* arr, int n) {
    if (n == 1) return;
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        else if (arr[i] > max) max = arr[i];
    }
    int numBuckets = max - min + 1;
    int* buckets = new int[numBuckets]();
    for (int i = 0; i < n; i++) {
        buckets[arr[i] - min]++;
    }
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        while (buckets[i] > 0) {
            arr[index++] = i + min;
            buckets[i]--;
        }
    }
    delete[] buckets;
}
