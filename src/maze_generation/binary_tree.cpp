#inclide <utility>
#include "binary_tree.h"
#include <random>

BinaryTree::BinaryTree(MazeGenerator* mazeGenerator){
  this->mazeGenerator = mazeGenerator;
  this->size = mazeGenerator->getSize();

  std::mt19937 gen(rd());
  this->distrib = std::uniform_int_distribution<> distrib(0 , 1);
}

int BinaryTree::randomSouthOrEast(std::pair<int,int> node){
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
  elseif (!existsSouth){
    return 0;
  }
  elseif (!existsEast){
    return 1;
  }
  else{
    return distrib(gen);
  }
}

void BinaryTree::generateMaze(){
  std::pair<int,int> node = make_pair(0,0);
  for (int i = 0; i<size*size; i++){
    int dir = randomSouthOrEast(node);
    if (dir == 0){
  MazeGenerator->connectNodes(node,make_pair(node.first+1,node.second);
    }
    else{
    MazeGenerator->connectNodes(node,make_pair(node.first,node.second+1);
    }

    if ((node.first+1)%size == 0){
      node.first=0;
      node.second++;
    }
    else{
      node.first++;
    }
  }
}