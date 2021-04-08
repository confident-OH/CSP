#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
int xiangsu[1100][2000];
int blocks_r[1100][2000];
int block_b[1100][2000];
int block_g[1100][2000];

void print_color(int a)
{
    if(a>0){
        print_color(a/10);
    }
    else{
        return;
    }
    int i = a%10;
    switch(i){
    case 0:
        printf("\x30");
        break;
    case 1:
        printf("\x31");
        break;
    case 2:
        printf("\x32");
        break;
    case 3:
        printf("\x33");
        break;
    case 4:
        printf("\x34");
        break;
    case 5:
        printf("\x35");
        break;
    case 6:
        printf("\x36");
        break;
    case 7:
        printf("\x37");
        break;
    case 8:
        printf("\x38");
        break;
    case 9:
        printf("\x39");
        break;
    }
}

int main()
{
    int m, n;
    int p, q;
    scanf("%d %d", &m, &n);
    getchar();
    scanf("%d %d", &p, &q);
    getchar();
    char str[10];
    char number[10] = "0x";
    number[8] = '\0';
    int color_item;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            fgets(str, 10, stdin);
            if(strlen(str) == 3){
                for(int k = 2; k<=7; k++){
                    number[k] = str[1];
                }
                sscanf(number, "%x", &color_item);
            }
            else if(strlen(str) == 5){
                number[2] = str[1];
                number[3] = str[1];
                number[4] = str[2];
                number[5] = str[2];
                number[6] = str[3];
                number[7] = str[3];
                sscanf(number, "%x", &color_item);
            }
            else{
                number[2] = str[1];
                number[3] = str[2];
                number[4] = str[3];
                number[5] = str[4];
                number[6] = str[5];
                number[7] = str[6];
                sscanf(number, "%x", &color_item);
            }
            blocks_r[j/q][i/p] += color_item & 0xff;
            block_b[j/q][i/p] += (color_item >> 8) & 0xff;
            block_g[j/q][i/p] += (color_item >> 16) & 0xff;
        }
    }
    int mult = p*q;
    int real_n = n/q;
    int real_m = m/p;
    int pre_r = 0;
    int pre_b = 0;
    int pre_g = 0;
    int r, b, g;
    //output:
    for(int i = 0; i<real_n; i++){
        for(int j = 0; j<real_m; j++){
            r = blocks_r[i][j] / mult;
            b = block_b[i][j] / mult;
            g = block_g[i][j] / mult;
            if(r == pre_r && b == pre_b && g == pre_g){
            }
            else{
                pre_r = r;
                pre_b = b;
                pre_g = g;
                if(r == 0 && b == 0 && g == 0){
                    printf("\x1B\x5B\x30\x6D");
                }else{
                    printf("\x1B\x5B\x34\x38\x3B\x32");
                    printf("\x3B");
                    print_color(r);
                    printf("\x3B");
                    print_color(b);
                    printf("\x3B");
                    print_color(g);
                    printf("\x6D");
                }
            }
            printf("\x20");
        }
        if(pre_r!=0 || pre_g!=0 || pre_b!=0){
            printf("\x1B\x5B\x30\x6D\x0A");
            pre_r = 0;
            pre_b = 0;
            pre_g = 0;
        }else{
            printf("\x0A");
        }
    }
    return 0;
}
