#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n;
const int Max = 3010;
int h[Max], ne[Max], e[Max], w[Max], idx;
bool th[Max];
int a[Max];
int sums[Max];
int in[Max];
queue<int> q;

void init()
{
    memset(h, -1, sizeof(h));
    memset(sums, 0, sizeof(sums));
}

void add(int a, int b, int c)
{
    e[idx] = b; w[idx] = c; ne[idx] = h[a]; h[a] = idx++;
}

void spfa(int start)
{
    queue<int>qq;
    for(int i = 0; i<=n; i++){
        qq.push(i);
        th[i]=true;
        sums[i]=0;
        in[i]=1;
    }
     while(!qq.empty())
     {
         int x=qq.front();
         qq.pop();
         in[x]++;
         th[x]=false;
         if(in[x]>n){
            cout<<"noanswer"<<endl;
            return ;
         }
         for(int i=h[x];i!=-1;i=ne[i])
         {
             int nx=e[i];
             if(sums[nx]<sums[x]+w[i])
             {
                 sums[nx]=sums[x]+w[i];
                 if(!th[nx])
                 {
                     th[nx]=1;
                     qq.push(nx);
                 }
             }
         }
     }
     return ;
}

int main()
{
    init();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        add(i, i+1, 1);
    }
    add(0, 2, 2*a[1]);
    add(2, 0, -2*a[1] - 1);
    for(int i = 2; i<n; i++){
        add(i - 2, i+1, 3*a[i]);
        add(i+1, i - 2, -3*a[i] - 2);
    }
    add(n-2, n, 2*a[n]);
    add(n, n-2, -2*a[n]-1);
    spfa(0);
    for(int i = 0; i<n; i++){
        cout << sums[i+1] - sums[i] << " ";
    }
    return 0;
}
