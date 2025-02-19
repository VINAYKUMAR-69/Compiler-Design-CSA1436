#include <stdio.h>
#include <ctype.h>

int index = 0;
char input[100];

// Function to skip spaces
void skip_spaces() {
    while (input[index] == ' ') {
        index++;
    }
}

// Check if the current character is a valid identifier (id)
int is_id() {
    if (isalpha(input[index])) {
        while (isalnum(input[index])) index++;  // Consume the identifier
        return 1;
    }
    return 0;
}

// Handle factor (F → (E) | id)
int F() {
    skip_spaces();  // Skip spaces
    if (input[index] == '(') {
        index++;  // Consume '('
        if (E() && input[index] == ')') {
            index++;  // Consume ')'
            return 1;
        }
        return 0;
    }
    return is_id();
}

// Handle term (T → F | T * F)
int T() {
    skip_spaces();  // Skip spaces
    if (F()) {
        while (input[index] == '*') {
            index++;  // Consume '*'
            if (!F()) return 0;
        }
        return 1;
    }
    return 0;
}

// Handle expression (E → T | E + T)
int E() {
    skip_spaces();  // Skip spaces
    if (T()) {
        while (input[index] == '+') {
            index++;  // Consume '+'
            if (!T()) return 0;
        }
        return 1;
    }
    return 0;
}

// Start symbol (S → E)
int S() {
    skip_spaces();  // Skip spaces
    return E() && input[index] == '\0';  // Ensure input ends after a valid expression
}

int main() {
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);
    
    if (S())
        printf("Valid expression.\n");
    else
        printf("Invalid expression.\n");
    
    return 0;
}
