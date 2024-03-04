#include <cstdlib>
#include <iostream>
#include <fstream>
#include <valarray>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {

    float x1, y1, x2, y2, valor, distancia;
    
    ifstream coordenadas ("coordenadas.txt");
    if(!coordenadas.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    coordenadas >> valor;
    x1 = valor;
    coordenadas >> valor;
    y1 = valor;
    coordenadas >> valor;
    x2 = valor;
    coordenadas >> valor;
    y2 = valor;
    
    coordenadas.close();
    
    distancia = sqrt(((x1 - y1)*(x1 - y1))+((x2 - y2)*(x2 - y2)));
            
    cout << "Valor da distancia = " << distancia;
    

    return 0;
}

