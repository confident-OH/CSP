#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 100010;
int s[N], v[N];
int result;

void init()
{
    for(int i = 0; i<N; i++){
        s[i] = i;
    }
    memset(v, 0, sizeof(v));
}

pair<int, int> findFa(int a)
{
    if(a == s[a]) return {a, 0};
    pair<int, int> item = findFa(s[a]);
    s[a] = item.first;
    item.second += v[a];
    v[a] = item.second % 3;
    item.second = v[a];
    return item;
}

void update(int a, int b, int op)
{
    pair<int, int> itema = findFa(a);
    pair<int, int> itemb = findFa(b);
    if(itema.first == itemb.first){
        if(op == 2){
            if((itema.second + 3 - itemb.second)%3 != 1){
                result++;
            }
        }
        else{
            if(itema.second % 3 != itemb.second % 3){
                result++;
            }
        }
    }
    else{
        if(op == 2){
            s[itema.first] = itemb.first;
            v[itema.first] = (3 + itemb.second + 1 - itema.second) % 3;
        }
        else{
            s[itema.first] = itemb.first;
            v[itema.first] = (3 + itemb.second - itema.second) % 3;
        }
    }
}

int main()
{
    int n, m;
    init();
    scanf("%d %d", &n, &m);
    int lable, x, y;
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &lable, &x, &y);
        if(x > n || y > n){
            result++;
            continue;
        }
        if(lable == 1){
            if(x == y){
                result++;
                continue;
            }
            update(x, y, lable);
        }
        else{
            update(x, y, lable);
        }
    }
    cout << result;
    return 0;
}
