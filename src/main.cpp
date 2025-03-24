#include "../includes/Game.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>

int main(){	
	int number_players{4}, number_games{100000};
	std::ofstream file;
	file.open("statistics.csv");

	Game game;
	std::map <int, int> results;
	int res;
	for (int i = 0; i < number_games; ++i){
		res = game.play_game(number_players);
		if (auto search = results.find(res); search != results.end())
			search->second += 1;
		else
			results.insert({res, 1});
	}
	for (const auto &[result, repetition] : results){
		file << result << "," << repetition << "\n";
	}
	file.close();
}