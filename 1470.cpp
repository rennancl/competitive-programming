#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <string.h> 
#include <algorithm>
#include <set>
#define print(x) std::cout << x << std::endl;

void print_fita(std::vector<int> fita){
    for(int i = 0; i < fita.size(); i++){
        std::cout << fita[i] << " ";
    }
    std::cout << std::endl;
}
std::vector<int> inverte(std::vector<int> fita){
    std::vector<int> new_fita;
    for(int i = fita.size(); i > 0; i--){
        new_fita.push_back(fita[i - 1]);
    }
    return new_fita;
}

std::vector<int> dobra(std::vector<int> fita, int pos){
    std::vector<int> new_fita;
    int i;
    for(i = 0; i < pos; i++){
        new_fita.push_back(fita[i]);
    }
    for(; i < fita.size(); i++){
        new_fita[2*pos - i - 1] += fita[i];
    }
    return new_fita;
}

std::vector<int> dobra_maior(std::vector<int> fita, int pos){
    if((int)fita.size() - pos > pos){
        std::vector<int> new_fita = inverte(fita);
        pos = (int)fita.size() - pos;
        new_fita = dobra(new_fita, pos);
        return new_fita;
    }else{
        return dobra(fita, pos);
    }
}

std::set<std::vector<int> > s;
int maquina(std::vector<int> in, std::vector<int> out){
    bool res = false;
    if(in == out or inverte(in) == out) return true;
    if((int)in.size() <= (int)out.size()) return false;
    for(int i = 1; i < (int)in.size() ; i++){
        std::vector<int>  maior =  dobra_maior(in,i);
        if(s.find(maior) != s.end()) continue;
        res = res or maquina(maior, out);
        if(not res) s.insert(maior);
    }
    return res;
}


int main() {
    std::string line;
    int v;
    while (std::getline(std::cin, line))
    {
        std::vector<int> in, out;
        int len = atoi(line.c_str());
        for(int i = 0; i < len; i++){
            scanf(" %d", &v);
            in.push_back(v);
        }
        scanf(" %d", &len);
        for(int i = 0; i < len; i++){
            scanf(" %d", &v);
            out.push_back(v);
        }
        getchar();
        if(in == out or in == inverte(out)){
            print("S");
            continue;
        }

        if(maquina(in, out)){
            print("S");
        }
        else{
            print("N");
        }
    }
    return 0;
}