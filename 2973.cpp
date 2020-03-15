#include <bits/stdc++.h>

int main() {
    int n, c, t;
    int sacos[1000000];
    int total = 0;
    scanf("%d %d %d", &n, &c, &t);
    for(int i = 0; i < n; i++){
        scanf(" %d", &sacos[i]);
        total += sacos[i];
    }
    // tempo minimo pra começar e evitar operações desnecessárias
    int mint = total/(t*c) - 1;
    if(mint < 0) mint = 1;
    // std::cout << mint << std::endl;

    for(int i = mint; i < total + 1; i++){
        int counter = 0;
        int sum = 0;
        int quant_vez = i*t;
        // std::cout << quant_vez << std::endl;

        for(int j = 0; j < n; j++){
            if(sum < quant_vez)
                sum += sacos[j];

            if(sacos[j] > quant_vez){
                counter = 100000;
                break;
            }
            if(sum > quant_vez){
                sum = sacos[j];
                counter +=1;
                if(counter > c){
                    break;
                }
            }
            if(sum == quant_vez){
                sum = 0;
                counter +=1;
                if(counter > c){
                    break;
                }
            }

            // std::cout << sum << " s" << sacos[j] << " m" << counter << " c";
            // std::cout << std::endl;

        }
        if(sum > 0) counter++;
        if(counter <= c){
            std::cout << i << std::endl;
            return 0;
        }
    }

    return 0;

}