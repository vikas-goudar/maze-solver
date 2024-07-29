#include <vector>
#include <utiltiy>
#include "node.h"


Node::Node(int xCoord , int yCoord , int maxNumNeighbours , int isEdgeNode){
  this->xCoord = xCoord;
  this->yCoord = yCoord;
  this->maxNumNeighbours = maxNumNeighbours;
  connectionsSize = 0; 
  this->isEdgeNode = isEdgeNode;
}

Node::~Node(){
}

int Node::getIsEdgeNode(){
  return isEdgeNode;
}

pair<int,int> Node::getCoord(){
  return std::make_pair(xCoord , yCoord);
}

int getNumConnected(){
  return numConnected;
}

int getMaxNumNeighbours(){
  return maxNumNeighbours;
}

std::vector<Node*> getConnections(){
  return connections;
}

void Node::connectNode(Node* node , int bidi){
  connections.push_back(node);
  connectionsSize++;
  if (bidi == 1){
    node->connectNode(this , 0);
  }
}


