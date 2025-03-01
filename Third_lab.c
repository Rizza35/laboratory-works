#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int isConsonant(unsigned char c) {
    const char *consonants = "бвгджзйклмнпрстфхцчшщъь";
    char temp[2];
    temp[0] = tolower(c);
    temp[1] = '\0';

    for (int i = 0; consonants[i] != '\0'; i++) {
        char consonantStr[2];
        consonantStr[0] = consonants[i];
        consonantStr[1] = '\0';
        if (strcmp(temp, consonantStr) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    char sentence[1000];
    int wordCount = 0;
    int consonantEndCount = 0;

    printf("Введите предложение на русском языке: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    char *token = strtok(sentence, " ");
    while (token != NULL) {
        wordCount++;

        int wordLength = strlen(token);

        if (wordLength > 0) {
            int lastCharIndex = wordLength - 1;
            while (lastCharIndex >= 0 && ispunct(token[lastCharIndex])) {
                lastCharIndex--;
            }

            if (lastCharIndex >= 0) {
                unsigned char lastChar = (unsigned char)token[lastCharIndex];
                if (isConsonant(lastChar)) {
                    consonantEndCount++;
                }
            }
        }

        token = strtok(NULL, " ");
    }

    printf("Количество слов, заканчивающихся на согласную букву: %d\n", consonantEndCount);

    return 0;
}