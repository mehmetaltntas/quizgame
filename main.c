#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "quiz.h"
#include "help.h"
void print_menu();

int main()
{
  FILE *question_file = fopen("questions.txt", "r");
  FILE *record_file = fopen("record.txt", "a");
  FILE *record_file_r = fopen("record.txt", "r");

  FILE *report_file = fopen("report.txt", "a");
  if (question_file == NULL)
  {
    exit(EXIT_FAILURE);
  }
  if (record_file == NULL)
  {
    exit(EXIT_FAILURE);
  }
  if (report_file == NULL)
  {
    exit(EXIT_FAILURE);
  }
  int question_count;
  question questions[MAX_QUESTION_COUNT];
  read_questions(questions, question_file, &question_count);

  while (1)
  {
    print_menu();
    char choice;
    choice = toupper(getc(stdin));
    getc(stdin);
    int test = sizeof(questions) / sizeof(questions[0]);

    switch (choice)
    {
    case 'S':
      start_quiz(questions, question_count, record_file);

      break;
    case 'R':
      show_record(record_file_r);
      getc(stdin);

      break;
    case 'C':
      comment(report_file);
      getc(stdin);

      break;
    case 'H':
      help();
      getc(stdin);

    case 'Q':
      fclose(question_file);
      fclose(record_file);
      fclose(report_file);
      exit(EXIT_SUCCESS);
    default:
      printf("Unknown choice");
    }
  }

  return 0;
}

void print_menu(void)
{
  system("cls");
  printf("\n\t\t________________________________________\n");
  printf("\n\t\t\t    THE MILLIONAIRE");
  printf("\n\t\t________________________________________");
  printf("\n\t\t________________________________________\n");
  printf("\n\t\t > Press S - START PROGRAM");
  printf("\n\t\t > Press V - SHOW ANSWERS");
  printf("\n\t\t > Press R - SHOW RECORDS");
  printf("\n\t\t > Press C - COMMENT");
  printf("\n\t\t > press H - HELP");
  printf("\n\t\t > press Q - QUIT");
  printf("\n\t\t________________________________________\n\n");
  printf("->");
}