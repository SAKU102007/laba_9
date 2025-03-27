#include "functions.h"

// Функция для заполнения файла словами с клавиатуры
void fillFileWithWords(const char *fileName, int *length) {
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    printf("\n\nВведите слова(до 99 символов)\n"
           "Чтобы окончить ввод, нажмите enter дважды:\n");

    while (1) {
        char input[1000];

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
void countWordsInFile(const char *fileName) {
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        return;
    }

    int number_of_words = 0;
    char input[100];

    while (fgets(input, sizeof(input), fp) != NULL) {
        int i = 0;
        while (input[i] != '\0')
        {
            while (input[i] == ' ' || input[i] == '\n')
                i++;

            if (input[i] != '\0' && input[i] != ' '&& input[i] != '\n') 
                number_of_words++;

            while (input[i] != '\0' && input[i] != ' ' && input[i] != '\n') 
                i++;
        }
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

    char word[100];
    char longestWord[100] = "";
    int max_length = 0;
    long max_position = 0;

    long current_position = ftell(fp);

    // Поиск самого длинного слова
    while (fscanf(fp, "%99s", word) == 1) {
        // int word_length = strlen(word);
        int word_length = 0;
        while (word[word_length] != '\0')  
            word_length++;
        
        if (word_length > max_length) {
            max_length = word_length;
            int i = 0;
            while (word[i] != '\0')
            {
                longestWord[i] = word[i];
                i++;
            }
            longestWord[i] = '\0';
            max_position = current_position;
        }
        
        current_position = ftell(fp);
    }

    if (max_length == 0) {
        printf("Файл не содержит слов.\n");
        fclose(fp);
        return;
    }

    printf("Самое длинное слово: %s (%d символов)\n", longestWord, max_length);

    // Реверс самого длинного слова
    for (int i = 0, j = max_length - 1; i < j; i++, j--) {
        char temp = longestWord[i];
        longestWord[i] = longestWord[j];
        longestWord[j] = temp;
    }

    printf("Самое длинное слово после реверса: %s\n", longestWord);

    // Запись реверсированного слова обратно в файл
    fseek(fp, max_position, SEEK_SET);
    fprintf(fp, "\n%s", longestWord);

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
    char input[1000];
    for (int i = 0; i < length; i++) {
        if (fgets(input, sizeof(input), fp) != NULL)
            printf("%s", input);
    }

    fclose(fp);
}
