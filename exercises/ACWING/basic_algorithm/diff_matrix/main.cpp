#include <iostream>
#include <cstdio>

using namespace std;
int n, m, q;
int s[1010][1010], A[1010][1010];
void insertMy(int x1, int y1, int x2, int y2, int c)
{
    s[x1][y1]+=c;
    s[x1][y2+1]-=c;
    s[x2+1][y1]-=c;
    s[x2+1][y2+1]+=c;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    int items;
    int x1, y1, x2, y2, c;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf("%d", &items);
            insertMy(i, j, i, j, items);
        }
    }
    for(int i = 1; i<=q; i++){
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
        insertMy(x1, y1, x2, y2, c);
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            A[i][j] = A[i-1][j]+A[i][j-1]-A[i-1][j-1]+s[i][j];
            printf("%d ", A[i][j]);
        }
        puts("");
    }
    return 0;
}
