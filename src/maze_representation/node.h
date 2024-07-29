#ifndef NODE_H
#define NODE_H

#include <vector>
#include <utility>

class Node{
  private:
    int xCoord;
    int yCoord;
    int numConnected;
    int isEdgeNode;
    int connectionsSize;
    int maxNumNeighbours;// max num of neighbours a node can have

    std::vector<Node*> connections;

  public:
    Node(int xCoord , int yCoord , int maxNumNeighbours , int isEdgeNode);
    ~Node();
     
    int getIsEdgeNode();
    std::pair<int,int> getCoord();
    int getNumConnected();
    int getMaxNumNeighbours();
    std::vector<Node*> getConnections();
    
    void connectNode(Node* node , int bidi);
};

#endif
