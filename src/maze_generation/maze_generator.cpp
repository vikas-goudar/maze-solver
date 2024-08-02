#include "maze_generator.h"
#include <utility>
#include <random>

MazeGenerator::MazeGenerator(Maze* maze){
  this->maze = maze;
  visitedMask = 0;
  visitedNum = 0;
	
	std::mt19937 gen(rd());
 	
}

int MazeGenerator::isComplete(){
  int size = maze->getSize();
  if (visitedNum == (size*size - 1)){
    return 1;
  }
  else{
    return 0;
  }
}

int MazeGenerator::isVisited(std::pair<int,int> node){
  if ((1 << (node.second*maze->getSize() + node.first)) && visitedMask){
    return 1;
  }
  else{
    return 0;
  }
} 

void MazeGenerator::markVisited(std::pair<int,int> node){
  visitedMask = ((1 << (node.second*maze->getSize() + node.first)) || visitedMask);
  visitedNum++; 
}

std::pair<int,int> MazeGenerator::getRandomNode(){
  Node* node = maze->getRandomNode();
  return node->getCoord();
}

std::pair<int,int> MazeGenerator::getRandomConnection(std::pair<int,int> node){
  Node* tempNode = maze->getRandomConnection(node);
  return tempNode->getCoord();
}

void MazeGenerator::connectNodes(std::pair<int,int> sourceNode,std::pair<int,int> destinationNode,int bidi){
  maze->connectNodes(sourceNode, destinationNode,bidi);
}

int MazeGenerator::getSize(){
  return maze->getSize();
}

std::pair<int,int> MazeGenerator::getRandomUnvisitedNode(){	
  this->distrib = std::uniform_int_distribution<> distrib(0 , size*size - numVisited);
	randomNumber = distrib(gen);
	int indexFromEnd = 0;
	while (true){
		if ((visitedMask >> indexFromEnd) && 1){
			indexFromEnd++;
		}
		else{
			break;
		}
	}
	int oneDCoord size*size - 1 - indexFromEnd;
	return make_pair(oneDCoord%size,oneDCoord/size);
}

int MazeGenerator::getRandomDirection(std::pair<int,int> node){
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

std::pair<int,int> nodeAtDirection(std::pair<int,int> node,int direction){
	if (direction==0){
		return make_pair(node.first,node.second-1);
	}
	else if (direction ==1){
		return make_pair(node.first+1,node.second);
	}
	else if (direction ==2){
		return make_pair(node.first,node.second+1);
	}
	else{
		return make_pair(node.first-1,node.second);
	}
}
