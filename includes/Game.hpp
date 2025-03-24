#pragma once
#include"Player.hpp"
#include"Deck.hpp"
#include <list>

class Game
{
private:
	Deck _deck;
	std::vector<Card *> _bank;
	std::vector<Player> _players;
	std::vector<Player *>_active_players;
	int _rounds_played;
public:
	Game();
	~Game();
	void set_game(int n_of_players);
	int play_game(int n_of_players);
	void do_round(std::vector <Player*> &players);
	void share_bank(std::vector <Player *>&players);
	void remove_inactive_players();
	// int cards_in_game();
};