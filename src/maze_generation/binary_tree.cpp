for each cell randomly add either a "north" or a "west" passage to an adjacent cell { don't go out of bounds }

the reason it is called binary tree is because each node can have upto 2 children

The algorithm creates a maze that has a diagonal bias { since each cell exists to the right or up making it easy to go 
from the south-west node to the north-east node but vice versa is hard }
The northern and eastern boundaries will be unbroken {nodes can't point out of the maze, therefore in the northern and eastern
boundaries the nodes has passages in the same direction } 

#include "binary_tree.h"
#inclide <utility>
#include <random>

BinaryTree::BinaryTree(MazeGenerator* mazeGenerator){
  this->mazeGenerator = mazeGenerator;
  this->size = mazeGenerator->getSize();

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0 , 1);
    int randomNumber = distrib(gen);

}

int BinaryTree::randomSouthOrEast(std::pair<int,int> node){
  
}

void BinaryTree::generateMaze(){
  std::pair<int,int> node = make_pair(0,0);
  for (int i = 0; i<size*size; i++){
    
  }
}