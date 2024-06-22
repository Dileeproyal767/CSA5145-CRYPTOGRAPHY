#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    char cipher[MAX_LENGTH];
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    char cipherAlphabet[] = "nopqrstuvwxyzabcdefghijklm";
    int i;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character

    printf("Encrypted message: ");
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                printf("%c", toupper(cipherAlphabet[alphabet[(int)tolower(message[i]) - 'a']]));
            } else {
                printf("%c", cipherAlphabet[alphabet[(int)message[i] - 'a']]);
            }
        } else {
            printf("%c", message[i]);
        }
    }
    printf("\n");

    return 0;
}
