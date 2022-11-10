/*!
@file gamelib.c
@author Timothy Wong
@course RSE1201
@week 10
@lab09
@date 9/11/2022
@brief  Accordion is a solitaire game for one player using a single deck of playing cards. It is so named
        because it looks like accordion pleats which have to be ironed out. 
*//*_____________________________________________________________*/

#include <stdio.h>
#include "gamelib.h"

void del_card(Card game[], CardIndex position) // Replaces a card from the deck and shifts the elements of the array to replaced card.
{
	if ((game[position].suit == game[position - 3].suit) || (game[position].rank == game[position - 3].rank)) game[position - 3] = game[position];
	else game[position - 1] = game[position];
	while (game[position].suit != '0' && game[position].suit != '0') {
		position++;
		game[position - 1] = game[position];
	}
	return;
}

void load_game(const char str[], Card game[]) // Loads a game by reading it from text[] into the array of cards.
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

void play_game(Card game[]) // Plays a game.
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

void display_game(const Card game[]) // Displays the sequence of cards.
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
