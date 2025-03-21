#include "functions.h"

// Функция для заполнения файла словами с клавиатуры
void fillFileWithWords(const char *fileName, int *length) {
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    printf("Введите слова через enter\n"
           "Не больше 99 букв в слове\n"
           "Чтобы окончить ввод нажмите enter дважды:\n");

    while (1) {
        char input[100];

        int i = 0;
        char c;

        while ((c = getchar()) != '\n' && i < 99) {
            input[i] = c;
            i++;
        }

        input[i] = '\0';
        if (i == 0) { // Если введена пустая строка, завершаем ввод
            break;
        }

        fputs(input, fp);
        fputc('\n', fp);
        (*length)++;
    }

    fclose(fp);
}

// Функция для подсчёта количества слов в файле
void countWordsInFile(const char *fileName, int length) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return;
    }

    int number_of_words = 0;
    char input[100];
    for (int i = 0; i < length; i++) {
        if (fgets(input, sizeof(input), fp) != NULL)
            number_of_words++;
    }

    printf("Количество слов в файле: %d\n", number_of_words);

    fclose(fp);
}

// Функция для реверса самого длинного слова в файле
void reverseLongestWordInFile(const char *fileName, int length) {
    FILE *fp = fopen(fileName, "r+");
    if (fp == NULL) {
        perror("Error opening file for reading & writing");
        return;
    }

    char input[100] = "";
    int max_length = 0;
    int max_position = 0;
    int max_length_for_count;

    // Поиск самого длинного слова
    for (int i = 0; i < length; i++) {
        if (fgets(input, sizeof(input), fp) != NULL) {
            int cur_length = 0;
            while (input[cur_length] != '\0' && input[cur_length] != '\n') {
                cur_length++;
            }
            if (max_length < cur_length) {

                max_length = cur_length;
                max_position = ftell(fp) - cur_length - 1;
                max_length_for_count = cur_length;
            }
        }
    }

    printf("Самое длинное слово имеет %d символов\n", max_length);

    // Перемещаем указатель файла на начало самого длинного слова
    fseek(fp, max_position, SEEK_SET);

    // Читаем самое длинное слово
    char temp[100];
    fgets(temp, sizeof(temp), fp);
    printf("Самое длинное слово: ");
    int q = 0;
    while (temp[q] != '\0' && temp[q] != '\n') {
        putchar(temp[q]);
        q++;
    }
    printf("\n");

    // Перемещаем указатель файла на начало самого длинного слова
    fseek(fp, max_position, SEEK_SET);
    fgets(input, sizeof(input), fp);

    // Реверс самого длинного слова
    for (int i = 0; i < (max_length_for_count - 0) / 2; i++) {
        char temp = input[max_length_for_count - 1 - i];
        input[max_length_for_count - 1 - i] = input[i];
        input[i] = temp;
    }

    // Вывод реверсированного слова
    printf("Самое длинное слово после реверса: ");
    q = 0;
    while (input[q] != '\0' && input[q] != '\n') {
        putchar(input[q]);
        q++;
    }
    printf("\n");

    // Записываем реверсированное слово обратно в файл
    fseek(fp, max_position, SEEK_SET);
    fputs(input, fp);

    fclose(fp);
}

// Функция для вывода содержимого файла
void printFileContents(const char *fileName, int length) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return;
    }

    printf("Вывод содержимого файла: \n");
    char input[100];
    for (int i = 0; i < length; i++) {
        if (fgets(input, sizeof(input), fp) != NULL)
            printf("%s", input);
    }

    fclose(fp);
}
