#include <stdio.h>

void fillArr(int arr[], int size);
void printArr(int arr[], int size);
void findMaxSum(int V[], int N, int *Smax, int W[], int *Wsize);
void removeRepetitiveSequences(int W[], int *Wsize);

int main() {
    int N;
    do {
        printf("Enter the size of the array (must be between 2 and 100): ");
        scanf("%d", &N);
    } while (N < 2 || N > 100);

    int V[N];
    fillArr(V, N);
    printf("Original Array V: ");
    printArr(V, N);

    int Smax, Wsize;
    int W[N * 2];  // Assuming the result array won't be larger than 2 times the original size

    findMaxSum(V, N, &Smax, W, &Wsize);
    printf("\nThe largest sum (Smax) of 2 contiguous elements is: %d\n", Smax);

    printf("Array W containing contiguous elements with sum equal to Smax: ");
    printArr(W, Wsize);

    removeRepetitiveSequences(W, &Wsize);
    printf("Modified Array W without repetitive sequences: ");
    printArr(W, Wsize);

    return 0;
}

void fillArr(int arr[], int size) {
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArr(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void findMaxSum(int V[], int N, int *Smax, int W[], int *Wsize) {
    *Smax = 0;
    *Wsize = 0;

    for (int i = 0; i < N - 1; i++) {
        int sum = V[i] + V[i + 1];
        if (sum > *Smax) {
            *Smax = sum;
        }
    }

    int index = 0;
    for (int i = 0; i < N - 1; i++) {
        int sum = V[i] + V[i + 1];
        if (sum == *Smax) {
            W[index++] = V[i];
            W[index++] = V[i + 1];
            *Wsize = index;
        }
    }
}

void removeRepetitiveSequences(int W[], int *Wsize) {
    int newSize = 0;
    for (int i = 0; i < *Wsize - 1; i++) {
        if (W[i] != W[i + 1]) {
            W[newSize++] = W[i];
        }
    }
    W[newSize++] = W[*Wsize - 1];
    *Wsize = newSize;
}
