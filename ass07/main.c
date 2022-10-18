// TODO: Add file-level documentaion

#include <stdio.h>		// file and console I/O

#define INCLUDE_KEYWORD
#include "q.h"			// include declarations and the decryption keyword

int main(void)
{
	#ifdef ENCRYPT

	// TODO: encrypt characters from plain.txt and put them in file cipher.txt
	FILE *ptr;
	char *ch;

	if (NULL == ptr) {
		printf("cannot open file");
	}
	else {
		do {
			ch = fgetc(ptr);
			encrypt(ch);
		}
		while (ch != EOF);

		fclose(ptr);
	}

	#else

	// TODO: decrypt cipher.txt into out_plain.txt
	// TODO: write count of words into stderr

	#endif

	return 0;
}
