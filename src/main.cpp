
//@author Richard Price-Jones (rij12)

#include <vector>
#include "Robot.h"
#include "Grid.h"


int main() {

    Robot myRobot;
    Grid grid(myRobot.getPoses(), myRobot.getRanges());

    return 0;
}



