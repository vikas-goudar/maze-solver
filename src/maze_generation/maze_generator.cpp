#include "maze_generator.h"
#include <utility>

MazeGenerator::MazeGenerator(Maze* maze){
  this->maze = maze;
  visitedMask = 0;
  visitedNum = 0;
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
