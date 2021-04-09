#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, s, d;
const int Max = 200010;
int h[Max], e[Max], ne[Max], idx;
int result;
bool th[Max];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void init()
{
    memset(h, -1, sizeof(h));
}

int dfs(int start){
    int sum = 1, res = 0;
    th[start] = true;
    for(int i = h[start]; i!=-1; i = ne[i]){
        int j = e[i];
        if(!th[j]){
            int item = dfs(j);
            res = max(res, item);
            sum += item;
        }
    }
    res = max(res, n - sum);
    result = min(result, res);
    return sum;
}

int main()
{
    init();
    scanf("%d", &n);
    for(int i = 0; i<n-1; i++){
        scanf("%d %d", &s, &d);
        add(s, d); add(d, s);
    }
    result = 1e5;
    dfs(1);
    cout << result;
    return 0;
}
