#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char message[MAX_LENGTH];
    int shift, i;

    printf("Enter the message to be encrypted: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove the newline character

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    printf("Encrypted message: ");
    for (i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                printf("%c", ((message[i] - 'A' + shift) % 26) + 'A');
            } else {
                printf("%c", ((message[i] - 'a' + shift) % 26) + 'a');
            }
        } else {
            printf("%c", message[i]);
        }
    }
    printf("\n");

    return 0;
}
