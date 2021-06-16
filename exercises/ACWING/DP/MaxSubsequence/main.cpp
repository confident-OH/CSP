#include <iostream>

using namespace std;

const int N = 1010;
int dp[N][N];
string str1, str2;

int main()
{
    int n, m;
    cin >> n >> m;
    cin >> str1 >> str2;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] = max(dp[i][j-1], dp[i][j]);
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}
