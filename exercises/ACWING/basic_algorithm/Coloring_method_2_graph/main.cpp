#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N_MAX = 400040;
int e[N_MAX], h[N_MAX], ne[N_MAX], idx;
int color[N_MAX];
vector<int> c_stack;

bool dfs(int index)
{
    while(!c_stack.empty()){
        int start = c_stack.back();
        c_stack.pop_back();
        for(int i = h[start]; ~i; i = ne[i]){
            int edge = e[i];
            if(color[edge] == 0){
                color[edge] = -color[start];
                c_stack.push_back(edge);
            }
            else{
                if(color[edge] == color[start]){
                    return false;
                }
            }
        }
    }
    return true;
}

void add_edge(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

int main()
{
    int n, m;
    int a, b;
    bool label = true;
    memset(color, 0, sizeof(color));
    memset(h, -1, sizeof(h));
    scanf("%d %d", &n, &m);
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        add_edge(a, b);
        add_edge(b, a);
    }
    for(int i = 1; i<=n; i++){
        if(color[i] == 0){
            color[i] = 1;
            c_stack.push_back(i);
            if(!dfs(i)){
                label = false;
                break;
            }
        }
    }
    if(label){
        cout << "Yes" <<endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}
