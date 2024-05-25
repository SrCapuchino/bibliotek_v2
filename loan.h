#ifndef LOAN_H
#define LOAN_H

typedef struct {
    int bookId;
    int userId;
    char dueDate[20];
} Loan;

void addLoan(int bookId, int userId, const char *dueDate);
void returnLoan(int bookId, int userId);
void listLoans();

#endif // LOAN_H