#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
string str[1001];
int dp[11][11];

int main()
{
    int n, m;
    cin >> n >> m;
    string str_test;
    int num;
    for(int i = 0; i<n; i++){
        cin >> str[i];
    }
    for(int i = 0; i<m; i++){
        cin >> str_test >> num;
        int result = 0;
        for(int j = 0; j < n; j++){
            string str_now = str[j];
            int len1 = str_now.size();
            int len2 = str_test.size();
            memset(dp, 0, sizeof(dp));
            for(int k = 1; k<=len1; k++){
                dp[k][0] = k;
            }
            for(int k = 1; k<=len2; k++){
                dp[0][k] = k;
            }
            for(int k = 1; k <=len1; k++){
                for(int l = 1; l<=len2; l++){
                    int item2 = dp[k-1][l-1];
                    if(str_now[k-1] != str_test[l-1]){
                        item2++;
                    }
                    dp[k][l] = min(dp[k-1][l] + 1, dp[k][l-1] + 1);
                    dp[k][l] = min(item2, dp[k][l]);
                }
            }
            if(dp[len1][len2] <= num){
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}
