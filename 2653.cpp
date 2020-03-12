#include <bits/stdc++.h>

int main() {
    std::string line;
    std::set<std::string> s;
    while (std::getline(std::cin, line))
    {
        s.insert(line);
    }
    std::cout << s.size() << std::endl;
    return 0;
}