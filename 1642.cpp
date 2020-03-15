#include <bits/stdc++.h>

int main() {
    int n;
    while(1){
        scanf("%d\n", &n);
        if(n == 0) break;
        std::set<char> s;
        std::string line;
        std::getline(std::cin, line);
        std::unordered_map<char, int> dict;
        for(int i = 0; i < (int)line.size(); i++){
            dict[line[i]] = 0;
        }
        int counter = 0;
        int max = 0;
        int k = 0;
        for(int i = 0; i < (int)line.size(); i++){
                s.insert(line[i]);
                dict[line[i]] += 1;
                counter++;
                if(s.size() > n){
                    while(k < (int)line.size()){
                        counter--;
                        dict[line[k]]--;
                        if(dict[line[k]] == 0){
                            s.erase(line[k]);
                            k++;
                            break;
                        } 
                        k++;
                    }
                }
                if(counter >= max) max = counter;
            }
            std::cout << max << std::endl;
        }
    return 0;
}