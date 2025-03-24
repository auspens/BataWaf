#include "../includes/Game.hpp"
#include <vector>

Game::Game()
{
	_bank.reserve(36);
	_players.reserve(4);
	_players.emplace_back(Player());
	_players.emplace_back(Player());
	_players.emplace_back(Player());
	_players.emplace_back(Player());
	_rounds_played = 0;
}

Game::~Game()
{
}

int Game::play_game(int n){
	set_game(n);
	while (_active_players.size() > 1){
		do_round(_active_players);
		remove_inactive_players();
		++_rounds_played;
	}
	_active_players[0]->cardsToDeck(_deck);
	_active_players.clear();
	return _rounds_played;
}

void Game::set_game(int n){
	_deck.shuffle();
	_rounds_played = 0;
	for (int i = n-1; i >= 0 ; --i){
		_active_players.push_back(&_players[i]);
		for (int j = 36/n; j > 0; --j)
			_players[i].cardToHand(_deck.giveCard());
	}
}

void Game::do_round(std::vector <Player *> &players){
	std::vector<Player *>winning_players;
	winning_players.reserve(4);
	Card *winning_card = nullptr;
	Card *thrown_card;
	bool bata_waf = false;
	for (auto it = players.begin(); it != players.end(); ++it){
		thrown_card = (*it)->makeMove();
		if (!thrown_card){
			continue;
		}
		_bank.push_back(thrown_card);
		if (!winning_card){
			winning_card = thrown_card;
			winning_players.push_back(*it);
			thrown_card = nullptr;
			continue;
		}
		else if (thrown_card->getValue() > winning_card->getValue()){
			winning_card = thrown_card;
			winning_players.clear();
			winning_players.push_back(*it);
			thrown_card = nullptr;
			bata_waf = false;
			continue;
		}
		else if (thrown_card->getValue() == winning_card->getValue()){
			winning_players.push_back(*it);
			bata_waf = true;
			thrown_card = nullptr;
			continue;
		}
	}
	if (winning_players.empty()){
		share_bank (players);
	}
	else if (bata_waf){
		do_round(winning_players);	
	}
	else{
		winning_players[0]->cardsToLoot(_bank);
	}
}

void Game::share_bank(std::vector <Player *> &players){
	std::default_random_engine rng (std::time(nullptr));
	std::shuffle(_bank.begin(), _bank.end(), rng);
	std::vector<Card *>::iterator iterator = _bank.begin();
	while (iterator != _bank.end()){
		for (unsigned int i = 0; i < players.size(); ++i){
			if (iterator != _bank.end()){
				players[i]->cardToLoot(*iterator);
				++iterator;
			}
		}
	}
	_bank.clear();
}

void Game::remove_inactive_players(){
	for (auto it = _active_players.begin(); it != _active_players.end(); ){
		if ((*it)->getHand().size() == 0 && (*it)->getLoot().size() == 0)
			it = _active_players.erase(it);
		else
		 	++it;
	}
}

// int Game::cards_in_game(){
// 	int result{0};
// 	for (Player *player : _active_players){
// 		result += player->getHand().size();
// 		result+= player->getLoot().size();
// 	}
// 	result += _bank.size();
// 	return result;
// }
// void Game::share_bank_tester(std::vector <Card *> &bank, std::vector <Player *> &players){
// 	auto rng = std::default_random_engine {};
// 	std::shuffle(bank.begin(), bank.end(), rng);
// 	std::vector<Card *>::iterator iterator = bank.begin();
// 	while (iterator != bank.end()){
// 		for (unsigned int i = 0; i < players.size(); ++i){
// 			if (iterator != bank.end()){
// 				players[i]->cardToLoot(*iterator);
// 				++iterator;
// 			}
// 		}
// 	}
// }
