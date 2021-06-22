#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> q;

int my_dist[6][6];
int qinqi[6];

const int N=50010;
int h[N], e[4*N], ne[4*N], idx, d[4*N];
int dist[N];
int th[N];
int m, n;
int res;

void add(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void dijk(int start)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    q.push({0, start});
    dist[start] = 0;
    while(!q.empty()){
        auto item = q.top();
        q.pop();
        int di = item.second;
        int dd = item.first;
        if(th[di]) continue;
        th[di] = true;
        for(int i = h[di]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j]>dd+d[i]){
                dist[j] = dd+d[i];
                q.push({dist[j], j});
            }
        }
    }
}

void add_res(vector<bool> ths, int mid_res, int start)
{
    bool label = true;
    for(int i = 1; i<=5; i++){
        if(ths[i]){
            ths[i] = false;
            add_res(ths, mid_res+my_dist[start][i], i);
            ths[i] = true;
            label = false;
        }
    }
    if(label){
        res = min(res, mid_res);
    }
}

void travel()
{
    vector<bool> th1(6, true);
    add_res(th1, 0, 0);
}


int main()
{
    memset(h, -1, sizeof(h));
    res = 0x3f3f3f3f;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d %d", &qinqi[1], &qinqi[2], &qinqi[3], &qinqi[4], &qinqi[5]);
    qinqi[0] = 1;
    int x, y, t;
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &x, &y, &t);
        add(x, y, t);
        add(y, x, t);
    }
    for(int i = 0; i<6; i++){
        dijk(qinqi[i]);
        for(int j = 0; j<6; j++){
            my_dist[i][j] = dist[qinqi[j]];
            //printf("%d %d: %d\n", qinqi[i],qinqi[j], dist[qinqi[j]]);
        }
    }
    travel();
    cout << res << endl;
    return 0;
}
