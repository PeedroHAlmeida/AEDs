#include <cstdlib>
#include <iostream>
#include <fstream>

#define TAM 10

using namespace std;

int main(int argc, char** argv) {
    
    float vet1[TAM], vet2[TAM], valor, numero;
    int cont1, cont2, cont3;
    
    ifstream texto ("texto.txt");
    if(!texto.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    texto >> numero;
    cout << "Vetor 1: ";
    for(cont1 = 0; cont1 < TAM; cont1++){
        vet1[cont1] = numero;
        cout << vet1[cont1] << " ";
        texto >> numero;       
    }
    
    cout << endl << "Vetor 2: ";
    for(cont2 = 0; cont2 < TAM; cont2++){
        vet2[cont2] = numero;
        cout << vet2[cont2] << " ";
        texto >> numero;       
    }
    
    cout << endl << endl << "Digite o valor que ira multiplicar o vetor 2 e depois ser somado com o vetor 1: "; 
    cin >> valor;

    cout << endl << "Novo valor do Vetor 1: ";
    for(cont3 = 0; cont3 < TAM; cont3++){
        vet1[cont3] = vet1[cont3] + (vet2[cont3] * valor); //Conta
        cout << vet1[cont3] << " ";
    }
    
    return 0;
}

