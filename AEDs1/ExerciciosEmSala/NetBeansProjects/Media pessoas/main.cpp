#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    float altura, media, pessoas;
    
    pessoas = 0;
    media = 0;
    altura = 0;
    
    while(pessoas < 10){
        printf("\tDigite a altura da pessoa %.0f: ", pessoas+1);
        scanf("%f", &altura);
        while(altura < 0){
            printf("\tAltura invalida! Digite uma altura positiva: ");
            scanf("%f", &altura);
        }
        media = media + altura;
        pessoas++;
    }
    printf("\n\tMedia = %.2f",media/10);

    return 0;
}

