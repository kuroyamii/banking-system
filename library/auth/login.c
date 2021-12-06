#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

bool read(char username[51], char password[51])
{
    FILE *fptr;
    char tmp[60], uname[60], pass[60];
    fptr = fopen("../database/user.txt", "r");
    while (fgets(tmp, 60, fptr) != NULL)
    {
        if (strcmp(tmp, "*****\n") == 0)
        {
            fgets(tmp, 60, fptr);
            sscanf(tmp, "%60[^\n]\n", &uname);
            fgets(tmp, 60, fptr);
            sscanf(tmp, "%60[^\n]\n", &pass);
            fflush(stdin);
            if (strcmp(uname, username) == 0 && strcmp(pass, password) == 0)
            {
                fclose(fptr);
                return true;
            }
        }
    }
    fclose(fptr);
    return false;
}

bool signin()
{
    char username[51];
    char password[51];
    FILE *fptr;
    printf("Admin Login\n");
    fflush(stdin);
    printf("Username: ");
    scanf("%[^\n]s", &username);
    fflush(stdin);
    printf("Password: ");
    scanf("%[^\n]s", &password);
    return read(username, password);
}