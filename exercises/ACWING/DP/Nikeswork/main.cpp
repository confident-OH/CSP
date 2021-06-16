#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
vector<PII> arr;
vector<PII>::iterator iter_arr;

const int N = 10010;
int nk[N];

int main()
{
    int n, k;
    cin >> n >> k;
    int a, b;
    for(int i = 0; i<k; i++){
        cin >> a >> b;
        arr.push_back({-a, b});
    }
    sort(arr.begin(), arr.end());
    int lable = n+1;
    bool ccc = true;
    for(PII item:arr){
        while(lable>-item.first){
            lable--;
            nk[lable] = nk[lable+1];
            ccc = true;
        }
        if(ccc){
            nk[lable] = item.second + nk[lable + item.second];
            ccc =false;
        }
        else{
            nk[lable] = min(nk[lable], item.second + nk[lable + item.second]);
        }
    }
    lable--;
    while(lable>0){
        nk[lable] = nk[lable+1];
        lable--;
    }
    cout << n - nk[1];
    return 0;
}
