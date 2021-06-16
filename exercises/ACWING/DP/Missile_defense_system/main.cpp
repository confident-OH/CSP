#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 10100;
int dp[N];
int main()
{
    vector<int> arr;
    int item;
    while(cin >> item){
        arr.push_back(item);
    }
    int max_result = 0;
    for(int i = 1; i<=arr.size(); i++){
        dp[i] = 1;
        for(int j = 1; j<i; j++){
            if(arr[i - 1]<=arr[j - 1]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        max_result = max(max_result, dp[i]);
    }
    cout << max_result << endl;
    vector<int> up;
    up.push_back(300000);
    for(auto num_i:arr){
        bool num_label = true;
        for(int i = 0; i<up.size(); i++){
            if(num_i<=up[i]){
                up[i] = num_i;
                num_label = false;
                break;
            }
        }
        if(num_label){
            up.push_back(num_i);
        }
    }
    cout << up.size() << endl;
    return 0;
}
