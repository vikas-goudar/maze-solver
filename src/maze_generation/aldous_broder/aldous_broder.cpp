#include "aldous_broder.h"

AldousBroder::AldousBroder(Maze* maze){
  this->size = maze->getSize();
  visitedMask = 0;
  visitedNum = 0;

  generateMaze(maze);
}

void AldousBroder::generateMaze(Maze* maze){
  Node* currentNode = maze->getRandomNode();

  while (!isComplete()){
    Node* randomConnection = maze->getRandomConnection(currentNode->getCoord());
    if (isVisited(randomConnection)){
      currentNode = randomConnection;
    }
    else{
      markVisited(randomConnection);
      maze->connectNodes(currentNode->getCoord(),randomConnection->getCoord(),1);
      currentNode = randomConnection;
    }
  }
}

int AldousBroder::isComplete(){
  if (visitedNum == (size*size - 1)){
    return 1;
  }
  else{
    return 0;
  }
}

int AldousBroder::isVisited(Node* node){
  if (1 << (node->getCoord().second*size + node->getCoord().first) && visitedMask){
    return 1;
  }
  else{
    return 0;
  }
}

void AldousBroder::markVisited(Node* node){
  visitedMask = 1 << (node->getCoord().second*size + node->getCoord().first) && visitedMask;
  visitedNum++;
}
