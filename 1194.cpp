// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

char pre[2001], in[2001];
int casos, len;
    
void divide(int inicio, int fim, int root){
    char raiz = pre[root];
    if(inicio == fim - 1) {
        std::cout << in[inicio];
        return;
    }
    for(int i = inicio; i < fim; i++){
        if(in[i] == raiz){
            divide(inicio, i, inicio+1);
            divide(i+1, fim, i+1);
            std::cout << raiz;
            return; 
        }
    }
}

int main() {
    scanf(" %d", &casos);
    for(int i = 0; i < casos; i++){
        scanf(" %d %s %s", &len, pre, in);
        divide(0, strlen(pre), 0);
        std::cout  << std::endl;
    }
    return 0;
}