#include <bits/stdc++.h>

int main() {
    std::string l, c;
    std::getline(std::cin, l);
    std::getline(std::cin, c);
    int n = 0,enigma = 0;
    for(int i = 0; i < l.size() - c.size() + 1; i++){
        enigma = 1;
        for(int j = 0; j < c.size(); j++){
            if(l[i + j] == c[j]){
                enigma = 0;
                break;
            }
        }
        n += enigma;
    }
    std::cout << n << std::endl;
    return 0;
}