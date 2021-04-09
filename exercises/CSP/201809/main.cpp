#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int x[310], limit[310], y[310];
int n;

bool test(){
    int item = (x[0]+x[1]) / 2;
    if(item != y[0]) return false;
    for(int i = 1; i<n-1; i++){
        item = (x[i-1]+x[i+1]+x[i]) / 3;
        if(item != y[i]) return false;
    }
    item = (x[n-2] + x[n-1]) / 2;
    if(item != y[n-1]) return false;
    return true;
}

int dfs(int now)
{
    x[now] = 1;
    if(now == n-1){
        while(x[now]<limit[now]){
            if(test()){
                return 1;
            }
            else{
                x[now]++;
            }
        }
        return -1;
    }
    while (dfs(now+1) == -1){
        if(x[now]<limit[now]){
            x[now]++;
        }
        else{
            return -1;
        }
    }
    return 1;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &y[i]);
    }
    limit[0] = min(2*(y[0] + 1), 3*(y[1] + 1));
    limit[n - 1] = min(2*(y[n - 1] + 1), 3*(y[n - 2] + 1));
    if(n>2){
        limit[1] = min(limit[0], 3*(y[2] + 1));
        for(int i = 2; i<n-2; i++){
            limit[i] = min(3*(y[i-1]+1), 3*(y[i]+1));
            limit[i] = min(limit[i], 3*(y[i+1] +1));
        }
        limit[n - 2] = min(limit[n - 1], 3*(y[n - 3] + 1));
    }
    dfs(0);
    for(int i = 0; i<n; i++){
        printf("%d ", x[i]);
    }
    return 0;
}
