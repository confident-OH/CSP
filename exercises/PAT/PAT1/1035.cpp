#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int NI = 0, NO = 0, line_l = 0;
    vector<string> arrays;
    char info[25];
    scanf("%d", &NI);
    getchar();
    int j;
    for(int i = 0; i<NI; i++){
        line_l = 0;
        fgets(info, 25, stdin);
        j = 0;
        while(info[j]!=' '){
            j++;
        }
        j++;
        while(info[j]!='\n'){
            switch(info[j])
            {
                case '1':
                {
                    info[j] = '@';
                    line_l = 1;
                    break;
                }
                case 'l':
                {
                    info[j] = 'L';
                    line_l = 1;
                    break;
                }
                case '0':
                    {
                        info[j] = '%';
                        line_l = 1;
                        break;
                    }
                case 'O':
                    {
                        info[j] = 'o';
                        line_l = 1;
                        break;
                    }
            }
            j++;
        }
        if(line_l){
            arrays.push_back(string(info));
            NO++;
        }
    }
    if(NO){
        cout << NO << endl;
        for(int i = 0; i<NO; i++){
            cout << arrays[i];
        }
    }
    else{
        if(NI == 1){
            printf("There is 1 account and no account is modified\n");
        }
        else{
            printf("There are %d accounts and no account is modified\n", NI);
        }
    }
    return 0;
}

// 字符串的题目一定要注意审题
