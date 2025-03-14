// void function_3(const char *fileName, int length) {
//     FILE *fp = fopen(fileName, "r+");
//     if (fp == NULL) {
//         perror("Error opening file for reading & writing");
//         return;
//     }

//     char input[100] = "";
//     int max_length = 0;
//     int max_position = 0;
//     int max_length_for_count;

//     for (int i = 0; i < length; i++)
//     {
//         if (fgets(input, sizeof(input), fp) != NULL)
//         {
//             int cur_length = 0;
//             int actual_length = 0;
//             while (input[cur_length] != '\0' && input[cur_length] != '\n')
//             {
//                 if((input[cur_length] & 0xC0) != 0x80)
//                     actual_length++;
//                 cur_length++;
//             }

//             if (max_length < actual_length)
//             {
//                 max_length = actual_length;
//                 max_position = ftell(fp) - cur_length - 1;
//                 max_length_for_count = cur_length;
//             }
//         }
//     }
//     printf("Самое длинное слово имеет %d элемента\n"
//     "Но если брать русские буквы за 2 байта, то это слово имеет %d элемента\n", max_length, max_length_for_count);

//     fseek(fp, max_position, SEEK_SET);

//     char tempor[100];
//     fgets(tempor, sizeof(tempor), fp);
//     printf("Cамое большое слово : ");
//     int q = 0;
//     while (tempor[q] != '\0' && tempor[q] != '\n') 
//     {
//         putchar(tempor[q]);
//         q++;
//     }
//     printf("\n");

//     fseek(fp, max_position, SEEK_SET);
//     fgets(input, sizeof(input), fp);

//     for (int i = 0; i < (max_length_for_count - 1) / 2; i++) //стоит -2, мб его надо будет убрать
//     {
//         if ((input[i+1] & 0xC0) != 0x80)
//         {
//             char temp = input[max_length_for_count - 2 - i];
//             input[max_length_for_count - 2 - i] = input[i];
//             input[i] = temp;
//         } 
        
//         else
//         {
//             char temp1 = input[max_length_for_count - 3 - i];
//             char temp2 = input[max_length_for_count - 2 - i];
//             input[max_length_for_count - 3 - i] = input[i];
//             input[max_length_for_count - 2 - i] = input[i+1];
//             input[i] = temp1;
//             input[i+1] = temp2;
//             i++;
//         }
//     }


//     printf("Cамое большое слово (вроде как реверснутое) : ");
//     q = 0;
//     while (input[q] != '\0' && input[q] != '\n') 
//     {
//         putchar(input[q]);
//         q++;
//     }
//     printf("\n");

//     fclose(fp);
// }



// 1 функция чатажпт

// void function_3(const char *fileName, int length) {
//     FILE *fp = fopen(fileName, "r+");
//     if (fp == NULL) {
//         perror("Error opening file for reading & writing");
//         return;
//     }

//     char input[100] = "";
//     int max_length = 0;
//     int max_position = 0;
//     int max_length_for_count;

//     for (int i = 0; i < length; i++) {
//         if (fgets(input, sizeof(input), fp) != NULL) {
//             int cur_length = 0;
//             int actual_length = 0;
//             while (input[cur_length] != '\0' && input[cur_length] != '\n') {
//                 if ((input[cur_length] & 0xC0) != 0x80)
//                     actual_length++;
//                 cur_length++;
//             }

//             if (max_length < actual_length) {
//                 max_length = actual_length;
//                 max_position = ftell(fp) - cur_length - 1;
//                 max_length_for_count = cur_length;
//             }
//         }
//     }

//     printf("Самое длинное слово имеет %d символов\n"
//            "Но если брать русские буквы за 2 байта, то это слово имеет %d байт\n",
//            max_length, max_length_for_count);

//     fseek(fp, max_position, SEEK_SET);

//     char temp[100];
//     fgets(temp, sizeof(temp), fp);
//     printf("Самое большое слово: ");
//     int q = 0;
//     while (temp[q] != '\0' && temp[q] != '\n') {
//         putchar(temp[q]);
//         q++;
//     }
//     printf("\n");

