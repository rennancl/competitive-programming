#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

int table[101][51];
int num[101][51];
int main(){
    int n, cases, v, w;
    scanf(" %d", &cases);
    int max = 0;
    for(int j = 0; j < cases; j++){
        std::vector<int> values;
        std::vector<int> weights;
        max = 0;
        for(int i = 0; i <= 100; i++){
            for(int W = 0; W < 51; W++){
                table[i][W] = 0;
                num[i][W] = 0;
            }
        }
        scanf(" %d", &n);
        for(int i = 0; i < n; i++){
            scanf(" %d %d", &v, &w);
            values.push_back(v);
            weights.push_back(w);
        }
        for(int i = 0; i <= n; i++){
            for(int W = 0; W <= 50; W++){
                if(i == 0 or W == 0){
                    table[i][W] = 0;
                    continue;
                }
                if(weights[i-1] <= W and values[i-1] + table[i-1][W - weights[i-1]] > table[i-1][W]){
                    table[i][W] = values[i-1] + table[i-1][W - weights[i-1]];
                    num[i][W] = 1 + num[i-1][W - weights[i-1]];
                }else{
                    table[i][W] = table[i-1][W];
                    num[i][W] = num[i-1][W];
                }
                if(table[i][W] > max) max = table[i][W];
            }
        }

        for(int i = 0; i <= n; i++){
            for(int W = 0; W < 51; W++){
                if(table[i][W] == max){
                    std::cout << max << " brinquedos" << std::endl;
                    std::cout << "Peso: " << W << " kg" << std::endl;
                    std::cout << "sobra(m) " << n - num[i][W] << " pacote(s)" << std::endl << std::endl;
                    max = -1;
                }
            }
        }
    }
}