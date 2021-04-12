// 离散化区间和
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
const int Max = 300010;
int A[Max], sum[Max];
vector<int> alls;
vector<PII> add, query;

int twoFind(int s)
{
    int l = 0;
    int mid;
    int r = alls.size() - 1;
    while(l!=r){
        mid = (l+r)>>1;
        if(alls[mid]<s){
            l = mid+1;
        }
        else{
            if(alls[mid]>s){
                r = mid - 1;
            }
            else{
                l = mid;
                r = mid;
            }
        }
    }
    return r+1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 0; i<n; i++){
        scanf("%d %d", &a, &b);
        add.push_back({a, b});
        alls.push_back(a);
    }
    for(int i = 0; i<m; i++){
        scanf("%d %d", &a, &b);
        query.push_back({a, b});
        alls.push_back(a);
        alls.push_back(b);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for(auto item:add){
        int ind = twoFind(item.first);
        A[ind] += item.second;
    }
    for(int i = 1; i<=alls.size(); i++){
        sum[i] = sum[i-1]+A[i];
    }
    for(auto item:query){
        int indl = twoFind(item.first);
        int indr = twoFind(item.second);
        printf("%d\n", sum[indr] - sum[indl-1]);
    }
    return 0;
}
