BIENVENIDO A BIBLIOTEK VERSION 2.0.0

# Sistema de Biblioteca

Este programa es una aplicación de escritorio para gestionar una biblioteca, desarrollada utilizando GTK para la interfaz gráfica. Permite realizar operaciones básicas como añadir, eliminar, buscar y listar libros, usuarios y préstamos.

## Requisitos

- GTK+ 3.0
- Un compilador compatible con C (por ejemplo, GCC)

## Compilación

Para compilar el programa, asegúrate de tener GTK+ 3.0 instalado y ejecuta el siguiente comando:

gcc -o biblioteca gui.c pkg-config --cflags --libs gtk+-3.0

## Ejecución

Para ejecutar el programa, usa el siguiente comando:

./biblioteca


## Funcionalidades

### Gestión de Libros

- **Añadir Libro**: Permite añadir un nuevo libro proporcionando el título y el autor.
- **Eliminar Libro**: Elimina un libro existente utilizando su ID.
- **Buscar Libro**: Busca un libro por su título.
- **Listar Libros**: Muestra una lista de todos los libros disponibles en la biblioteca.

### Gestión de Usuarios

- **Añadir Usuario**: Permite añadir un nuevo usuario proporcionando el nombre y el email.
- **Eliminar Usuario**: Elimina un usuario existente utilizando su ID.
- **Buscar Usuario**: Busca un usuario por su nombre.
- **Listar Usuarios**: Muestra una lista de todos los usuarios registrados en la biblioteca.

### Gestión de Préstamos

- **Añadir Préstamo**: Permite registrar un nuevo préstamo proporcionando el ID del libro, el ID del usuario y la fecha de devolución.
- **Devolver Préstamo**: Registra la devolución de un préstamo utilizando el ID del libro y el ID del usuario.
- **Listar Préstamos**: Muestra una lista de todos los préstamos registrados.

### Otras Funcionalidades

- **Guardar Datos**: Guarda los datos actuales de libros, usuarios y préstamos en un archivo.
- **Cargar Datos**: Carga los datos de libros, usuarios y préstamos desde un archivo.
- **Salir del Programa**: Cierra la aplicación.

## Uso

1. **Añadir Libro**: Introduce el título del libro en el campo de entrada y haz clic en "Añadir Libro". Luego, introduce el autor del libro en el diálogo que aparece y confirma.
2. **Eliminar Libro**: Introduce el ID del libro en el campo de entrada y haz clic en "Eliminar Libro".
3. **Buscar Libro**: Introduce el título del libro en el campo de entrada y haz clic en "Buscar Libro".
4. **Listar Libros**: Haz clic en "Listar Libros" para ver todos los libros.
5. **Añadir Usuario**: Introduce el nombre del usuario en el campo de entrada y haz clic en "Añadir Usuario". Luego, introduce el email del usuario en el diálogo que aparece y confirma.
6. **Eliminar Usuario**: Introduce el ID del usuario en el campo de entrada y haz clic en "Eliminar Usuario".
7. **Buscar Usuario**: Introduce el nombre del usuario en el campo de entrada y haz clic en "Buscar Usuario".
8. **Listar Usuarios**: Haz clic en "Listar Usuarios" para ver todos los usuarios.
9. **Añadir Préstamo**: Introduce el ID del libro en el campo de entrada y haz clic en "Añadir Préstamo". Luego, introduce el ID del usuario y la fecha de devolución en los diálogos que aparecen y confirma.
10. **Devolver Préstamo**: Introduce el ID del libro en el campo de entrada y haz clic en "Devolver Préstamo". Luego, introduce el ID del usuario en el diálogo que aparece y confirma.
11. **Listar Préstamos**: Haz clic en "Listar Préstamos" para ver todos los préstamos.
12. **Guardar Datos**: Haz clic en "Guardar Datos" para guardar los datos actuales.
13. **Cargar Datos**: Haz clic en "Cargar Datos" para cargar los datos desde un archivo.
14. **Salir del Programa**: Haz clic en "Salir del Programa" para cerrar la aplicación.

## Contribuciones

Las contribuciones son bienvenidas. Por favor, abre un issue o un pull request para discutir cualquier cambio que te gustaría hacer.

## Licencia

Este proyecto está licenciado bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.

Muchas gracias!


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

WELCOME TO BIBLIOTEK VERSION 2.0.0

#Library System

This program is a desktop application for managing a library, developed using GTK for the graphical interface. It allows basic operations such as adding, deleting, searching and listing books, users and loans.

##Requirements

- GTK+ 3.0
- A C-compatible compiler (e.g. GCC)

## Compilation

To compile the program, make sure you have GTK+ 3.0 installed and run the following command:

gcc -o library gui.c pkg-config --cflags --libs gtk+-3.0

## Execution

To run the program, use the following command:

./library


## Features

### Book Management

- **Add Book**: Allows you to add a new book by providing the title and author.
- **Delete Book**: Delete an existing book using its ID.
- **Search Book**: Search for a book by its title.
- **List Books**: Shows a list of all the books available in the library.

### User Management

- **Add User**: Allows you to add a new user by providing the name and email.
- **Delete User**: Delete an existing user using their ID.
- **Search User**: Search for a user by name.
- **List Users**: Shows a list of all registered users in the library.

### Loan Management

- **Add Loan**: Allows you to register a new loan by providing the book ID, the user ID and the return date.
- **Return Loan**: Records the return of a loan using the book ID and the user ID.
- **List Loans**: Shows a list of all registered loans.

### Other Features

- **Save Data**: Saves current book, user and loan data to a file.
- **Load Data**: Load the data of books, users and benefits from a file.
- **Exit Program**: Close the application.

## Use

1. **Add Book**: Enter the title of the book in the input field and click "Add Book". Then, enter the author of the book in the dialog that appears and confirm.
2. **Delete Book**: Enter the book ID in the input field and click "Delete Book".
3. **Search Book**: Enter the title of the book in the input field and click "Search Book".
4. **List Books**: Click "List Books" to see all books.
5. **Add User**: Enter the user's name in the input field and click "Add User". Then, enter the user's email in the dialog that appears and confirm.
6. **Delete User**: Enter the user ID in the input field and click "Delete User".
7. **Search User**: Enter the user name in the input field and click "Search User".
8. **List Users**: Click "List Users" to see all users.
9. **Add Loan**: Enter the book ID in the input field and click "Add Loan". Then, enter the user ID and return date in the dialogs that appear and confirm.
10. **Return Loan**: Enter the book ID in the input field and click "Return Loan". Then, enter the user ID in the dialog that appears and confirm.
11. **List Loans**: Click "List Loans" to view all loans.
12. **Save Data**: Click “Save Data” to save the current data.
13. **Load Data**: Click “Load Data” to load data from a file.
14. **Exit Program**: Click "Exit Program" to close the application.

##Contributions

Contributions are welcome. Please open an issue or pull request to discuss any changes you would like to make.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

Thank you so much!
