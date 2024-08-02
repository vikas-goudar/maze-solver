for each cell randomly add either a "north" or a "west" passage to an adjacent cell { don't go out of bounds }

the reason it is called binary tree is because each node can have upto 2 children

The algorithm creates a maze that has a diagonal bias { since each cell exists to the right or up making it easy to go 
from the south-west node to the north-east node but vice versa is hard }
The northern and eastern boundaries will be unbroken {nodes can't point out of the maze, therefore in the northern and eastern
boundaries the nodes has passages in the same direction } 

