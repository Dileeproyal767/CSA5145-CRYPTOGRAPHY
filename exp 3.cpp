#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define MATRIX_SIZE 5

int main() {
    char keyword[MAX_LENGTH];
    char message[MAX_LENGTH];
    char matrix[MATRIX_SIZE][MATRIX_SIZE];
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    int i, j, k, l, m, n;
    int row, col;
    int flag = 0;

    printf("Enter the keyword: ");
    fgets(keyword, MAX_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = '\0'; // Remove the newline character

    // Initialize the matrix
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = ' ';
        }
    }

    // Fill the matrix with the keyword and the alphabet
    for (i = 0; i < strlen(keyword); i++) {
        if (matrix[0][0] == ' ') {
            matrix[0][0] = keyword[i];
        } else {
            matrix[i % MATRIX_SIZE][i / MATRIX_SIZE] = keyword[i];
        }
    }

    // Fill the remaining spaces in the matrix with the alphabet
    for (i = 0; i < 26; i++) {
        if (matrix[0][0] == ' ') {
            matrix[0][0] = 'a' + i;
        } else if (matrix[1][0] == ' ') {
            matrix[1][0] = 'a' + i;
        } else if (matrix[0][1] == ' ') {
            matrix[0][1] = 'a' + i;
        } else if (matrix[1][1] == ' ') {
            matrix[1][1] = 'a' + i;
        } else if (matrix[2][0] == ' ') {
            matrix[2][0] = 'a' + i;
        } else if (matrix[2][1] == ' ') {
            matrix[2][1] = 'a' + i;
        } else if (matrix[3][0] == ' ') {
            matrix[3][0] = 'a' + i;
        } else if (matrix[3][1] == ' ') {
            matrix[3][1] = 'a' + i;
        } else if (matrix[4][0] == ' ') {
            matrix[4][0] = 'a' + i;
        } else if (matrix[4][1] == ' ') {
            matrix[4][1] = 'a' + i;
        }
    }

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character

    // Encrypt the message
    for (i = 0; i < strlen(message); i += 2) {
        if (i + 1 < strlen(message)) {
            plaintext[0] = message[i];
            plaintext[1] = message[i + 1];
        } else {
            plaintext[0] = message[i];
            plaintext[1] = 'X';
        }

        // Find the positions of the plaintext letters in the matrix
        for (j = 0; j < MATRIX_SIZE; j++) {
            for (k = 0; k < MATRIX_SIZE; k++) {
                if (matrix[j][k] == plaintext[0]) {
                    row = j;
                    col = k;
                }
                if (matrix[j][k] == plaintext[1]) {
                    m = j;
                    n = k;
                }
            }
        }

        // Calculate the positions of the ciphertext letters
        if (row == m) {
            ciphertext[i] = matrix[row][(col + 1) % MATRIX_SIZE];
            ciphertext[i + 1] = matrix[row][(n + 1) % MATRIX_SIZE];
        } else if (col == n) {
            ciphertext[i] = matrix[(row + 1) % MATRIX_SIZE][col];
            ciphertext[i + 1] = matrix[(m + 1) % MATRIX_SIZE][n];
        } else {
            if (row < m) {
                ciphertext[i] = matrix[row][n];
                ciphertext[i + 1] = matrix[m][n];
            } else {
                ciphertext[i] = matrix[m][col];
                ciphertext[i + 1] = matrix[row][n];
            }
        }
    }

    printf("Encrypted message: ");
    for (i = 0; ciphertext[i]; i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
