#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting by start time
int compare(const void *a, const void *b) {
    int *m1 = (int *)a;
    int *m2 = (int *)b;
    return m1[0] - m2[0];
}

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int i) {
    while(i > 0 && heap[(i-1)/2] > heap[i]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(int heap[], int size, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;
    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int val) {
    heap[*size] = val;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    int meetings[n][2];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i][0], &meetings[i][1]);
    }

    // Step 1: sort by start time
    qsort(meetings, n, sizeof(meetings[0]), compare);

    int heap[n];
    int size = 0;

    // First meeting
    push(heap, &size, meetings[0][1]);

    // Process remaining meetings
    for(int i = 1; i < n; i++) {
        if(heap[0] <= meetings[i][0]) {
            pop(heap, &size); // reuse room
        }
        push(heap, &size, meetings[i][1]);
    }

    printf("%d", size); // number of rooms
    return 0;
}