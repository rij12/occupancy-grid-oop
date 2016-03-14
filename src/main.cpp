#include "main.h"
#include "Robot.h"
#include "Grid.h"


int main() {


    Robot myRobot;
    Grid grid = Grid(myRobot.getPoses(), myRobot.getRanges());
    grid.printGrid();

    return 0;
}



