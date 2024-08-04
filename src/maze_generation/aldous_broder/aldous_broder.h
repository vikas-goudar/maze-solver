#ifndef ALDOUS_BRODER_H
#define ALDOUS_BRODER_H

#include "../maze_generator.h"

class AldousBroder{
  private:
    MazeGenerator* mazeGenerator;

  public:
    AldousBroder(MazeGenerator* mazeGenerator);
    void generateMaze();
};

#endif
