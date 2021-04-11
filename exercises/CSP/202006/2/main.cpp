#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;

map<int, int>v, u;
map<int, int>::iterator vitor, uitor;
int a, u_num, v_num;
ll result;

int main()
{
    freopen("datas.txt", "r", stdin);
    freopen("re.txt", "w", stdout);
    scanf("%d %d %d", &a, &v_num, &u_num);
    int c, d;
    for(int i = 0; i<v_num; i++){
        scanf("%d %d", &c, &d);
        v.insert({c, d});
    }
    for(int i = 0; i<u_num; i++){
        scanf("%d %d", &c, &d);
        u.insert({c, d});
    }
    for(vitor = v.begin(), uitor = u.begin(); vitor!=v.end() && uitor!=u.end(); ){
        if(vitor->first == uitor->first){
            result += vitor->second * uitor->second;
            vitor++;
            uitor++;
        }
        else if(vitor->first > uitor->first){
            uitor++;
        }
        else{
            vitor++;
        }
    }
    cout << result;
    return 0;
}