//     fseek(fp, max_position, SEEK_SET);
//     fgets(input, sizeof(input), fp);

//     // Реверс строки
//     for (int i = 0; i < (max_length_for_count - 1) / 2; i++) {
//         if ((input[i] & 0xC0) == 0xC0) {
//             // Меняем местами двухбайтовый символ
//             int j = max_length_for_count - 2 - i - 1; // Индекс для двухбайтового символа
//             char temp1 = input[j];
//             char temp2 = input[j + 1];
//             input[j] = input[i];
//             input[j + 1] = input[i + 1];
//             input[i] = temp1;
//             input[i + 1] = temp2;
//             i++; // Пропускаем следующий байт, так как символ двухбайтовый
//         } else {
//             // Меняем местами однобайтовый символ
//             int j = max_length_for_count - 2 - i; // Индекс для однобайтового символа
//             char temp = input[j];
//             input[j] = input[i];
//             input[i] = temp;
//         }
//     }

//     // Вывод реверсированной строки
//     printf("Самое большое слово (реверсированное): ");
//     q = 0; // Сбрасываем q в ноль
//     while (input[q] != '\0' && input[q] != '\n') {
//         putchar(input[q]);
//         q++;
//     }
//     printf("\n");

//     fclose(fp);
// }



// 2 функция жпт

// void function_3(const char *fileName, int length) {
//     FILE *fp = fopen(fileName, "r+");
//     if (fp == NULL) {
//         perror("Error opening file for reading & writing");
//         return;
//     }

//     char input[100] = "";
//     int max_length = 0;
//     int max_position = 0;
//     int max_length_for_count;

//     for (int i = 0; i < length; i++) {
//         if (fgets(input, sizeof(input), fp) != NULL) {
//             int cur_length = 0;
//             int actual_length = 0;
//             while (input[cur_length] != '\0' && input[cur_length] != '\n') {
//                 if ((input[cur_length] & 0xC0) != 0x80)
//                     actual_length++;
//                 cur_length++;
//             }

//             if (max_length < actual_length) {
//                 max_length = actual_length;
//                 max_position = ftell(fp) - cur_length - 1;
//                 max_length_for_count = cur_length;
//             }
//         }
//     }

//     printf("Самое длинное слово имеет %d символов\n"
//            "Но если брать русские буквы за 2 байта, то это слово имеет %d байт\n",
//            max_length, max_length_for_count);

//     fseek(fp, max_position, SEEK_SET);

//     char temp[100];
//     fgets(temp, sizeof(temp), fp);
//     printf("Самое большое слово: ");
//     int q = 0;
//     while (temp[q] != '\0' && temp[q] != '\n') {
//         putchar(temp[q]);
//         q++;
//     }
//     printf("\n");

//     fseek(fp, max_position, SEEK_SET);
//     fgets(input, sizeof(input), fp);

//     // Реверс строки
//     int i = 0;
//     int j = max_length_for_count - 2; // Исключаем символ '\n'

//     while (i < j) {
//         // Проверяем, является ли текущий символ двухбайтовым
//         if ((input[i] & 0xC0) == 0xC0) {
//             // Меняем местами двухбайтовый символ
//             char temp1 = input[j - 1];
//             char temp2 = input[j];
//             input[j - 1] = input[i];
//             input[j] = input[i + 1];
//             input[i] = temp1;
//             input[i + 1] = temp2;
//             i += 2;
//             j -= 2;
//         } else {
//             // Меняем местами однобайтовый символ
//             char temp = input[j];
//             input[j] = input[i];
//             input[i] = temp;
//             i++;
//             j--;
//         }
//     }

//     // Вывод реверсированной строки
//     printf("Самое большое слово (реверсированное): ");
//     q = 0; // Сбрасываем q в ноль
//     while (input[q] != '\0' && input[q] != '\n') {
//         putchar(input[q]);
//         q++;
//     }
//     printf("\n");


//     // Вывод байтов строки до реверса
//     printf("Байты до реверса: ");
//     for (int i = 0; i < max_length_for_count; i++) {
//         printf("%02X ", (unsigned char)input[i]);
//     }
//     printf("\n");

//     // Реверс строки
//     // (ваш код реверса)

