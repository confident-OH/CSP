#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
vector<int> chang;

const int N = 3000;
priority_queue<PII, vector<PII>, greater<PII>> q;
int h[N], d[N], e[N], ne[N], idx;
int dist[1000][N];
int th[1000][N];
void add_edge(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void dijk(int start, int line)
{
    q.push({0, start});
    dist[line][start] = 0;
    while(!q.empty()){
        PII item = q.top();
        q.pop();
        if(th[line][item.second]) continue;
        th[line][item.second] = true;
        for(int i = h[item.second]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[line][j]>d[i]+item.first){
                dist[line][j] = d[i]+item.first;
                q.push({dist[line][j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    int n, p, c;
    int num;
    int a, b, w;
    scanf("%d %d %d", &n, &p, &c);
    for(int i = 0; i<n; i++){
        scanf("%d", &num);
        chang.push_back(num);
    }
    for(int i = 0; i<c; i++){
        scanf("%d %d %d", &a, &b, &w);
        add_edge(a, b, w);
        add_edge(b, a, w);
    }
    for(int i = 1; i<=p; i++){
        dijk(i, i);
    }
    int result = 0x3fffffff;
    for(int i = 1; i<=p; i++){
        int itemr = 0;
        for(auto j:chang){
            if(dist[i][j] == 0x3f3f3f3f){
                itemr = 0x3f3f3f3f;
                break;
            }
            itemr+=dist[i][j];
        }
        result = min(result, itemr);
    }
    cout << result;
    return 0;
}

/*
5 10 24
4
5
1
8
5
8 1 187
2 10 11
3 10 144
3 8 30
3 9 123
10 1 222
10 7 170
7 4 169
2 3 158
6 8 124
7 5 213
2 6 14
4 2 192
10 6 87
4 8 207
7 1 212
4 1 12
10 8 64
6 1 160
5 1 38
7 6 28
5 3 62
9 1 79
4 3 125

result = 180
*/
