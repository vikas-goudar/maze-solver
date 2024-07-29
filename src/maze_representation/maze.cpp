#include "maze.h"
#include "node.h"

#include <random>
#include <vector>

Maze::Maze() : Maze(10 , 4){
  //default size is 10x10 and maxNumNeighbours as 4

}

Maze::Maze(int size , int maxNumNeighbours){
  this->size = size;
  this->maxNumNeighbours = maxNumNeighbours;
  arrayNodes = new Node*[size*size];
}

Maze::~Maze(){
  delete[] arrayNodes; 
  for (int i = 0 ; i < size*size ; i++){
    delete arrayNodes[i];
  } 
}

void Maze::setArrayNodes(){
  int xCoord = 0;
  int yCoord = 0;
  int edgeNode;

  while (yCoord < size){
    if (xCoord == 0 || xCoord == (size-1) || yCoord0 == 0 || yCoord == (size-1)){
      edgeNode = 0;
    }
    else{
      edgeNode = 1;
    }

    arrayNodes[yCoord*size + xCoord] = new Node(xCoord , yCoord , maxNumNeighbour , edgeNode);
    
    xCoord = (xCoord+1)%size;
    if (xCoord == 0){
      yCoord++;
    }
  }
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

void Maze::connectNodes(std::pair<int,int> src , std::pair<int,int> dest , int bidi){
  getNode(src.first , src.second).connectNode(getNode(dest.first , dest.second , bidi);
}

std::vector<Node*> Maze::getConnections(std::pair<int,int> node){
  return getNode(node.first,node.second).getConnections();
}

Node* Maze::getRandomNeighbour(std::pair<int,int> node){
  int numConnected = node.getNumConnected();
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0 , numConnected - 1);
  int randomNumber = distrib(gen);

  return getConnections(node)[randomNumber];
  
}