//     // Вывод байтов строки после реверса
//     printf("Байты после реверса: ");
//     for (int i = 0; i < max_length_for_count; i++) {
//         printf("%02X ", (unsigned char)input[i]);
//     }
//     printf("\n");

//     fclose(fp);
// }






// void function_3(const char *fileName, int length) {
//     FILE *fp = fopen(fileName, "r+");
//     if (fp == NULL) {
//         perror("Error opening file for reading & writing");
//         return;
//     }

//     char input[100] = "";
//     int max_length = 0;
//     int max_position = 0;
//     int max_length_for_count = 0;

//     // Поиск самого длинного слова
//     for (int i = 0; i < length; i++) {
//         if (fgets(input, sizeof(input), fp) != NULL) {
//             int cur_length = 0;
//             int actual_length = 0;
//             while (input[cur_length] != '\0' && input[cur_length] != '\n') {
//                 if ((input[cur_length] & 0xC0) != 0x80)
//                     actual_length++;
//                 cur_length++;
//             }

//             if (max_length < actual_length) {
//                 max_length = actual_length;
//                 max_position = ftell(fp) - cur_length - 1;
//                 max_length_for_count = cur_length;
//             }
//         }
//     }

//     // Вывод информации о самом длинном слове
//     printf("Самое длинное слово имеет %d символов\n"
//            "Но если брать русские буквы за 2 байта, то это слово имеет %d байт\n",
//            max_length, max_length_for_count);

//     // Перемещаем указатель файла на начало самого длинного слова
//     fseek(fp, max_position, SEEK_SET);

//     // Читаем самое длинное слово
//     char temp[100];
//     fgets(temp, sizeof(temp), fp);
//     printf("Самое большое слово: ");
//     int q = 0;
//     while (temp[q] != '\0' && temp[q] != '\n') {
//         putchar(temp[q]);
//         q++;
//     }
//     printf("\n");

//     // Перемещаем указатель файла на начало самого длинного слова
//     fseek(fp, max_position, SEEK_SET);
//     fgets(input, sizeof(input), fp);

//     // Вывод байтов до реверса
//     printf("Байты до реверса: ");
//     for (int i = 0; i < max_length_for_count; i++) {
//         printf("%02X ", (unsigned char)input[i]);
//     }
//     printf("\n");

//     // Реверс строки
//     int i = 0;
//     int j = max_length_for_count - 2; // Исключаем символ '\n'

//     while (i < j) {
//         // Проверяем, является ли текущий символ двухбайтовым
//         if ((input[i] & 0xC0) == 0xC0) {
//             // Меняем местами двухбайтовый символ
//             char temp1 = input[j - 1];
//             char temp2 = input[j];
//             input[j - 1] = input[i];
//             input[j] = input[i + 1];
//             input[i] = temp1;
//             input[i + 1] = temp2;
//             i += 2;
//             j -= 2;
//         } else {
//             // Меняем местами однобайтовый символ
//             char temp = input[j];
//             input[j] = input[i];
//             input[i] = temp;
//             i++;
//             j--;
//         }
//     }

//     // Вывод байтов после реверса
//     printf("Байты после реверса: ");
//     for (int i = 0; i < max_length_for_count; i++) {
//         printf("%02X ", (unsigned char)input[i]);
//     }
//     printf("\n");

//     // Вывод реверсированной строки через printf
//     printf("Самое большое слово (реверсированное через printf): %s\n", input);

//     // Вывод реверсированной строки через putchar
//     printf("Самое большое слово (реверсированное через putchar): ");
//     q = 0; // Сбрасываем q в ноль
//     while (input[q] != '\0' && input[q] != '\n') {
//         putchar(input[q]);
//         q++;
//     }
//     printf("\n");

//     fclose(fp);
// }





// // Функция для реверса строки с учётом многобайтовых символов (UTF-8)
// void reverse_utf8_string(char *str, int length) {
//     int i = 0;
//     int j = length - 1;

