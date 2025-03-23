#include "library2.h"

int main() {
    Book *books = NULL;
    Member *members = NULL;
    int bookCount = 0, memberCount = 0;

    // Iniciando o sistema da biblioteca
    loadData(&books, &bookCount, &members, &memberCount); 

    int option;
    do {
        printf("\n");
        printf("===================================================\n");
        printf("===================================================\n");
        printf("Sistema de Gerenciamento de Biblioteca\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n"); 
        printf("2. Listar Livros\n");
        printf("3. Buscar Livro\n");
        printf("4. Remover Livro\n");
        printf("5. Adicionar Estudante\n");
        printf("6. Listar Estudantes\n");
        printf("7. Buscar Estudante\n");
        printf("8. Remover Estudante\n");
        printf("9. Salvar e Sair\n");
        printf("===================================================\n\n");
        printf("Escolha e digite uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1: addBook(&books, &bookCount); break;
            case 2: listBooks(books, bookCount); break;
            case 3: searchBook(books, bookCount); break;
            case 4: removeBook(&books, &bookCount); break;
            case 5: addMember(&members, &memberCount); break;
            case 6: listMembers(members, memberCount); break;
            case 7: searchMember(members, memberCount); break;
            case 8: removeMember(&members, &memberCount); break;
            case 9: saveData(books, bookCount, members, memberCount); break;
            default: printf("Opção inválida.\n");
        }
    } while (option != 9);

    free(books);
    free(members);

    return 0;
}
