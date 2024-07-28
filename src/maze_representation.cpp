#include <random>
#include <vector>
#include "maze_representation.h"

using namespace std;

/* Node*/

Node::Node(int xCoord , int yCoord, int numNeighbours){
  this->xCoord = xCoord;
  this->yCoord = yCoord;
  this->numNeighbours = numNeighbours;
  connections = new Node*[numNeighbours]();
  connectionsSize = 0; //number of connections
}

Node::~Node(){
  delete[] connections;
  /* if nodes are dynamically allocated, delete them also */
}

vector<int> Node::getCoord(){
  return {xCoord , yCoord};
}

void Node::connectNode(Node* node , int direction , int bidi){
  connections[direction] = node;
  connectionsInt.push_back(direction);
  connectionsSize++;
  if (bidi == 1){
    node->connectNode(this , (direction+2)%4 , 0);
  }
}

Node* Node::getRandomNeighbour(){
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0,connectionsSize - 1);
  int randomNumber = distrib(gen);

  return connections[randomNumber];
}


/* Maze */

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
