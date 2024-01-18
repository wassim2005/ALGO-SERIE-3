#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int Arr[], int n);
void printArray(int Arr[], int n);
void areIdentical(int Vec1[], int Size1, int Vec2[], int Size2);
void notInCommon(int Vec1[], int Size1, int Vec2[], int Size2);
void scalarOperation(int Vec1[], int Size1, int Vec2[], int Size2);
void mergeVectors(int Vec1[], int Size1, int Vec2[], int Size2);

int main() {
    int Size1, Size2;

    printf("Enter the size of Vec1: ");
    scanf("%d", &Size1);

    printf("Enter the size of Vec2: ");
    scanf("%d", &Size2);

    int Vec1[Size1];
    int Vec2[Size2];

    printf("Enter %d elements for Vec1:\n", Size1);
    fillArray(Vec1, Size1);

    printf("Enter %d elements for Vec2:\n", Size2);
    fillArray(Vec2, Size2);

    printf("\nVec1: ");
    printArray(Vec1, Size1);

    printf("\nVec2: ");
    printArray(Vec2, Size2);

    areIdentical(Vec1, Size1, Vec2, Size2);
    notInCommon(Vec1, Size1, Vec2, Size2);
    scalarOperation(Vec1, Size1, Vec2, Size2);
    mergeVectors(Vec1, Size1, Vec2, Size2);

    return 0;
}

void fillArray(int Arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &Arr[i]);
    }
}

void printArray(int Arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", Arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void areIdentical(int Vec1[], int Size1, int Vec2[], int Size2) {
    if (Size1 != Size2) {
        printf("The vectors are not identical.\n");
    } else {
        int isIdentical = 1;

        for (int i = 0; i < Size1 && isIdentical; i++) {
            if (Vec1[i] != Vec2[i]) {
                isIdentical = 0;
            }
        }

        if (isIdentical) {
            printf("The vectors are identical.\n");
        } else {
            printf("The vectors are not identical.\n");
        }
    }
}

void notInCommon(int Vec1[], int Size1, int Vec2[], int Size2) {
    int notCommon[Size1];
    int count = 0;

    for (int i = 0; i < Size1; i++) {
        int isCommon = 0;

        for (int j = 0; j < Size2 && !isCommon; j++) {
            if (Vec1[i] == Vec2[j]) {
                isCommon = 1;
            }
        }

        if (!isCommon) {
            notCommon[count] = Vec1[i];
            count++;
        }
    }

    printf("Elements not in common: ");
    printArray(notCommon, count);
}

void scalarOperation(int Vec1[], int Size1, int Vec2[], int Size2) {
    int size = Size1 * (Size1 <= Size2) + Size2 * (Size2 < Size1);
    int sum = 0;
    int product = 0;

    for (int i = 0; i < size; i++) {
        sum += (Vec1[i] + Vec2[i]);
        product += (Vec1[i] * Vec2[i]);
    }

    printf("Scalar sum of the two vectors: %d, and the product: %d.\n", sum, product);
}

void mergeVectors(int Vec1[], int Size1, int Vec2[], int Size2) {
    int MergedVec[Size1 + Size2];
    int MergedSize = Size1 + Size2;
    int temp;

    for (int i = 0; i < Size2; i++) {
        MergedVec[i] = Vec2[i];
    }

    for (int i = 0; i < Size1; i++) {
        temp = Vec1[i];
        int j = Size2 - 1 + i;

        while (MergedVec[j] > Vec1[i] && j > -1) {
            MergedVec[j + 1] = MergedVec[j];
            j--;
        }

        MergedVec[j + 1] = temp;
    }

    printf("Merged Vector: ");
    printArray(MergedVec, MergedSize);
}
