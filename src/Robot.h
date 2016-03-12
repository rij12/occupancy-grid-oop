//
// Created by rich on 11/03/16.
//

#ifndef OCCUPANCY_GRID_OOP_ROBOT_H
#define OCCUPANCY_GRID_OOP_ROBOT_H

#include <ostream>
#include <vector>
class Robot {

public:
    Robot();
    ~Robot();
    double getX();
    double getY();

private:
    const double RADS_TO_DEGREES = 57.2958;
    const double GRID_OFF_SET = 0.2;
    double XCoordinate (double x_r, double sensors_range, double senor_alpha, double senor_beta);
    double YCoordinate(double y_r, double senor_range, double senor_alpha, double senor_beta);
    double convert_to_radians (double degrees);
    double CellIndexY(double y);
    double CellIndexX(double x);

};


#endif //OCCUPANCY_GRID_OOP_ROBOT_H
