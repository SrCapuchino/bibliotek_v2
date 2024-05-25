#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct {
    int id;
    char title[100];
    char author[100];
    int available;
} Book;

void addBook(const char *title, const char *author);
void deleteBook(int id);
void searchBook(const char *title);
void listBooks();

#endif