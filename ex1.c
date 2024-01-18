#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mma(int a[], int n);
void cot(int T[], int n);
void rev(int T[], int n);
void rem(int nt[], int n);
void ins(int T[], int n, int pos);
void rap(int T[], int n);
void ods(int T[], int n);
void mdp(int T[], int n);

int main() {
    srand(time(NULL));

    int sz;
    printf("Enter the size of the array: ");
    scanf("%d", &sz);

    int arr[sz];

    printf("Enter %d elements for the array:\n", sz);
    for (int i = 0; i < sz; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\nArray: [");
    for (int i = 0; i < sz; i++) {
        printf("%d", arr[i]);
        if (i < sz - 1) {
            printf(", ");
        }
    }
    printf("]\n======================\n");

    mma(arr, sz);
    cot(arr, sz);
    rev(arr, sz);

    int nArr[] = {0, 55, 98, 82, 0, 0};
    rem(nArr, 6);
    ins(arr, sz, 0);
    rap(arr, sz);
    ods(arr, sz);
    mdp(arr, sz);

    return 0;
}

void mma(int a[], int n) {
    int min = a[0], max = a[0], ac = 0;
    float avg = 0;
    long int prod = 1;

    for (int i = 0; i < n; i++) {
        min = (a[i] < min) ? a[i] : min;
        max = (a[i] > max) ? a[i] : max;

        if (a[i] > 0) {
            prod *= a[i];
        }

        if (a[i] < 0) {
            avg += a[i];
            ac++;
        }
    }

    avg = (ac == 0) ? 0 : (avg / ac);

    printf("\nMin: %d, Max: %d, Avg: %f, Product: %ld\n", min, max, avg, prod);
}

void cot(int T[], int n) {
    int val, num = 0;
    printf("Enter a value to count occurrences: ");
    scanf("%d", &val);

    for (int i = 0; i < n; i++) {
        num += (val == T[i]);
    }

    printf("Occurrences of %d: %d\n", val, num);
}

void rev(int T[], int n) {
    printf("\nReversed Array: [");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", T[i]);
        if (i > 0) {
            printf(", ");
        }
    }
    printf("]\n");
}

void rem(int nt[], int n) {
    printf("\nArray without zeros: [");
    for (int i = 0; i < n; i++) {
        if (nt[i] != 0) {
            printf("%d", nt[i]);
            if (i < n - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

void ins(int T[], int n, int pos) {
    int ins;
    printf("Enter a value to insert: ");
    scanf("%d", &ins);

    printf("\nArray after insertion: [");
    for (int i = 0; i <= n; i++) {
        if (i == pos) {
            printf("%d", ins);
            if (i < n) {
                printf(", ");
            }
        } else {
            printf("%d", T[i - (i > pos)]);
            if (i < n - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

void rap(int T[], int n) {
    for (int i = 0, j = 0, temp; i < n; i++) {
        if (T[i] < 0) {
            temp = T[j];
            T[j++] = T[i];
            T[i] = temp;
        }
    }

    printf("\nArray after rearrangement: [");
    for (int i = 0; i < n; i++) {
        printf("%d", T[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void ods(int T[], int n) {
    int lo = 0, o = 0, loI;

    for (int i = 0; i < n - 1; i++) {
        o = (T[i] <= T[i + 1]) ? o + 1 : 0;

        if (o > lo) {
            lo = o;
            loI = i + 1;
        }
    }

    printf("\nOrdered Sequence: [");
    for (int i = loI - lo; i <= loI; i++) {
        printf("%d", T[i]);
        if (i < loI) {
            printf(", ");
        }
    }
    printf("]\n");
}

void mdp(int T[], int n) {
    int i = 0, d = 100, i1, i2, cd;

    while (i < n - 1 && d != 0) {
        int j = i + 1;

        while (j < n && d != 0) {
            cd = abs(T[i] - T[j]);

            if (cd < d) {
                d = cd;
                i1 = i;
                i2 = j;
            }

            j++;
        }

        i++;
    }

    printf("\nMin Distance Pair: [%d, %d] with Distance: %d\n", T[i1], T[i2], d);
}
