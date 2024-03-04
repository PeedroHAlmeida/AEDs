/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: pedro
 *
 * Created on 30 de junho de 2023, 13:44
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    int n, m, j, aux, vet[4000], i, y, x, novotamanho, cont1, cont2, contbbs, contdecrescente, contsct, continsrt, menor, posicao, troca, valor;
    
        ofstream contadores ("contadores.txt");
	if(!contadores.is_open()){
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
        cout << "Digite um valor de separação: ";
        cin >> valor;
    
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
    
	cout << endl << endl << "Vetor em ordem aleatório e sem repetições" << endl;
	cont2 = 0;
	while(cont2 < novotamanho){
            cout << vet[cont2] << " ";
            cont2++;
	}
        
        contbbs = 0;
        for(i = 0; i < novotamanho; i++){
            contbbs++;
            for(j = i+1; j < novotamanho; j++){
                contbbs++;
                if(vet[i] > vet[j]){
                    aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                }
            }
        }
        
        cout << endl << endl << "Vetor ordenado crescente boubble sort" << endl;
	cont2 = 0;
        ofstream crescentebbs ("crescentebbs.txt");
	if(!crescentebbs.is_open()){
            cout << "\nErro: Arquivo nao encontrado.\n";
            return 1;
	}
	while(cont2 < novotamanho){
            crescentebbs << vet[cont2] << endl;
            cout << vet[cont2] << " ";
            cont2++;
	}
        crescentebbs << endl << "Contador bbs: " << contbbs;
        
        cout << endl << endl << "Vetor ordenado crescente insertion sort" << endl;
	cont2 = 0;
        ofstream insertion ("inserion.txt");
	if(!insertion.is_open()){
            cout << "\nErro: Arquivo nao encontrado.\n";
            return 1;
	}
        
        continsrt = 0;
        for(i = 0; i < novotamanho-1; i++){
            continsrt++;
            for(j = i+1; j > 0; j--){
                continsrt++;
                if(vet[j] < vet[j-1]){
                    aux = vet[j];
                    vet[j] = vet[j-1];
                    vet[j-1] = aux;
                }
            }
        }
        
	while(cont2 < novotamanho){
            insertion << vet[cont2] << endl;
            cout << vet[cont2] << " ";
            cont2++;
	}
        insertion << endl << "Contador insertion: " << continsrt;
        
        cout << endl << endl << "Vetor ordenado crescente selection sort" << endl;
	cont2 = 0;
        ofstream selection ("selection.txt");
	if(!selection.is_open()){
            cout << "\nErro: Arquivo nao encontrado.\n";
            return 1;
	}
        
        contsct = 0;
        for(i = 0; i < novotamanho-1; i++){
            menor = vet[i];
            posicao = i;
            troca = false;
            contsct++;
            for(j = i+1; j < novotamanho; j++){
                contsct++;
                if(vet[j] < menor){
                    menor = vet[j];
                    posicao = j;
                    troca = true;
                }
            }
            if(troca){
                aux = vet[i];
                vet[i] = menor;
                vet[posicao] = aux;
            }
        }
        
	while(cont2 < novotamanho){
            selection << vet[cont2] << endl;
            cout << vet[cont2] << " ";
            cont2++;
	}
        selection << endl << "Contador selection: " << contsct;
        
        cout << endl << endl << "Vetor ordenado decrescente" << endl;
	cont2 = 0;
        ofstream decrescente ("decrescente.txt");
	if(!decrescente.is_open()){
            cout << "\nErro: Arquivo nao encontrado.\n";
            return 1;
	}
        
        contdecrescente = 0;
        for(i = 0; i < novotamanho; i++){
            contdecrescente++;
            for(j = i+1; j < novotamanho; j++){
                contdecrescente++;
                if(vet[i] < vet[j]){
                    aux = vet[i];
                    vet[i] = vet[j];
                    vet[j] = aux;
                }
            }
        }
        
	while(cont2 < novotamanho){
            decrescente << vet[cont2] << endl;
            cout << vet[cont2] << " ";
            cont2++;
	}
        decrescente << endl << "Contador decrescente: " << contdecrescente;
        cout << endl << endl << "Valor do novo tamanho do vetor: " << novotamanho;
        
       


	return 0;
}


