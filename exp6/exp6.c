#include <stdio.h>
#include <string.h>

#define MAX 10

void eliminate_left_recursion(char *non_terminal, char productions[MAX][MAX], int num_productions) {
    char temp[MAX][MAX];
    int i, j, k, count = 0;

    for (i = 0; i < num_productions; i++) {
        if (productions[i][0] == non_terminal[0]) {
            strcpy(temp[count], productions[i] + 1);
            count++;
        }
    }

    for (i = 0; i < num_productions; i++) {
        if (productions[i][0] != non_terminal[0]) {
            strcpy(temp[count], productions[i]);
            count++;
        }
    }

    printf("%c -> ", non_terminal[0]);
    for (i = 0; i < count; i++) {
        if (i == count - 1) {
            printf("%s", temp[i]);
        } else {
            printf("%s | ", temp[i]);
        }
    }
    printf("\n");
}

int main() {
    char non_terminal[MAX] = "A";
    char productions[MAX][MAX] = { "A->Aα", "A->β" };
    int num_productions = 2;

    eliminate_left_recursion(non_terminal, productions, num_productions);

    return 0;
}
