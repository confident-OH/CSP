#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
typedef pair<int, int> PII;

priority_queue<PII, vector<PII>, greater<PII>> q;
const int N=1010;
int h[N], e[N], ne[N], d[N], idx, l[N];
int dist[N];
bool th[N];
int n, m;

void add_edge(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

int dijk(int start)
{
    q.push({0, start});
    dist[start] = 0;
    while(!q.empty()){
        PII item = q.top();
        q.pop();
        if(th[item.second]) continue;
        th[item.second] = true;
        for(int i = h[item.second]; ~i; i=ne[i]){
            int di = e[i];
            if((l[di]>=l[1]-m||l[di]<=l[1]+m||di==n+1) && dist[di]>item.first+d[i]){
                dist[di] = item.first+d[i];
                q.push({dist[di], di});
                //printf("Test: %d %d\n", dist[di], di);
            }
        }
    }
    return dist[n+1];
}


int main()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    int P, L, X;
    int T, V;
    cin >> m >> n;
    for(int i = 1 ;i <=n; i++){
        cin >> P >> L >> X;
        l[i] = L;
        add_edge(i, n+1, P);
        for(int j = 0; j<X; j++){
            cin >> T >> V;
            add_edge(i, T, V);
        }
    }
    cout << dijk(1) << endl;
    return 0;
}
