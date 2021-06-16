#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 100010;
char tstr[100010];
int trieTree[N][26], cnt[N], idx;
void myInsert(char* str)
{
    int n = 0;
    for(int i = 0; str[i]; i++){
        int item = str[i] - 'a';
        if(!trieTree[n][item]){
            trieTree[n][item] = ++idx;
        }
        n = trieTree[n][item];
    }
    cnt[n]++;
}

int myQuery(char* str)
{
    int n = 0;
    for(int i = 0; str[i]; i++){
        int item = str[i] - 'a';
        if(!trieTree[n][item]) return 0;
        n = trieTree[n][item];
    }
    return cnt[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    char c;
    getchar();
    for(int i = 0; i<n; i++){
        scanf("%c %s", &c, tstr);
        getchar();
        if(c == 'I'){
            myInsert(tstr);
        }
        else{
            printf("%d\n", myQuery(tstr));
        }
    }
    return 0;
}



/* stl×ö·¨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
map<string, int> q;

int main()
{
    int n;
    cin >> n;
    char c;
    string strs;
    for(int i = 0; i<n; i++){
        cin >> c >> strs;
        if(c == 'I'){
            q[strs]++;
        }
        else{
            cout << q[strs] << endl;
        }
    }
    return 0;
}
*/
