#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 100010;
int h[N], ne[2*N], e[2*N], idx;
double w[2*N], dist[2*N];
bool th[2*N];
int in[N];
queue<int> q;

void add_edge(int a, int b, double c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a];
    h[a] = idx++;
}

int spfa(int start)
{
    q.push(start);
    th[start] = true;
    dist[start] = 1;
    while(!q.empty()){
        int item = q.front();
        q.pop();
        th[item] = false;
        for(int i = h[item]; ~i; i = ne[i]){
            int edge = e[i];
            if(dist[edge]<dist[item]*w[i]){
                dist[edge] = dist[item]*w[i];
                //cout << "now start:" << item << " end:" << edge << " distence: " <<dist[edge] << "dist[item]: "<< dist[item] << "w[edge]: " << w[edge] << endl;
                if(!th[edge]){
                    q.push(edge);
                    th[edge] = true;
                    in[edge]++;
                    if(in[edge]>N) return -2;
                }
            }
        }
    }
    return 1;
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(th, 0, sizeof(th));
    for(int i = 0; i<N; i++){
        dist[i] = 0;
    }
    memset(in, 0, sizeof(in));
    int n, m;
    int x, y, z;
    int A, B;
    double zz;
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &x, &y, &z);
        zz = (100.0 - z)/100;
        //cout << "zz: " << zz << endl;
        add_edge(x, y, zz);
        add_edge(y, x, zz);
    }
    cin >> A >> B;
    spfa(A);
    //cout << "dist: " << dist[B] << endl;
    if(dist[B]!=0){
        printf("%.8f", 100/dist[B]);
    }
    return 0;
}
