#ifndef SIDEWINDER_H
#define SIDEWINDER_H

#include "../maze_generator.h"
#include <utility>
#include <random>

class Sidewinder{
	private:
		MazeGenerator* mazeGenerator;
		int size;

		std::random_device rd;
		std::mt19937 gen;
    std::uniform_int_distribution<> distrib;
		std::uniform_int_distribution<> distribRandomUse;

	public:
		Sidewinder(MazeGenerator* mazeGenerator);
		void generateMaze();
		int getRandomSouthOrEast(std::pair<int,int>);
};

#endif
