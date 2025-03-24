#pragma once
#include "Deck.hpp"
#include <vector>

class Game;

class  Player
{
private:
	std::vector <Card *> _loot;
	std::vector <Card *> _hand;
	// int _index;
public:
	void cardToHand(Card * card);
	void cardToLoot(Card *card);
	void cardsToLoot(std::vector <Card*> & incoming);
	void lootToHand();
	void cardsToDeck(Deck &deck);
	void printCards();
	std::vector <Card *> &getHand();
	std::vector <Card *> &getLoot();
	Card *makeMove();
	Player();
	// Player(int index);
	~ Player();
};


