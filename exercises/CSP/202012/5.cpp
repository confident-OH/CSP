#include <iostream>
#include <stdio.h>
#include <string.h>
#define ll long long int
#define maxline 110000
using namespace std;

ll engine[3][4 * maxline];
ll lazy_k[3][4 * maxline];

void memset()
{
    for(int i = 0; i<3; i++){
        memset(engine[i], 0, sizeof(engine[i]));
        memset(lazy_k[i], 0, sizeof(lazy_k[i]));
    }
}

void pushdown(int k, int ind, int l, int r){
    if(lazy_k[ind][k]){
        int gap1 = (r - l + 1) / 2;
        int gap2 = r - l - gap1 + 1;
        lazy_k[ind][k<<1] = lazy_k[ind][k];
        engine[ind][k<<1] += lazy_k[ind][k] * gap1;
        lazy_k[ind][k<<1|1] = lazy_k[ind][k];
        engine[ind][(k<<1)|1] += lazy_k[ind][k] * gap2;
        lazy_k[ind][k] = 0;
    }
}

void update1(int node, int l, int r, int node_l, int node_r, int ind, int v)
{
    if(node_l > r || node_r < l){
        return;
    }
    if(node_l >= l && node_r <= r){
        engine[ind][node] += (node_r - node_l + 1) * v;
        lazy_k[ind][node] += v;
    }
    else{
        pushdown(node, ind, node_l, node_r);
        int midnode = (node_l + node_r)/2;
        if(node_l <= midnode){
            update1(node << 1, l, r, node_l, midnode, ind, v);
        }
        if(node_r > midnode){
            update1((node << 1) | 1, l, r, midnode + 1, node_r, ind, v);
        }
    }
}

ll query (int node, int l, int r, int node_l, int node_r, int ind){
    if(l>node_r || r<node_l) return 0;
    if(l<=node_l&&r>=node_r){
        return engine[ind][node];
    }
    else{
        int mid = (node_l+node_r)/2;
        if(r<mid){
            return query(node<<1, l, r, node_l, mid, ind);
        }
        if(l>mid){
            return query((node<<1)|1, l, r, mid+1, mid, ind);
        }
        return query((node<<1)|1, l, r, mid+1, mid, ind)+query(node<<1, l, r, node_l, mid, ind);
    }
}

int main()
{
    memset();
    ll resultA, resultB, resultC;
    int n, m;
    int workid, rangeR, rangeL, ai, bi, ci, multi;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        scanf("%d", &workid);
        scanf("%d %d", &rangeL, &rangeR);
        switch(workid){
        case 1:
            int add_i;
            for(int i = 0; i < 3; i++){
                scanf("%d", &add_i);
                update1(1, rangeL, rangeR, 1, n, i, add_i);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            ll result[3];
            ll p;
            for(int i = 0; i<3; i++){
                result[i] = query(1, rangeL, rangeR, 1, n, i);
                result[i] %= 1000000007;
                result[i] = result[i] * result[i];
                p += result[i] % 1000000007;
                p %= 1000000007;
            }
            printf("%lld\n", p);
            break;
        }
    }    
    return 0;
}