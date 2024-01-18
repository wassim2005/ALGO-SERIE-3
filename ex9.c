#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *word) {
    int start = 0;
    int end = strlen(word) - 1;

    while (start < end) {
        
        while (!isalnum(word[start]) && start < end) {
            start++;
        }
        while (!isalnum(word[end]) && start < end) {
            end--;
        }

        
        if (tolower(word[start]) != tolower(word[end])) {
            return 0; 
        }

        
        start++;
        end--;
    }

    return 1; 
}

int main() {
    char word[] = "Radar";
    
    if (isPalindrome(word)) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}
