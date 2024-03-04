#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    float vet1[10] = {4,1,8,2,5,7,6,9,54,3};
    int a, menorvalor, maiorvalor, b, c, posicao;
    
    a = 0;
    menorvalor = maiorvalor = vet1[a];
    while(a < 10){
        if(vet1[a] < menorvalor){
            menorvalor = a;
        }
        if(vet1[a] > maiorvalor){
            maiorvalor = a;
        }
        a++;
    }
    cout << "Posição do maior valor: " << maiorvalor << endl;
    cout << "Posição do menor valor: " << menorvalor << endl << endl;
    
    cout << "Digite um numero: ";
    cin >> b;
    
    c = 0;
    posicao = -3;
    while(c < 10 && posicao != c-1){
        if(vet1[c] == b){
            posicao = c;
            cout << "Valor na posição: " << posicao;
        }
        c++;
    }
    if(posicao == -3){
        cout << "Valor não encontrado :( ";
    }
    

    return 0;
}

