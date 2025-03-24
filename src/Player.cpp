#include "../includes/Player.hpp"
#include "../includes/Game.hpp"

Player:: Player()
{
	_hand.reserve(36);
	_loot.reserve(36);
}

Player::~ Player(){}

void Player::cardToHand(Card * card){
	_hand.push_back(card);}

void Player::cardToLoot(Card * card){
	_loot.push_back(card);}

void Player::cardsToLoot(std::vector <Card*> & incoming){
	for (Card *card:incoming)
		_loot.push_back(card);
	incoming.clear();
}

void Player::lootToHand(){
	std::default_random_engine rng (std::time(nullptr));
	std::shuffle(_loot.begin(), _loot.end(), rng);
	for(Card *card:_loot)
		_hand.push_back(card);
	_loot.clear();
}

void Player::cardsToDeck(Deck &deck){
	deck.returnCards(_loot);
	deck.returnCards(_hand);
}

void Player::printCards(){
	std::cout << " Hand: ";
	for (Card * card :_hand)
		std::cout <<card->getValue() << ", ";
	std::cout << "Loot: ";
	for (Card * card :_loot)
		std::cout <<card->getValue() << ", ";
	std::cout << '\n';
}

Card *Player::makeMove(){
	if (_hand.empty()){
		lootToHand();
		if (_hand.empty())
			return nullptr; 
	}
	Card *card = _hand.back();
	_hand.pop_back();
	return card;
}

std::vector <Card *> &Player::getHand(){return _hand;}
std::vector <Card *> &Player::getLoot(){return _loot;}