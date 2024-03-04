#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    char nome[30], sobrenome[30], nome2[30], nomecompleto[60];
    int i, g, f;
    
    nome[0] = 'P';
    nome[1] = 'e';
    nome[2] = 'd';
    nome[3] = 'r';
    nome[4] = 'o';
    nome[5] = '\0';
    
    cout << nome;
    
    sobrenome[0] = 'A';
    sobrenome[1] = 'l';
    sobrenome[2] = 'm';
    sobrenome[3] = 'e';
    sobrenome[4] = 'i';
    sobrenome[5] = 'd';
    sobrenome[6] = 'a';
    sobrenome[7] = '\0';
    
    cout << " " << sobrenome << endl << endl;;
    
    i = 0;
    while(nome[i] != '\0'){
        nomecompleto[i] = nome[i];
        nome2[i] = nome[i];
        i++;
    }
    nome2[i] = '\0';
    
    nomecompleto[i] = ' ';
    i++;
    
    g = 0;
    while(sobrenome[g] != '\0'){
        nomecompleto[i] = sobrenome[g];
        i++;
        g++;
    }
    
    nomecompleto[i] = '\0';
    
    cout << nomecompleto << endl << endl;
    
    
    f = 0;
    while(nome[f] == nome2[f] && nome[f] != '\0' && nome2[f] != '\0'){
        f++;
    }
    
    if(nome[f] == '\0' && nome2[f] == '\0'){
        cout << "Os vetores são iguais!";
    }else{
        cout << "Os vetores são diferentes :(";
    }
    
    
    
    return 0;
}

