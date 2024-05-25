#include "user.h"
#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

User users[MAX_USERS];
int userCount = 0;

void addUser(const char *name, const char *email) {
    if (userCount >= MAX_USERS) {
        printf("No se pueden añadir más usuarios.\n");
        return;
    }
    User newUser;
    newUser.id = userCount + 1;
    strncpy(newUser.name, name, sizeof(newUser.name) - 1);
    newUser.name[sizeof(newUser.name) - 1] = '\0'; // Asegura la terminación nula
    strncpy(newUser.email, email, sizeof(newUser.email) - 1);
    newUser.email[sizeof(newUser.email) - 1] = '\0'; // Asegura la terminación nula
    users[userCount++] = newUser;
    printf("Usuario añadido con éxito.\n");
}

void deleteUser(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("Usuario eliminado con éxito.\n");
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

void searchUser(const char *name) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Usuario encontrado: ID=%d, Nombre=%s, Email=%s\n",
                   users[i].id, users[i].name, users[i].email);
            return;
        }
    }
    printf("Usuario no encontrado.\n");
}

void listUsers() {
    if (userCount == 0) {
        printf("No hay usuarios en el sistema.\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        printf("ID=%d, Nombre=%s, Email=%s\n",
               users[i].id, users[i].name, users[i].email);
    }
}