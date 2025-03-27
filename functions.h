#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
// #include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void fillFileWithWords(const char *fileName, int *length);
void countWordsInFile(const char *fileName);
void reverseLongestWordInFile(const char *fileName, int length);
void printFileContents(const char *fileName, int length);


#endif
