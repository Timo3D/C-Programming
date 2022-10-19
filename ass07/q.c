/******************************************************************************
* @filename q.c
* @author   Timothy Wong
* @SIT mail 2201258@sit.singaporetech.edu.sg 
* @course   RSE1201
* @date     18/10/2022
* @brief    This file contains encryption and decription tools. It gets the key
			from the header file q and encrypts and decrypts them accordingly.
******************************************************************************/
#include <stdio.h>

// Encrypt a single letter of an input text.
void encrypt(char* letter, char key) {
    int newChar = *letter + key;
    if (newChar > 127) {
        newChar -= 128;
    }
    *letter = (char) newChar;
    //printf("%c", *letter);
}

// Decrypt a single letter of an input text.
void decrypt(char* letter, char key) {
    int newChar = *letter - key;
    if (newChar < 0) {
        newChar += 128;
    }
    *letter = (char) newChar;
    //printf("%c", *letter);
}