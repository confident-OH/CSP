#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

struct ways
{
    int dist;
    int a;
    int b;
    ways(int _dist, int _a, int _b):dist(_dist), a(_a), b(_b){}
    bool operator < (const struct ways c) const{
        return dist<c.dist;
    }
};

const int N = 10010;
int n, k;
vector<ways> arr;
int bin_search[N];

int my_find(int a, int b)
{
    if(a == b){
        return -1;
    }
    if(bin_search[a] == -1 && bin_search[b] == -1){
        bin_search[a] = b;
        return b;
    }
    else if(bin_search[a] == -1){
        int t = my_find(a, bin_search[b]);
        if(t!=-1){
            bin_search[b] = t;
        }
        return t;
    }
    else {
        int t = my_find(bin_search[a], b);
        if(t!=-1){
            bin_search[a] = t;
        }
        return t;
    }
}

int main()
{
    memset(bin_search, -1, sizeof(bin_search));
    cin >> n >> k;
    int a, b, c;
    int sum = 0;
    for(int i = 0; i<k; i++){
        cin >> a >> b >> c;
        ways item(c, a, b);
        sum+=c;
        arr.push_back(item);
    }
    sort(arr.begin(), arr.end());
    int min_result = 0;
    for(ways i:arr){
        if(my_find(i.a, i.b)!=-1){
            min_result+=i.dist;
        }
    }
    cout << sum - min_result;
    return 0;
}
