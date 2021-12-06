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