#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    int a, b, i;

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the newline character

    printf("Enter the value of a: ");
    scanf("%d", &a);

    printf("Enter the value of b: ");
    scanf("%d", &b);

    // Encrypt the message
    for (i = 0; plaintext[i]; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[i] = 'A' + (a * (plaintext[i] - 'A') + b) % 26;
            } else {
                ciphertext[i] = 'a' + (a * (plaintext[i] - 'a') + b) % 26;
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
