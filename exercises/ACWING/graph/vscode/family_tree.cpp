#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 100010;
int h[N], e[2*N], ne[2*N], idx;
int in[N];
queue<int> que;
vector<int> result;
int n;

void add (int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool torpsort()
{
    for(int i = 1; i<=n; i++){
        if(in[i] == 0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int item = que.front();
        que.pop();
        result.push_back(item);
        for(int i = h[item]; ~i; i = ne[i]){
            int j = e[i];
            in[j]--;
            if(in[j]==0){
                que.push(j);
            }
        }
    }
    if(result.size()!=n){
        return false;
    }
    else{
        return true;
    }
}

int main()
{
    memset(h, -1, sizeof(h));
    memset(in, 0, sizeof(in));
    idx = 0;
    cin >> n;
    int i = 1; 
    while(i<=n){
        int a;
        scanf("%d", &a);
        if(a == 0){
            i++;
        }else{
            add(i, a);
            in[a]++;
        }
    }
    if(torpsort()){
        printf("%d", result[0]);
        for(i = 1; i<n; i++){
            printf(" %d", result[i]);
        }
    }
    else{
        puts("-1");
    }
    return 0;
}
