#include <bits/stdc++.h>

int main() {
    // tentar tanto na vertical quanto horizontal
    // ve se a largura é divisor
    // se sim, ve se tem somas do tamanho da outra dimensão o suficiente pra quantidade de colunas da divisão

    int t[100000], t_used[100000];
    int number, number2, larg, cols, cols2;
    int a, b, k, count, count2, c;
    while(1){
        count = 0;
        count2 = 0;
        number = 0;
        number2 = 0;
        scanf(" %d%d", &a, &b);
        if(a == 0 and b == 0) break;
        scanf(" %d", &larg);
        scanf(" %d", &k);
        for(int i = 0; i < k; i++){
            scanf(" %d", &t[i]);
        }
        std::sort(t, t + k);
        for(int i = 0; i < k; i++){
            t_used[i] = t[i];
        }
        c = k;
        if(not((a*100) % larg)){
            cols = (a*100)/larg;
            for(int i = 0; i < k; i++){
                if(t[i] > b){
                    c = i;
                    break;
                }
            }

            for(int i = 0; i < c; i++){
                if(count == cols or (2 * t[i]) > b) break;
                for(int j = c; j > i; j--){
                    if (t[j] == b){
                        t[j] = 0;
                        count++;
                    }
                    if (t[i] + t[j] == b){
                        t[j] = 0;
                        t[i] = 0;
                        count++;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < k; i++){
            if(t[i] == 0) number++;
            t[i] = t_used[i];
        }
        if(((a*100) % larg) or count < cols){
            number = INT16_MAX /2;
        }
        if(not((b*100) % larg)){
            cols2 = (b*100)/larg;
            for(int i = 0; i < k; i++){
                if(t[i] > a){
                    c = i;
                    break;
                }
            }

            for(int i = 0; i < c; i++){
                if(count2 == cols2 or (2 * t[i]) > a) break;
                for(int j = c; j > i; j--){
                    if (t[j] == a){
                        t[j] = 0;
                        count2++;
                    }
                    if (t[i] + t[j] == a){
                        t[j] = 0;
                        t[i] = 0;
                        count2++;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < k; i++){
            if(t[i] == 0) number2++;
        }
        if(((b*100) % larg) or count2 < cols2){
            number2 = INT16_MAX /2;
        }

        if(cols2 == 0 or cols == 0 or (count < cols and count2 < cols2)){
            printf("impossivel\n");
        }else{
            if(number < number2){
                printf("%d\n", number);
            }else{
                printf("%d\n", number2);
            }
        }
    }
    return 0;
}