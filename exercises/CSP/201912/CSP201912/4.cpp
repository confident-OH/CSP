#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <queue>
#include <vector>
#define N 520
#define M 10010
using namespace std;
typedef vector<int> VI;
vector<VI> links;
int e[M], blocks[N], head[M], ind;
int t;
int node[N];
struct OP
{
    int t, m, vi, vo;
    bool operator< (const OP& r) const {
        return t>r.t;
    }
};
priority_queue<OP> heap;

void add (int a, int b) //a->b
{
    e[ind] = b;
    head[ind] = blocks[a];
    blocks[a] = ind;
    ind++;
}

void eval()
{
    auto work = heap.top();
    heap.pop();
    int num = work.m;
    auto &a = links[node[num]], &b = links[work.vo];
    if(a.size()<b.size() || a.size() == b.size() && a.back()>b.back()){
        node[num] = work.vo;
        for(int i = blocks[num]; ~i; i = head[i]){
            if(e[i] !=num && e[i] != work.vi)
                heap.push({work.t + t, e[i], num, node[num]});
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    memset(head, -1, sizeof(head));
    memset(blocks, -1, sizeof(blocks));
    int x, y;
    for (int i = 0; i<m; i++){
        scanf("%d %d", &x, &y);
        getchar();
        add(x, y);
        add(y, x);
    }
    int k;
    scanf("%d %d", &t, &k);
    getchar();
    char str[50];
    links.push_back({0});
    for(int i = 0; i<k; i++){
        fgets(str, 50, stdin);
        stringstream ssin(str);
        int a[3], cnt = 0;
        while(ssin>>a[cnt]) cnt++;
        if(cnt == 3){
            while(!heap.empty() && heap.top().t <= a[1]) eval();
            links.push_back(links[node[a[0]]]);
            links.back().push_back(a[2]);
            node[a[0]] = links.size() - 1;
            for(int i = blocks[a[0]]; ~i; i = head[i]){
                if(e[i]!=a[0]){
                    heap.push({a[1]+t, e[i], a[0], node[a[0]]});
                }
            }
        }else{
            while(!heap.empty() && heap.top().t <= a[1]) eval();
            printf("%d", links[node[a[0]]].size());
            for(auto j:links[node[a[0]]]){
                printf(" %d", j);
            }
            puts("");
        }
    }
    return 0;
}

/*
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> VI;
const int N = 510, M = 20010;

int n, m, w, Q;
int h[N], e[M], ne[M], idx;
vector<VI> g;
int node[N];

struct Op
{
    int t, id, pid, hid;
    bool operator< (const Op& r) const
    {
        return t > r.t;
    }
};
priority_queue<Op> heap;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void eval()
{
    auto t = heap.top();
    heap.pop();

    auto &a = g[node[t.id]], &b = g[t.hid];
    if (b.size() > a.size() || b.size() == a.size() && b.back() < a.back())
    {
        node[t.id] = t.hid;
        for (int i = h[t.id]; ~i; i = ne[i])
            if (e[i] != t.pid && e[i] != t.id)
                heap.push({t.t + w, e[i], t.id, t.hid});
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    g.push_back({0});
    memset(h, -1, sizeof h);
    while (m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    scanf("%d%d", &w, &Q);
    getchar();
    char str[100];
    while (Q -- )
    {
        fgets(str, 100, stdin);
        stringstream ssin(str);
        int a[3], cnt = 0;
        while (ssin >> a[cnt]) cnt ++ ;
        if (cnt == 3)
        {
            while (heap.size() && heap.top().t <= a[1]) eval();
            g.push_back(g[node[a[0]]]);
            g.back().push_back(a[2]);
            node[a[0]] = g.size() - 1;
            for (int i = h[a[0]]; ~i; i = ne[i])
                if (e[i] != a[0])
                    heap.push({a[1] + w, e[i], a[0], node[a[0]]});
        }
        else
        {
            while (heap.size() && heap.top().t <= a[1]) eval();
            printf("%d ", g[node[a[0]]].size());
            for (auto x: g[node[a[0]]])
                printf("%d ", x);
            puts("");
        }
    }
    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/913488/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
