#include <gtk/gtk.h>
#include "library.h"
#include "user.h"
#include "loan.h"
#include "file_manager.h"
#include "utils.h"
#include <stdio.h>

void initGUI(int argc, char *argv[]); // Declaración de la función initGUI

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv); // Inicializa GTK
    loadData();
    initGUI(argc, argv); // Llama a la función para inicializar la GUI
    return 0;
}