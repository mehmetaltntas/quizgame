#include <time.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *strupr(char *s)
{
    int i = 0;
    char *str = strdup(s);
    while (str[i])
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
    return (str);
}
char *date()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *date;
    date = (char *)malloc(sizeof(char) * 64);
    assert(strftime(date, 63, "%c", tm));
    return date;
}
 char *readcontent(FILE *fp)
{
    char *fcontent = NULL;
    int fsize = 0;

    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        fsize = ftell(fp);
        rewind(fp);

        fcontent = (char *)malloc(sizeof(char) * fsize);
        fread(fcontent, 1, fsize, fp);
        fclose(fp);
    }
    return fcontent;
}
