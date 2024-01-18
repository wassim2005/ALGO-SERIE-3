#include <stdio.h>

int vowCnt(char A[][30], int N, int M);
int findChr(char A[][30], int N, int M, char target);
void transMtx(char A[][30], int N, int M);
void rotCols(char A[][30], int N, int M);
void insVec(char A[][30], int N, int M, char V[], int J);

int main() {
    char mtx[20][30];
    int r, c;

    do {
        printf("Enter the number of rows (2 to 20): ");
        scanf("%d", &r);
    } while (r < 2 || r > 20);

    do {
        printf("Enter the number of columns (2 to 30): ");
        scanf("%d", &c);
    } while (c < 2 || c > 30);

   
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf(" %c", &mtx[i][j]); 
        }
    }

    int vowCount = vowCnt(mtx, r, c);
    printf("Number of vowels in the matrix: %d\n", vowCount);

    char targetChar;
    printf("Enter a character to find in the matrix: ");
    scanf(" %c", &targetChar);
    int charFound = findChr(mtx, r, c, targetChar);
    printf("Character '%c' %s in the matrix.\n", targetChar, (charFound ? "found" : "not found"));

    transMtx(mtx, r, c);
    rotCols(mtx, r, c);

    char vector[3];
    printf("Enter a vector of 3 characters to insert in the matrix: ");
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &vector[i]);
    }

    int colToInsert;
    do {
        printf("Enter the column index to insert the vector: ");
        scanf("%d", &colToInsert);
    } while (colToInsert < 0 || colToInsert >= c);

    insVec(mtx, r, c, vector, colToInsert);

    
    printf("Modified matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%c ", mtx[i][j]);
        }
        printf("\n");
    }

    

    return 0;
}

int vowCnt(char A[][30], int N, int M) {
    int vCnt = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 10; k++) {
                if (A[i][j] == vowels[k]) {
                    vCnt++;
                    break;
                }
            }
        }
    }

    return vCnt;
}

int findChr(char A[][30], int N, int M, char target) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;
}

void transMtx(char A[][30], int N, int M) {
    char transM[30][20];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            transM[j][i] = A[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = transM[i][j];
        }
    }
}

void rotCols(char A[][30], int N, int M) {
    char temp[30];

    for (int j = 0; j < M; j++) {
        temp[0] = A[N - 1][j];

        for (int i = N - 1; i > 0; i--) {
            A[i][j] = A[i - 1][j];
        }

        A[0][j] = temp[0];
    }
}

void insVec(char A[][30], int N, int M, char V[], int J) {
    for (int i = 0; i < N; i++) {
        A[i][J] = V[i];
    }
}
