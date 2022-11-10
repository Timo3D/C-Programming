// TODO: Add file-level documentation.

#include <stdio.h>
#include "gamelib.h"


// TODO: Add function-level documentation.
void del_card(Card game[], CardIndex position)
{
	if ((game[position].suit == game[position - 3].suit) || (game[position].rank == game[position - 3].rank)) game[position - 3] = game[position];
	else game[position - 1] = game[position];
	while (game[position].suit != '0' && game[position].suit != '0') {
		position++;
		game[position - 1] = game[position];
	}
	return;
}

// TODO: Add function-level documentation.
void load_game(const char str[], Card game[])
{
	int i = 0;
	while (str[i * 3] != '0') {
		game[i].suit = str[i * 3];
		game[i].rank = str[i * 3 + 1];
		i++;
	}
	game[i].suit = '0';
	game[i].rank = '0';
	return;
}

// TODO: Add function-level documentation.
void play_game(Card game[])
{
		unsigned char i = 0;
		while (game[i].suit != '0') {
			if ((i - 3 >= 0 && (game[i].suit == game[i - 3].suit || game[i].rank == game[i - 3].rank)) || (i - 1 >= 0 && (game[i].suit == game[i - 1].suit || game[i].rank == game[i - 1].rank))) {
				del_card(game, i);
				i = 0;
			}
			i++;
		}
	
	return;
}

// TODO: Add function-level documentation.
void display_game(const Card game[])
{
	int i = 0;
	while (game[i].suit != '0') {
		printf("%c", game[i].suit);
		printf("%c ", game[i].rank);
		i++;
	}
	printf("00 \n");
	return;
}
