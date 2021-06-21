#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;

typedef pair<int, int> PII;
priority_queue <PII, vector<PII>, greater<PII>> q;

const int N = 510;
int n, m;
bool g[N][N];
int dist[N], stop[N];
bool th[N];

void spfa(int start)
{
    q.push({0, start});
    dist[start] = 0;
    while(!q.empty()){
        PII item = q.top();
        q.pop();
        if(th[item.second]) continue;
        th[item.second] = true;
        for(int i = 1; i<=n; i++){
            if(g[item.second][i] && dist[i] > item.first+1){
                dist[i] = item.first+1;
                q.push({dist[i], i});
            }
        }
    }
}

int main()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    cin >> m >> n;
    string line;
    getline(cin, line);

    for(int i = 0; i<m; i++){
        getline(cin, line);
        int item;
        int p = 0;
        stringstream ssin(line);
        while(ssin >> item){
            stop[p] = item;
            p++;
        }
        for(int i = 0; i<p; i++){
            for(int j = i+1; j<p; j++){
                g[stop[i]][stop[j]] = true;
            }
        }
    }
    spfa(1);
    if(dist[n] == 0x3f3f3f3f){
        cout << "NO" << endl;
    }
    else{
        cout << dist[n] - 1 << endl;
    }
    return 0;
}
