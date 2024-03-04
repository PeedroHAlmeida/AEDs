#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    float valor, media, soma, registro, maior, menor;
    ifstream teclado ("salve.txt");
    if (!teclado.is_open()){
        cout << "\nErro: Arquivo não encontrado. \n";
        return 1;
    }
    
    soma = 0;
    registro = 0;
    
    teclado >> valor;
    maior = menor = valor;
    while ( valor != 0){
        cout << "valor: " << valor << endl;       
        soma = soma + valor;
        registro ++;
        if(valor > maior)
            maior = valor;
        if(valor < menor)
            menor = valor;
        teclado >> valor;
    }
    
           
    if(registro != 0){
        media = soma/registro;
        cout << "\nA média dos valores é: " << media;
        }
        cout << "\nO maior valor é: " << maior;
        cout << "\nO menor valor é: " << menor;
 
    teclado.close();
    
    return 0;
}
