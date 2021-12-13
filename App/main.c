#include <stdio.h>
#include <stdlib.h>
#include "../library/utils/utils.h"
#include "../library/auth/auth.h"
#include "../library/transaction/trx.h"

int choice;
char id[8];
void header();
void menu();

//Main Driver To Run The Program
int main()
{
    int pilihan;
    header();
    do
    {
        printf("Apakah anda sudah memiliki rekening? ");
        printf("\n1. Sudah\n2. Belum\nPilih: ");
        scanf("%d", &pilihan);
        if (pilihan == 2)
        {
            printf("Apakah anda ingin membuat rekening?");
            printf("\n1. Ya\n2. Tidak\n3. Keluar\nPilih: ");
            scanf("%d", &pilihan);
            if (pilihan == 1)
            {
                addRekening();
            }
            else if (pilihan == 3)
            {
                goto end;
            }
        }
    } while (pilihan < 1 || pilihan > 2);

main:
    clear();
    header();
    printf("(NAMABANK) Banking System");
    printf("\n\n1. Login\n2. Sign Up\n3. Exit");
    printf("\n\nSelect Action: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        //login();
        break;
    case 2:
        //signup();
        break;
    case 3:
        goto end;
        break;
    default:
        pauseErr();
        goto main;
        break;
    }

end:
    return 0;
}

/*
Procedure to print out the title of the app
*/
void header()
{
    clear();
    printf("-----------------------------------------\n");
    printf("|       (NAMABANK) Banking System       |\n");
    printf("|              ID %-8s              |\n", id);
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
        //trxWithdraw();
        break;
    case 2:
        header();
        //trxDeposit(id);
        break;
    case 3:
        header();
        //trxHistory();
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
