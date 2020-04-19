#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <string.h> 
#include <algorithm>

int ep = 20;

long long unsigned int problem_penalty(std::pair <int, int> p, int EP){
    /*
     A penalidade de um problema é TP + EP x FA, onde TP é a penalidade de tempo para aquele problema, 
     EP é a penalidade de erro do competidor e FA é o número de tentativas frustradas de resolver 
     o problema antes de submeter uma solução certa.
    */

    if(p.second == -1) return 0;
    //TP + FA X EP
    long long unsigned int FA = (p.first);
    FA = FA > 0 ? FA : 0;
    return p.second + FA * EP;
}

long long unsigned int team_penalty(std::vector< std::pair <int, int> > team, int EP){
    long long unsigned int penalty = 0;
    for(int i = 0; i < team.size(); i++){
        penalty += problem_penalty(team[i], EP);
    }
    return penalty;
}

bool compare_times(const std::pair<int, std::vector< std::pair <int, int> > > &team1,const std::pair<int, std::vector< std::pair <int, int> > > &team2){
    int n1 = 0, n2 = 0;
    for(int j = 0; j < team1.second.size(); j++){
        if(team1.second[j].second > -1) n1++;
        if(team2.second[j].second > -1) n2++;
    }
    if(n1 == 0 and n2 == 0) return false;
    if(n1 == n2) return team_penalty(team1.second, ep) < team_penalty(team2.second, ep); 
    return n1 > n2;
}

std::vector<std::pair < int, int> > get_board(std::vector< std::pair<int, std::vector< std::pair <int, int> > > >  times){
    int pos = 1;
    std::vector<std::pair < int, int> >  score;
    long long unsigned int actual = team_penalty(times[0].second, ep);
    score.push_back(std::make_pair(times[0].first, pos));
    for(int i = 1; i < times.size(); i++){
        if(team_penalty(times[i].second, ep) != actual) pos++;
        score.push_back(std::make_pair(times[i].first, pos));
        actual = team_penalty(times[i].second, ep);
    }
    return score;
}


int main() {
    int t, p;
    int retries, tempo;
    char Cretries[10], Ctempo[10];

    while(1){
        ep = 20;
        std::vector<std::pair < int, int> > original_score,score;
        std::vector< std::pair<int, std::vector< std::pair <int, int> > > > times; 
        std::vector< std::pair<int, std::vector< std::pair <int, int> > > > times2, original; 
        scanf(" %d %d", &t, &p);
        if(p == 0 and t == 0) break;
        for(int i = 0; i < t; i++){
            int n = 0;
            std::vector< std::pair <int, int> > team;
            for(int j = 0; j < p; j++){
                scanf(" %99[^/]/%s", Cretries, Ctempo);
                retries = atoi(Cretries);
                tempo = strcmp(Ctempo, "-") ?  atoi(Ctempo) : -1;
                team.push_back(std::make_pair(retries, tempo));
            }
            times.push_back(std::make_pair(i,team));
        }
        sort(times.begin(), times.end(), compare_times); 
        original = times;
        original_score = get_board(times);
        //alterar esse valor altera a resposta!!!
        int lower, upper;
        for(int i = 1; i < 21; i++){
            ep = i;
            sort(times.begin(), times.end(), compare_times);
            score = get_board(times);    
            times = original;
            if(original_score == score){lower = i; break;}
        }
        ep = 200000000;
        sort(times.begin(), times.end(), compare_times);
        score = get_board(times);             
        times = original;
        if(original_score == score){
            std::cout << lower << " " << '*' << std::endl;
            continue;
        }
        for(int i = 21; i <= 200000000; i++){
            ep = i; upper = i;
            sort(times.begin(), times.end(), compare_times); 
            score = get_board(times);
            times = original;
            if(original_score != score){upper = i - 1; break;}
        }
        if(upper < 200000000)
        std::cout << lower << " " << upper << std::endl;
        else
        std::cout << lower << " " << '*' << std::endl;
    }
    return 0;
}