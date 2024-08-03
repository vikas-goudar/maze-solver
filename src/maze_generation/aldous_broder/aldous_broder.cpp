#include "aldous_broder.h"
#include <utility>
#include <vector>

AldousBroder::AldousBroder(MazeGenerator* mazeGenerator){
  this->mazeGenerator = mazeGenerator;
}

void AldousBroder::generateMaze(){
  std::pair<int,int> currentNode = mazeGenerator->getRandomNode();
  
  while (!mazeGenerator->isComplete()){
		int randomDirection = mazeGenerator->getRandomDirection(currentNode); 
    std::pair<int,int> randomConnection = mazeGenerator->nodeAtDirection(currentNode,randomDirection);
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

