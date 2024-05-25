#include "file_manager.h"
#include "library.h"
#include "user.h"
#include "loan.h"
#include <stdio.h>

extern Book books[];
extern int bookCount;
extern User users[];
extern int userCount;
extern Loan loans[];
extern int loanCount;

void saveData() {
    FILE *file = fopen("data.dat", "wb");
    if (file == NULL) {
        printf("Error al abrir el archivo para guardar.\n");
        return;
    }
    fwrite(&bookCount, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), (size_t)bookCount, file);
    fwrite(&userCount, sizeof(int), 1, file);
    fwrite(users, sizeof(User), (size_t)userCount, file);
    fwrite(&loanCount, sizeof(int), 1, file);
    fwrite(loans, sizeof(Loan), (size_t)loanCount, file);
    fclose(file);
    printf("Datos guardados con éxito.\n");
}

void loadData() {
    FILE *file = fopen("data.dat", "rb");
    if (file == NULL) {
        printf("Error al abrir el archivo para cargar.\n");
        return;
    }
    fread(&bookCount, sizeof(int), 1, file);
    fread(books, sizeof(Book), (size_t)bookCount, file);
    fread(&userCount, sizeof(int), 1, file);
    fread(users, sizeof(User), (size_t)userCount, file);
    fread(&loanCount, sizeof(int), 1, file);
    fread(loans, sizeof(Loan), (size_t)loanCount, file);
    fclose(file);
    printf("Datos cargados con éxito.\n");
}
