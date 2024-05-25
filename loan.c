#include "loan.h"
#include "library.h"
#include "user.h"
#include <stdio.h>
#include <string.h>

#define MAX_LOANS 100

Loan loans[MAX_LOANS];
int loanCount = 0;

void addLoan(int bookId, int userId, const char *dueDate) {
    if (loanCount >= MAX_LOANS) {
        printf("No se pueden añadir más préstamos.\n");
        return;
    }
    Loan newLoan;
    newLoan.bookId = bookId;
    newLoan.userId = userId;
    strncpy(newLoan.dueDate, dueDate, sizeof(newLoan.dueDate) - 1);
    newLoan.dueDate[sizeof(newLoan.dueDate) - 1] = '\0'; // Asegura la terminación nula
    loans[loanCount++] = newLoan;
    printf("Préstamo añadido con éxito.\n");
}

void returnLoan(int bookId, int userId) {
    for (int i = 0; i < loanCount; i++) {
        if (loans[i].bookId == bookId && loans[i].userId == userId) {
            for (int j = i; j < loanCount - 1; j++) {
                loans[j] = loans[j + 1];
            }
            loanCount--;
            printf("Préstamo devuelto con éxito.\n");
            return;
        }
    }
    printf("Préstamo no encontrado.\n");
}

void listLoans() {
    if (loanCount == 0) {
        printf("No hay préstamos en el sistema.\n");
        return;
    }
    for (int i = 0; i < loanCount; i++) {
        printf("Libro ID=%d, Usuario ID=%d, Fecha de devolución=%s\n",
               loans[i].bookId, loans[i].userId, loans[i].dueDate);
    }
}
