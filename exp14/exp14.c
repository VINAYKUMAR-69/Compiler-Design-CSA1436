#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char expression[MAX];
    char temp_var[MAX];
} SubExpression;

SubExpression sub_expressions[MAX];
int sub_expr_count = 0;

int find_common_subexpression(char* expr) {
    for (int i = 0; i < sub_expr_count; i++) {
        if (strcmp(sub_expressions[i].expression, expr) == 0) {
            return i;
        }
    }
    return -1;
}

void optimize_expression(char* expr, char* result_var) {
    int index = find_common_subexpression(expr);
    if (index == -1) {
        strcpy(sub_expressions[sub_expr_count].expression, expr);
        sprintf(sub_expressions[sub_expr_count].temp_var, "t%d", sub_expr_count + 1);
        printf("%s = %s\n", sub_expressions[sub_expr_count].temp_var, expr);
        strcpy(result_var, sub_expressions[sub_expr_count].temp_var);
        sub_expr_count++;
    } else {
        strcpy(result_var, sub_expressions[index].temp_var);
    }
}

int main() {
    char expression1[MAX], expression2[MAX];
    char result1[MAX], result2[MAX];
    
    printf("Enter first expression: ");
    fgets(expression1, sizeof(expression1), stdin);
    expression1[strcspn(expression1, "\n")] = 0;
    
    printf("Enter second expression: ");
    fgets(expression2, sizeof(expression2), stdin);
    expression2[strcspn(expression2, "\n")] = 0;
    
    optimize_expression(expression1, result1);
    optimize_expression(expression2, result2);
    
    printf("\nOptimized Code:\n");
    printf("%s = %s\n", result1, expression1);
    printf("%s = %s\n", result2, expression2);
    
    return 0;
}
