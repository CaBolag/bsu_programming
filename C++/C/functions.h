//
// Created by Victor on 06.12.2020.
//

#ifndef PRACTICE_8__FUNCTIONS_H_
#define PRACTICE_8__FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#define MAXLINES 5000

char *lineptr[MAXLINES];
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);



#endif //PRACTICE_8__FUNCTIONS_H_
