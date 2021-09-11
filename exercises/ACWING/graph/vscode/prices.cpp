#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

int h[N], e[2*N], ne[2*N], idx;
int in[N];
int price[N];
int m, n;
int result;
int now_p;
queue<int> que;

void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool topsort()
{
    for(int i = 1; i<=n; i++){
        if(in[i] == 0){
            que.push(i);
            now_p++;
        }
    }
    while(!que.empty()){
        int item = que.front();
        result += price[item];
        que.pop();
        for(int i = h[item]; ~i; i = ne[i]){
            int j = e[i];
            in[j]--;
            if(in[j] == 0){
                que.push(j);
                now_p++;
                price[j] = price[item]+1;
            }
        }
    }
    if(now_p!=n){
        return false;
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    int a, b;
    for(int i = 1; i<=n; i++){
        price[i] = 100;
    }
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        add(b, a);
        in[a]++;
    }
    if(topsort()){
        cout << result;
    }
    else{
        puts("Poor Xed");
    }
    
    return 0;
}