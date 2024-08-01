#include "aldous_broder.h"
#include <utility>

AldousBroder::AldousBroder(MazeGenerator* mazeGenerator){
  this->mazeGenerator = mazeGenerator;
}

void AldousBroder::generateMaze(){
  std::pair<int,int> currentNode = mazeGenerator->getRandomNode();
  
  while (!mazeGenerator->isComplete()){
    std::pair<int,int> randomConnection = mazeGenerator->getRandomConnection(currentNode);
    if (mazeGenerator->isVisited(randomConnection)){
      currentNode = randomConnection;
    }
    else{
      mazeGenerator->markVisited(randomConnection);
      mazeGenerator->connectNodes(currentNode,randomConnection);
      currentNode = randomConnection;
    }
  }

}

