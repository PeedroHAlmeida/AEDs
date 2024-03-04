/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Autores: Pedro Henrique de Almeida - 2022.1.08.045 e João Pedro Bueno Lellis - 2022.1.08.046
 * Matéria: AEDS-I Trabalho 1
 *  
 * Criado no dia 23 de maio de 2023, 17:07
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    
    float Hatch, SUV, Pickup, Passeio, Van, Seda, Autodraulica, ano, valor, numero, menorvalor, quilometragem, maiorvalor, mediakm, contadorkm, geral;
    string modelo, marca, tipo, potencia, combustivel, cambio, direcao, cor, portas, placa, placamenor, placamaior;
    
    ifstream dados ("BD_veiculos.txt");
    if(!dados.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    Hatch = 0; //Contador de tipo de carros
    SUV = 0;
    Pickup = 0;
    Passeio = 0;
    Van = 0;
    Seda = 0;
    
    Autodraulica = 0; //Contador de carros automáticos e com direção hidráulica
    
    menorvalor = 10000000; //Variável para calcular o veículo de menor valor
    
    maiorvalor = 0;  //Variável para calcular o veículo de maior valor
    
    mediakm = 0; //Somador de quilometragem para média 
    contadorkm = 0; //Contador de veículos com 5 anos ou mais
    
    geral = 0; //Contador geral
    
    
    dados >> modelo;    //Entrada while
    while(modelo != "FIM"){
        dados >> marca;
        dados >> tipo;       
        dados >> ano;
        dados >> quilometragem;
        dados >> potencia;
        dados >> combustivel;
        dados >> cambio;
        dados >> direcao;
        dados >> cor;
        dados >> portas;
        dados >> placa;
        dados >> valor;   
        
        if(tipo == "Hatch"){        //Calculo dos tipos de veículos
            Hatch++;
        }else if(tipo == "SUV"){
            SUV++;
        }else if(tipo == "Pick-up"){
            Pickup++;
        }else if(tipo == "Passeio"){
            Passeio++;
        }else if(tipo == "Van"){
            Van++;
        }else{
            Seda++;
        }
        
        if(cambio == "Automático" && direcao == "Hidráulica"){    //Calculo dos veículos com câmbio automático e direção hidráulica
            Autodraulica++;
        }
        
        if(potencia == "1.0"){           //Calculo do veículo de menor valor com motor de potência de 1.0
            if(valor < menorvalor){
                menorvalor = valor;
                placamenor = placa;
            }
        }
        
        if(direcao == "Hidráulica" && combustivel == "Flex"){     //Calculo do veículo de maior valor com direção hidráulica e combustivel flex
            if(valor > maiorvalor){
                maiorvalor = valor;
                placamaior = placa;
            }
        }
        
        if(ano <= 2018){         //Calculo da media de quilometragem dos veículos com 5 anos ou mais
            mediakm = mediakm + quilometragem;
            contadorkm++;
        }
        
        dados >> modelo;  //Comparação while
        geral++;
    }
    dados.close();
    
    cout << "Porcentagem de veiculos Hatch: " << (Hatch/geral)*100 << "%" << endl;
    cout << "Porcentagem de veiculos SUV: " << (SUV/geral)*100 << "%" << endl;
    cout << "Porcentagem de veiculos Pick-up: " << (Pickup/geral)*100 << "%" << endl;
    cout << "Porcentagem de veiculos Passeio: " << (Passeio/geral)*100 << "%" << endl;
    cout << "Porcentagem de veiculos Van: " << (Van/geral)*100 << "%" << endl;
    cout << "Porcentagem de veiculos Sedã: " << (Seda/geral)*100 << "%" << endl << endl;
    
    cout << "Porcentagem de veículos com câmbio automático e com direção hidráulica entre todos os veículos: " << (Autodraulica/geral)*100 << "%" << endl << endl;
    
    cout << "Placa e valor do veiculo mais barato com totencia do motor igual a 1.0. Placa: " << placamenor << " e Valor: R$" << menorvalor << endl << endl;
    
    cout << "Placa e valor do veiculo mais caro com direção hidráulica e com combustivel flex. Placa: " << placamaior << " e Valor: R$" << maiorvalor << endl << endl;
    
    cout << "Quantidade média de quilometragem dos veiculos com 5 anos ou mais: " << mediakm/contadorkm << "Km" << endl;
    
    return 0;
}

//(1,49⁴⁸*valorcarro)/48
//0,066*valorcarro