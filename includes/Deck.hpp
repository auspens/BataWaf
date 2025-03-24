#pragma once
#include "Card.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <exception>
#include<iostream>
#include<ctime>

class Deck{
	public:
		Deck();
		Deck(Deck const &Deck);
		~Deck();
		void shuffle();
		Card *giveCard();
		void returnCards(std::vector<Card *> &cards);
		std::vector<Card*>&get_deck();
	private:
		std::vector <Card*> _deck;
};