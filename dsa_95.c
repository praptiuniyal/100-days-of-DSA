#include <stdio.h>

// Insertion sort for each bucket
void insertionSort(float arr[], int n) {
    for(int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Bucket Sort
void bucketSort(float arr[], int n) {
    // Create buckets (2D array)
    float bucket[n][n];
    int count[n];

    // Initialize counts
    for(int i = 0; i < n; i++)
        count[i] = 0;

    // Distribute elements into buckets
    for(int i = 0; i < n; i++) {
        int idx = n * arr[i];   // bucket index
        bucket[idx][count[idx]++] = arr[i];
    }

    // Sort individual buckets
    for(int i = 0; i < n; i++) {
        insertionSort(bucket[i], count[i]);
    }

    // Concatenate buckets
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);

    // Print sorted array
    for(int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}