#include "library2.h"

// Adiciona um novo livro
void addBook(Book **books, int *bookCount) {
    // Realoque espaço para um novo livro
    *books = realloc(*books, (*bookCount + 1) * sizeof(Book));
    if (*books == NULL) {
        printf("===================================================\n");
        printf("====== Erro ao alocar memória para o livro. =======\n");
        printf("===================================================\n");
        return;
    }

    printf("===================================================\n");
    // Preenche os dados do novo livro
    printf("Digite o título do livro: ");
    getchar(); // Limpa o buffer
    fgets((*books)[*bookCount].title, MAX_TITLE, stdin);
    (*books)[*bookCount].title[strcspn((*books)[*bookCount].title, "\n")] = '\0';

    printf("Digite o autor do livro: ");
    fgets((*books)[*bookCount].author, MAX_AUTOR, stdin);
    (*books)[*bookCount].author[strcspn((*books)[*bookCount].author, "\n")] = '\0';

    printf("Digite o ano de publicação: ");
    scanf("%d", &(*books)[*bookCount].year);

    (*bookCount)++;

    printf("===================================================\n");
    printf("========== Livro adicionado com sucesso! ==========\n");
    printf("===================================================\n");
}

// Lista todos os livros
void listBooks(Book *books, int bookCount) {
    printf("===================================================\n");
    if (bookCount == 0) {
        printf("============= Nenhum livro cadastrado. ============\n");
        printf("===================================================\n");
        return;
    }
    printf("================= Lista de Livros: ================\n");
    for (int i = 0; i < bookCount; i++) {
        printf("==== Título: %s\n", books[i].title);
        printf("==== Autor: %s\n", books[i].author);
        printf("==== Ano: %d\n", books[i].year);
        printf("===================================================\n");
    }
}

// Pesquisa um livro pelo título
void searchBook(Book *books, int bookCount) {
    printf("===================================================\n");
    if (bookCount == 0) {
        printf("============= Nenhum livro cadastrado. ============\n");
        printf("===================================================\n");
        return;
    }

    char title[MAX_TITLE];
    printf("Digite o título do livro para buscar: ");
    getchar();
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("===================================================\n");
            printf("================= Livro encontrado ================\n");
            printf("==== Título: %s\n", books[i].title);
            printf("==== Autor: %s\n", books[i].author);
            printf("==== Ano: %d\n", books[i].year);
            printf("===================================================\n");
            return;
        }
    }
    printf("===================================================\n");
    printf("============== Livro não encontrado. ==============\n");
    printf("===================================================\n");
}

// Remove um livro
void removeBook(Book **books, int *bookCount) {
    if (*bookCount == 0) {
        printf("===================================================\n");
        printf("============= Nenhum livro cadastrado. ============\n");
        printf("===================================================\n");
        return;
    }

    printf("===================================================\n");
    char title[MAX_TITLE];
    printf("Digite o título do livro para remover: ");
    getchar();
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < *bookCount; i++) {
        if (strcmp((*books)[i].title, title) == 0) {
            for (int j = i; j < *bookCount - 1; j++) {
                (*books)[j] = (*books)[j + 1];
            }
            (*books) = realloc(*books, (*bookCount - 1) * sizeof(Book));
            (*bookCount)--;
            printf("===================================================\n");
            printf("=========== Livro removido com sucesso! ===========\n");
            printf("===================================================\n");
            return;
        }
    }
    printf("============= Livro não encontrado.\n =============");
    printf("===================================================\n");
}

// (Funções de membro seguem estrutura semelhante às de livros.)

void addMember(Member **members, int *memberCount){
    // Realoca espaço para um novo membro
    *members = realloc(*members, (*memberCount + 1) * sizeof(Member));
    if (*members == NULL) {
        printf("===================================================\n");
        printf("==== Erro ao alocar memória para o estudante. =====\n");
        printf("===================================================\n");
        return;
    }

    printf("===================================================\n");
    // Preenche os dados do novo membro
    printf("Digite o nome do estudante: ");
    getchar(); // Limpa o buffer
    fgets((*members)[*memberCount].name, MAX_NAME, stdin);
    (*members)[*memberCount].name[strcspn((*members)[*memberCount].name, "\n")] = '\0';

    printf("Digite o número de matrícula do estudante: ");
    scanf("%d", &(*members)[*memberCount].id);

    (*memberCount)++;

    printf("===================================================\n");
    printf("======== Estudante adicionado com sucesso! ========\n");
    printf("===================================================\n");
}

