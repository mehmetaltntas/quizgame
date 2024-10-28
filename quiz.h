
#ifndef quiz_game_h
#define quiz_game_h
#include "data.h"
#include <stdlib.h>
#include <stdio.h>
void start_quiz(question questions[MAX_QUESTION_COUNT], int question_count, FILE *record_file);

char *date();
char *strupr(char *str);

#endif
