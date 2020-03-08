#include <bits/stdc++.h>

int main() {
    // tentar tanto na vertical quanto horizontal
    // ve se a largura é divisor
    // se sim, ve se tem somas do tamanho da outra dimensão o suficiente pra quantidade de colunas da divisão

    int t[10000] = {}, t_used[10000] = {};
    int number, number2, larg, cols, cols2;
    int a, b, k, count, count2, c, pos, big = 0;
    while(1){
        count = 0;
        count2 = 0;
        number = 0;
        number2 = 0;
        scanf(" %d %d", &a, &b);
        if(a == 0 or b == 0) break;
        scanf(" %d", &larg);
        scanf(" %d", &k);

        for(int i = 0; i < 10000; i++){
            t[i] = 0;
            t_used[i] = 0;
        }
        for(int i = 0; i < k; i++){
            scanf(" %d",&pos);
            t[pos]++;
            t_used[pos]++;
            if(pos > big) big = pos;
        }

        if(not((a*100) % larg)){
            cols = (a*100)/larg;
            count += t[b];
            number += t[b];
            t[b] = 0;
            if(count > cols) number = cols;
            for(int i = 0; i < big; i++){
                while(b - i > 0 and t[i] > 0 and t[b-i] > 0 and count < cols){
                    if(i == b - i and t[i] == 1) break;
                    count++;
                    number+=2;
                    t[i]--;
                    t[b-i]--;

                }
            }
        }
        if(((a*100) % larg) or count < cols){
            number = INT_MAX /2;
        }
        if(not((b*100) % larg)){
            cols2 = (b*100)/larg;
            count2 += t_used[a];
            number2 += t_used[a];
            t_used[a] = 0;
            if(count2 > cols2) number2 = cols2;
            for(int i = 0; i < big; i++){
                while(a - i > 0 and t_used[i] > 0 and t_used[a-i] > 0 and count2 < cols2){
                    if(i == a - i and t_used[i] == 1) break;
                    count2++; 
                    number2+=2;
                    t_used[i]--;
                    t_used[a-i]--;
                }
            }
        }
        if(((b*100) % larg) or count2 < cols2){
            number2 = INT_MAX /2;
        }

        // printf("%d-%d %d-%d\n", count,  cols, count2, cols2);
        if(cols2 == 0 or cols == 0 or (count < cols and count2 < cols2)){
            printf("impossivel\n");
        }else{
            if(number < number2 and count >= cols){
                printf("%d\n", number);
            }else{
                printf("%d\n", number2);
            }
        }
    }
    return 0;
}