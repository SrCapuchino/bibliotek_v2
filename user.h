#ifndef USER_H
#define USER_H

typedef struct {
    int id;
    char name[100];
    char email[100];
} User;

void addUser(const char *name, const char *email);
void deleteUser(int id);
void searchUser(const char *name);
void listUsers();

#endif // USER_H