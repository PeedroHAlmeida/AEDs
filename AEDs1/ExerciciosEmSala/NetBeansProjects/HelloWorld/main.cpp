#include <cstdlib>
#include <stdio.h>

using namespace std;


int main(int argc, char** argv) {
    
    
    float nota1 = 8, nota2 = 7, trabalho = 7;
    
    printf("Digite o valor da nota 1: ");
    scanf(" %f", &nota1);
    printf("Digite o valor da nota 2: ");
    scanf(" %f", &nota2);
    printf("Digite a nota do trabalho: ");
    scanf(" %f", &trabalho);
    
    printf("\n\tHello World!!!\n\n");
    printf("\n\tNota de AEDs : %.2f\n\n", (3*nota1+3*nota2+4*trabalho)/10);
    
    return 0;
}

