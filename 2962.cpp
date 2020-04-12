// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

long int group[12345][4];
long int pai[12345];

long int find(long int i)
{
    if (pai[i] == i)
        return i;
    return find(pai[i]);
}

void union_(long int x, long int y){
	long int xset = find(x);
    long int yset = find(y);
    if(yset < xset)  pai[xset] = yset; else pai[yset] = xset;
	return;
}

int main() {
    long int m, n, k;
    scanf(" %ld %ld %ld", &m, &n, &k);
    long int sensors[12345][3];
    long int r, x, y;
    for(int i = 0; i < k; i++){
        group[i][0] = m;
        group[i][1] = 0;
        group[i][2] = n;
        group[i][3] = 0;
        pai[i] = i;
        scanf(" %ld %ld %ld", &sensors[i][0], &sensors[i][1], &sensors[i][2]);
    }

    //faz o union de todos os circulos
    for(int i = 0; i < k; i++){
        for(int j = i + 1; j < k; j++){
            x = sensors[i][0] - sensors[j][0];
            y = sensors[i][1] - sensors[j][1];
            r = sensors[j][2] + sensors[i][2];
            if((x*x)+(y*y) <= (r * r)){
                union_(i, j);
            }
        }
    }

    for(int j = 0; j < k; j++){
        long int i = find(j);
        if((sensors[j][0] - sensors[j][2]) < group[i][0]) group[i][0] = sensors[j][0] - sensors[j][2];
        if((sensors[j][0] + sensors[j][2]) > group[i][1]) group[i][1] = sensors[j][0] + sensors[j][2];
        if((sensors[j][1] - sensors[j][2]) < group[i][2]) group[i][2] = sensors[j][1] - sensors[j][2];
        if((sensors[j][1] + sensors[j][2]) > group[i][3]) group[i][3] = sensors[j][1] + sensors[j][2];
    }

    for(int j = 0; j < k; j++){
        long int i = find(j);
        if(group[i][0] <= 0 and group[i][2] <= 0){
            std::cout << "N" << std::endl; 
            return 0;
        }
        if(group[i][1] >= m and group[i][3] >= n){
            std::cout << "N" << std::endl; 
            return 0;
        }
    }
    std::cout << "S" << std::endl;
    return 0;
}
