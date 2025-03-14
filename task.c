// #include <stdio.h>
// #include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *fileName = argv[1];
    int length = 0;

    // Заполнение файла словами с клавиатуры
    fillFileWithWords(fileName, &length);

    printf("Введите выбор выполняемого задания:\n"
           "1 - Посчитать количество слов в файле.\n"
           "2 - Сделать реверс самого длинного слова в файле.\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            countWordsInFile(fileName, length);
            break;
        case 2:
            reverseLongestWordInFile(fileName, length);
            break;
        default:
            printf("Неверный выбор! Допустимые значения: 1, 2.\n");
            return 1;
    }

    // Вывод содержимого файла
    printFileContents(fileName, length);

    return 0;
}
