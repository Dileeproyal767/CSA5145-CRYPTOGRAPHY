#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define KEY_LENGTH 10

int main() {
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char key[KEY_LENGTH];
    int i, j, k, l, m;
    int row, col;
    int flag = 0;

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the newline character

    printf("Enter the key: ");
    fgets(key, KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0'; // Remove the newline character

    // Encrypt the message
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = toupper(key[(i % KEY_LENGTH)]);
            } else {
                ciphertext[i] = tolower(key[(i % KEY_LENGTH)]);
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("Encrypted message: ");
    for (i = 0; ciphertext[i]; i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    return 0;
}
