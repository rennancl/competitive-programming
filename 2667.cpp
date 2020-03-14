#include <bits/stdc++.h>

int main() {
    std::string line;
    int value = 0;
    std::getline(std::cin, line);
    for(int i = 0; i < (int)line.size(); i++){
        value += (int)line[i] - 48;
    }
    std::cout << value % 3 << std::endl;
    return 0;
}

