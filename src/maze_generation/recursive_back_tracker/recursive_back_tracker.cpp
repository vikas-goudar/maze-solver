#include "recursive_back_tracker.h"

RecursiveBackTracker::RecursiveBackTracker(MazeGenerator* mazeGenerator){
	this->mazeGenerator;
}

void RecursiveBackTracker::generateMaze(){
	std::pair<int,int> node = mazeGenerator->getRandomNode();
	mazeGenerator->markVisited(node);

	while (!mazeGenerator->isComplete()){
		
	}
}
