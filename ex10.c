#include <stdio.h>
#include <string.h>

const char* checkSquare(const char* S) {
    int len = strlen(S);

    
    if (len % 2 != 0) {
        return "Not a square";
    }

    
    int halfLen = len / 2;

    
    if (strncmp(S, S + halfLen, halfLen) == 0) {
        return "Square";
    } else {
        return "Not a square";
    }
}

int main() {
    char userString[100];  

    
    printf("Enter a string: ");
    fgets(userString, sizeof(userString), stdin);

    
    size_t len = strlen(userString);
    if (len > 0 && userString[len - 1] == '\n') {
        userString[len - 1] = '\0';
    }

    printf("%s is %s.\n", userString, checkSquare(userString));

    return 0;
}
