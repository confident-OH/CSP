#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;
PII arr[N];
int timeMin[N][N];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    for(int i = 1; i<=n; i++)
    {
        timeMin[1][i] = 1;
    }
    for(int i = 2; i<=n; i++){
        for(int j = 1; j<=n; j++){

        }
    }
    return 0;
}
