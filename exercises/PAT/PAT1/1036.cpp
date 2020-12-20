#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    getchar();
    char name[15], genda[10], ID[15];
    int score;
    string m_name, f_name;
    string m_ID, f_ID;
    int m_score = 101, f_score = -1;
    bool f = true, m = true;
    for(int i = 0; i<N; i++){
        scanf("%s %s %s %d", name, genda, ID, &score);
        getchar();
        if(!strcmp(genda, "F")){
            f = false;
            if(score>f_score){
                f_score = score;
                f_name = string(name);
                f_ID = string(ID);
            }
        }
        else{
            m = false;
            if(score<m_score){
                m_score = score;
                m_name = string(name);
                m_ID = string(ID);
            }
        }
    }
    if(!f){
        cout << f_name << " " << f_ID << endl;
    }
    else{
        printf("Absent\n");
    }
    if(!m){
        cout << m_name << " " << m_ID << endl;
    }
    else{
        printf("Absent\n");
    }
    if(f||m){
        cout << "NA" << endl;
    }
    else{
        printf("%d\n", f_score-m_score);
    }
    return 0;
}
