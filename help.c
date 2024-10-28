#include "help.h"
#include "util.h"
#include <ctype.h>
#include <stdlib.h>

void show_record(FILE *record_file)
{
    system("cls");
    char* record;
    record =readcontent(record_file);
    printf("%s\n",record);

}
void comment(FILE *report_file)
{
    system("cls");
    char reports[1000];

    printf("\t\tEnter your opinion about the program\n\n\t->");
    fgets(reports, sizeof(reports), stdin);
    printf("%s\n", reports);
    fprintf(report_file, "%s: %s\n", date(), reports);
    fflush(report_file);
}
void help(void)
{
    system("cls");
    printf("\n                                HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ----------------          ABOUT PROGRAM          -----------------------");
    printf("\n\n>> This program is a competition program with a prize of $ 1 million");
    printf("\n>> The person participating in the competition tries to reach this award by knowing the questions correctly.");
    printf("\n>> Every correct answer has a certain prize money");
    printf("\n>> After knowing each question, the reward for the next question increases exponentially");
    printf("\n>> There are a total of 12 questions in the competition");
    printf("\n>> Each question has 4 options");
    printf("\n>> The contest ends when the wrong answer is given.");
    printf("\n\n>> Questions and awards are as follows\n");
    printf("\n>> 1 --- > 500 $");
    printf("\n>> 2 --- > 1000 $");
    printf("\n>> 3 --- > 2000 $");
    printf("\n>> 4 --- > 3000 $");
    printf("\n>> 5 --- > 5000 $");
    printf("\n>> 6 --- > 7500 $");
    printf("\n>> 7 --- > 15000 $");
    printf("\n>> 8 --- > 30000 $");
    printf("\n>> 9 --- > 60000 $");
    printf("\n>> 10 --- > 125000 $");
    printf("\n>> 11 --- > 250000 $");
    printf("\n>> 12 --- > 1000000 $");
}