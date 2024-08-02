#include "aldous_broder.h"
#include <utility>
#include <vector>
#include <random>

AldousBroder::AldousBroder(MazeGenerator* mazeGenerator){
  this->mazeGenerator = mazeGenerator;

  std::mt19937 gen(rd());
}

void AldousBroder::generateMaze(){
  std::pair<int,int> currentNode = mazeGenerator->getRandomNode();
  
  while (!mazeGenerator->isComplete()){
    std::pair<int,int> randomConnection = getRandomDirection(currentNode);
    if (mazeGenerator->isVisited(randomConnection)){
      currentNode = randomConnection;
    }
    else{
      mazeGenerator->markVisited(randomConnection);
      mazeGenerator->connectNodes(currentNode,randomConnection,1);
      currentNode = randomConnection;
    }
  }

}

int AldousBroder::getRandomDirection(std::pair<int,int> node){
	vector<int> directions = {0,1,2,3};
	if (node.second == 0){
		directions.remove(0);
	}
	if (node.first+1==size){
		directions.remove(1);
	}
	if ((node.second+1)==size){
		directions.remove(2);
	}
	if (node.first==0){
		directions.remove(3);
	}
  distrib = std::uniform_int_distribution<> distrib(0 ,directions.size()-1);
	int randNum = distrib(gen);
	return directions[randNum];
}
