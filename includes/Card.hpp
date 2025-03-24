#pragma once
#include <string>

class Card {
	public:
	Card(int value);
	~Card();
	int getValue();

	private:
	const int _value;
	Card();
	Card(Card const &src);
};