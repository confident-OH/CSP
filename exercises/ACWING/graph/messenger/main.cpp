#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;

const int N = 200010;
int h[N], e[N], d[N], ne[N], idx;
priority_queue<PII, vector<PII>, greater<PII>> q;
int dist[N];
bool th[N];

void add_edge(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void dijk(int start, int dest)
{
    q.push({0, start});
    while(!q.empty()){
        PII item = q.top();
        q.pop();
        if(th[item.second]) continue;
        th[item.second] = true;
        for(int i = h[item.second]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j]>d[i]+item.first){
                dist[j] = d[i]+item.first;
                q.push({dist[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    int n,m;
    scanf("%d %d", &n, &m);
    int a, b, c;
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    dijk(1, n);
    int result = 0;
    for(int i = 1; i<=n; i++){
        result = max(result, dist[i]);
    }
    if(result == 0x3f3f3f3f){
        cout << -1;
    }
    else{
        cout << result;
    }
    return 0;
}
