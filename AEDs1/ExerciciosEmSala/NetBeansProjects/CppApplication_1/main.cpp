#include <iostream>

using namespace std;

void bubblesort(int v[], int n){
  cout << " Execução do Algoritmo BubbleSort." << endl;
}

void insertionsort(int v[], int n){
  cout << " Execução do Algoritmo InsertionSort." << endl;
}

void selectionsort(int v[], int n){
  cout << " Execução do Algoritmo SelectionSort." << endl;
}

void imprimevetor(int v[], int n){
  for (int i = 0; i < n; i++)
    cout << "  " << v[i];
  cout << endl;
}

int main(int argc, char**argv){

  cout << endl << " Métodos de Ordenação" << endl << endl;

  int vb0[10] = {0,1,2,3,4,5,6,7,9,8}; // Vetor ordenado.
  int vb1[10] = {5,8,2,0,6,9,1,4,3,7}; // Vetor desordenado.
  int vb2[10] = {9,8,7,6,5,4,3,2,1,0}; // Vetor em ordem inversa.

  cout << " Bubble Sort, vetor ordenado: " << endl;
  imprimevetor(vb0, 10);
  bubblesort(vb0, 10);
  imprimevetor(vb0, 10);

  cout << " Bubble Sort, vetor desordenado: " << endl;
  imprimevetor(vb1, 10);
  bubblesort(vb1, 10);
  imprimevetor(vb1, 10);

  cout << " Bubble Sort, vetor em ordem inversa: " << endl;
  imprimevetor(vb2, 10);
  bubblesort(vb2, 10);
  imprimevetor(vb2, 10);

  return 0;
}