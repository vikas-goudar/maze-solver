#ifndef MAZE_REPRESENTATION_H
#define MAZE_REPRESENTATION_H

#include <vector>
using namespace std;

class Node{
  private:
    int xCoord;
    int yCoord;
    int numNeighbours;
    // [North , West , South , East]
    Node** connections; //array of pointer of neighbours
    vector<int> connectionsInt; //vector of index of connected neighbours in connections
    int connectionsSize; //number of connected neighbours
  
  public:
    Node(int xCoord , int yCoord , int numNeighbours);
    ~Node();
    vector<int> getCoord();
    void connectNode(Node* node , int direction , int bidi);
    Node* getRandomNeighbour();
};

class Maze{
  private:
    int size;
    Node** arrayNodes;
    int numNeighbours;

  public:
    Maze();
    Maze(int size , int numNeighbours);
    ~Maze();
    Node* getRandomNode();
    Node* getNode(int xCoord , int yCoord);
    void printNodes();
};

#endif
