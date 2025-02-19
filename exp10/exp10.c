#include <stdio.h>
#include <ctype.h>

int index = 0;
char input[100];

void skip_spaces() {
    while (input[index] == ' ') {
        index++;
    }
}

int is_id() {
    if (isalpha(input[index])) {
        while (isalnum(input[index])) index++;
        return 1;
    }
    return 0;
}

int F() {
    skip_spaces();
    if (input[index] == '(') {
        index++;
        if (E() && input[index] == ')') {
            index++;
            return 1;
        }
        return 0;
    }
    return is_id();
}

int T() {
    skip_spaces();
    if (F()) {
        while (input[index] == '*') {
            index++;
            if (!F()) return 0;
        }
        return 1;
    }
    return 0;
}

int E() {
    skip_spaces();
    if (T()) {
        while (input[index] == '+') {
            index++;
            if (!T()) return 0;
        }
        return 1;
    }
    return 0;
}

int S() {
    skip_spaces();
    return E() && input[index] == '\0';
}

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);
    
    if (S()) {
        printf("Valid expression.\n");
    } else {
        printf("Invalid expression.\n");
    }

    return 0;
}
