#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 100010;
int dp[N];

void init()
{
    for(int i = 0; i<N; i++){
        dp[i] = -1e9;
    }
}

int findp(int l, int r, int item)
{
    int mid;
    while(l<r){
        mid = (l + r + 1) >> 1;
        if(dp[mid] >= item) r = mid - 1;
        else{
            l = mid;
        }
    }
    return l;
}

int main()
{
    int n, item;
    init();
    int l = 0, r = 1;
    cin >> n;
    cin >> item;
    dp[1] = item;
    for(int i = 2; i<=n; i++){
        cin >> item;
        int itemNow = findp(l, r, item);
        if(itemNow == r){
            r++;
            dp[itemNow + 1] = item;
        }
        else dp[itemNow + 1] = min(dp[itemNow + 1], item);
    }
    cout << r;
    return 0;
}
