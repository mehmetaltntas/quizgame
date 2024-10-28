#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#include "quiz.h"
#include "util.h"
char get_valid_choice();
void start_quiz(question questions[MAX_QUESTION_COUNT], int question_count, FILE *record_file)
{

  user user1;
  system("cls");
  printf("Enter your name :");
  scanf("%s", user1.name);
  printf("Enter your surname :");
  scanf("%s", user1.surname);
  int price[13] = {0, 500, 1000, 2000, 3000, 5000, 7500, 15000, 30000, 60000, 125000, 250000, 1000000};
  int check, j, l, correct_count = 0;
  int question_check[question_count];
  for (l = 0; l < question_count; l++)
  {
    question_check[l] = 0;
  }
  char choice;

  srand(time(NULL));
  int selected = 0;
  if (question_count > 13)
    for (j = 0; j < 13; j++)
    {
      system("cls");
      selected = rand() % (question_count);
      while (question_check[selected] != 0)
      {
        selected = rand() % (question_count);
      }
      question_check[selected] = 1;
      print_question(questions[selected]);
      printf("\n\n\n");
      printf("Press Q if you want to withdraw \t\t\t REWARD -> $ %d \n\n", price[correct_count + 1]);
      printf("-> ");

      choice = get_valid_choice();
      if (choice == 'Q')
      {
        printf("\nYOUR REWARD IS $ %d ", price[correct_count]);
        fprintf(record_file, "\n%s:%s %s: $ %d", date(), user1.name, user1.surname, price[correct_count]);
        getc(stdin);
        return;
      }
      if (choice == questions[selected].answer)
      {
        printf("Congratulations!\n");
        getc(stdin);
        if (correct_count == 11)
        {
          printf("YOU HAVE BEEN A MILLIONER");
          printf("\nYOUR REWARD IS $ %d", price[correct_count]);
          fprintf(record_file, "\n%s:\n%s %s: $ %d", date(), user1.name, user1.surname, price[12]);
          getc(stdin);
          return;
        }
        correct_count++;
      }
      else
      {
        printf("You are eliminated ! Correct answer is %c", questions[selected].answer);
        if (correct_count < 2)
        {
          printf("\nYOUR REWARD IS $ %d", 0);
          fprintf(record_file, "\n%s:\n%s %s: $ %d", date(), user1.name, user1.surname, 0);
        }
        else if (correct_count > 2 && correct_count < 8)
        {
          printf("\nYOUR REWARD IS $ %d", price[3]);
          fprintf(record_file, "\n%s:\n%s %s: $ %d", date(), user1.name, user1.surname, price[3]);
        }
        else
        {
          printf("\nYOUR REWARD IS $ %d", price[8]);
          fprintf(record_file, "\n%s:\n%s %s: $ %d", date(), user1.name, user1.surname, price[8]);
        }
        fflush(record_file);
        return;
      }
    }
  fflush(stdin);
  getc(stdin);
}

int is_valid_choice(const char choice)
{
  return (choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D' || choice == 'Q');
}
char get_valid_choice()
{
  char choice;
  int input_check = 0;
  while (input_check != 1)
  {

    getc(stdin);
    choice = '\0';
    while (!isalpha(choice))
      choice = getc(stdin);
    choice = toupper(choice);
    if (is_valid_choice(choice))
    {
      input_check = 1;
    }
  }
  return choice;
}