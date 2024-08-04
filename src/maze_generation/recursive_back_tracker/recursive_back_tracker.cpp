#include "recursive_back_tracker.h"
#include <utility>
#include <vector>

RecursiveBackTracker::RecursiveBackTracker(MazeGenerator* mazeGenerator){
	this->mazeGenerator;
}

void RecursiveBackTracker::generateMaze(){
	std::pair<int,int> node = mazeGenerator->getRandomNode();	
	std::vector<std::pair<int,int>> stack;	
	
	int direction;
	std::pair<int,int> tempNode;

	stack.push_back(node);
	mazeGenerator->markVisited(node);


	while (!mazeGenerator->isComplete()){
		node = stack.back();
		mazeGenerator->markVisited(node);
		
		direction = mazeGenerator->getRandomUnvisitedDirection(node);
		if (direction == -1){
			stack.pop_back();
		}
		else{
			tempNode = mazeGenerator->nodeAtDirection(node,direction);	
			mazeGenerator->connectNodes(node,tempNode,1);
			
			node = tempNode;
			stack.push_back(node);
			mazeGenerator->markVisited(node);
		}
	}
}
