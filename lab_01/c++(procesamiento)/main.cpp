#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <random>
using namespace std;

double distancia_formula(const vector<double>& punto1, const vector<double>& punto2) {
    double sumaCuadrados = 0.0;

    for (size_t i = 0; i < punto1.size(); ++i) {
        double diferencia = punto1[i] - punto2[i];
        sumaCuadrados += diferencia * diferencia;
    }
    return sqrt(sumaCuadrados);
}
void calcularYGuardar(const vector<vector<double>>& puntos, const string& dimension) {
    ofstream archivo("datos_dimension_"+dimension+".txt");
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return;
    }
    for (size_t i = 0; i < puntos.size(); ++i) {
        for (size_t j = i + 1; j < puntos.size(); ++j) {
            double distancia = distancia_formula(puntos[i], puntos[j]);
            archivo<<distancia<<endl;
        }
    }
    archivo.close();
}
auto crear_datos(int p,int dimensiones){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    vector<vector<double>>datos;
    for(int i=0;i<p;i++){
        vector<double> punto;
        for(int j=0;j<dimensiones;j++){
            punto.push_back(dis(gen));
        }
        datos.push_back(punto);
    }
    return datos;
}

int main() {
    int p=100;
    vector<int>dimensiones={10, 50, 100, 500, 1000, 2000, 5000};
    vector<string> demensiones_cadena;
    for (int dimension : dimensiones) {
        string cadena = to_string(dimension);
        demensiones_cadena.push_back(cadena);
    }
    for(int i=0;i<dimensiones.size();i++){
        vector<vector<double>> puntos = crear_datos(p,dimensiones[i]);
        calcularYGuardar(puntos, demensiones_cadena[i]);
    }

    return 0;
}
