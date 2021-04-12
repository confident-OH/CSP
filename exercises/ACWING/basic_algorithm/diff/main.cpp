#include <iostream>
#include <cstdio>

using namespace std;
const int Max = 100010;
int arr[Max];
int diff[Max];
int n, m;

void insertMy(int i, int j, int c)
{
    diff[i]+=c;
    diff[j+1]-= c;
}
int main()
{
    scanf("%d %d", &n, &m);
    int s, e, w;
    for(int i = 1; i<=n; i++){
        scanf("%d", &arr[i]);
        insertMy(i, i, arr[i]);
    }
    for(int i = 0; i<m; i++){
        scanf("%d %d %d", &s, &e, &w);
        insertMy(s, e, w);
    }
    for(int i = 1; i<=n; i++){
        arr[i] = arr[i-1]+diff[i];
        printf("%d ", arr[i]);
    }
    return 0;
}
