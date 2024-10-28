#ifndef quiz_data_h
#define quiz_data_h

#define MAX_QUESTION_COUNT 1000
#define MAX_QUESTION_LENGTH 400
#define MAX_OPTION_LENGTH 100
#define MAX_USER_COUNT 100
#include <stdlib.h>
#include <stdio.h>
typedef struct user
{
    char name[15];
    char surname[15];
} user;
typedef struct question
{
    char question[MAX_QUESTION_LENGTH];
    char options[4][MAX_OPTION_LENGTH];
    char answer;
} question;
void print_question(question question);
void print_user(user us);
void read_questions(question questions[MAX_QUESTION_COUNT], FILE *question_file, int *question_count);

#endif