//
// Created by rich on 11/03/16.
//

#include "Grid.h"
#include "Robot.h"

Grid::Grid(){
    // Initalise Grid vector
    vector<vector<int>> grid;
    Grid::intialiseGrid(grid);

}

Grid::~Grid() {
    free(Grid);
}

void Grid::printGrid(vector<vector<int>> grid){

    for (int y = 49; y >= 0 ; y--){
      for (int x = 0; x <= 49; x++) {
            //   cout << "x"<<"[" << x << "] ";
        if(grid[x][y] == 1) {
          cout << "*";
        }else{
          cout << " ";
            }
        }
        // cout << "y"<<"[" << y << "];";

        cout << endl;
    }

}


void Grid::buildingGrid(vector<vector<double> > & poses,
                         vector<vector<double> > & ranges,
                         vector<vector<int> > & grid){
    // const int Max_Lines = 41;
    // cycle though, vectors get first index


    // Poses Data
    double currentGridX = 0;
    double currentGridY = 0;
    double currentOrientation = 0;
    // Senor Data
//  double currentSenorValue;
    int x = 0;
    int y = 0;
    // initialising an empty grid.

    // To Do list:
    // I need to loop though the vectors and compare the senor values to max range value if less than
    // then find out what cell index and then use to set that occupied.

    //Iterates though Outer vectors. 0-40
    for (int i = 0; i < 40;i++){
        // Find out the Robot current location.
        currentGridX = poses[i][0];
        currentGridY = poses[i][1];
        currentOrientation = poses[i][2];
        double what_is_range;
        // Looping though all the senors (0-7)
        for(int j =0; j <= 7; j++){
            if (ranges[i][j] < MAX_RANGE_OF_SENORS){
                // then I need to get the cell index and mark it.
                what_is_range = ranges[i][j];
                cout << "What is that: "<<what_is_range << endl;
                x = (int)getCellIndexX(getXCoordinate(currentGridX,ranges[i][j], j * 45, currentOrientation));
            }
            if(ranges[i][j] < MAX_RANGE_OF_SENORS){
               y = Robot::getY(currentGridX,i,j,currentOrientation);
            }
            grid[x][y] = 1;
        }
    }
}

// Intialising empty grid

void Grid::intialiseGrid(vector<vector<int >> &grid){

    for (int i = 0; i < GRID_WIDTH; i++){
        vector<int> gridData;
        for (int j = 0; j < GRID_WIDTH; j++ ){
            gridData.push_back(0);
        }
        grid.push_back(gridData);
    }

}
