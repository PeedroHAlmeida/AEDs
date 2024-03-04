#include <cstdlib>
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
    
    float tempcel, tempfah, incremento;
    
    tempcel = 0;
    incremento = 0;
    
    printf("\tDigite um valor de 1 a 10 para o incremento: ");
    scanf("%f", &incremento);
    while(incremento < 1 || incremento > 10){
        printf("\tErro, digite um numero entre 1 e 10: ");
        scanf("%f", &incremento);
    }    

    printf("\tGraus C - Graus F\n");
    while(tempcel <= 100){
        tempfah = tempcel*9/5+32;
        printf("\t%.0fC - %.2fF\n", tempcel, tempfah);
        tempcel = tempcel + incremento;
    }
    
    return 0;
}

