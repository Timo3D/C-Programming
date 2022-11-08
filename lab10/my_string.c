/*!
@file spellcheck.c
@author Timothy Wong
@course RSE1201
@week 10
@lab09
@date 28/10/2022
@brief This file contains the definitions for some of the functions
       in string.h. The source code for the original code is taken.
*//*_____________________________________________________________*/

#include "my_string.h"

// https://en.cppreference.com/w/c/string/byte/strlen
size_t my_strlen(const char* str) { //same as string.h strlen().
  const char *char_ptr;
  const unsigned long int *longword_ptr;
  unsigned long int longword, himagic, lomagic;
  for (char_ptr = str; ((unsigned long int) char_ptr
			& (sizeof (longword) - 1)) != 0;
       ++char_ptr)
    if (*char_ptr == '\0')
      return (size_t) (char_ptr - str);
  longword_ptr = (unsigned long int *) char_ptr;
  himagic = 0x80808080L;
  lomagic = 0x01010101L;
  if (sizeof (longword) > 4)
    {
      himagic = ((himagic << 16) << 16) | himagic;
      lomagic = ((lomagic << 16) << 16) | lomagic;
    }
  if (sizeof (longword) > 8)
    return 0;
  for (;;)
    {
      longword = *longword_ptr++;
      if (((longword - lomagic) & ~longword & himagic) != 0)
	{
	  const char *cp = (const char *) (longword_ptr - 1);
	  if (cp[0] == 0)
	    return (size_t) (cp - str);
	  if (cp[1] == 0)
	    return (size_t) (cp - str + 1);
	  if (cp[2] == 0)
	    return (size_t) (cp - str + 2);
	  if (cp[3] == 0)
	    return (size_t) (cp - str + 3);
	  if (sizeof (longword) > 4)
	    {
	      if (cp[4] == 0)
		return (size_t) (cp - str + 4);
	      if (cp[5] == 0)
		return (size_t) (cp - str + 5);
	      if (cp[6] == 0)
		return (size_t) (cp - str + 6);
	      if (cp[7] == 0)
		return (size_t) (cp - str + 7);
	    }
	}
    }
}

// https://en.cppreference.com/w/c/string/byte/strcpy
char* my_strcpy(char* dest, const char* src) { //same as string.h strcpy().
    // return if no memory is allocated to the destination
    if (dest == NULL) {
        return NULL;
    }
 
    // take a pointer pointing to the beginning of the destination string
    char *ptr = dest;

    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    // include the terminating null character
    *dest = '\0';
    // the destination is returned by standard `strcpy()`
    return ptr;
}

// https://en.cppreference.com/w/c/string/byte/strcat
char* my_strcat(char* dest, const char* src) { //same as string.h strcat().
    my_strcpy (dest + my_strlen(dest), src);
    return dest;
}

// https://en.cppreference.com/w/c/string/byte/strcmp
int my_strcmp(const char* p1, const char* p2) { //same as string.h strcmp().
  const unsigned char *s1 = (const unsigned char *) p1;
  const unsigned char *s2 = (const unsigned char *) p2;
  unsigned char c1, c2;
  do
    {
      c1 = (unsigned char) *s1++;
      c2 = (unsigned char) *s2++;
      if (c1 == '\0')
	return c1 - c2;
    }
  while (c1 == c2);
  return c1 - c2;
}

// https://en.cppreference.com/w/c/string/byte/strstr
char* my_strstr(const char* string, const char* substring) { //same as string.h strstr().
	const char *a, *b;
	b = substring;
	if(*b == 0) return (char*) string;
	for (; *string != 0; string += 1) {
		if (*string != *b) continue;
		a = string;
		while (1) {
			if (*b == 0) return (char*)string;
			if (*a++ != *b++) break;
		}
		b = substring;
  }
	return NULL;
}