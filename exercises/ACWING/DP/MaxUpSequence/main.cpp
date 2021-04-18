#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int dp[N];
int nums[N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> nums[i];
    }
    for(int i = 1; i<=n; i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int result = 0;
    for(int i = 1; i<=n; i++){
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}
