/******************************************************************************
* @filename main.c
* @author   Timothy Wong
* @SIT mail 2201258@sit.singaporetech.edu.sg 
* @course   RSE1201
* @date     18/10/2022
* @brief    This file contains encryption and decription tools. It gets the key
			from the header file q and encrypts and decrypts them accordingly.
******************************************************************************/

#include <stdio.h>		// file and console I/O

#define INCLUDE_KEYWORD
#include "q.h"			// include declarations and the decryption keyword

int main(void)
{
	#ifdef ENCRYPT

	FILE *plain;
	FILE *outputTo;

	plain = fopen("plain.txt", "r");
	outputTo = fopen("cipher.txt", "w");

	char *ch;
	long unsigned int ctr = 0;

	while (1) {
		char newRead = (char) fgetc(plain);
		ch = &newRead;
		if (*ch != EOF) {
			encrypt(ch, key[ctr]);
			fputc(*ch, outputTo);
			ctr++;
			if (ctr > (sizeof(key) - 1)) { //loop to the first letter of the key
				ctr = 0;
			}
		}
		else {
			break;
		}
	}
	fclose(plain);
	fclose(outputTo);

	#else

	FILE *encryptedOutput;
	FILE *writeToOutPlain;

	encryptedOutput = fopen("cipher.txt", "r");
	writeToOutPlain = fopen("out_plain.txt", "w");

	char *ch;
	char detectChar = 0;
	int wordCounter = 0;
	long unsigned int ctr = 0;
	
	while (1) {
		char newRead = (char) fgetc(encryptedOutput);
		ch = &newRead;
		if (*ch != EOF) {
			decrypt(ch, key[ctr]);
			fputc(*ch, writeToOutPlain);
		}
		else {
			break;
		}
		ctr++;
		if (ctr > (sizeof(key) - 1)) { //loop to the first letter of the key
			ctr = 0;
		}
		if ((*ch == ' ' || *ch == '\n' || *ch == '\r' || *ch == '\t')) { //check if decrypted key is a whitespace, tab, newline, etc
			detectChar = 0;
		}
		else {
			if (!detectChar) { //if first char is a non newline, tab, or whitespace, etc. OR previous char is a newline, tab, or whitespace, etc. THEN add word to counter
				wordCounter++;
			}
			detectChar = 1;
		}
	}
	fclose(encryptedOutput);
	fclose(writeToOutPlain);

	fprintf(stderr, "Words: %d\n", wordCounter);

	#endif

	return 0;
}