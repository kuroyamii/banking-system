#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

char nama[101], email[51], ttl[11], ktp[21];

bool eligible()
{
    FILE *fp;
    char tmp[101], data[101];
    fp = fopen("../database/database_rekening.txt", "r");
    fflush(stdin);
    printf("Nama                     : ");
    scanf("%[^\n]s", nama);
    lower(nama);
    fflush(stdin);

    printf("Email                    : ");
    scanf("%[^\n]s", email);
    lower(email);
    fflush(stdin);

    printf("Tanggal Lahir(DD/MM/YYYY): ");
    scanf("%[^\n]s", ttl);
    fflush(stdin);

    printf("No. KTP                  : ");
    scanf("%[^\n]s", ktp);
    lower(ktp);
    fflush(stdin);

    while (fgets(tmp, 101, fp) != NULL)
    {
        if (strcmp(tmp, "*****\n") == 0)
        {
            fgets(tmp, 101, fp);
            sscanf(tmp, "%101[^\n]\n", &tmp);
            fflush(stdin);
            if (strcmp(tmp, nama) == 0)
            {
                fgets(tmp, 51, fp);
                sscanf(tmp, "%51[^\n]\n", &tmp);
                fflush(stdin);
                if (strcmp(tmp, email) == 0)
                {
                    fgets(tmp, 11, fp);
                    sscanf(tmp, "%11[^\n]\n", &tmp);
                    fflush(stdin);
                    if (strcmp(tmp, ttl) == 0)
                    {
                        fgets(tmp, 21, fp);
                        fflush(stdin);
                        fgets(tmp, 21, fp);
                        sscanf(tmp, "%21[^\n]\n", &tmp);
                        fflush(stdin);
                        if (strcmp(tmp, ktp) == 0)
                        {
                            fclose(fp);
                            return true;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    return false;
}

void signup()
{
    FILE *filePointer;
    char username[101], password[101], tmp[101], tmp2[101];
    bool loop = true;
    filePointer = fopen("../database/user.txt", "a+");
    printf("Masukkan data untuk memeriksa eligibility:\n");

    if (eligible() == true)
    {
        printf("Masukkan data yang ingin didaftarkan:\n");
        printf("Username: ");
        while (loop == true)
        {
            fflush(stdin);
            scanf("%100[^\n]s", username);
            fflush(stdin);
            while (fgets(tmp, 101, filePointer) != NULL)
            {
                sscanf(tmp, "%[^\n]\n", tmp2);
                if (strcmp(tmp, tmp2) == 0)
                {
                    break;
                }
                else
                {
                    loop = false;
                }
            }

            if (loop == true)
            {
                printf("Username telah terpakai!\n");
            }
        }
        fflush(stdin);
        printf("Password: ");
        scanf("%100[^\n]s", password);
        fflush(stdin);
        fprintf(filePointer, "*****\n%s\n%s\n", username, password);
    }
    else
    {
        printf("Maaf anda belum memenuhi kriteria!\nSilahkan buka rekening terlebih dahulu apabila belum memiliki rekening!\n");
    }
}

void addRekening()
{
    printf("Masukkan data untuk membuka rekening:\n");
    FILE *fptr;
    fptr = fopen("../database/database_rekening.txt", "a");
    if (eligible() == false)
    {
        fprintf(fptr, "*****\n%s\n%s\n%s\n%s\n", nama, email, ttl, ktp);
    }
    fclose(fptr);
}