#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100 // Define a maximum length for strings

void encrypt(char *plaintext, char *ekey);
void decrypt(char *ciphertext, char *dkey);

int get_int(const char *prompt) {
    int input;
    printf("%s", prompt);
    scanf("%d", &input);
    return input;
}

char* get_string(const char *prompt) {
    char *input = malloc(MAX_LENGTH * sizeof(char));
    if (!input) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", prompt);
    scanf(" %99[^\n]", input); // Read input up to newline or up to 99 characters
    return input;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];
    int keyLength = strlen(key);

    if (keyLength != 26) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < keyLength; i++) {
        if (!isalpha(key[i])) {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        key[i] = toupper(key[i]);
        for (int j = i + 1; j < keyLength; j++) {
            if (key[i] == key[j]) {
                printf("Key must not contain duplicate characters.\n");
                return 1;
            }
        }
    }

    int encrypt_decrypt = get_int("Type 1 for encrypt or Type 2 for decrypt: ");
    if (encrypt_decrypt != 1 && encrypt_decrypt != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    if (encrypt_decrypt == 1) {
        char *plaintext = get_string("Plaintext = ");
        encrypt(plaintext, key);
        printf("Ciphertext: %s\n", plaintext);
        free(plaintext);
    } else if (encrypt_decrypt == 2) {
        char *ciphertext = get_string("Ciphertext = ");
        decrypt(ciphertext, key);
        printf("Plaintext: %s\n", ciphertext);
        free(ciphertext);
    }

    return 0;
}

void encrypt(char *plaintext, char *ekey) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (islower(plaintext[i])) {
            int c = plaintext[i] - 'a';
            plaintext[i] = tolower(ekey[c]);
        } else if (isupper(plaintext[i])) {
            int c = plaintext[i] - 'A';
            plaintext[i] = ekey[c];
        }
    }
}

void decrypt(char *ciphertext, char *dkey) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (islower(ciphertext[i])) {
            for (int j = 0; j < 26; j++) {
                if (tolower(dkey[j]) == ciphertext[i]) {
                    ciphertext[i] = j + 'a';
                    break;
                }
            }
        } else if (isupper(ciphertext[i])) {
            for (int j = 0; j < 26; j++) {
                if (dkey[j] == ciphertext[i]) {
                    ciphertext[i] = j + 'A';
                    break;
                }
            }
        }
    }
}
