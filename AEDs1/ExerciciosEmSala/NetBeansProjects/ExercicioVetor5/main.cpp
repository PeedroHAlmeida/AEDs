#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    
    ifstream texto ("texto.txt");
    if(!texto.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    float valor;
    int tamanhovetor, cont1, cont2, vet1[tamanhovetor], novotamanho;
    
    cont1 = 0;
    texto >> tamanhovetor;
    while(cont1 < tamanhovetor){
        texto >> valor;
        vet1[cont1] = valor;
        cout << vet1[cont1] << " ";
        cont1++;
    }
    
    cout << endl << "Digite o tamanho do vetor que será utilizado: ";
    cin >> tamanhovetor;
    
    cont2 = 0;
    while(cont2 < tamanhovetor){
        cout << vet1[cont2] << " ";
        cont2++;
    }

    return 0;
}

