#include <random>
#include <vector>
#include "sidewinder.h"

Sidewinder::Sidewinder(MazeGenerator* mazeGenerator){
	this->mazeGenerator = mazeGenerator;
	this->size = mazeGenerator->getSize();
	
	gen = std::mt19937(rd());
  }

int Sidewinder::getRandomSouthOrEast(std::pair<int,int> node){
  int existsSouth = 1;
  int existsEast = 1;
  distrib = std::uniform_int_distribution<> (0 , 1);

  if ((node.second*size+node.first+1)%size==0){
    existsEast=0;
  }
  if ((node.second*size+node.first)>=size*(size-1)){
    existsSouth=0;
  }
  
  if (!(existsSouth || existsEast)){
    return -1;
  }
  else if (!existsSouth){
    return 1;
  }
  else if (!existsEast){
    return 2;
  }
  else{
    return distrib(gen);
  }
}

void Sidewinder::generateMaze(){
	std::pair<int,int> node = std::make_pair(0,0);
	std::vector<std::pair<int,int>> activeSet;
	for (int i =0; i<size*size; i++){
		activeSet.push_back(node);
		int dir = getRandomSouthOrEast(node);
		if (dir == 0){	
    	mazeGenerator->connectNodes(node,mazeGenerator->nodeAtDirection(node,dir),1);
  	}
  	else{
			distrib = std::uniform_int_distribution<> (0,activeSet.size()-1);	
			int randNum = distrib(gen);
			std::pair<int,int> randomNode = activeSet[randNum];
    	mazeGenerator->connectNodes(randomNode,mazeGenerator->nodeAtDirection(node,0),1);
			activeSet.clear();
  	}
	}

	if ((node.first+1)%size == 0){
  	node.first=0;
    node.second++;
  }
  else{
  	node.first++;
  }
}	
