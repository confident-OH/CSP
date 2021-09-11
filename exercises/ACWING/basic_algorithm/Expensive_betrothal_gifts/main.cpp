#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
typedef pair<int, int> PII;

priority_queue<PII, vector<PII>, greater<PII>> heap;
const int N=20010;
int h[110], e[N], ne[N], d[N], idx, l[110];
int dist[110];
bool th[110];
int n, m;

void add_edge(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

int dijk(int start, int up, int down)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    dist[start] = 0;

    heap.push({0, start});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if (th[ver]) continue;
        th[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (((l[j]>=up&&l[j]<down)||j==n+1) && dist[j] > dist[ver] + d[i])
            {
                dist[j] = dist[ver] + d[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n+1] == 0x3f3f3f3f) return -1;
    return dist[n+1];
}


int main()
{
    memset(h, -1, sizeof(h));
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
    int res = 0x3f3f3f3f;
    for(int i = l[1]-m; i<=l[1]; i++){
        res = min(res, dijk(1, i, i+m));
    }
    cout << res << endl;
    return 0;
}
