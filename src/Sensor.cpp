
#include "./Sensor.h"
#include "../vendor/lista.h"

using namespace std;


Sensor::Sensor(const Sensor & c){
    nombre = c.nombre;
	mediciones = c.mediciones;
}

Sensor const & Sensor::operator=(Sensor const &c) {
	nombre = c.nombre;
	mediciones = c.mediciones;
	return *this;
}

bool operator==(Sensor const &x, Sensor const &y) {
	bool b = (x.nombre != y.nombre || x.mediciones != y.mediciones) ? false : true;
	return b;
}

istream & operator>>(istream &is, Sensor &c) {
	int good = false;
	int bad  = false;
	string nombre = "";
	double medicion = 0;
	char ch = 0;

    // Si es una letra, se esta leyendo nombre del sensor
	if (is >> ch
	    && isalpha(ch) ) {
        is.putback(ch);
		if ( getline(is,nombre,',')){
            c.nombre= nombre;
            good = true;
        }			
		else
			bad = true;
	} else if (is.good()) {
		is.putback(ch);

        // Si no era letra, chequeo si es numero (medicion)
		if (is >> medicion
		    && is >> ch
		    && ch == ',')
			good = true;
		else
			bad = true;
	}

	if (good)
		c.mediciones.push_back(medicion);
	if (bad)
		is.clear(ios::badbit);

	return is;
}