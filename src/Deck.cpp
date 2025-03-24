#include "../includes/Deck.hpp"

Deck::Deck(){
	_deck.reserve(36);
	for (int i = 1; i < 7; ++i){
		for (int j = 0; j < 6; ++j)
			_deck.push_back(new Card (i));
	}
}
Deck::Deck(Deck const &src){
	for (Card * card : src._deck){
		_deck.push_back(new Card (card->getValue()));
	}
}

void Deck::shuffle(){
	std::default_random_engine rng (std::time(nullptr));
	std::shuffle(_deck.begin(), _deck.end(), rng);
}
Card * Deck::giveCard(){
	if (_deck.empty())
		throw std::out_of_range("Trying to get card from empty deck");
	Card * res = _deck.back();
	 _deck.pop_back();
	return res;
}

Deck::~Deck(){
	for (Card * card : _deck)
		delete(card);
}

void Deck::returnCards(std::vector <Card *> &cards){
	for(Card *card:cards)
		_deck.push_back(card);
	cards.clear();
}

std::vector<Card*> &Deck::get_deck(){return _deck;}