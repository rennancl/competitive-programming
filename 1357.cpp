#include <bits/stdc++.h>

int main() {

    char op;
    int n = 0, value;
    int p[101][10];
    char line[500], c;


    while(1){
        for(int i = 0; i < 101; i++){
            for(int j = 0; j < 10; j++){
                p[i][j] = 0;
            }
        }
        std::vector<int> v;
        scanf(" %d", &n);
        if(n == 0) break;
        scanf(" %c", &op);
        getchar();
        if(op == 'S'){
            for(int i = 0; i < n; i++){
                scanf("%c", &c);
                value = (int)c - 48;
                v.push_back(value);
            }
            getchar();

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < v.size(); j++)
                {
                    if(i == 0){
                        if(v[j] == 1 or v[j] == 5 or v[j] == 2 or v[j] == 8){
                            printf("*.");
                        }
                        if(v[j] == 3 or v[j] == 4 or v[j] == 6 or v[j] == 7){
                            printf("**");                  
                        }
                        if(v[j] == 9 or v[j] == 0){
                            printf(".*");
                        }
                    }
                    if(i == 1){
                        if(v[j] == 7 or v[j] == 8 or v[j] == 0){
                            printf("**");
                        }
                        if(v[j] == 6 or v[j] == 2 or v[j] == 9){
                            printf("*.");                   
                        }
                        if(v[j] == 1 or v[j] == 3){
                            printf("..");                    
                        }
                        if(v[j] == 4 or v[j] == 5){
                            printf(".*");                   
                        }
                    }
                    if(i == 2){
                        printf("..");
                    }
                    if(j < v.size() - 1) printf(" ");
                }
                printf("\n");
            }

        }else{
            for(int i = 0; i < 101; i++){
                for(int j = 0; j < 10; j++){
                    p[i][j] = 0;
                }
            }
            for(int i = 0; i < 3; i++){
                char line[500], c;
                fgets (line, 500 , stdin);
                // printf("%s", line);
                for(int k = 0; k <=  strlen(line) - 3; k+=3){
                    if(line[k] == '*' and line[k + 1] == '*' and i == 0){
                        p[k / 3][3] += 1;
                        p[k / 3][4] += 1;
                        p[k / 3][6] += 1;
                        p[k / 3][7] += 1;
                    }
                    if(line[k] == '*' and line[k + 1] == '.' and i == 0){
                        p[k / 3][1] += 1;
                        p[k / 3][5] += 1;
                        p[k / 3][2] += 1;
                        p[k / 3][8] += 1;
                    }
                    if(line[k] == '.' and line[k + 1] == '*' and i == 0){
                        p[k / 3][9] += 1;
                        p[k / 3][0] += 1;
                    }
                    if(line[k] == '*' and line[k + 1] == '*' and i == 1){
                        p[k / 3][7] += 1;
                        p[k / 3][0] += 1;
                        p[k / 3][8] += 1;
                    }
                    if(line[k] == '.' and line[k + 1] == '.' and i == 1){
                        p[k / 3][1] += 1;
                        p[k / 3][3] += 1;
                    }
                    if(line[k] == '.' and line[k + 1] == '*' and i == 1){
                        p[k / 3][5] += 1;
                        p[k / 3][4] += 1;
                    }
                    if(line[k] == '*' and line[k + 1] == '.' and i == 1){
                        p[k / 3][6] += 1;
                        p[k / 3][2] += 1;
                        p[k / 3][9] += 1;
                    }
                }
            }

            for(int i = 0; i < n; i++){
                int m = 0;
                for(int j = 0; j < 10; j++){
                    if(p[i][j] > m) m = p[i][j];
                }
                for(int j = 0; j < 10; j++){
                    if(p[i][j] == m) printf("%d", j);
                }
                // for(int j = 0; j < 10; j++){
                //     printf("%d ", p[i][j]);
                // }
                // printf("\n");
            }
            printf("\n");
        }
    }

    return 0;
}