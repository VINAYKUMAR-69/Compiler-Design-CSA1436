#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    int character_count = 0, word_count = 0, line_count = 0;
    int in_word = 0;

    printf("Enter text (Ctrl+D or Ctrl+Z to end input):\n");

    while ((ch = getchar()) != EOF) {
        character_count++;  // Count characters

        if (ch == '\n') {
            line_count++;  // Count lines
        }

        // Detect words based on spaces or punctuation marks
        if (isspace(ch) || ispunct(ch)) {
            if (in_word) {
                word_count++;  // Word ended
                in_word = 0;
            }
        } else {
            if (!in_word) {
                in_word = 1;  // Word started
            }
        }
    }

    // If input ends while still inside a word
    if (in_word) {
        word_count++;
    }

    printf("\nTotal characters: %d\n", character_count);
    printf("Total words: %d\n", word_count);
    printf("Total lines: %d\n", line_count);

    return 0;
}