void listMembers(Member *members, int memberCount) {
    printf("===================================================\n");
    if (memberCount == 0) {
        printf("=========== Nenhum estudante cadastrado. ==========\n");
        printf("===================================================\n");
        return;
    }
    printf("===================================================\n");
    printf("============== Lista de Estudantes: ===============\n");
    for (int i = 0; i < memberCount; i++) {
        printf("==== Nome: %s\n", members[i].name);
        printf("==== Matrícula: %d\n", members[i].id);
        printf("===================================================\n");
    }
}

void searchMember(Member *members, int memberCount) {
    printf("===================================================\n");
    if (memberCount == 0) {
        printf("=========== Nenhum estudante cadastrado. ==========\n");
        printf("===================================================\n");
        return;
    }

    char name[MAX_NAME];
    printf("Digite o nome do estudante para buscar: ");
    getchar(); // Limpa o buffer
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < memberCount; i++) {
        if (strcmp(members[i].name, name) == 0) {
            printf("===================================================\n");
            printf("============ Estudante encontrado: ================\n");
            printf("==== Nome: %s\n", members[i].name);
            printf("==== Matrícula: %d\n", members[i].id);
            printf("===================================================\n");
            return;
        }
    }
    printf("===================================================\n");
    printf("============ Estudante não encontrado. ============\n");
    printf("===================================================\n");
}

void removeMember(Member **members, int *memberCount) {
    if (*memberCount == 0) {
        printf("===================================================\n");
        printf("========= Nenhum estudante para remover. ==========\n");
        printf("===================================================\n");
        return;
    }

    printf("===================================================\n");
    char name[MAX_NAME];
    printf("Digite o nome do estudante para remover: ");
    getchar(); // Limpa o buffer
    fgets(name, MAX_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < *memberCount; i++) {
        if (strcmp((*members)[i].name, name) == 0) {
            for (int j = i; j < *memberCount - 1; j++) {
                (*members)[j] = (*members)[j + 1];
            }
            *members = realloc(*members, (*memberCount - 1) * sizeof(Member));
            (*memberCount)--;
            printf("===================================================\n");
            printf("========== Estudante removido com sucesso! ========\n");
            printf("===================================================\n");
            return;
        }
    }
    printf("============= Estudante não encontrado. ===========\n");
    printf("===================================================\n");
}


// Salva os dados em arquivo
void saveData(Book *books, int bookCount, Member *members, int memberCount) {
    FILE *file = fopen(DATA_FILE, "w");
    if (file == NULL) {
        printf("===================================================\n");
        printf("======= Erro ao abrir o arquivo para salvar. ======\n");
        printf("===================================================\n");
        return;
    }

    // Salva livros
    fprintf(file, "%d\n", bookCount);
    for (int i = 0; i < bookCount; i++) {
        fprintf(file, "%s|%s|%d\n", books[i].title, books[i].author, books[i].year);
    }

    // Salva membros
    fprintf(file, "%d\n", memberCount);
    for (int i = 0; i < memberCount; i++) {
        fprintf(file, "%s|%d\n", members[i].name, members[i].id);
    }

    fclose(file);
    printf("===================================================\n");
    printf("============ Dados salvos com sucesso. ============\n");
    printf("===================================================\n");
}

// Carrega os dados do arquivo
void loadData(Book **books, int *bookCount, Member **members, int *memberCount) {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        printf("===================================================\n");
        printf("======= Nenhum arquivo de dados encontrado. =======\n");
        printf("======= Começando com dados vazios.================\n");
        printf("===================================================\n");
        return;
    }

    fscanf(file, "%d\n", bookCount);
    *books = malloc(*bookCount * sizeof(Book));
    for (int i = 0; i < *bookCount; i++) {
        fscanf(file, "%[^|]|%[^|]|%d\n", (*books)[i].title, (*books)[i].author, &(*books)[i].year);
    }

    fscanf(file, "%d\n", memberCount);
    *members = malloc(*memberCount * sizeof(Member));
    for (int i = 0; i < *memberCount; i++) {
        fscanf(file, "%[^|]|%d\n", (*members)[i].name, &(*members)[i].id);
    }

    fclose(file);
    printf("===================================================\n");
    printf("======= SEJA BEM VINDO A BIBLIOTECA DA UESC! ======");
}