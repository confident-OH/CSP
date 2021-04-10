#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int Max = 100010;
int h[Max], ne[Max], e[Max], idx, w[Max];
int n, m;
bool th[Max];
queue<int> q;
int dist[Max];

void add(int a, int b, int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void init()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof(dist));
}

int spfa(int start)
{
    dist[start] = 0;
    q.push(start);
    th[start] = true;
    while(!q.empty()){
        int k = q.front();
        q.pop();
        th[k] = false;
        for(int i = h[k]; i!=-1; i = ne[i]){
            int j = e[i];
            int weight = w[i];
            if(weight + dist[k] < dist[j]){
                dist[j] = weight + dist[k];
                if(!th[j]){
                    q.push(j);
                    th[j] = true;
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    init();
    scanf("%d %d", &n, &m);
    int a, b, c;
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    int res = spfa(1);
    if(res == -1) cout << "impossible";
    else cout << res;
    return 0;
}
