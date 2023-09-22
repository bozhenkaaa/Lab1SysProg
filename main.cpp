#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 30

int isUniqueWord(const char *word) {
    int seenChars[26] = {0}; // Масив для зберігання літер (тільки малі літери)
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        char c = tolower(word[i]); // Перетворення на малу літеру перед перевіркою
        if (!isalpha(c)||seenChars[c - 'a'] == 1) {
            return 0; // Знайдено повторну літеру
        }
        seenChars[c - 'a'] = 1;
    }

    return 1; // Всі літери унікальні
}

int main() {
    FILE *inputFile = fopen("input.txt", "r"); // Назва текстового файлу

    if (inputFile == NULL) {
        perror("Не вдалося відкрити файл!");
        return 1;
    }

    char word[MAX_WORD_LENGTH + 1]; // +1 для завершувача рядк

    while (fscanf(inputFile, "%s", word) == 1) {
        if (isUniqueWord(word) && strlen(word) <= MAX_WORD_LENGTH) {
            printf("%s\n", word);
        }
    }

    fclose(inputFile);

    return 0;
}
