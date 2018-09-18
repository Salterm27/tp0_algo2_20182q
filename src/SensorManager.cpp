#include "./SensorManager.h"

using namespace std;


int SensorManager::get_NroSensores(){
    return (int)sensores.size();
}


void SensorManager::CargarSensores(){

	Sensor aux;
    string line;

	getline(*is_, line);
	stringstream linestream(line);

	// La primer linea contiene los nombres de los sensores
	while(linestream >> aux) {
		sensores.push_back(aux);
	}

	// Error de formato en input stream.
	// Detenemos la ejecución del programa.
	if (linestream.bad()) {
		cerr << "Error de formato en los nombres de los sensores" << endl;
		exit(1);
	}     

	getline(*is_, line);
	stringstream linestream2(line);

    //El resto de las lineas contienen las mediciones en orden
    //for(vector<Sensor>::iterator it = sensores.begin(); it != sensores.end(); ++it) {
    for(vector<Sensor>::size_type i = 0; i != sensores.size(); i++) {    
		aux = sensores[i];
        linestream2 >> aux;
		sensores[i] = aux;		
    }    



	// Error de formato en input stream.
	// Detenemos la ejecución del programa.
	if (linestream.bad()) {
		cerr << "Error de formato en las mediciones de los sensores" << endl;
		exit(1);
	}    
}