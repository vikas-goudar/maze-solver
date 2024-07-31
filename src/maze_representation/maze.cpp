#include <random>
#include <vector>
#include <utility>
#include "maze.h"


Maze::Maze() : Maze(10){
  //default size is 10x10
}

Maze::Maze(int size){
  this->size = size;
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
    if (xCoord == 0 || xCoord == (size-1) || yCoord == 0 || yCoord == (size-1)){
      edgeNode = 1;
    }
    else{
      edgeNode = 0;
    }

    arrayNodes[yCoord*size + xCoord] = new Node(std::make_pair(xCoord,yCoord) , edgeNode);
    
    xCoord = (xCoord+1)%size;
    if (xCoord == 0){
      yCoord++;
    }
  }
}

Node* Maze::getNode(std::pair<int,int> coord){ 
  return arrayNodes[coord.second*size + coord.first];
}

Node* Maze::getRandomNode(){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0 , size*size - 1);
  int randomNumber = distrib(gen);
  
  return arrayNodes[randomNumber];
}

void Maze::connectNodes(std::pair<int,int> src , std::pair<int,int> dest , int bidi){
  getNode(src)->connectNode(getNode(dest) , bidi);
}

std::vector<Node*> Maze::getConnections(std::pair<int,int> node){
  return getNode(node)->getConnections();
}

Node* Maze::getRandomConnection(std::pair<int,int> node){
  int numConnected = getNode(node)->getNumConnected();
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0 , numConnected - 1);
  int randomNumber = distrib(gen);

  return getConnections(node)[randomNumber]; 
}

