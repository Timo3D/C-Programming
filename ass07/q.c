#include <stdio.h>

// Encrypt a single letter of an input text.
void encrypt(char* letter, char key) {
    int newChar = *letter + key;
    if (newChar > 127) {
        newChar -= 128;
    }
    printf("%c", newChar);
}

// Decrypt a single letter of an input text.
void decrypt(char* letter, char key) {
    char newChar = *letter - key;
    if (newChar < 0) {
        newChar += 128;
    }
    *letter = newChar;
    if (*letter != ';') {
        printf("%c", *letter);
    }
}