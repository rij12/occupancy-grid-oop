//
// Created by rich on 11/03/16.
//

#ifndef OCCUPANCY_GRID_OOP_ROBOT_H
#define OCCUPANCY_GRID_OOP_ROBOT_H

#include <ostream>
#include <vector>
#include <iostream>
using std::cout;
using std:: endl;
using std::cin;
using std::vector;
using std::string;
class Robot {

public:
    Robot();
    ~Robot();
    const vector<vector<double>> &getRanges();
    const vector<vector<double>> &getPoses();
    void setPoses(vector<vector<double>> & poses);
    void setRanges(vector<vector<double>> &ranges);
    double getX(double currentGridX, int i, int j, double currentOrientation);
    double getY(double currentGridX, int i, int j, double currentOrientation);


private:
    const double RADS_TO_DEGREES = 57.2958;
    const double GRID_OFF_SET = 0.2;
    std::vector<std::vector<double>> poses;
    std::vector<std::vector<double>> ranges;
    double convert_to_radians(double degrees);
    void readPosesData(std::vector<std::vector<double>> &poses);
    void readRangeData(std::vector<std::vector<double>> &ranges);
    double CellIndexY(double y);
    double CellIndexX(double x);
    double XCoordinate(double x_r, double sensors_range, double senor_alpha, double senor_beta);
    double YCoordinate(double y_r, double senor_range, double senor_alpha, double senor_beta);
};




#endif //OCCUPANCY_GRID_OOP_ROBOT_H
