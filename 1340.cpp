#include <bits/stdc++.h>

int main()
{


    int ty[3] = {1, 1 ,1};
    int line_number = 0;
    std::string line;
    int op, value;
    int counter;
    while (scanf("%d", &line_number) != -1){
        std::priority_queue<int> pq;
        std::queue<int> q;
        std::stack<int> s;
        for(int i = 0; i <3; i++) ty[i] = 1;
        for(int i = 0; i <line_number; i++)
        {
            scanf(" %d %d",  &op , &value);
            if(op == 1){
                s.push(value);
                pq.push(value);
                q.push(value);
            }
            else
            {
                if(value != s.top()){
                    ty[0] = 0;
                }
                s.pop();

                if(value != pq.top()){
                    ty[1] = 0;
                }
                pq.pop();

                if(value != q.front()){
                    ty[2] = 0;
                }
                q.pop();
            }
            // printf("%d %d\n",  op, value);
        }
        counter = 0;
        for(int i = 0; i <3; i++)
        {
            counter+= ty[i];
        }
        if(counter > 1){
            printf("not sure\n");

        }
        else if(counter == 0){
            printf("impossible\n");

        }
        else{
            for(int i = 0; i <3; i++)
            {
                if(ty[i]){
                    if(i == 0) printf("stack\n");
                    if(i == 1) printf("priority queue\n");
                    if(i == 2) printf("queue\n");
                }
            }

        }
        
    }
        return 0;
    

}
