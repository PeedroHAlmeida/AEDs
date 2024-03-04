#include <cstdlib>
#include <iostream>
#include <fstream>
#include <valarray>

using namespace std;

int main(int argc, char** argv) {
    
    float altura, pessoas, masculino, feminino, PessoasMaior180, MediaHomem, MulherMenor170;
    string pessoa;
    
    ifstream dados ("dados.txt");
    if(!dados.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }

    altura = 1;
    masculino = 0;
    feminino = 0;
    PessoasMaior180 = 0;
    MulherMenor170 = 0;
    pessoas = 0;
    while(altura != 0){
        dados >> pessoa;
        if(pessoa == "m"){
            masculino++;
            pessoas++;
        }else if(pessoa == "f"){
            feminino++;
            pessoas++;
        }else{
            cout << "Sexo nao correspondente" << endl;
        }
        dados >> altura;
        if(altura != 0){
            if(pessoa == "m"){
                MediaHomem = MediaHomem + altura;
            }
            if((pessoa == "m" || pessoa == "f") && altura > 1.8){
                PessoasMaior180++; 
            }
            if(pessoa == "f" && altura <= 1.7){
                MulherMenor170++;
            }
        }
    }
        
    cout << "Porcentagem de pessoas maior que 1.80m = " << (PessoasMaior180/pessoas)*100 << "%" << endl;
    cout << "Média de altura dos homens = " << MediaHomem/masculino << endl;
    cout << "Porcentagem de mulheres menores que 1.70m entre todas as pessoas = " << (MulherMenor170/pessoas)*100 << "%";
    
    return 0;
}

