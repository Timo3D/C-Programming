// TODO: Add file-level documentaion

#include <stdio.h>		// file and console I/O

#define INCLUDE_KEYWORD
#include "q.h"			// include declarations and the decryption keyword

int main(void)
{
	#ifdef ENCRYPT

	// TODO: encrypt characters from plain.txt and put them in file cipher.txt
	FILE *plain;
	char ch;
	long unsigned int ctr = 0;

	plain = fopen("plain.txt", "r");

	if (NULL == plain) {
		printf("cannot open file");
	}
	else {
		do {
			ch = (char) fgetc(plain);
			encrypt(&ch, key[ctr]);
			ctr++;
			if (ctr > (sizeof(key) - 1)) {
				ctr = 0;
			}
		}
		while (ch != EOF);

		fclose(plain);
	}

	#else

	FILE *encryptedOutput;
	char *ch;
	int wordCounter = 0;
	long unsigned int ctr = 0;

	// encryptedOutput = fopen("actual-output.txt", "r");
	encryptedOutput = fopen("expected-cipher.txt", "r");
	
	if (NULL == encryptedOutput) {
		printf("cannot open file");
	}
	else {
		while (*ch != ';') {
			// for (int  i = 0; i < 500; i++) {
			char newRead = (char) fgetc(encryptedOutput);
			ch = &newRead;
			decrypt(ch, key[ctr]);
			ctr++;
			if (ctr > (sizeof(key) - 1)) {
				ctr = 0;
			}
			if (*ch == ' ' || *ch == '\n' || *ch == '\r' || *ch == '\t') {
				wordCounter++;
			}
		}
		// while (*ch != ';');

		fclose(encryptedOutput);
	}

	fprintf(stderr, "Words: %d\n", wordCounter);

	#endif

	return 0;
}
