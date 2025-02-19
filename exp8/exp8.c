#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[20];
    char type[20];
    int address;
} Symbol;

Symbol symbol_table[MAX];
int symbol_count = 0;

void insert_symbol(char *name, char *type, int address) {
    if (symbol_count < MAX) {
        strcpy(symbol_table[symbol_count].name, name);
        strcpy(symbol_table[symbol_count].type, type);
        symbol_table[symbol_count].address = address;
        symbol_count++;
    }
}

int lookup_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void display_symbol_table() {
    for (int i = 0; i < symbol_count; i++) {
        printf("%s %s %d\n", symbol_table[i].name, symbol_table[i].type, symbol_table[i].address);
    }
}

void delete_symbol(char *name) {
    int index = lookup_symbol(name);
    if (index != -1) {
        for (int i = index; i < symbol_count - 1; i++) {
            symbol_table[i] = symbol_table[i + 1];
        }
        symbol_count--;
    }
}

int main() {
    insert_symbol("x", "int", 100);
    insert_symbol("y", "float", 104);
    insert_symbol("z", "char", 108);

    printf("Symbol Table:\n");
    display_symbol_table();

    printf("\nLookup 'y':\n");
    int idx = lookup_symbol("y");
    if (idx != -1) {
        printf("%s found at address %d\n", symbol_table[idx].name, symbol_table[idx].address);
    } else {
        printf("Symbol not found\n");
    }

    printf("\nDeleting 'y'...\n");
    delete_symbol("y");

    printf("Symbol Table after deletion:\n");
    display_symbol_table();

    return 0;
}
