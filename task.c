// #include <stdio.h>
// #include <string.h>
#include "functions.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *fileName = argv[1];

    while (1)
    {
        int length = 0;

        // Заполнение файла словами с клавиатуры
        fillFileWithWords(fileName, &length);

        printf("Введите выбор выполняемого задания:\n"
            "0 - Выход из программмы.\n"
            "1 - Посчитать количество слов в файле.\n"
            "2 - Сделать реверс самого длинного слова в файле.\n");
        int choice;
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 0 :
            printf("Вы вышли из программы.\n");
            return 0;
        case 1:
            countWordsInFile(fileName);
            break;
        case 2:
            reverseLongestWordInFile(fileName, length);
            break;
        default:
            printf("Неверный выбор! Допустимые значения: 0, 1, 2.\n");
            break;
        }

        // Вывод содержимого файла
        printFileContents(fileName, length);
    }

    return 0;
}
