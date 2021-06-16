#include <iostream>

using namespace std;

const int N = 1010;
int dp[N][N];
int w[N];

int sumMy(int l, int r){
    int result = 0;
    for(int i = l; i<=r; i++){
        result+=w[i];
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> w[i];
        dp[i][i] = 0;
    }
    int item;
    for(int i = 2; i<=n; i++){
        // length of gap
        for(int j = 1; j<=n-i+1; j++){
            item = 1e9;
            // start node
            for(int k = 0; k<i-1; k++){
                // offset
                item = min(item, dp[j][j+k] + dp[j+k+1][j+i-1]);
            }
            dp[j][j+i-1] = item+sumMy(j, j+i-1);
        }
    }
    cout << dp[1][n];
    return 0;
}
