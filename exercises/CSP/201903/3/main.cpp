#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

unsigned int my_atoi(string item)
{
    unsigned int result = 0;
    for(int i = 0; i<8; i++){
        result = result << 4;
        if(item[i]>='0' && item[i]<='9'){
            result += item[i] - '0';
        }
        else{
            result += item[i] - 'A'+ 10;
        }
    }
    return result;
}

void num_print(char *ch, unsigned int num)
{
    ch[8] = 0;
    for(int i = 0; i<8; i++){
        unsigned int item = 0xf;
        item = item << (4*i);
        item = item & num;
        item = item >> (4*i);
        if(item > 9){
            ch[7-i] = 'A' + item - 10;
        }
        else{
            ch[7-i] = '0' + item;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, s, l;
    vector<unsigned int> datas[1001];
    cin >> n >> s >> l;
    int diskId;
    int blen = 0;
    string dataLine;
    for(int i = 0; i<l; i++){
        cin >> diskId;
        cin >> dataLine;
        for(int j = 0; j<dataLine.size();j += 8){
            unsigned int item = my_atoi(dataLine.substr(j,8));
            datas[diskId].push_back(item);
            //printf("%x\n", item);
        }
    }
    blen = dataLine.size()/8;
    if(l == n-1){
        for(int i = 0; i<n; i++){
            if(datas[i].empty()){
                for(int j = 0; j<blen; j++){
                    unsigned int item = 0;
                    for(int k = i-1; k>=0; k--){
                        item ^= datas[k][j];
                    }
                    for(int k = i+1; k<n; k++){
                        item ^= datas[k][j];
                    }
                    datas[i].push_back(item);
                    //printf("%x\n", item);
                }
                break;
            }
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i<m; i++){
        unsigned int b;
        cin >> b;
        unsigned int disk, td, ntd, x, y;
        td = b / s;
        disk = td%n;
        ntd = td/(n-1);
        if(datas[disk].empty()){
            printf("-\n");
            continue;
        }
        x = disk;
        y = ntd * s + b%s;
        if(y >= blen){
            printf("-\n");
            continue;
        }
        char number[10];
        num_print(number, datas[x][y]);
        printf("%s\n", number);
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;
const int N = 1010, M = 40 * 1024 * 8 + 10;
unsigned int datas[N][M>>3];
bool labels[N];
unsigned int my_atoi(char *item)
{
    unsigned int result = 0;
    for(int i = 0; i<8; i++){
        result = result << 4;
        if(item[i]>='0' && item[i]<='9'){
            result += item[i] - '0';
        }
        else{
            result += item[i] - 'A'+ 10;
        }
    }
    return result;
}

void num_print(char *ch, unsigned int num)
{
    ch[8] = 0;
    for(int i = 0; i<8; i++){
        unsigned int item = 0xf;
        item = item << (4*i);
        item = item & num;
        item = item >> (4*i);
        if(item > 9){
            ch[7-i] = 'A' + item - 10;
        }
        else{
            ch[7-i] = '0' + item;
        }
    }
}

char stline[M];

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    int n, s, l;
    scanf("%d %d %d", &n, &s, &l);
    getchar();
    int diskId;
    int blen = 0;
    for(int i = 0; i<l; i++){
        scanf("%d", &diskId);
        getchar();
        fgets(stline, M, stdin);
        labels[diskId] = true;
        blen = (strlen(stline) - 1) >> 3;
        for(int j = 0; j<blen;j++){
            unsigned int item = my_atoi(stline + (j<<3));
            datas[diskId][j] = item;
            //printf("%x\n", item);
        }
    }
    if(l == n-1){
        for(int i = 0; i<n; i++){
            if(!labels[i]){
                for(int j = 0; j<blen; j++){
                    unsigned int item = 0;
                    for(int k = i-1; k>=0; k--){
                        item ^= datas[k][j];
                    }
                    for(int k = i+1; k<n; k++){
                        item ^= datas[k][j];
                    }
                    datas[i][j]=item;
                    //printf("%x\n", item);
                }
                break;
            }
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i<m; i++){
        unsigned int b;
        scanf("%u", &b);
        unsigned int disk, td, ntd, x, y;
        td = b / s;
        disk = td%n;
        ntd = td/(n-1);
        x = disk;
        y = ntd * s + b%s;
        if(y >= blen){
            printf("-\n");
            continue;
        }
        char number[10];
        num_print(number, datas[x][y]);
        printf("%s\n", number);
    }
    return 0;
}
*/
