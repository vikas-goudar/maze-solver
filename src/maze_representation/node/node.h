#ifndef NODE_H
#define NODE_H

#include <vector>
#include <utility>

class Node{
  private:
    std::pair<int,int> coord;
    int numConnected;
    int isEdgeNode;
    std::vector<Node*> connections;

  public:
    Node(std::pair<int,int> coord , int isEdgeNode); 
    int getIsEdgeNode();
    std::pair<int,int> getCoord();
    int getNumConnected();
    std::vector<Node*> getConnections();
    void connectNode(Node* node , int bidi);
};

#endif
