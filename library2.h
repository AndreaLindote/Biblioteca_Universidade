#ifndef LIBRARY2_H
#define LIBRARY2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define MAX_TITLE 100
#define MAX_AUTOR 100
#define MAX_NAME 50
#define DATA_FILE "library_data.txt"

// Estruturas
typedef struct {
    char title[MAX_TITLE];
    char author[MAX_AUTOR];
    int year;
} Book;

typedef struct {
    char name[MAX_NAME];
    int id;
} Member;

// Funções para livros
// Adiciona um livro
void addBook(Book **books, int *bookCount);
// Lista os livros
void listBooks(Book *books, int bookCount);
// Busca um livro
void searchBook(Book *books, int bookCount);
// Remove um livro
void removeBook(Book **books, int *bookCount);

// Funções para membros
// Adiciona um membro
void addMember(Member **members, int *memberCount);
// Lista os membros
void listMembers(Member *members, int memberCount);
// Busca um membro
void searchMember(Member *members, int memberCount);
// Remove um membro
void removeMember(Member **members, int *memberCount);

// Funções de manipulação de arquivos
void loadData(Book **books, int *bookCount, Member **members, int *memberCount);
void saveData(Book *books, int bookCount, Member *members, int memberCount);

#endif
