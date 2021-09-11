#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    string small, large, large_pre;
    int label, n, k;
    cin >> small;
    cin >> label;
    cin >> n;
    if(label == 1){
        for(int i = 0; i<n; i++){
            cin >> large;
            for(int j = 0; j<large.size(); j++){
                for(k = 0; k<small.size(); k++){
                    if(small[k] != large[j+k]){
                        break;
                    }
                }
                if(k == small.size()){
                    cout << large << endl;
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i<small.size(); i++){
            if(small[i]>='A' && small[i] <= 'Z'){
                small[i] = small[i] - 'A' + 'a';
            }
        }
        for(int i = 0; i<n; i++){
            cin >> large_pre;
            large = string(large_pre);
            for(int j = 0; j<large.size(); j++){
                if(large[j]>='A' && large[j]<='Z'){
                    large[j] = large[j] - 'A' + 'a';
                }
            }
            for(int j = 0; j<large.size(); j++){
                for(k = 0; k<small.size(); k++){
                    if(small[k] != large[j+k]){
                        break;
                    }
                }
                if(k == small.size()){
                    cout << large_pre << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
