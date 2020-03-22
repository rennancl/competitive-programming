#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>

int graph[10001][10001];
int dis[10001];
int vis[10001];

int min = 199999999;
int max = 1;
int main(){
    int n, m, p, s, x, y;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        dis[i] = 99999999;
        vis[i] = 0;
        for(int j = 1; j <= n; j++){
            graph[j][i] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        scanf(" %d %d %d", &x, &y, &p);
        graph[x][y] = p;
        graph[y][x] = p;
    }
    scanf(" %d", &s);
    dis[s] = 0;
    int node = s;
    while(1){
        int max = 9999999;
        vis[node] = 1; 
        for(int i = 1; i <= n; i++){
            if(graph[node][i]){
                if(dis[i] > dis[node] + graph[node][i]){
                    dis[i] = dis[node] + graph[node][i];
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(not vis[i] and dis[i] < max){
                max = dis[i];
                node = i;
            }
        }
        if(max == 9999999) break;
    }

    for(int i = 1; i <= n ; i++){
        if(0 < dis[i] and dis[i] <= min) min = dis[i];
        if(dis[i] >= max) max = dis[i];
    }
    std::cout << max -  min << std::endl;
}