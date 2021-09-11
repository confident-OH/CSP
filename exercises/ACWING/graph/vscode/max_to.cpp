#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 30010;
int h[N], e[N], ne[N], idx;
int in[N];
bitset<N> to[N];
int n, m;
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
        }
    }
    while(!que.empty()){
        int item = que.front();
        to[item];
        que.pop();
        for(int i = h[item]; ~i; i = ne[i]){
            int j = e[i];
            in[j]--;
            to[j] |= to[item];
            if(in[j] == 0){
                que.push(j);
            }
        }
    }
}

int bit_sum(int a)
{
    int result = 0;
    unsigned int item = 1;
    for(int i = 0; i<32;  i++){
        result += ((item&a)!=0);
        item = item<<1;
    }
    return result;
}

int main (){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        to[i][i] = 1;
    }
    for(int i = 0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        add(b, a);
        in[a]++;
    }
    topsort();
    for(int i = 1; i<=n; i++){
        printf("%d\n", to[i].count());
    }
    return 0;
}