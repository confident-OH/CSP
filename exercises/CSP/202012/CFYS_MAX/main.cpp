#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

int m, n;
const int Max = 100010;
int h[Max], e[Max], ne[Max], idx, w[Max];
bool th[Max];
ll dist[Max];
int in[Max];
queue<int> q;

void init()
{
    memset(h, -1, sizeof(h));
    memset(dist, -1, sizeof(dist)); // find max len
}

void add(int a, int b, int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

int spfa(int start)
{
    q.push(start);
    th[start] = true;
    dist[start] = 0;
    while(!q.empty()){
        int k = q.front();
        th[k] = false;
        q.pop();
        for(int i = h[k]; ~i; i = ne[i]){
            int var = e[i];
            int wei = w[i];
            if(dist[var] < dist[k]+wei){
                dist[var] = dist[k]+wei;
                if(!th[var]){
                    in[var]++;
                    q.push(var);
                    th[var] = true;
                    if(in[var]>n+1){
                        return -2;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    init();
    int a, b, c;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; i++){
        add(0, i, 0);
    }
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, -c);
    }
    int lable = spfa(0);
    if(lable == -2) cout << "NO";
    else{
        for(int i = 1; i<=n; i++){
            printf("%d ", dist[i]);
        }
    }
    return 0;
}
