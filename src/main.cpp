#include "../includes/Game.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>

int main(){	
	int number_players, number_games;
	std::string buf;
	while (1){
		std::cout <<"Number of players:"<< std::endl;
		std::cin>>buf;
		if (buf.size() == 1 && (buf[0] == '2' || buf[0] == '3' || buf[0] == '4'))
			break;
	}
	number_players = std::stoi(buf, nullptr, 10);
	while (1){
		std::cout <<"Number of games:"<< std::endl;
		std::cin>>buf;
		try {
			number_games = std::stoi(buf);
			if (number_games > 0)
				break;
		}
		catch (std::exception &e){}
	}
	std::ofstream file;
	std::string filename = "btw"+std::to_string(number_players)
							+"p"+std::to_string(number_games)+"g";
	file.open(filename);

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