#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>
#include <time.h>

#define MAX_CIDADES 15

typedef struct {
    int x;
    int y;
} Cidade;

// Função para ler os dados de um arquivo .tsp
int lerTSPLIB(const char *nome_arquivo, Cidade cidades[]) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return -1;
    }

    int n = 0;
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (strstr(linha, "NODE_COORD_SECTION") != NULL) {
            while (fgets(linha, sizeof(linha), arquivo)) {
                if (linha[0] == 'E') break; // Termina quando encontrar a linha 'EOF'
                sscanf(linha, "%d %d %d", &n, &cidades[n].x, &cidades[n].y);
            }
        }
    }
    fclose(arquivo);
    return n;
}

// Função para calcular a distância euclidiana entre duas cidades
double calcularDistancia(Cidade a, Cidade b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Função para calcular a distância total de uma permutação
double calcularDistanciaTotal(Cidade cidades[], int perm[], int n) {
    double distanciaTotal = 0;
    for (int i = 0; i < n - 1; i++) {
        distanciaTotal += calcularDistancia(cidades[perm[i]], cidades[perm[i + 1]]);
    }
    distanciaTotal += calcularDistancia(cidades[perm[n - 1]], cidades[perm[0]]); // Voltar à cidade inicial
    return distanciaTotal;
}

// Declarações das funções
int next_permutation(int* begin, int* end);
void reverse_array(int* begin, int* end);

// Função para gerar todas as permutações e calcular a menor distância
void calcularRotaMinima(Cidade cidades[], int n) {
    int perm[MAX_CIDADES];
    double menorDistancia = DBL_MAX;
    int melhorRota[MAX_CIDADES];

    // Inicializa a permutação
    for (int i = 0; i < n; i++) {
        perm[i] = i;
    }

    // Medir tempo de início
    clock_t inicio = clock();

    // Algoritmo de força bruta para todas as permutações
    do {
        double distanciaAtual = calcularDistanciaTotal(cidades, perm, n);
        if (distanciaAtual < menorDistancia) {
            menorDistancia = distanciaAtual;
            for (int i = 0; i < n; i++) {
                melhorRota[i] = perm[i];
            }
        }
    } while (next_permutation(perm, perm + n));

    // Medir tempo de fim
    clock_t fim = clock();
    double tempo_segundos = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibe a melhor rota e a distância total
    printf("Melhor Rota: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", melhorRota[i]);
    }
    printf("%d\n", melhorRota[0]); // Retorno à cidade inicial

    printf("Distância Total: %.2f\n", menorDistancia);
    printf("Tempo de processamento: %.2f segundos\n", tempo_segundos);
}

// Função para gerar a próxima permutação lexicograficamente
int next_permutation(int* begin, int* end) {
    int* i = end;
    if (begin == end || begin + 1 == end)
        return 0;
    i--;
    while (1) {
        int* j = i;
        i--;
        if (*i < *j) {
            int* k = end;
            while (!(*i < *--k));
            int temp = *i;
            *i = *k;
            *k = temp;
            reverse_array(j, end);
            return 1;
        }
        if (i == begin) {
            reverse_array(begin, end);
            return 0;
        }
    }
}

// Função para inverter a ordem de elementos entre dois ponteiros
void reverse_array(int* begin, int* end) {
    while ((begin) < --end) {
        int temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
    }
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int n = lerTSPLIB("testes/teste1.tsp", cidades);

    if (n < 2) {
        printf("Número de cidades inválido\n");
        return 1;
    }

    printf("\n--- ALGORITIMO DE FORÇA BRUTA ---\n");
    printf("Número de cidades: %d\n", n);
    printf("Calculando a melhor rota...\n");
    calcularRotaMinima(cidades, n);

    return 0;
}
