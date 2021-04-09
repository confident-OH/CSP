#include <iostream>
#include <cstring>
#include <cstdio>
#define ll long long

using namespace std;

int hotels[110][11];
int head[110], ne[110], e[110], ind, w[110];
int cost[110][11];
int q[110], cross_d[110];
bool cross_by[110];

void edge_add(int s, int d, int W)
{
    ne[ind] = head[s];
    head[s] = ind;
    w[ind] = W;
    e[ind++] = d;
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(ne, -1, sizeof(head));
    memset(e, -1, sizeof(e));
    memset(w, 0, sizeof(w));
    ind = 0;
    memset(cost, 0, sizeof(cost));
}

int main()
{
    int M, N, K, s, d, W;
    init();
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=K; j++){
            scanf("%d", &hotels[i][j]);
        }
    }
    for(int i = 0; i<N-1; i++){
        scanf("%d %d %d", &s, &d, &W);
        edge_add(s, d, W);
        edge_add(d, s, W);
    }
    int t, h;
    for(int i = 1; i<=N; i++){
        t = 0;
        h = 0;
        memset(cross_by, 0, sizeof(cross_by));
        memset(q, 0, sizeof(q));
        memset(cross_d, 0, sizeof(cross_d));
        q[t++] = i;
        while(h<t){
            for(int j = head[q[h]]; j!=-1; j = ne[j]){
                int ed = e[j];
                if(!cross_by[ed]){
                    cross_by[ed] = true;
                    q[t] = ed;
                    cross_d[t] = cross_d[q[h]] + w[j];
                    for(int k = 1; k<=K; k++){
                        if(hotels[ed][k]){
                            cost[i][k]+=cross_d[t];
                        }
                    }
                    t++;
                }
            }
            h++;
        }
    }
    for(int i = 1; i<=N; i++){
        printf("%d cost: ", i);
        for(int j = 1; j<=K; j++){
            printf("%d ", cost[i][j]);
        }
        cout << endl;
    }
    return 0;
}
