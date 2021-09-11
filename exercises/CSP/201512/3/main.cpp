#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

char picture[110][110];
int m, n, p;

void colorFit(int a, int b, char f)
{
    bool th[110][110];
    memset(th, 0, sizeof(th));
    picture[a][b] = f;
    vector<PII> v;
    v.push_back({a, b});
    th[a][b] = true;
    while(!v.empty()){
        auto item = v.back();
        v.pop_back();
        int x = item.first;
        int y = item.second;
        if((x>0) && !th[x-1][y] && (picture[x-1][y]!='+' && picture[x-1][y]!='-' && picture[x-1][y]!='|')){
            picture[x-1][y] = f;
            v.push_back({x-1, y});
            th[x-1][y] = true;
        }
        if((x<m-1) && !th[x+1][y] && (picture[x+1][y]!='+' && picture[x+1][y]!='-' && picture[x+1][y]!='|')){
            picture[x+1][y] = f;
            v.push_back({x+1, y});
            th[x+1][y] = true;
        }
        if((y>0) && !th[x][y-1] && (picture[x][y-1]!='+' && picture[x][y-1]!='-' && picture[x][y-1]!='|')){
            picture[x][y-1] = f;
            v.push_back({x, y-1});
            th[x][y-1] = true;
        }
        if((y<n-1) && !th[x][y+1] && (picture[x][y+1]!='+' && picture[x][y+1]!='-' && picture[x][y+1]!='|')){
            picture[x][y+1] = f;
            v.push_back({x, y+1});
            th[x][y+1] = true;
        }
    }
}

int main()
{
    memset(picture, '.', sizeof(picture));
    cin >> m >> n >> p;
    int label, x1, y1, x2, y2;
    char fit[2];
    for(int i = 0; i<p; i++){
        cin >> label >> x1 >> y1;
        if(label == 1){
            cin >> fit;
            colorFit(x1, y1, fit[0]);
        }
        else{
            cin >> x2 >> y2;
            if(x1 == x2){
                for(int j = min(y1, y2); j<=max(y1, y2); j++){
                    if(picture[x1][j] == '-'){
                        picture[x1][j] = '+';
                    }
                    else{
                        picture[x1][j] = '|';
                    }
                }
            }
            else {
                for(int j = min(x1, x2); j<=max(x1, x2); j++){
                    if(picture[j][y1] == '|'){
                        picture[j][y1] = '+';
                    }
                    else{
                        picture[j][y1] = '-';
                    }
                }

            }
        }
    }

    // Êä³ö×Ö·û»­
    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<m; j++){
            cout << picture[j][i];
        }
        cout << endl;
    }
    return 0;
}
