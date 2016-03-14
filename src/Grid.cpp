//
// Created by rich on 11/03/16.
//

#include <stdlib.h>
#include "Grid.h"
#include "Robot.h"

Grid::Grid(vector<vector<double>> poses, vector<vector<double >> ranges){

    intialiseGrid(grid);
    buildingGrid(poses,ranges,grid);
    }

Grid::Grid(){
    intialiseGrid(grid);
};
//Grid::~Grid() {
//    free(Grid);
//}

void Grid::printGrid(){

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


void Grid::buildingGrid(vector<vector<double>> poses,
                         vector<vector<double>> ranges,
                         vector<vector<int>> & grid){

    // Poses Data
    double currentGridX = 0;
    double currentGridY = 0;
    double currentOrientation = 0;

    int x = 0;
    int y = 0;

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
                x = (int)Robot::getCellIndexX(Robot::getXCoordinate(currentGridX,ranges[i][j], j * DGREE_MULTIPLER,currentOrientation));
            }
            if(ranges[i][j] < MAX_RANGE_OF_SENORS){
                y = (int)Robot::getCellIndexY(Robot::getYCoordinate(currentGridY,ranges[i][j], j * DGREE_MULTIPLER,currentOrientation));
            }
            grid[x][y] = 1;
        }
    }
}

// initialising empty grid

void Grid::intialiseGrid(vector<vector<int>> &grid){

    for (int i = 0; i < GRID_WIDTH; i++){
        vector<int> gridData;
        for (int j = 0; j < GRID_WIDTH; j++ ){
            gridData.push_back(0);
        }
        grid.push_back(gridData);
    }

}
