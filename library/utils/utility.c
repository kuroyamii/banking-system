//Function Clear Screen Cross-Platform.
void clear()
{
#ifdef _WIN32
    //Windows
std:
    system("cls");
#else
    //POSIX (Unix), etc
std:
    system("clear");
#endif
}

//Function Pause
void pauseErr()
{
    printf("\nPilihan Tidak Tersedia.");
    printf("\nTekan ENTER untuk kembali...");
    fflush(stdin);
    getchar();
}

void pause()
{
    printf("\n\nTekan ENTER untuk melanjutkan");
    fflush(stdin);
    getchar();
}