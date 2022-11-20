#ifndef Q_H
#define Q_H

typedef struct
{
	char upper;
	char lower;
	unsigned short int value;
} Datum;

typedef Datum Data[2];

void print_data(const void* ptr, size_t size, size_t span);

#endif // Q_H
