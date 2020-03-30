#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

int main(){
    int n, m;
    int counter;
    int temp, sum = 0;
    std::vector<int> lampadas;
    std::vector<int> interruptores[10000];
    std::vector<std::pair < int, std::vector<int> > > solutions;
    int s = 0;
    scanf("%d %d", &n, &m);
    scanf("%d", &counter);

    for(int i = 0; i < m; i++){
        lampadas.push_back(0);
    }
    for(int i = 0; i < counter; i++){
        scanf(" %d", &temp);
        lampadas[temp] = 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &counter);
        for(int j = 0; j < counter; j++){
            scanf(" %d", &temp);
            interruptores[i].push_back(temp);
        }
    }

    while(1){
        int i = s % n;
        for(int k = 0; k < solutions.size(); k++){
            if(i == solutions[k].first and lampadas == solutions[k].second){
                std::cout << -1 << std::endl;
                return 0;
            }
        }
        std::vector<int> vect_copy; 
        vect_copy = lampadas;
        solutions.push_back(make_pair(i, vect_copy));
        for(int j = 0; j <  interruptores[i].size(); j++){
            lampadas[interruptores[i][j]] = lampadas[interruptores[i][j]] ? 0 : 1;
        }
        s++;
        for(int k = 1; k <= m; k++) sum += lampadas[k];
        if(sum == 0) break;
        sum = 0;
    }    
    std::cout << s << std::endl;
    return 0;
}

