#include <cstdlib>
#include <iostream>
#include <fstream>

#define TAM 50

using namespace std;

int main(int argc, char** argv) {
    
    ifstream texto ("texto.txt");
    if(!texto.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    float vet1[TAM], vet2[TAM], numero;
    int menorintervalo, maiorintervalo, cont1, cont2, cont3;
    
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
    
    cout << endl << endl << "Digite o menor valor dos intervalos: ";
    cin >> menorintervalo;
    while(menorintervalo < 0 || menorintervalo > 50){
        cout << "Erro! Digite um valor maior ou igual a 0 e menor que 50: ";
        cin >> menorintervalo;
    }
    cout << endl << "Digite o maior valor dos intervalos: ";
    cin >> maiorintervalo;
    while(menorintervalo > maiorintervalo || maiorintervalo > 50){
        cout << "Erro! Digite um valor maior que " << menorintervalo << " e menor que 50: ";
        cin >> maiorintervalo;      
    }
    
    cont3 = 0;
    while(cont3 < menorintervalo){
        cout << vet1[cont3] << " ";
        cont3++;
    }
    
    while(menorintervalo != maiorintervalo){
        vet1[menorintervalo] = vet2[menorintervalo];
        cout << vet1[menorintervalo] << " ";
        menorintervalo++;
    }
    

    while(maiorintervalo < 50){
        cout << vet1[maiorintervalo] << " ";
        maiorintervalo++;
    }

    return 0;
}

