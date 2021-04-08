#include <iostream>
#define ll long long
using namespace std;

int w[100010];
int s[100010];

int main()
{
    int n;
    cin >> n;
    ll result = 0;
    for(int i = 0; i<n; i++){
        cin >> w[i] >> s[i];
        result += w[i] * s[i];
    }
    if(result<=0) cout << 0;
    else cout << result;
    return 0;
}
