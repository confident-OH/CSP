#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int dp1[N], dp2[N];
int arr[N];
int n;

int main()
{
    cin >> n;
    int result = 0;
    int item;
    for(int i = 1; i<=n; i++){
        cin >>  arr[i];
        dp1[i] = 1;
        dp2[i] = 1;
    }
    for(int i = n-1; i>=1; i--){
        for(int j = n; j>i; j--){
            if(arr[i] > arr[j]){
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<i; j++){
            if(arr[i] > arr[j]){
                dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        item = dp1[i]+dp2[i]-1;
        result = max(item, result);
    }
    cout << n - result;
    return 0;
}
