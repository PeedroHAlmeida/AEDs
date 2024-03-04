#include <cstdlib>
#include <iostream>
#include <fstream>
#include <valarray>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    
    ifstream cena ("cena.txt");
    if(!cena.is_open()){
        cout << "\nErro: Arquivo nao encontrado.\n";
        return 1;
    }
    
    float cubo, esfera, cilindro, pi, altura, raio, a, b, c, bases, geratriz;
    float area_paralelepipedo, vol_paralelepipedo, area_cubo, vol_cubo, area_cilindro, vol_cilindro, area_esfera, vol_esfera, vol_piramideb4, area_piramideb4, vol_total, area_total, vol_cone, area_cone;
    string objeto;
    double f;
    
    pi = 3.14159;
    
    cout << fixed << setprecision(2);
    cena >> objeto;
    while(objeto != "fim"){
        
        if(objeto == "cubo"){
            cena >> a;
            vol_cubo = pow(a, 3);
            vol_total = vol_total + vol_cubo;
            area_cubo = 12*a;
            area_total = area_total + area_cubo;
            cout << "Volume do cubo = " << vol_cubo << endl;
            cout << "Área do cubo = " << area_cubo << endl << endl;
        }else if(objeto == "cilindro"){
            cena >> raio;
            cena >> altura;
            vol_cilindro = pi * pow(raio, 2) * altura;
            vol_total = vol_total + vol_cilindro;
            area_cilindro = 2*pi*raio*(raio + altura);
            area_total = area_total + area_cilindro;
            cout << "Volume do cilindro = " << vol_cilindro << endl;
            cout << "Área do cilindro = " << area_cilindro << endl << endl;
        }else if(objeto == "esfera"){
            cena >> raio;
            vol_esfera = 4/3 * pi * pow(raio, 3);
            vol_total = vol_total + vol_esfera;
            area_esfera = 4 * pi * pow(raio, 2);
            area_total = area_total + area_esfera;
            cout << "Volume da esfera = " << vol_esfera << endl;
            cout << "Área do esfera = " << area_esfera << endl << endl;
        }else if(objeto == "paralelepipedo"){
            cena >> a;
            cena >> b;
            cena >> c;
            area_paralelepipedo = a*b*c;
            area_total = area_total + area_paralelepipedo;
            vol_paralelepipedo = 2*a*b + 2*b*c + 2*a*c;
            vol_total = vol_total + vol_paralelepipedo;
            cout << "Volume do paralelepipedo = " << vol_paralelepipedo << endl;
            cout << "Área do paralelepipedo = " << area_paralelepipedo << endl << endl;
        }else if(objeto == "cone"){
            cena >> raio;
            cena >> altura;
            cena >> geratriz;
            vol_cone = (pi*pow(raio, 2)*altura)/3;
            vol_total = vol_total + vol_cone;
            area_cone = pi*raio*(raio*geratriz);        // revisar, algo pode estar errado (cone)
            area_cone = area_total + area_cone;
            cout << "Volume do cone = " << vol_cone << endl;
            cout << "Área do cone = " << area_cone << endl << endl;
        }else if(objeto == "piramide_base_quadrada"){
            cena >> a;
            cena >> altura; 
            cena >> bases;
            vol_piramideb4 = pow(a, 2) * (altura/3);
            vol_total = vol_total + vol_piramideb4;
            area_piramideb4 = pow(a, 2) + bases;                                               //A área lateral é calculada pelo número de lados da base multiplicado pela área da face lateral, que é um trapézio.
            area_total = area_total + area_piramideb4;
            cout << "Volume da piramide de base quadrada = " << vol_piramideb4 << endl;        //O volume da pirâmide é calculado pelo produto entre a área da base e a altura dividido por três
            cout << "Área da piramide de base quadrada = " << area_piramideb4 << endl << endl;        
        }else{
            cout << "Não trabalhamos com " << objeto << ", apenas com cubo, cilindro, esfera, paralelepipedo, cone e piramide de base quadrada" << endl << endl;
        }
        cena >> objeto;
    }
    cena.close(); 
    
    cout << "Volume total = " << vol_total << endl;
    cout << "Área total = " << area_total << endl;
   
    return 0;
}

