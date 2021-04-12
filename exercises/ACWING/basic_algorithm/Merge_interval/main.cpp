// 区间合并
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> PII;
vector<PII> itv;

int main()
{
    int n;
    cin >> n;
    int opl, opr;
    for(int i = 0; i<n; i++){
        cin >> opl >> opr;
        itv.push_back({opl, opr});
    }
    sort(itv.begin(), itv.end());
    int result = 1;
    int arrEnd = itv[0].second;
    for(auto item:itv)
    {
        if(item.first<=arrEnd){
            arrEnd = max(item.second, arrEnd);
        }
        else{
            result++;
            arrEnd = item.second;
        }
    }
    cout << result;
    return 0;
}
