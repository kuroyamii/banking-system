#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *lower(char str[])
{
    int i;
    for (i = 0; i <= strlen(str); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    }
    return str;
}

char *upper(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

char *capitalize(char str[])
{
    int i;
    strcpy(str, lower(str));
    for (i = 0; i <= strlen(str); i++)
    {
        if (str[0] >= 'a' && str[0] <= 'z')
        {
            str[0] = str[0] - 32;
        }
        else if (str[i - 1] == ' ' && (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] = str[i] - 32;
        }
    }
}