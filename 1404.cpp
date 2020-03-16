#include <bits/stdc++.h>

int n, m;
int ori[21][21];

int caminho(int i, int j, int tab[21][21]){
    int copy[21][21];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            copy[i][j] =  tab[i][j];
        }
    }

    int a = 0, b = 0, c = 0, d = 0;
        
    if(i+2 < n and j+2 < m and tab[i+1][j+1] == 2 and tab[i+2][j+2] == 0){
        tab[i+1][j+1] = 0;
        tab[i][j] = 0;
        a = 1 + caminho( i+2, j+2,tab);
    }
    if(i+2 < n and j-2 >= 0 and tab[i+1][j-1] == 2 and tab[i+2][j-2] == 0){
        for(int i = 0; i < n; i++){
            for(int j = i%2; j < m; j+=2){
                tab[i][j] = copy[i][j] ;
            }
        }

        tab[i+1][j-1] = 0;
        tab[i][j] = 0;
        b = 1 + caminho(i+2, j-2, tab);
    }
    if(i-2 >= 0 and j+2 < m and tab[i-1][j+1] == 2 and tab[i-2][j+2] == 0){
        for(int i = 0; i < n; i++){
            for(int j = i%2; j < m; j+=2){
                tab[i][j] = copy[i][j] ;
            }
        }

        tab[i-1][j+1] = 0;
        tab[i][j] = 0;
        c = 1 + caminho(i-2, j+2, tab);
    }
    if(i-2 >= 0 and j-2 >= 0 and tab[i-1][j-1] == 2 and tab[i-2][j-2] == 0){

        for(int i = 0; i < n; i++){
            for(int j = i%2; j < m; j+=2){
                tab[i][j] = copy[i][j] ;
            }
        }

        tab[i-1][j-1] = 0;
        tab[i][j] = 0;
        d = 1 + caminho(i-2, j-2, tab);
    }
    tab[i][j] = 0;
    int v = std::max(std::max(a, b), std::max(c, d));
    return  v;
}

int main() {
    int total = 0;
    int tab[21][21];

    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 and m == 0) break;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                tab[i][j] = 0;
                ori[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = i % 2; j < m; j+=2){
                scanf(" %d", &tab[i][j]);
                ori[i][j] = tab[i][j];
            }
        }
        int max = 0;
        for(int i = 0; i < n; i++){
            for(int j = i % 2; j < m; j+=2){
                if(tab[i][j] == 1){
                    int c = caminho(i, j, tab);
                    if(c > max) max = c;
                    for(int k= 0; k < n; k++){
                        for(int l= k % 2; l < m; l+=2){
                            tab[k][l] = ori[k][l];
                        }
                    }
                }
            }
        }

        std::cout << max << std::endl;


    }
}