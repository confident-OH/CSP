#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
const int NMax = 100010, MMax = 100010;
bool th[NMax];
int h[MMax], e[NMax], ne[NMax], idx;
int q[NMax], d[NMax];

void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int bfs()
{
    int tt = -1, hh = 0;
    for(int i = 1; i<=n; i++){
        if(!d[i]) q[++tt] = i;
    }
    while(hh<=tt){
        int k = q[hh];
        for(int i = h[k]; i!=-1; i = ne[i]){
            int j = e[i];
            d[j]--;
            if(!d[j]){
                q[++tt] = j;
            }
        }
        hh++;
    }
    if(tt == n - 1){
        return 0;
    }else{
        return -1;
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        add(a, b);
        d[b]++;
    }
    if(bfs() == -1){
        cout << "-1";
    }else{
        for(int i = 0; i<n; i++){
            printf("%d ", q[i]);
        }
    }
    return 0;
}
