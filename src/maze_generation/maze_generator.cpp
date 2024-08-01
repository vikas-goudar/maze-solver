#include "maze_generator.h"
#include <utility>

MazeGenerator::MazeGenerator(Maze* maze){
  this->maze = maze;
  visitedMask = 0;
  visitedNum = 0;
}

int MazeGenerator::isComplete(){
  int size = maze->getSize()
  if (visitedNum == (size*size - 1)){
    return 1;
  }
  else{
    return 0;
  }
}

int MazeGenerator::isVisited(std::pair<int,int> node){
  if ((1 << (node.second*maze->getSize() + noed.first)) && visitedMask){
    return 1;
  }
  else{
    return 0;
  }
 
void MazeGenerator::markVisited(std::pair<int,int> node){
  visitedMask = ((1 << (node.second*maze->getSize() + node.first)) && visitedMask);
  visitedNum++; 
}

std::pair<int,int> MazeGenerator::getRandomNode(){
  Node* node = maze->getRandomNode();
  return node->getCoord();
}

std::pair<int,int> MazeGenerator::getRandomConnection(std::pair<int,int> node){
  Node* node = maze->getRandomConnection(node);
  return node->getCoord();
}

void MazeGenerator::connectNode(std::pair<int,int> currentNode,std::pair<int,int> randomNode){
  maze->connectNodes(currentNode,randomNode);
}

