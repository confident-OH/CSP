#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int N = 1000;

int dp[N];

void init()
{
    for(int i = 0; i<N; i++){
        dp[i] = INT_MIN;
    }
}

int main()
{
    int n, item;
    init();
    cin >> n;
    for(int i = 1; i<=n; i++){
        for(int j = i; j>=1; j--){
            cin >> item;
            dp[j] = max(dp[j - 1], dp[j]) + item;
        }
    }
    int result = INT_MIN;
    for(int i = 1; i<=n; i++){
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}
