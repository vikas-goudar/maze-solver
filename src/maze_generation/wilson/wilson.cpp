#include "wilson.h"
#include <utility>
#include <random>

Wilson::Wilson(MazeGenerator* mazeGenerator){
	this->mazeGenerator = mazeGenerator;
	std::mt19937 gen(rd());

 }
std::pair<int,int> getRandomUnvisitedNode(){	
  this->distrib = std::uniform_int_distribution<> distrib(0 , 1);
}
