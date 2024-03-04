#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define TAM 10

using namespace std;

int main(int argc, char** argv) {

    ifstream texto ("texto.txt");
    if(!texto.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    int cont1, cont2, x, y, l, novotamanho;
    float vet1[novotamanho], valor;   
    
    cont1 = 0;
    while(cont1 < TAM){
        texto >> valor;
        vet1[cont1] = valor;
        cout << vet1[cont1] << " ";
        cont1++;
    }
    
    y = 0;
    x = 1;
    novotamanho = TAM;
    while(y < novotamanho){
        while(x < novotamanho){
            if(vet1[y] == vet1[x]){
                novotamanho = novotamanho - 1;
                cont2 = x;
                while(cont2 < novotamanho){
                    vet1[cont2] = vet1[cont2 + 1];
                    cont2++;
                }
            }
            x++;
        }       
        y++;
        x = y+1;
    }
    
    cout << endl << endl;
    cont1 = 0;
    while(cont1 < novotamanho){
        cout << vet1[cont1] << " ";
        cont1++;
    }
    
    
    return 0;
}

