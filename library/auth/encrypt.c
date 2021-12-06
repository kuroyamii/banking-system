#include <stdio.h>

char *encryptPassword(char password[])
{
    char ch;
    int i, key;
    key = 5;
    for (i = 0; password[i] != '\0'; ++i)
    {
        ch = password[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            password[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            password[i] = ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            ch = ch + (key - 2);
            if (ch > '9')
            {
                ch = ch - '9' + '0' - 1;
            }
        }
    }

    return password;
}

char *decryptPassword(char password[])
{
    char ch;
    int i, key;
    key = 5;
    for (i = 0; password[i] != '\0'; ++i)
    {
        ch = password[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            password[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            password[i] = ch;
        }
        else if (ch >= '0' && ch <= '9')
        {
            ch = ch - (key - 2);
            if (ch < '0')
            {
                ch = ch + '9' - '0' + 1;
            }
        }
    }
    return password;
}