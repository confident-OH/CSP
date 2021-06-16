#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> q;
int T, C, START, Dest;
const int N_Max = 100010;
int h[N_Max], e[N_Max], ne[N_Max], idx, w[N_Max];
int dist[N_Max];
bool th[N_Max];

void add_edge(int a, int b, int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a]= idx++;
}

int dijk(int start, int d)
{
    q.push({0, start});
    while(!q.empty()){
        PII item = q.top();
        q.pop();
        if(th[item.second]) continue;
        th[item.second] = true;
        for(int i = h[item.second]; ~i; i = ne[i]){
            if(dist[e[i]]>w[i]+item.first){
                dist[e[i]] = w[i]+item.first;
                q.push({dist[e[i]], e[i]});
            }
        }
    }
    if(dist[d] == 0x3f3f3f3f) return -1;
    else return dist[d];
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    scanf("%d %d %d %d", &T, &C, &START, &Dest);
    int a, b, c;
    for (int i = 0; i<C; i++){
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    cout << dijk(START, Dest) << endl;
    return 0;
}