//     while (i < j) {
//         // Определяем длину символа в байтах (для UTF-8)
//         int left_char_len = 1;
//         if ((str[i] & 0xC0) == 0xC0) {
//             // Если символ многобайтовый, определяем его длину
//             if ((str[i] & 0xF0) == 0xF0) left_char_len = 4;
//             else if ((str[i] & 0xE0) == 0xE0) left_char_len = 3;
//             else if ((str[i] & 0xC0) == 0xC0) left_char_len = 2;
//         }

//         int right_char_len = 1;
//         if ((str[j] & 0xC0) == 0xC0) {
//             // Если символ многобайтовый, определяем его длину
//             if ((str[j] & 0xF0) == 0xF0) right_char_len = 4;
//             else if ((str[j] & 0xE0) == 0xE0) right_char_len = 3;
//             else if ((str[j] & 0xC0) == 0xC0) right_char_len = 2;
//         }

//         // Меняем местами символы
//         if (left_char_len == 1 && right_char_len == 1) {
//             // Если оба символа однобайтовые
//             char temp = str[i];
//             str[i] = str[j];
//             str[j] = temp;
//             i++;
//             j--;
//         } else {
//             // Если хотя бы один символ многобайтовый
//             char temp[4];
//             memcpy(temp, &str[i], left_char_len);
//             memcpy(&str[i], &str[j - right_char_len + 1], right_char_len);
//             memcpy(&str[j - right_char_len + 1], temp, left_char_len);
//             i += left_char_len;
//             j -= right_char_len;
//         }
//     }
// }

// void function_3(const char *fileName, int length) {
//     FILE *fp = fopen(fileName, "r+");
//     if (fp == NULL) {
//         perror("Error opening file for reading & writing");
//         return;
//     }

//     char input[100] = "";
//     int max_length = 0;
//     int max_position = 0;
//     int max_length_for_count = 0;

//     // Поиск самого длинного слова
//     for (int i = 0; i < length; i++) {
//         if (fgets(input, sizeof(input), fp) != NULL) {
//             int cur_length = 0;
//             int actual_length = 0;
//             while (input[cur_length] != '\0' && input[cur_length] != '\n') {
//                 if ((input[cur_length] & 0xC0) != 0x80)
//                     actual_length++;
//                 cur_length++;
//             }

//             if (max_length < actual_length) {
//                 max_length = actual_length;
//                 max_position = ftell(fp) - cur_length - 1;
//                 max_length_for_count = cur_length;
//             }
//         }
//     }

//     // Вывод информации о самом длинном слове
//     printf("Самое длинное слово имеет %d символов\n"
//            "Но если брать русские буквы за 2 байта, то это слово имеет %d байт\n",
//            max_length, max_length_for_count);

//     // Перемещаем указатель файла на начало самого длинного слова
//     fseek(fp, max_position, SEEK_SET);

//     // Читаем самое длинное слово
//     char temp[100];
//     fgets(temp, sizeof(temp), fp);
//     printf("Самое большое слово: ");
//     int q = 0;
//     while (temp[q] != '\0' && temp[q] != '\n') {
//         putchar(temp[q]);
//         q++;
//     }
//     printf("\n");

//     // Перемещаем указатель файла на начало самого длинного слова
//     fseek(fp, max_position, SEEK_SET);
//     fgets(input, sizeof(input), fp);

//     // Вывод байтов до реверса
//     printf("Байты до реверса: ");
//     for (int i = 0; i < max_length_for_count; i++) {
//         printf("%02X ", (unsigned char)input[i]);
//     }
//     printf("\n");

//     // Реверс строки
//     reverse_utf8_string(input, max_length_for_count);

//     // Вывод байтов после реверса
//     printf("Байты после реверса: ");
//     for (int i = 0; i < max_length_for_count; i++) {
//         printf("%02X ", (unsigned char)input[i]);
//     }
//     printf("\n");

//     // Вывод реверсированной строки через printf
//     printf("Самое большое слово (реверсированное через printf): %s\n", input);

//     // Вывод реверсированной строки через putchar
//     printf("Самое большое слово (реверсированное через putchar): ");
//     q = 0; // Сбрасываем q в ноль
//     while (input[q] != '\0' && input[q] != '\n') {
//         putchar(input[q]);
//         q++;
//     }
//     printf("\n");

//     fclose(fp);
// }