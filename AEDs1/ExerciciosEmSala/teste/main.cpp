#include <cstdlib>
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

int main(int argc, char** argv) {
    
    int pessoas;
    float altura, media, soma, menor, maior, valor;
    
    ifstream dados ("dados.txt");
    if(!dados.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    pessoas = -1;
    soma = 0;
    menor = 100000000000;
    maior = 0;
    
    dados >> altura;
    while (altura != 0){        
        soma = soma + altura;
        if (altura != 0);        
            pessoas++;       
            if (menor > altura && altura != 0){
                menor = altura;
            }
            if (maior < altura){
                maior = altura;
            }
    }
    dados.close();
    
    media = soma/pessoas;
    cout << "\n\tMédia das alturas = " <<  media << endl;
    cout << "\n\tMenor valor das alturas = " << menor << endl;
    cout << "\n\tMaior valor das alturas = " << maior << endl;

    return 0;
}
