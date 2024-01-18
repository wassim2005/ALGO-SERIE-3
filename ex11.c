#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cleanString(const char* S, char* cleanedString) {
    int j = 0;
    for (int i = 0; S[i] != '\0'; ++i) {
        if (isalpha(S[i]) || isspace(S[i])) {
            cleanedString[j++] = S[i];
        }
    }
    cleanedString[j] = '\0'; 
}

int main() {
    char userString[100];  
    char cleanedString[100];  
    
    printf("Enter a string: ");
    fgets(userString, sizeof(userString), stdin);

    
    size_t len = strlen(userString);
    if (len > 0 && userString[len - 1] == '\n') {
        userString[len - 1] = '\0';
    }

    
    cleanString(userString, cleanedString);

    
    printf("Original string: %s\n", userString);
    printf("Cleaned string: %s\n", cleanedString);

    return 0;
}
