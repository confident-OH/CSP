//ac
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char courses[5] = "EMCA";

bool cmp (pair<char, int> a, pair<char, int> b){
    return a.first>b.first;
}

int main(void)
{
    int n, m;
    int ID;
    int scores, sum;
    pair<char, int> x_n;
    vector<pair<char, int>> cpp, avg, math, engl, all[4];
    cin >> n >> m;  //n->man number ; m->search number
    getchar();
    for(int i = 0; i<n; i++){
        cin >> ID;
        sum = 0;
        for(int j = 1; j<4; j++){
            cin >> scores;
            sum+=scores;
            x_n.first = (char)scores;
            x_n.second = ID;
            all[j].push_back(x_n);
        }
        scores = sum/3;
        x_n.first = (char)scores;
        all[0].push_back(x_n);
    }
    for(int i = 0; i<4; i++){
        sort(all[i].begin(), all[i].end(), cmp);
    }
    int result[2],zan[2];
    auto sp = cpp.begin();
    for(int i = 0; i<m; i++){
        cin >> ID;
        result[0] = INT_MAX;
        result[1] = INT_MAX;
        for(int j = 0; j<4; j++){
            for(zan[0] = 1, zan[1]=0,sp = all[3-j].begin();sp!=all[3-j].end()&&zan[0]<=result[0]; sp++){
                zan[1]++;
                if(zan[1]!=1&&(*(sp - 1)).first!=(*sp).first){
                    zan[0] = zan[1];
                }
                if((*sp).second == ID&&zan[0]<=result[0]){
                    result[0] = zan[0];
                    result[1] = j;
                    break;
                }
            }
        }
        if(result[1] == INT_MAX){
            printf("N/A\n");
        }else{
            printf("%d %c\n", result[0], courses[result[1]]);
        }

    }
}
