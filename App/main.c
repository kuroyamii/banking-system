#include <stdio.h>
#include <stdlib.h>

int choice;
char id[8];
void header();
void pause();
void trxWithdraw();
void trxDeposit();
void trxHistory();
void menu();

//Main Driver To Run The Program
int main()
{
main:

    clear();
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
        pause;
        goto main;
        break;
    }

end:
    return 0;
}

//Function Header Program (CLI)
void header()
{
    clear();
    printf("-----------------------------------------\n");
    printf("|       (NAMABANK) Banking System       |\n");
    printf("|              ID %-8s              |\n", id);
    printf("|            version xxx                |\n");
    printf("-----------------------------------------\n");
}

void pause()
{
    printf("\nPilihan Tidak Tersedia.");
    printf("\nTekan ENTER untuk kembali...");
    fflush(stdin);
    getchar();
}
void trxWithdraw()
{
    //TBA
}

void trxDeposit()
{
    //TBA
}

void trxHistory()
{
    printf("\n1. Nominal Terkecil Ke Terbesar");
    printf("\n2. Nominal Terbesar Ke Terkecil");
    printf("\n3. Default\n4. Kembali");
    printf("\n\nMasukkan Pilihan: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        //TBA
        break;
    case 2:
        //TBA
        break;
    case 3:
        //TBA
        break;
    case 4:
        menu();
    default:
        pause();
        trxHistory();
        break;
    }
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
        trxWithdraw();
        break;
    case 2:
        header();
        trxDeposit();
        break;
    case 3:
        header();
        trxHistory();
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
        pause();
        menu();
        break;
    }
}
