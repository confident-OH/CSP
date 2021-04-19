#include <iostream>

using namespace std;

const int N = 1010;
int dp[N][N];

string strn, strm;

int main()
{
    int n, m;
    cin >> n;
    cin >> strn;
    cin >> m;
    cin >> strm;
    int item1, item2, item3;
    for(int i = 1; i<=n; i++){
        dp[i][0] = i;
    }
    for(int i = 1; i<=m; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(strn[i-1] == strm[j-1]){
                item3 = dp[i-1][j-1];
            }
            else{
                item3 = dp[i-1][j-1] + 1;
            }
            item2 = dp[i][j-1] + 1;
            item1 = dp[i-1][j] + 1;
            dp[i][j] = item1;
            dp[i][j] = min(dp[i][j], item2);
            dp[i][j] = min(dp[i][j], item3);
        }
    }
    cout << dp[n][m];
    return 0;
}
