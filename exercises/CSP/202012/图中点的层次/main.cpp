#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
const int NMax = 100010, MMax = 100010;
int h[MMax], ne[NMax], e[NMax], idx;
bool th[MMax];
int q[NMax];
int des[NMax];
int ans;

void add(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void bfs(int i)
{
    q[0] = i;
    th[0] = true;
    int hh = 0, tt = 0;
    while(hh <= tt){
        int i = q[hh];
        for(int j = h[i]; j != -1; j = ne[j]){
            int k = e[j];
            tt++;
            q[tt] = k;
            des[tt] = des[hh] + 1;
            if(k == n){
                ans = des[tt];
                return;
            }
        }
        hh++;
    }
    ans = -1;
}

int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    bfs(1);
    cout << ans;
    return 0;
}
