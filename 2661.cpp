#include <bits/stdc++.h>

int main() {
    long long int n;
    std::set<long long int> s;
    scanf("%lld*c", &n);
    long long int c = n;


    if((n % 2) == 0){
        s.insert(2);
    }
    while((n % 2) == 0){
        n =  n / 2;
    }

    for(long long  i = 3;(i * i) < c + 1; i+=2){

        if((n % i) == 0){
            s.insert(i);
        }else{
            continue;
        }
        while((n % i) == 0){
            n =  n / i;

        }
    }
    if(n > 1){
        s.insert(n);
    }
    // std::cout << s.size() << std::endl;

    int fat = 1, total = 0, comb = 1;
    for(int i = 2; i <= (int)s.size(); i++){
        fat = fat * i;
        int v =  (int)s.size(), comb = 1;
        for (int j = 0; j < i; j++)
        {
            comb *= v;
            v --;
        }
        
        total += (comb/ fat);
    }
    std::cout << total << std::endl;

    return 0;
}
