#ifndef ALDOUS_BRODER_H
#define ALDOUS_BRODER_H

#include "../../maze_representation/maze/maze.h"

class AldousBroder{
  private:
    MazeGenerator* mazeGenerator;

  public:
    AldousBroder(MazeGenerator* mazeGenerator);
    void generateMaze();
};

#endif
