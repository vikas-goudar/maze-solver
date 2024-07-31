#include <vector>
#include <utility>
#include "node.h"


Node::Node(std::pair<int,int> coord , int isEdgeNode){
  this->coord = coord;
  connectionsSize = 0; 
  this->isEdgeNode = isEdgeNode;
}

int Node::getIsEdgeNode(){
  return isEdgeNode;
}

std::pair<int,int> Node::getCoord(){
  return coord;
}

int Node::getNumConnected(){
  return numConnected;
}

std::vector<Node*> Node::getConnections(){
  return connections;
}

void Node::connectNode(Node* node , int bidi){
  connections.push_back(node);
  connectionsSize++;
  if (bidi == 1){
    node->connectNode(this , 0);
  }
}


