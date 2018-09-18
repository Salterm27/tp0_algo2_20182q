#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Sensor {
   

public:
    Sensor(): nombre("") { }
    ~Sensor(){};
    Sensor(const Sensor &);

    Sensor const &operator=(Sensor const &);

    string nombre; 
    vector<double> mediciones;
    
    friend bool operator==(Sensor const &, Sensor const &);
    friend std::istream &operator>>(std::istream &, Sensor &);

};

#endif