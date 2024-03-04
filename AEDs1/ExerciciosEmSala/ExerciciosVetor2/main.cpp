#include <cstdlib>
#include <iostream>
#include <fstream>

#define TAM 10

using namespace std;

int main(int argc, char** argv) {
    
    ifstream texto ("texto.txt");
    if(!texto.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    float vet1[TAM], vet2[TAM], vet3[TAM], numero;
    int cont1, cont2, cont3;
    
    texto >> numero;
    for(cont1 = 0; cont1 < TAM; cont1++){
        vet1[cont1] = numero;
        cout << vet1[cont1] << " ";
        texto >> numero;       
    }
    
    cout << endl;
    for(cont2 = 0; cont2 < TAM; cont2++){
        vet2[cont2] = numero;
        cout << vet2[cont2] << " ";
        texto >> numero;       
    }
    
    cout << endl << endl;
    for(cont3 = 0; cont3 < TAM; cont3++){
        vet3[cont3] = vet1[cont3] + vet2[cont3];
        cout << vet3[cont3] << " "; 
    }
    
    

    return 0;
}

