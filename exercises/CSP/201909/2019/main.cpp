#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct goods
{
    int type;
    int recom;
    int name;
    goods(int _t, int _r, int _n) : type(_t), recom(_r), name(_n) {}
    bool operator<(const goods & g) const
    {
        if(recom == g.recom){
            if(type == g.type) return name>g.name;
            else return type>g.type;
        }
        else return recom<g.recom;
    }
};

int m, n;
const int mMax = 51;
map<int, set<int>, greater<int>> shop[mMax];
map<int, set<int>, greater<int>>::iterator shop_iter;
map<int, int> shop_menu[mMax];
map<int, int>::iterator shop_menu_iter;

int main()
{
    scanf("%d %d", &m, &n);
    int rec, name;
    int opnum;
    int optype, op1, op2, op3;
    int search_rec;
    int K, ki;
    for(int i = 0; i<n; i++){
        scanf("%d %d", &name, &rec);
        for(int j = 0; j<m; j++){
            shop[j][rec].insert(name);
            shop_menu[j][name] = rec;
        }
    }
    scanf("%d", &opnum);
    for(int i = 0; i<opnum; i++){
        scanf("%d", &optype);
        switch(optype)
        {
        case 1:
            scanf("%d %d %d", &op1, &op2, &op3);
            shop[op1][op3].insert(op2);
            shop_menu[op1][op2] = op3;
            break;
        case 2:
            scanf("%d %d", &op1, &op2);
            search_rec = shop_menu[op1][op2];
            shop[op1][search_rec].erase(op2);
            if(shop[op1][search_rec].empty()){
                shop[op1].erase(search_rec);
            }
            shop_menu[op1].erase(op2);
            break;
        case 3:
            scanf("%d", &K);
            priority_queue<goods> func3;
            for(int j = 0; j<m; j++){
                scanf("%d", &ki);
                shop_iter = shop[j].begin();
                while(shop_iter!=shop[j].end() && ki != 0){
                    set<int>::iterator h = (shop_iter->second).begin();
                    while(h != (shop_iter->second).end() && ki != 0){
                        func3.push(goods(j, shop_iter->first, *h));
                        h++;
                        ki--;
                    }
                    shop_iter++;
                }
            }
            vector<int> ans[m];
            while(K>0 && !func3.empty()){
                ans[func3.top().type].push_back(func3.top().name);
                func3.pop();
                K--;
            }
            for(int j = 0; j<m; j++){
                if(ans[j].empty()){
                    puts("-1");
                }
                else{
                    for(int rrr:ans[j]){
                        printf("%d ", rrr);
                    }
                    puts("");
                }
            }
            break;
        }
    }
    return 0;
}
