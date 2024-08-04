#include <utility>
#include <random>
#include "binary_tree.h"

BinaryTree::BinaryTree(MazeGenerator* mazeGenerator){
  this->mazeGenerator = mazeGenerator;
  this->size = mazeGenerator->getSize();

  gen = std::mt19937(rd());
  this->distrib = std::uniform_int_distribution<> (0 , 1);
}

int BinaryTree::getRandomSouthOrEast(std::pair<int,int> node){
  int existsSouth = 1;
  int existsEast = 1;

  if ((node.second*size+node.first+1)%size==0){
    existsEast=0;
  }
  if ((node.second*size+node.first)>=size*(size-1)){
    existsSouth=0;
  }
  
  if (!(existsSouth || existsEast)){
    return -1;
  }
  else if (!existsSouth){
    return 1;
  }
  else if (!existsEast){
    return 2;
  }
  else{
    return distrib(gen);
  }
}

void BinaryTree::generateMaze(){
  std::pair<int,int> node = std::make_pair(0,0);
  for (int i = 0; i<size*size; i++){
    int dir = getRandomSouthOrEast(node);
		mazeGenerator->connectNodes(mazeGenerator->nodeAtDirection(dir));

    if ((node.first+1)%size == 0){
      node.first=0;
      node.second++;
    }
    else{
      node.first++;
    }
  }
}
