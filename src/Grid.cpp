/*
 * ar
 *
 *
 */

#include "Grid.h"
#include "Robot.h"
#include <windows.h>

Grid::Grid(){
    intialiseGrid(grid);
}
Grid::~Grid() {

}

Grid::Grid(vector<vector<double>> poses, vector<vector<double >> ranges){
    intialiseGrid(grid);
    buildingGrid(poses,ranges,grid);
    }

void Grid::printGrid(){

    for (int y = 49; y >= 0 ; y--) {
        for (int x = 0; x <= 49; x++) {
        if(grid[x][y] == 1) {
          cout << "*";
        }else{
          cout << " ";
            }
        }
            cout << endl;
    }
}

void Grid::buildingGrid(vector<vector<double>> poses,
                         vector<vector<double>> ranges,
                         vector<vector<int>> & grid){
    const int X_INDEX = 0;
    const int Y_INDEX = 1;
    const int BETA_INDEX = 2;
    // Poses Data
    double currentGridX = 0;
    double currentGridY = 0;
    double currentOrientation = 0;

    int x = 0;
    int y = 0;

    for (int i = 0; i < 40;i++){
        // Find out the Robot current location.
        currentGridX = poses[i][X_INDEX];
        currentGridY = poses[i][Y_INDEX];
        currentOrientation = poses[i][BETA_INDEX];

        for(int j =0; j <= 7; j++){
            if (ranges[i][j] < MAX_RANGE_OF_SENORS){

                x = (int)Robot::getCellIndexX(Robot::getXCoordinate(currentGridX,ranges[i][j], j * DEGREE_MULTIPLIER,
                                                                    currentOrientation));
            }
            if(ranges[i][j] < MAX_RANGE_OF_SENORS){
                y = (int)Robot::getCellIndexY(Robot::getYCoordinate(currentGridY,ranges[i][j], j * DEGREE_MULTIPLIER,
                                                                    currentOrientation));
            }
            grid[x][y] = 1;
        }
        Grid::printGrid();
        Sleep(3000);
    }
}

void Grid::intialiseGrid(vector<vector<int>> &grid){

    for (int i = 0; i < GRID_WIDTH; i++){
        vector<int> gridData;
        for (int j = 0; j < GRID_WIDTH; j++){
            gridData.push_back(0);
        }
        grid.push_back(gridData);
    }
}
