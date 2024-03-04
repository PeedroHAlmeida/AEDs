#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    int n, m, vet[4000], i, y, x, novotamanho, cont1, cont2;
    
    ofstream texto ("texto.txt");
    if(!texto.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    cout << "Digite um valor para n: ";
    cin >> n;
    cout << "Digite um valor para m: ";
    cin >> m;
    while(m < n){
        cout << "Errro! Digite um valor para m maior ou igual a n: ";
        cin >> m;
    }
    
    vet[0] = n;   
    cout << endl << vet[0] << " ";
    for(i = 1; i < vet[0]; i++){
        vet[i] = rand()%m;
        cout << vet[i] << " ";
    }
    vet[n+1] = '\0';
    
    y = 0;
    x = 1;
    novotamanho = n;
    while(y < novotamanho){
        while(x < novotamanho){
            if(vet[y] == vet[x]){
                novotamanho = novotamanho - 1;
                cont1 = x;
                while(cont1 < novotamanho){
                    vet[cont1] = vet[cont1 + 1];
                    cont1++;
                }
            }
            x++;
        }       
        y++;
        x = y+1;
    }
    
    cout << endl << endl;
    cont2 = 0;
    while(cont2 < novotamanho){
        cout << vet[cont2] << " ";
        texto << vet[cont2] << " ";
        cont2++;
    }


    return 0;
}

