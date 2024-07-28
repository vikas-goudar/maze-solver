#include <random>
#include <vector>
#include "maze.h"
#include "node.h"

using namespace std;


Maze::Maze() : Maze(10 , 4){
  //default size is 10x10 and numNeighbours as 4

}

Maze::Maze(int size , int numNeighbours){
  this->size = size;
  this->numNeighbours = numNeighbours;
  arrayNodes = new Node*[size*size];
}

Maze::~Maze(){
  delete[] arrayNodes; 
  /* if nodes are dynamically allocated, delete them also */
}

Node* Maze::getNode(int xCoord , int yCoord){
  return arrayNodes[yCoord*size + xCoord];
}

Node* Maze::getRandomNode(){
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0 , size*size - 1);
  int randomNumber = distrib(gen);
  
  return arrayNodes[randomNumber];
}

void Maze::printNodes(){};
