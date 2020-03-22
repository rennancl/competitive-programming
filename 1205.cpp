#include <stdio.h>
#include <iostream>
#include <cmath>
#include <iomanip>

int graph[10001][10001];
int cities[10001];
int dis[10001];
int vis[10001];

int main(){
    int m, n, k;
    double p;
    int x, y, start, end, ati, pos;
    std::cout << std::fixed;
    std::cout << std::setprecision(3);
    while (scanf(" %d %d %d %lf", &n, &m,&k, &p) != -1){
        for(int i = 1; i <= n; i++){
            cities[i] = 0;
            dis[i] = 99999999;
            vis[i] = 0;
            for(int j = 1; j <= n; j++){
                graph[j][i] = 0;
            }
        }
        for(int i = 0; i < m; i++){
            scanf(" %d %d", &x, &y);
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
        scanf(" %d", &ati);
        for(int i = 1; i <= ati; i++){
            scanf("%d", &pos);
            cities[pos]++;
        }
        scanf(" %d %d", &start, &end);
        dis[start] = cities[start];
        int node = start;
        while(1){
            int max = 9999999;
            vis[node] = 1; 
            for(int i = 1; i <= n; i++){
                if(graph[node][i]){
                    if(dis[i] > dis[node] + cities[i]){
                        dis[i] = dis[node] + cities[i];
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
        int t = dis[end];

        if(t > k){
            std::cout << 0.000 << std::endl;
        }else{
            std::cout << pow(p, t) << std::endl;
        }
    }
}