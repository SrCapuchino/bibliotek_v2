#include "utils.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    printf("\nPresiona Enter para continuar...");
    while (getchar() != '\n'); // Espera hasta que se presione Enter
}