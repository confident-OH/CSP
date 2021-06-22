#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef pair<int, int> PII;

const int n = 20010;
deque<PII> q;

int h[n], ne[n], e[n], d[n], idx;
int dist[n];
bool th[n];
int N, P, K;

int mid_res, start_res, end_res;

int result;

void add(int a, int b, int c)
{
    e[idx] = b; d[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}
// 双队列优化后的dijk
int dijk(int start)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(th, 0, sizeof(th));
    q.push_back({0, start});
    dist[start] = 0;
    while(!q.empty()){
        PII item = q.front();
        q.pop_front();
        if(th[item.second]) continue;
        th[item.second] = true;
        for(int i = h[item.second]; ~i; i = ne[i]){
            int j = e[i];
            int dj = 0;
            if(d[i]>mid_res) dj = 1;
            if(dist[j]>item.first+dj){
                dist[j] = item.first+dj;
                if(dj == 0){
                    q.push_front({dist[j], j});
                }
                else{
                    q.push_back({dist[j], j});
                }
            }
        }
    }
    if(dist[N]==0x3f3f3f3f)return -1;
    else return dist[N];
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> N >> P >> K;
    int a, b, c;
    for(int i = 0; i<P; i++){
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    start_res = 0;
    end_res = 1000001;
    bool is_linked = true;
    while(start_res<end_res){
        mid_res = (start_res+end_res) >> 1;
        int now_dist = dijk(1);
        if(now_dist == -1){
            cout << -1 << endl;
            is_linked = false;
            break;
        }
        if(now_dist>K) start_res = mid_res+1;
        else{
            end_res = mid_res;
        }
    }
    if(is_linked) cout << start_res << endl;
    return 0;
}
