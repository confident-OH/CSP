#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

int n, m;
const int Max = 100010;
int h[Max], e[Max], ne[Max], idx, w[Max];
bool th[Max];
int in[Max];
int dist[Max];
queue<int> q;

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
    q.push(start);
    th[start] = true;
    in[start] = 1;
    dist[start] = 0;
    while(!q.empty()){
        int k = q.front();
        th[k] = false;
        q.pop();
        for(int i = h[k]; ~i; i = ne[i]){
            int var = e[i];
            int wei = w[i];
            if(dist[var] > dist[k] + wei){
                dist[var] = dist[k]+wei;
                if(!th[var]){
                    th[var] = true;
                    q.push(var);
                    in[var]++;
                    if(in[var]>n+1){
                        return -1;
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
        add(b, a, c);
    }
    int lable = spfa(0);
    if(lable == -1) printf("NO");
    else{
        for(int i = 1; i<=n; i++){
            printf("%d ", dist[i]);
        }
    }
    return 0;
}
