#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
#define node pair<int, int>
#define ll long long
int thitaMaxNow;
ll result;
map<int, node> datas;
map<int, node>::iterator iter;

int main()
{
    int m;
    int y, r;
    scanf("%d", &m);
    for(int i = 0; i<m; i++){
        scanf("%d %d", &y, &r);
        if(r){
            datas[y].first++;
        }
        else{
            datas[y].second++;
        }
    }
    for(auto d:datas){
        result += d.second.first;
        //cout << d.first << ": " << d.second.first << " " << d.second.second <<endl;
    }
    ll item = result;
    iter = datas.begin();
    thitaMaxNow = iter->first;
    for(auto d:datas){
        iter++;
        item = item - d.second.first;
        item += d.second.second;
        if(item>=result){
            result = item;
            if(iter!=datas.end()){
                thitaMaxNow = iter->first;
            }
        }
    }
    cout << thitaMaxNow;
    return 0;
}
