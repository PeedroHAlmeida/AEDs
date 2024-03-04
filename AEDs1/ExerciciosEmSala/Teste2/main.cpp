#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {
    
    int i;

    for(i = 0; i < 100; i++){
        cout << rand()%10 << endl;
    }

    return 0;
}