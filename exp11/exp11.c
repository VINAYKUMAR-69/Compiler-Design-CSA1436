#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char expr[MAX];
int index = 0;

void skip_spaces() {
    while (expr[index] == ' ') {
        index++;
    }
}

int evaluate_factor();
int evaluate_term();
int evaluate_expression();

int evaluate_factor() {
    skip_spaces();
    int result = 0;

    if (expr[index] == '(') {
        index++;  // Skip '('
        result = evaluate_expression();
        if (expr[index] == ')') {
            index++;  // Skip ')'
        }
    } else {
        // If it's a number, process it
        while (isdigit(expr[index])) {
            result = result * 10 + (expr[index] - '0');
            index++;
        }
    }
    return result;
}

int evaluate_term() {
    skip_spaces();
    int result = evaluate_factor();
    
    while (expr[index] == '*' || expr[index] == '/') {
        char op = expr[index];
        index++;  // Skip the operator
        
        int factor = evaluate_factor();
        if (op == '*') {
            result *= factor;
        } else if (op == '/') {
            if (factor != 0) {
                result /= factor;
            } else {
                printf("Error: Division by zero.\n");
                exit(1);
            }
        }
    }
    return result;
}

int evaluate_expression() {
    skip_spaces();
    int result = evaluate_term();
    
    while (expr[index] == '+' || expr[index] == '-') {
        char op = expr[index];
        index++;  // Skip the operator
        
        int term = evaluate_term();
        if (op == '+') {
            result += term;
        } else if (op == '-') {
            result -= term;
        }
    }
    return result;
}

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);
    
    int result = evaluate_expression();
    
    printf("Result: %d\n", result);
    return 0;
}
