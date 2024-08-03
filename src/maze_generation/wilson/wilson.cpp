#include "wilson.h"
#include <utility>
#include <random>
#include <vector>

Wilson::Wilson(MazeGenerator* mazeGenerator){
	this->mazeGenerator = mazeGenerator;
 }

void Wilson::generateMaze(){
	std::pair<int,int> node = mazeGenerator->getRandomNode();
	mazeGenerator->markVisited(node);
	std::pair<int,int> tempNode;

	while (!mazeGenerator->isComplete()){
		node = mazeGenerator->getRandomUnvisitedNode();
		std::vector<std::pair<int,int>> path = loopErasedWalk(node);
		while (!path.empty()){
			tempNode = path.back();
			path.pop_back();
			mazeGenerator->connectNodes(node,tempNode,1);
			node = tempNode;
		}
	}
}

std::vector<std::pair<int,int>> Wilson::loopErasedWalk(std::pair<int,int> node){
	std::vector<std::pair<int,int>> path;
	path.push_back(node);
	int direction;
	int loopVisitedMask = 0;
	int size = mazeGenerator->getSize();

	while (true){
		direction = mazeGenerator->getRandomDirection(node);
		node = mazeGenerator->nodeAtDirection(node,direction);
		if ((1<<node.second*size+node.first)&&loopVisitedMask){
			while (true){
				if (path.back() == node){
					path.pop_back();
					node = path.back(); 
					break;
				}
				path.pop_back();
			}
		}
		else{
			loopVisitedMask = (1<<node.second*size+node.first)&&loopVisitedMask;	
			path.push_back(node);
			break;
		}
		return path;
	}
}
