#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analyze_string(char *CH) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int contains_all_vowels = 1;
    for (int i = 0; i < 5; ++i) {
        if (!strchr(CH, tolower(vowels[i]))) {
            contains_all_vowels = 0;
            break;
        }
    }
    printf("Contains all vowels: %s\n", contains_all_vowels ? "true" : "false");

    int num_vowels = 0;
    for (int i = 0; CH[i] != '\0'; ++i) {
        if (strchr("aeiouAEIOU", CH[i])) {
            num_vowels++;
        }
    }
    printf("Number of vowels: %d\n", num_vowels);

    char SCH[50];
    printf("Enter substring SCH: ");
    scanf("%s", SCH);

    int sch_frequency = 0;
    char *ptr = CH;
    while ((ptr = strstr(ptr, SCH)) != NULL) {
        sch_frequency++;
        ptr++;
    }
    printf("Frequency of %s: %d\n", SCH, sch_frequency);

    int num_characters = strlen(CH);
    int num_words = 0;
    int num_sentences = 0;
    for (int i = 0; CH[i] != '\0'; ++i) {
        if (CH[i] == ' ') {
            num_words++;
        } else if (CH[i] == '.') {
            num_sentences++;
        }
    }
    num_words++;
    printf("Number of characters: %d\n", num_characters);
    printf("Number of words: %d\n", num_words);
    printf("Number of sentences: %d\n", num_sentences);

    char *token = strtok(CH, " ");
    char first_letter = tolower(token[0]);
    int is_tautogram = 1;

    while (token != NULL) {
        if (tolower(token[0]) != first_letter) {
            is_tautogram = 0;
            break;
        }
        token = strtok(NULL, " ");
    }

    printf("Is a tautogram sentence: %s\n", is_tautogram ? "true" : "false");
}

int main() {
    char CH_example[500];  
    printf("Enter a string: ");
    scanf(" %[^\n]", CH_example); 
    analyze_string(CH_example);

    return 0;
}
