#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../utils/utils.h"

char nama[101], email[51], ttl[11], ktp[21], userId[50];

bool eligible(bool state)
{
    FILE *fptr;
    FILE *fp;
    char tmp[101], data[101];
    fp = fopen("../database/user_rekening.txt", "r");
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
                            if(state == true){
                                fptr = fopen("../database/user.txt","r");
                                fgets(tmp, 50, fp);
                                sscanf(tmp, "%50[^\n]\n", &userId);
                                fflush(stdin);

                                while((fgets(tmp, 101, fptr) != NULL)){
                                    if (strcmp(tmp, "*****\n") == 0){
                                        fgets(tmp, 50, fptr);
                                        fflush(stdin);
                                        fgets(tmp, 50, fptr);
                                        fflush(stdin);
                                        fgets(tmp, 50, fptr);
                                        sscanf(tmp, "%50[^\n]\n", &tmp);
                                        fflush(stdin);
                                        if(strcmp(tmp,userId) == 0){
                                            fclose(fp);
                                            fclose(fptr);
                                            return false;
                                        }
                                    }
                                }
                            }else{
                                fclose(fp);
                                return true;
                            }
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
    FILE *fp;
    char username[101], password[101], tmp[101], tmp2[101],pin[20];
    bool loop = true;
    filePointer = fopen("../database/user.txt", "a+");
    printf("Masukkan data untuk memeriksa eligibility:\n");

    if (eligible(true) == true)
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
        do{
            printf("Masukkan PIN (boleh kombinasi angka dan huruf): ");
            scanf("%20[^\n]s",pin);
        }while(strlen(pin) != 6);
        fprintf(filePointer, "*****\n%s\n%s\n%s\n", username, password,userId);
        fp = fopen("../database/database_rekening.txt","a+");
        while(fgets(tmp,100,fp)!=NULL){}
        fprintf(fp,"%s_%s_%d_%s\n",userId,nama,0,pin);
        fclose(fp);
    }
    else
    {
        printf("Akun tidak dapat dibuat!\n");
    }
    fclose(filePointer);
}

char *generateUID(char name[], char date[], long jumlahUser, char id[]){
    int hash = (int) strtol(name, (char **)NULL, 50)%9;
    hash++;
    char temp[20];
    char tgl[3],bln[3],thn[5];
    sprintf(temp,"%d",hash);
    //itoa(hash, temp,2);
    strcat(id,temp);
    sscanf(date,"%2[^/]/%2[^/]/%4[^\n]\n",&tgl,&bln,&thn);
    strcat(id,tgl);
    strcat(id,bln);
    strcat(id,thn);
    
    sprintf(temp,"%ld",jumlahUser);
    //ltoa(jumlahUser,temp,20);
    strcat(id,temp);
    return id;
}


long addRekening(long jumlahUser)
{
    char uid[30]="";
    printf("Masukkan data untuk membuka rekening:\n");
    FILE *fptr;
    fptr = fopen("../database/user_rekening.txt", "a");
    if (eligible(false) == false)
    {
        generateUID(nama,ttl,jumlahUser+1,uid);
        fprintf(fptr, "*****\n%s\n%s\n%s\n%s\n%s\n", nama, email, ttl, ktp, uid);
        fclose(fptr);
        return 1;
    }
    fclose(fptr);
    return 0;
}
