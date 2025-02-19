#include <stdio.h>
#include <string.h>

#define MAX 10
#define MAX_LENGTH 50

void eliminate_left_factoring(char *non_terminal, char productions[MAX][MAX_LENGTH], int num_productions) {
    int i, j, k;
    char prefix[MAX_LENGTH], new_non_terminal[MAX] = "A'", temp[MAX_LENGTH];

    // Step 1: Find the longest common prefix among productions
    int common_prefix_length = 0;
    int prefix_found = 0;

    for (i = 0; i < num_productions - 1; i++) {
        int min_len = strlen(productions[i]) < strlen(productions[i + 1]) ? strlen(productions[i]) : strlen(productions[i + 1]);
        for (j = 0; j < min_len; j++) {
            if (productions[i][j] == productions[i + 1][j]) {
                prefix_found = 1;
                prefix[j] = productions[i][j];
                common_prefix_length++;
            } else {
                break;
            }
        }
    }

    if (prefix_found) {
        prefix[common_prefix_length] = '\0';

        // Step 2: Create new productions with the common prefix factored out
        printf("%c -> %s%s\n", non_terminal[0], prefix, new_non_terminal);
        printf("%s -> ", new_non_terminal);
        for (i = 0; i < num_productions; i++) {
            if (strncmp(productions[i], prefix, common_prefix_length) == 0) {
                // Remove the prefix from the production
                strcpy(temp, productions[i] + common_prefix_length);
                if (i == num_productions - 1) {
                    printf("%s", temp);
                } else {
                    printf("%s | ", temp);
                }
            }
        }
        printf("\n");
    } else {
        // If no common prefix, print original productions
        printf("%c -> ", non_terminal[0]);
        for (i = 0; i < num_productions; i++) {
            if (i == num_productions - 1) {
                printf("%s", productions[i]);
            } else {
                printf("%s | ", productions[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char non_terminal[MAX] = "A";
    char productions[MAX][MAX_LENGTH] = { "A->αβ1", "A->αβ2" };
    int num_productions = 2;

    eliminate_left_factoring(non_terminal, productions, num_productions);

    return 0;
}
