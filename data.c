#include "data.h"
#include <stdio.h>
#include <string.h>

void print_question(question que)
{

    printf("%s\n", que.question);
    printf("%s\n", que.options[0]);
    printf("%s\n", que.options[1]);
    printf("%s\n", que.options[2]);
    printf("%s\n\n", que.options[3]);
}
void print_user(user us)
{
    printf("\nname: %s  surname: %s\n", us.name, us.surname);
}
void read_questions(question questions[MAX_QUESTION_COUNT], FILE *question_file, int *max_question_count)
{

    int question_count = 0;
    char buffer[MAX_QUESTION_LENGTH];
    int inside_index = 0;
    printf("\n");
    do
    {
        fgets(buffer, MAX_QUESTION_LENGTH, question_file);

        if (buffer[0] != '\n' && buffer[0] != '\r')
        {
            switch (inside_index)
            {
            case 0:
                strcpy(questions[question_count].question, buffer);
                inside_index++;
                break;
            case 1:
                inside_index++;
                questions[question_count].answer = buffer[0];
                break;
            case 2:
                inside_index++;
                strcpy(questions[question_count].options[0], buffer);
                break;
            case 3:
                inside_index++;
                strcpy(questions[question_count].options[1], buffer);
                break;
            case 4:
                inside_index++;
                strcpy(questions[question_count].options[2], buffer);
                break;
            case 5:
                inside_index = 0;
                strcpy(questions[question_count].options[3], buffer);
                question_count++;
                break;
            default:
                inside_index = 0;
                break;
            }
        }
    } while (!feof(question_file));
    *max_question_count = question_count;
}