#include <iostream>
#include <cstring>

using namespace std;

int nums[1010];

int main()
{
    memset(nums, 0, sizeof(nums));
    int m, n;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int line;
        cin >> line;
        for(int j = 0; j<line; j++){
            int ind, dis;
            cin >> ind >> dis;
            nums[ind] = dis;
        }
    }
    if(nums[1]<nums[n]){
        int a = 0;
        for(int i = 2; i<=n; i++){
            a+=nums[i];
            cout << a << endl;
        }
    }
    else{
        int a = 0;
        for(int i = n; i>=2; i--){
            a+=nums[i];
            nums[i] = a;
        }
        for(int i = 2; i<=n; i++){
            cout << nums[i] << endl;
        }
    }
    return 0;
}
