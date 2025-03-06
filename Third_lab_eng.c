#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YES 1
#define NO 0
#define MAX_LENGTH 1000 // Максимальная длина ввода

// Функция для проверки, является ли символ согласной буквой
int is_consonant(char c) {
    c = tolower(c); // Приводим к нижнему регистру для удобства
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int main(void) {
    char input[MAX_LENGTH]; // Буфер для ввода строки
    int cnt = 0;            // Счётчик
    int flag = NO;         // Признак слова
    char prev_c = ' ';     // Предыдущий символ

    printf("Введите предложение:\n");
    fgets(input, MAX_LENGTH, stdin); // Чтение строки с клавиатуры

    // Цикл по каждому символу введенной строки
    for (int i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (c == ' ' || c == '.' || c == '\n' || c == ',') {
            // Найден разделитель
            if (flag == YES && is_consonant(prev_c)) {
                // Если слово закончилось на согласную
                cnt++;
            }
            flag = NO;
        } else {
            // Найдена буква
            flag = YES;
        }
        prev_c = c;
    }

    // Проверка последнего слова, если оно не заканчивается разделителем
    if (flag == YES && is_consonant(prev_c)) {
        cnt++;
    }

    printf("Количество слов, заканчивающихся на согласную: %d\n", cnt);
    return 0;
}
