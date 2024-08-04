#include "maze_generator.h"
#include <utility>
#include <random>
#include <algorithm>

MazeGenerator::MazeGenerator(Maze* maze){
  this->maze = maze;
  visitedMask = 0;
  numVisited = 0;
		
  gen = std::mt19937(rd());
}

int MazeGenerator::isComplete(){
  int size = getSize();
  if (numVisited == (size*size - 1)){
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
  visitedMask = ((1 << (node.second*getSize() + node.first)) || visitedMask);
  numVisited++; 
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
	int size = getSize();
  this->distrib = std::uniform_int_distribution<> (0 , size*size - numVisited);
	int randomNumber = distrib(gen);
	int indexFromEnd = 0;
	int zeroOccurence = 0;
	while (true){
		if ((visitedMask >> indexFromEnd) && 1){
			indexFromEnd++;
		}
		else{
			if (zeroOccurence == randomNumber){
				break;
			}
			else{
				zeroOccurence++;
			}
		}
	}
	int oneDCoord = size*size - 1 - indexFromEnd;
	return std::make_pair(oneDCoord%size,oneDCoord/size);
}

std::vector<int> MazeGenerator::getAllDirections(std::pair<int,int> node){
	int size = getSize();
	std::vector<int> directions = {0,1,2,3};
	if (node.second == 0){
		directions.erase(std::remove(directions.begin(), directions.end(), 0), directions.end());
		
	}
	if (node.first+1==size){
		directions.erase(std::remove(directions.begin(), directions.end(), 1), directions.end());
	}
	if ((node.second+1)==size){
		directions.erase(std::remove(directions.begin(), directions.end(), 2), directions.end());		
	}
	if (node.first==0){
		directions.erase(std::remove(directions.begin(), directions.end(), 3), directions.end());
	}
	return directions;
}

int MazeGenerator::getRandomDirection(std::pair<int,int> node){
	std::vector<int> directions = getAllDirections(node);
	distrib = std::uniform_int_distribution<>(0 ,directions.size()-1);
	int randNum = distrib(gen);
	return directions[randNum];
}

int MazeGenerator::getRandomUnvisitedDirection(std::pair<int,int>){
	std::vector<int> directions = getAllDirections(node);
	std::vector<int> unvisitedDirections;
	std::pair<int,int> node;

	for (int i = 0; i< directions.size(); i++){
		node = nodeAtDirection(directions[i])
		if (!isVisited(node)){
			unvisitedDirection.push_back(node);
		}
	}
	distrib = std::uniform_int_distribution<>(0 ,unvisitedDirections.size()-1);
	int randNum = distrib(gen);
	return unvisitedDirections[randNum];
}

std::pair<int,int> MazeGenerator::nodeAtDirection(std::pair<int,int> node,int direction){
	if (direction==0){
		return std::make_pair(node.first,node.second-1);
	}
	else if (direction ==1){
		return std::make_pair(node.first+1,node.second);
	}
	else if (direction ==2){
		return std::make_pair(node.first,node.second+1);
	}
	else{
		return std::make_pair(node.first-1,node.second);
	}
}
