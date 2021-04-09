#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;
typedef pair<int,int> PII;

int n, m;
const int Max = 200010;
int h[Max], e[Max], ne[Max], d[Max], idx;
int dist[Max];
bool th[Max];
priority_queue<PII, vector<PII>, greater<PII>> q;

void add(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

int dijk(int start)
{
    q.push({0, 1});
    while(!q.empty()){
        PII k = q.top();
        q.pop();
        if(th[k.second]) continue;
        th[k.second] = true;
        for(int i = h[k.second]; i!=-1; i = ne[i]){
            int j = e[i];
            if(dist[j] > k.first + d[i]){
                dist[j] = k.first + d[i];
                q.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return 1;
}

void init()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
}

int main()
{
    init();
    scanf("%d %d", &n, &m);
    int a, b, w;
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &a, &b, &w);
        add(a, b, w);
    }
    int lable = dijk(1);
    if(lable == -1){
        cout << "-1";
    }else{
        cout << dist[n];
    }
    return 0;
}
