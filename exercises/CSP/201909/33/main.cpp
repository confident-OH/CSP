#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 10010;
int h[MAXN], e[MAXN], ne[MAXN], idx, d[MAXN];
queue<int> head;
queue<int> result;
int n;

void addEdge(int a, int b)
{
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

bool topsort()
{
    for(int i = 1; i<=n; i++){
        if(d[i] == 0){
            head.push(i);
        }
    }
    while(!head.empty()){
        int item = head.front();
        result.push(item);
        head.pop();
        for(int i = h[item]; ~i; i = ne[i]){
            int j = e[i];
            if(d[j] == 0){
                return false;
            }
            d[j] -- ;
            if(!d[j]){
                head.push(j);
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
    cin >> n;
    for(int i = 1; i<=n; i++){
        int item;
        cin >> item;
        while(item != 0){
            addEdge(i, item);
            //cout << "Debug: addEdget: " << i << "->" << item<< endl;
            d[item] ++;
            cin >> item;
        }
    }
    for(int i = 1; i<=n; i++){
        //cout << i << ": " << d[i] << endl;
    }
    if(topsort()){
        while(!result.empty()){
            cout << result.front() << " ";
            result.pop();
        }
    }
    else{
        cout << "Debug : circle!" << endl;
    }
    return 0;
}
