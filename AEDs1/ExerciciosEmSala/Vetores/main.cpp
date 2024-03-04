#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    float notas[10] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, media, vetor[10];
    int x, i, z, y, a, b, c, d;
    
    x = 0;
    i = 0;
    
    while(x < 10){        
        cout << "Valor na posição "<< x+1 << ": " << notas[x] << endl;
        x++;
    }
    
    for(i = 0; i < 10; i++){
        cout << endl << "Valor na posição "<< i+1 << ": " << notas[i];
    }
    
    media = 0;
    z = 0;
    while(z < 10){
        media = media + notas[z];
        z++;
    }
    media = media/10;
    cout << endl << "Média dos valores do vetor 'notas': " << media << endl;
    
    y = 0;
    while(y < 10){
        if(media < notas[y]){
            cout << endl << "O valor na posição " << y << " é acima da média: " << notas[y];
        }
        y++;
    }
    cout << endl << endl;
    
    a = 0;
    b = 9;
    while(a < 10){
        vetor[a] = notas[b];
        cout << " " << vetor[a];
        a++;
        b--;
    }
    cout << endl << endl;
    
    c = 9;
    for(d = 0; d < 10; d++){
        vetor[d] = notas[c];
        cout << " " << vetor[d];
        c--;
    }
    
    return 0;
}

