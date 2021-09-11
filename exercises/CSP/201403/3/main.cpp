#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;
char label[27];

int main()
{
    char exe_line[10000];
    string exe, item;
    string start;
    int n;
    fgets(exe_line, 10000, stdin);
    exe_line[strlen(exe_line)-1] = '\0';
    start = string(exe_line);
    int i = 0;
    while(i<start.size()){
        if(i == start.size() - 1){
            label[start[i]-'a'] = 1;
            break;
        }
        else{
            if(start[i+1] == ':'){
                label[start[i] - 'a'] = 2;
                i += 2;
            }
            else{
                label[start[i] - 'a'] = 1;
                i++;
            }
        }
    }
    cin >> n;
    getchar();
    for(int i = 0; i<n; i++){
        string para[27];
        bool labelUsed[27];
        memset(labelUsed, 0, sizeof(labelUsed));
        fgets(exe_line, 10000, stdin);
        exe_line[strlen(exe_line)-1] = '\0';
        exe = string(exe_line);
        // ´¦Àí×Ö·û´®
        string::size_type place = 0;
        while(place == 0 && place != exe.npos){
            place = exe.find(' ');
            item = string(exe, 0, place);
            exe = string(exe, place + 1, exe.size());
        }
        while (place != exe.npos){
            place = 0;
            while(place == 0 && place != exe.npos){
                place = exe.find(' ');
                item = string(exe, 0, place);
                exe = string(exe, place + 1, exe.size());
            }
            int cnt = item[1]-'a';
            if(item[0]!='-') break;
            if(label[cnt] == 0) break;
            if(label[cnt] == 1){
                labelUsed[cnt] = true;
                continue;
            }
            if(place == exe.npos) break;
            place = 0;
            while(place == 0 && place != exe.npos){
                place = exe.find(' ');
                item = string(exe, 0, place);
                //cout << "debug: " << item << endl;
                exe = string(exe, place + 1, exe.size());
            }
            labelUsed[cnt] = true;
            para[cnt] = item;
        }
        cout << "Case " << i+1 << ": ";
        for(int j = 0; j<26; j++){
            if(!labelUsed[j]){
                continue;
            }
            printf("-%c ", j+'a');
            if(label[j] == 2) cout << para[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
