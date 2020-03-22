#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

int pai[1000001];

int find(int i)
{
    if (pai[i] == i)
        return i;
    return find(pai[i]);
}

void union_(int x, int y){
	int xset = find(x);
    int yset = find(y);
    if(yset < xset)  pai[xset] = yset; else pai[yset] = xset;
	return;
}

bool sort_asc(const std::vector<int>& a, const std::vector<int>& b) {
  return a[2] < b[2];
}

bool sort_desc(const std::vector<int>& a, const std::vector<int>& b) {
  return a[2] > b[2];
}

int main(){
    int n, x, y, p;
    scanf("%d", &n);
    std::vector< std::vector<int> > graph;

    for(int i = 0; i < n; i++){
        scanf(" %d %d %d", &x, &y, &p);
        std::vector<int> edge;
        edge.push_back(x);
        edge.push_back(y);
        edge.push_back(p);
        graph.push_back(edge);
    }

    int value = 0;
    for (int j = 1; j <= n; ++j) pai[j] = j;
    std::sort(graph.begin(), graph.end(),sort_desc);    
    for(int i = 0; i < n; i++){

        if(find(graph[i][1]) != find(graph[i][0])){
            value += graph[i][2];
            union_(graph[i][0], graph[i][1]);
        }
    }
    std::cout << value << std::endl;

    value = 0;
    for (int j = 1; j <= n; ++j) pai[j] = j;
    std::sort(graph.begin(), graph.end(),sort_asc);
    for(int i = 0; i < n; i++){
        if(find(graph[i][1]) != find(graph[i][0])){
            value += graph[i][2];
            union_(graph[i][0], graph[i][1]);
        }
    }
    std::cout << value << std::endl;
}

