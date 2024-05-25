#include <gtk/gtk.h>
#include "library.h"
#include "user.h"
#include "loan.h"
#include "file_manager.h"
#include "utils.h"

// Declaraciones extern para las variables globales
extern int bookCount;
extern Book books[];

extern int userCount;
extern User users[];

extern int loanCount;
extern Loan loans[];

GtkWidget *text_view;
GtkWidget *entry;

static void append_text_to_view(const char *text) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_insert(buffer, &end, text, -1);
}

static void show_dialog(const char *message) {
    GtkWidget *dialog = gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

static void on_add_book_clicked(GtkWidget *widget, gpointer data) {
    const char *title = gtk_entry_get_text(GTK_ENTRY(entry));
    if (strlen(title) == 0) {
        show_dialog("Introduce el título del libro.");
        return;
    }

    GtkWidget *dialog = gtk_dialog_new_with_buttons("Añadir Libro", NULL, GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *author_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(author_entry), "Introduce el autor del libro");
    gtk_container_add(GTK_CONTAINER(content_area), author_entry);
    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        const char *author = gtk_entry_get_text(GTK_ENTRY(author_entry));
        if (strlen(author) == 0) {
            show_dialog("Introduce el autor del libro.");
        } else {
            addBook(title, author); // Usa los parámetros correctos
            append_text_to_view("Libro añadido.\n");
        }
    }
    gtk_widget_destroy(dialog);
}

static void on_delete_book_clicked(GtkWidget *widget, gpointer data) {
    const char *input = gtk_entry_get_text(GTK_ENTRY(entry));
    int id = atoi(input);
    deleteBook(id); // Usa el ID del libro para eliminarlo
    append_text_to_view("Libro eliminado.\n");
}

static void on_search_book_clicked(GtkWidget *widget, gpointer data) {
    const char *input = gtk_entry_get_text(GTK_ENTRY(entry));
    searchBook(input); // Usa el título del libro para buscarlo
    append_text_to_view("Búsqueda de libro realizada.\n");
}

static void on_list_books_clicked(GtkWidget *widget, gpointer data) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Listado de libros:\n");
    append_text_to_view(buffer);
    for (int i = 0; i < bookCount; i++) {
        snprintf(buffer, sizeof(buffer), "ID=%d, Título=%s, Autor=%s, Disponible=%d\n",
                 books[i].id, books[i].title, books[i].author, books[i].available);
        append_text_to_view(buffer);
    }
}

static void on_add_user_clicked(GtkWidget *widget, gpointer data) {
    const char *name = gtk_entry_get_text(GTK_ENTRY(entry));
    if (strlen(name) == 0) {
        show_dialog("Introduce el nombre del usuario.");
        return;
    }

    GtkWidget *dialog = gtk_dialog_new_with_buttons("Añadir Usuario", NULL, GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *email_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(email_entry), "Introduce el email del usuario");
    gtk_container_add(GTK_CONTAINER(content_area), email_entry);
    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        const char *email = gtk_entry_get_text(GTK_ENTRY(email_entry));
        if (strlen(email) == 0) {
            show_dialog("Introduce el email del usuario.");
        } else {
            addUser(name, email); // Usa los parámetros correctos
            append_text_to_view("Usuario añadido.\n");
        }
    }
    gtk_widget_destroy(dialog);
}

static void on_delete_user_clicked(GtkWidget *widget, gpointer data) {
    const char *input = gtk_entry_get_text(GTK_ENTRY(entry));
    int id = atoi(input);
    deleteUser(id); // Usa el ID del usuario para eliminarlo
    append_text_to_view("Usuario eliminado.\n");
}

static void on_search_user_clicked(GtkWidget *widget, gpointer data) {
    const char *input = gtk_entry_get_text(GTK_ENTRY(entry));
    searchUser(input); // Usa el nombre del usuario para buscarlo
    append_text_to_view("Búsqueda de usuario realizada.\n");
}

static void on_list_users_clicked(GtkWidget *widget, gpointer data) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Listado de usuarios:\n");
    append_text_to_view(buffer);
    for (int i = 0; i < userCount; i++) {
        snprintf(buffer, sizeof(buffer), "ID=%d, Nombre=%s, Email=%s\n",
                 users[i].id, users[i].name, users[i].email);
        append_text_to_view(buffer);
    }
}

