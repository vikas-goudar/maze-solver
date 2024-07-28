#include <random>

using namespace std;

class Maze{
  int size;
  Node* arrayNodes;

  public:
    Maze(){
      this(10);
    }
    
    Maze(int size){
      arrayNodes = new Node[size*size];
    }

    ~Maze(){
      delete[] arrayNodes;
    }

    Node* getNode(int xCoord,int yCoord){
      return &arrayNodes[y*size + x];
    }
    
    void printNodes(){
      
    }

};

class Node{
  int xCoord;
  int yCoord;
  // [North , West , South , East]
  Node* connections = {null , null , null , null}
  int connectionsInt[4];
  int connectionsSize = 0;

  public:
    Node(int xCoord, int yCoord){
      this.xCoord = xCoord;
      this.yCoord = yCoord; 
    }

    int* getCoord(){
      return {this.xCoord, this.yCoord};
    }

    void connectNode(Node* node , int direction , int bidi){
      connections[direction] = node;
      connectionsInt[connectionsSize++] = direction;
      connectionsInt
      if (bidi){
	(*node).connectNode(this , (direction+2)%4 , bidi = 0);
      }
    }

    Node* getRandomNode(){
      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<> distrib(0,connectionsSize - 1);
      int randomNumber = distrib(gen);

      return connections[randomNumber];
    }
};
