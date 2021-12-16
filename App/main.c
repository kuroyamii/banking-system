#include <stdio.h>
#include <stdlib.h>
#include "../library/utils/utils.h"
#include "../library/auth/auth.h"
#include "../library/transaction/trx.h"
#include <signal.h>

long users;
char u_ids[25]="";
long u_id;
int choice,choice2;
void header();
void menu();

void userCount(){
    FILE *fptr;
    char *ptr;
    char temp[20];
    fptr = fopen("../database/userCount.txt","r");
    fgets(temp,20,fptr);
    sscanf(temp,"%[^\n]\n",&temp);
    fflush(stdin);
    users = strtol(temp,&ptr,20);
    //users = atol(temp);
    fclose(fptr);
}

void userCountWrite(){
    FILE *fptr;
    char temp[20];
    fptr = fopen("../database/userCount.txt","w");
    fprintf(fptr,"%ld\n",users);
    fclose(fptr);
}


//Main Driver To Run The Program
int main()
{ 
    char *fp; 
    userCount();

main:
    do
    {
        //clear();
        printf("(NAMABANK) Banking System\n\n");
        printf("Apakah Anda Sudah Memiliki Rekening? ");
        printf("\n1. Sudah\n2. Belum\n3. Exit\nMasukkan Pilihan: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            do{
                printf("Menu:\n1. Sign in\n2. Sign up\n3. Keluar\nPilih: ");
                scanf("%d",&choice2);
                switch(choice2){
                    case 1:
                    {
                        if(signin(u_ids) == true){
                            u_id = strtol(u_ids, &fp, 10);
                            //u_id = atol(u_ids);
                            printf("%s %ld %ld berhasil masuk!\n",u_ids,u_id,users);
                            
                            menu();
                        }else{
                            printf("Gagal");   
                        }
                        break;
                    }
                    case 2:
                        signup();
                        
                        break;
                    case 3:
                        goto end;
                        break;
                }
            }while(choice2!=3);
            break;
        }
        case 2:
            clear();
            printf("(NAMABANK) Banking System\n\n");
            printf("Apakah Anda Ingin Membuat Rekening?");
            printf("\n1. Ya\n2. Tidak\n3. Keluar\n\nMasukkan Pilihan: ");
            scanf("%d", &choice);
            if (choice==1){
                users = users + addRekening(users);
            }
            else if (choice==2){
                goto main;
            }
            else if (choice==3){
                goto end;
            }
            break;
        default:
            break;
        }
    } while (choice!=3);

end:
    userCountWrite();
    return 0;
}

/*
Procedure to print out the title of the app
*/
void header()
{
    //clear();
    printf("-----------------------------------------\n");
    printf("|       (NAMABANK) Banking System       |\n");
    printf("|              ID %-8ld            |\n", u_id);
    printf("|            version xxx                |\n");
    printf("-----------------------------------------\n");
}

void menu()
{
    header();
    printf("\n1. Tarik Tunai\n2. Setor Tunai\n3. Riwayat Transaksi\n4. Logout");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        header();
        trxWithdraw(u_id);
        if (trxWithdraw)
        menu();
        break;
    case 2:
        header();
        trxDeposit(u_id);
        if (trxDeposit)
        menu();
        break;
    case 3:
        header();
        trxHistory(u_id);
        if (trxHistory)
        menu();
        break;
    case 4:
        header();
        printf("\nTekan ENTER untuk Logout.");
        fflush(stdin);
        getchar();
        //TBA
        break;
    default:
        header();
        pauseErr();
        menu();
        break;
    }
}