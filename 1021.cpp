
#include <bits/stdc++.h>

int main() {
    //le entrada
    //divide pelo valor e depois pega só o mod daquele valor
    //repete por outro valor
    double valor1;    
    scanf("%lf", &valor1);
    int valor = (int)(valor1 * 100);
    int notas[6] = {10000, 5000, 2000, 1000, 500, 200};
    int n_usadas[6];
    int moedas[6] = {100, 50, 25, 10, 5, 1};
    int m_usadas[6];

    printf("NOTAS:\n");
    for(int i = 0; i < 6; i++){
        n_usadas[i] = valor/ notas[i];
        valor = valor % notas[i];
        printf("%d nota(s) de R$ %d.00\n", n_usadas[i], notas[i]/100);
    }
    printf("MOEDAS:\n");
    for(int  i = 0; i < 6; i++){
        m_usadas[i] = valor/ moedas[i];
        valor = valor % moedas[i];
        printf("%d moeda(s) de R$ %.2f\n", m_usadas[i], (double)moedas[i] / 100);

    }
    return 0;
}