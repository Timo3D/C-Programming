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
	char ch;
	long unsigned int ctr = 0;

	plain = fopen("plain.txt", "r");

	if (NULL == plain) {
		printf("cannot open file");
	}
	else {
		while (1) {
			ch = (char) fgetc(plain);
			if (ch != EOF) {
				encrypt(&ch, key[ctr]);
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
	}

	#else

	FILE *encryptedOutput;
	char *ch;
	char detectChar = 0;
	int wordCounter = 0;
	long unsigned int ctr = 0;

	encryptedOutput = fopen("actual-output.txt", "r");
	
	if (NULL == encryptedOutput) {
		printf("cannot open file");
	}
	else {
		while (1) {
			char newRead = (char) fgetc(encryptedOutput);
			ch = &newRead;
			if (*ch != EOF) {
				decrypt(ch, key[ctr]);
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
	}

	fprintf(stderr, "Words: %d\n", wordCounter);

	#endif

	return 0;
}