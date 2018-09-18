#ifndef _SENSOR_MANAGER_H_INCLUDED_
#define _SENSOR_MANAGER_H_INCLUDED_

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./Sensor.h"

using namespace std;

class SensorManager {

    istream *is_;
    ostream *os_;

    vector<Sensor> sensores;

public:
    
    SensorManager(){};
	SensorManager(istream *is, ostream *os): is_(is), os_(os) {};
    ~SensorManager(){};

    void CargarSensores();

    int get_NroSensores();

};

#endif