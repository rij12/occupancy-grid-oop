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
    vector getGrid();
    Grid();
    ~Grid();


private:
    void printGrid(std::vector<std::vector<int >>  grid);
    void buildingGrid(std::vector<std::vector<double> > & poses,
                      std::vector<std::vector<double>> & ranges,
                      std::vector<std::vector<int>> & grid);
    const double MAX_RANGE_OF_SENORS = 2.5;
    const int GRID_WIDTH = 50;
    void Grid::intialiseGrid(vector<vector<int >> &grid);
//    double x;
//    double y;

};

#endif //OCCUPANCY_GRID_OOP_GRID_H