static void on_add_loan_clicked(GtkWidget *widget, gpointer data) {
    const char *input = gtk_entry_get_text(GTK_ENTRY(entry));
    int bookId = atoi(input);

    GtkWidget *dialog = gtk_dialog_new_with_buttons("Añadir Préstamo", NULL, GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *user_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(user_entry), "Introduce el ID del usuario");
    gtk_container_add(GTK_CONTAINER(content_area), user_entry);
    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        const char *user_input = gtk_entry_get_text(GTK_ENTRY(user_entry));
        int userId = atoi(user_input);

        GtkWidget *date_entry = gtk_entry_new();
        gtk_entry_set_placeholder_text(GTK_ENTRY(date_entry), "Introduce la fecha de devolución (YYYY-MM-DD)");
        gtk_container_add(GTK_CONTAINER(content_area), date_entry);
        gtk_widget_show_all(dialog);

        if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
            const char *dueDate = gtk_entry_get_text(GTK_ENTRY(date_entry));
            addLoan(bookId, userId, dueDate); // Usa los parámetros correctos
            append_text_to_view("Préstamo añadido.\n");
        }
    }
    gtk_widget_destroy(dialog);
}

static void on_return_loan_clicked(GtkWidget *widget, gpointer data) {
    const char *input = gtk_entry_get_text(GTK_ENTRY(entry));
    int bookId = atoi(input);

    GtkWidget *dialog = gtk_dialog_new_with_buttons("Devolver Préstamo", NULL, GTK_DIALOG_MODAL, "_OK", GTK_RESPONSE_OK, "_Cancel", GTK_RESPONSE_CANCEL, NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *user_entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(user_entry), "Introduce el ID del usuario");
    gtk_container_add(GTK_CONTAINER(content_area), user_entry);
    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        const char *user_input = gtk_entry_get_text(GTK_ENTRY(user_entry));
        int userId = atoi(user_input);
        returnLoan(bookId, userId); // Usa los parámetros correctos
        append_text_to_view("Préstamo devuelto.\n");
    }
    gtk_widget_destroy(dialog);
}

static void on_list_loans_clicked(GtkWidget *widget, gpointer data) {
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "Listado de préstamos:\n");
    append_text_to_view(buffer);
    for (int i = 0; i < loanCount; i++) {
        snprintf(buffer, sizeof(buffer), "Libro ID=%d, Usuario ID=%d, Fecha de devolución=%s\n",
                 loans[i].bookId, loans[i].userId, loans[i].dueDate);
        append_text_to_view(buffer);
    }
}

static void on_save_data_clicked(GtkWidget *widget, gpointer data) {
    saveData();
    append_text_to_view("Datos guardados.\n");
}

static void on_load_data_clicked(GtkWidget *widget, gpointer data) {
    loadData();
    append_text_to_view("Datos cargados.\n");
}

static void on_exit_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

void initGUI(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *button;
    GtkWidget *scrolled_window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Sistema de Biblioteca");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 400);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 2, 1);

    button = gtk_button_new_with_label("Añadir Libro");
    g_signal_connect(button, "clicked", G_CALLBACK(on_add_book_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("Eliminar Libro");
    g_signal_connect(button, "clicked", G_CALLBACK(on_delete_book_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

    button = gtk_button_new_with_label("Buscar Libro");
    g_signal_connect(button, "clicked", G_CALLBACK(on_search_book_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

    button = gtk_button_new_with_label("Listar Libros");
    g_signal_connect(button, "clicked", G_CALLBACK(on_list_books_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

    button = gtk_button_new_with_label("Añadir Usuario");
    g_signal_connect(button, "clicked", G_CALLBACK(on_add_user_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

    button = gtk_button_new_with_label("Eliminar Usuario");
    g_signal_connect(button, "clicked", G_CALLBACK(on_delete_user_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

    button = gtk_button_new_with_label("Buscar Usuario");
    g_signal_connect(button, "clicked", G_CALLBACK(on_search_user_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

    button = gtk_button_new_with_label("Listar Usuarios");
    g_signal_connect(button, "clicked", G_CALLBACK(on_list_users_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

    button = gtk_button_new_with_label("Añadir Préstamo");
    g_signal_connect(button, "clicked", G_CALLBACK(on_add_loan_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 1, 1);

    button = gtk_button_new_with_label("Devolver Préstamo");
    g_signal_connect(button, "clicked", G_CALLBACK(on_return_loan_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 5, 1, 1);

    button = gtk_button_new_with_label("Listar Préstamos");
    g_signal_connect(button, "clicked", G_CALLBACK(on_list_loans_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 1, 1);

    button = gtk_button_new_with_label("Guardar Datos");
    g_signal_connect(button, "clicked", G_CALLBACK(on_save_data_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 6, 1, 1);

    button = gtk_button_new_with_label("Cargar Datos");
    g_signal_connect(button, "clicked", G_CALLBACK(on_load_data_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 7, 1, 1);

    button = gtk_button_new_with_label("Salir del Programa");
    g_signal_connect(button, "clicked", G_CALLBACK(on_exit_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 7, 1, 1);

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_vexpand(scrolled_window, TRUE);
    gtk_widget_set_hexpand(scrolled_window, TRUE);
    gtk_grid_attach(GTK_GRID(grid), scrolled_window, 0, 8, 2, 1);

    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_container_add(GTK_CONTAINER(scrolled_window), text_view);

    gtk_widget_show_all(window);
    gtk_main();
}