/*
 *
 * @author Richard Price-Jones (rij12)
 *
 */


#include <tgmath.h>
#include <fstream>
#include <stdlib.h>
#include "Robot.h"

Robot::Robot() {
    readPosesData(poses);
    readRangeData(ranges);
}

Robot::~Robot() {

}

double Robot::getCellIndexX(double x){
    return round((x / 0.2) + GRID_OFF_SET );
}

double Robot::getCellIndexY(double y){
    return round((y / 0.2) + GRID_OFF_SET );
}

double Robot::getXCoordinate (double x_r, double sensors_range, double senor_alpha, double senor_beta){

    double absolute_x;
    absolute_x = x_r + sensors_range * cos(convertToRadians(senor_alpha + senor_beta));
    return absolute_x;
}

double Robot::getYCoordinate(double y_r, double sensors_range, double senor_alpha, double senor_beta){

    double absolute_y;
    absolute_y = y_r + sensors_range * sin(convertToRadians(senor_alpha + senor_beta));
    return absolute_y;
}

 double Robot::convertToRadians (double degrees){
    return   degrees / RADS_TO_DEGREES;
}

const vector<vector<double>> & Robot::getPoses(){
    return Robot::poses;
}

const vector<vector<double>> & Robot::getRanges() {
    return Robot::ranges;
}

void Robot::readRangeData(vector<vector<double> > & ranges) {

    //First we need a file object
    std::ifstream inFile;
    //File name
    string filename = "ranges_data.txt";
    double count = 0;
    inFile.open(filename);

    //Check if the file can be open

    if (!inFile.is_open()) {
        cout << "file could not be opened " << filename << endl;
        cout << "Program terminating. " << endl;
        exit(EXIT_FAILURE);
    }

    while (inFile.good()) {
        count++;
        // Define temp Vector
        double temp;

        //Fill inner Vector.
        for (int i = 0; i < 40; i++) {
            vector<double> tempVector;
            for (int j = 0; j <= 7; j++) {
                inFile >> temp;
                tempVector.push_back(temp);
            }

            // Now push back the temp vector into the main vector.
            ranges.push_back(tempVector);
        }
    }
    if (count == 0) {
        cout << "No data was read" << endl;
    }
    inFile.close();
}

void Robot::readPosesData(vector<vector<double>> & poses) {


    // First we need a file object
    std::ifstream inFile;
    // file name
    string filename = "poses_data.txt";
    // Temp data
    double temp;
    // DEBUGGING INFORMATION
    double count = 0;
    //Open the file

    inFile.open(filename);

    // Check if the file can be open

    if (!inFile.is_open()) {
        cout << "file could not be opened " << filename << endl;
        cout << "Program terminating. " << endl;
        exit(EXIT_FAILURE);
    }
    while (inFile.good()) {
        count++;
        // Get the value from the text file.
        // Loops though outer vector
        for (int i = 0; i < 40; i++) {
            vector<double> tempVector;
            // Loops though Inner vector
            for (int j = 0; j < 3; j++) {
                inFile >> temp;
                tempVector.push_back(temp);
            }
            // Now push back the temp vector into the main vector.
            poses.push_back(tempVector);
        }
        cout << "PoseData NO. " << count << endl;
    }
    if (count == 0) {
        cout << "No data was read" << endl;
    }
    inFile.close();
}