#include "library.h"
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook(const char *title, const char *author) {
    if (bookCount >= MAX_BOOKS) {
        printf("No se pueden añadir más libros.\n");
        return;
    }
    Book newBook;
    newBook.id = bookCount + 1;
    strncpy(newBook.title, title, sizeof(newBook.title) - 1);
    newBook.title[sizeof(newBook.title) - 1] = '\0'; // Asegura la terminación nula
    strncpy(newBook.author, author, sizeof(newBook.author) - 1);
    newBook.author[sizeof(newBook.author) - 1] = '\0'; // Asegura la terminación nula
    newBook.available = 1;
    books[bookCount++] = newBook;
    printf("Libro añadido con éxito.\n");
}

void deleteBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("Libro eliminado con éxito.\n");
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void searchBook(const char *title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Libro encontrado: ID=%d, Título=%s, Autor=%s, Disponible=%d\n",
                   books[i].id, books[i].title, books[i].author, books[i].available);
            return;
        }
    }
    printf("Libro no encontrado.\n");
}

void listBooks() {
    if (bookCount == 0) {
        printf("No hay libros en la biblioteca.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("ID=%d, Título=%s, Autor=%s, Disponible=%d\n",
               books[i].id, books[i].title, books[i].author, books[i].available);
    }
}