#include <cstdlib>
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

int main(int argc, char** argv) {
    
    float valor;
    ifstream teclado ("entrada.txt");
    if(!teclado.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    teclado >> valor;
    cout << "valor: " << valor << endl;
    while (valor != 0){
        teclado >> valor;
        cout << "valor: " << valor << endl;
    }
    teclado.close();

    return 0;
}
