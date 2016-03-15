//
// Created by rich on 11/03/16.
//

#ifndef OCCUPANCY_GRID_OOP_GRID_H
#define OCCUPANCY_GRID_OOP_GRID_H
#include <vector>
#include <ostream>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
class Grid{

public:
    // Constructor
    Grid();
    // De-constructor
    ~Grid();
    // Overloaded Constructor
    // @param vector<vector<double>> poses - Robot position data, each line stored as it's own vector.
    // @param vector<vector<double>> ranges - Robot Sensor Data, each line stored as a vector.
    Grid(vector<vector<double>> poses, vector<vector<double >> ranges);


private:
    // output grid vector to terminal window.
    void printGrid();

    // Fills grid, vector 50 by 50 vectors, intialised at 0.
    void intialiseGrid(vector<vector<int>> &grid);

    vector<vector<int>> grid;
    // Creates grid, loops though poses and ranges vectors, takes raw  positional and sensor data
    // into cell coordinates, if occupied sets corresponding cells to 1 (Empty Cell value = 0).
    // Every time occupied cell is found, printGrid() is called. To create animation effect when building grid.
    void buildingGrid(std::vector<std::vector<double>> poses,
                      std::vector<std::vector<double>> ranges,
                      std::vector<std::vector<int>> & grid);

    const double MAX_RANGE_OF_SENORS = 2.5;
    const int GRID_WIDTH = 50;
    //Used to identify current sensor(0-7)
    const int DEGREE_MULTIPLIER = 45;

};

#endif //OCCUPANCY_GRID_OOP_GRID_H
