#include <iostream>
#include <cstring>

using namespace std;

unsigned char R[2000][2000];
unsigned char G[2000][2000];
unsigned char B[2000][2000];
unsigned char r[2000][2000];
unsigned char g[2000][2000];
unsigned char b[2000][2000];

const char ch1[40] = "\\x1B\\x5B\\x34\\x38\\x3B\\x32\\x3B";
const char ch2[40] = "\\x1B\\x5B\\x30\\x6D";
int colMax;

void color_input(char *ch, int row, int col)
{
    int result = 0;
    if(strlen(ch) == 8){
        for(int i = 1; i<=6; i++){
            result = result << 4;
            if(ch[i] >= '0' && ch[i] <= '9'){
                result += ch[i] - '0';
            }
            else{
                result += ch[i] - 'a' + 10;
            }
        }
    }
    else if(strlen(ch) == 5){
        for(int i = 1;  i<=3; i++){
            result = result << 4;
            if(ch[i] >= '0' && ch[i] <= '9'){
                result += ch[i] - '0';
                result = result << 4;
                result += ch[i] - '0';
            }
            else{
                result += ch[i] - 'a' + 10;
                result = result << 4;
                result += ch[i] - 'a' + 10;
            }
        }
    }
    else{
        int item = 0;
        if(ch[1] >= '0' && ch[1] <= '9'){
            item = ch[1] - '0';
        }
        else{
            item = ch[1] - 'a' + 10;
        }
        for(int i = 0; i<6; i++){
            result += item << (i*4);
        }
    }
    B[row][col] = result & 0xff;
    G[row][col] = (result & 0xff00) >> 8;
    R[row][col] = (result & 0xff0000) >> 16;
}

void color_del(int m, int n, int p, int q)
{
    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("R: %d B: %d G: %d\t", R[i][j], G[i][j], B[i][j]);
        }
        puts("");
    }
    */
    int avgnum = p * q;
    for(int i = 0; i<n/q; i++){
        for(int j = 0; j<m/p; j++){
            int colorr = 0, colorg = 0, colorb = 0;
            for(int k = 0; k<q; k++){
                for(int l = 0; l<p; l++){
                    colorr += R[i*q + k][j*p + l];
                    colorg += G[i*q + k][j*p + l];
                    colorb += B[i*q + k][j*p + l];
                }
            }
            r[i][j] = colorr / avgnum;
            g[i][j] = colorg / avgnum;
            b[i][j] = colorb / avgnum;
        }
    }
    /*
    for(int i = 0; i<n/q; i++){
        for(int j = 0; j<m/p; j++){
            printf("r: %d g: %d b: %d\t", r[i][j], g[i][j], b[i][j]);
        }
        puts("");
    }
    */
}

bool needChange(int row, int col)
{
    bool result = true;
    if(col == 0 && r[row][col] == 0 && g[row][col] == 0 && b[row][col] == 0){
        result = false;
        return result;
    }
    if(r[row][col] == r[row][col-1] && g[row][col] == g[row][col-1] && b[row][col] == b[row][col-1]){
        result = false;
        return result;
    }
    return result;
}

void numPrint(int num)
{
    int a[3];
    int i;
    for(i = 0; i<3; i++){
        a[i] = num%10;
        num = num / 10;
        if(num == 0){
            break;
        }
    }
    while(i>=0){
        printf("\\x3%c", a[i] + '0');
        i--;
    }
}

bool howChange(int row, int col)
{
    if(r[row][col] == 0 && g[row][col] == 0 && b[row][col] == 0){
        return false;
    }
    else{
        return true;
    }
}

void output_item(int row, int col)
{
    if(needChange(row, col)){
        if(howChange(row, col)){
            printf("%s", ch1);
            numPrint(r[row][col]);
            printf("\\x3B");
            numPrint(g[row][col]);
            printf("\\x3B");
            numPrint(b[row][col]);
            printf("\\x6D");
        }
        else{
            printf("%s", ch2);
        }
    }
    printf("\\x20");
}

void output_return(int row)
{
    if(r[row][colMax] != 0 || g[row][colMax] != 0 || g[row][colMax] != 0){
        printf("%s", ch2);
    }
    printf("\\x0A");
}

int main()
{
    int m, n, p, q;
    scanf("%d %d %d %d", &m, &n, &p, &q);
    colMax = m/p - 1;
    getchar();
    int num = m*n;
    char line[10];
    for(int i = 0; i<num; i++){
        fgets(line, 10, stdin);
        color_input(line, i/m, i%m);
    }
    color_del(m, n, p, q);
    for(int i = 0; i<n/q; i++){
        for(int j = 0; j<m/p; j++){
            // 处理对应的[i][j]块
            output_item(i, j);
        }
        // 处理换行符
        output_return(i);
    }
    return 0;
}
