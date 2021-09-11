#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <map>

using namespace std;

int main()
{
    int m, n;
    char exeLine[100];
    string result_str;
    string holeFile;
    map<string, string> changVar;
    cin >> m >> n;
    getchar();
    for(int i = 0; i<m; i++){
        fgets(exeLine, 100, stdin);
        holeFile += string(exeLine);
    }
    string keyItem, valueItem;
    for(int i = 0; i<n; i++){
        fgets(exeLine, 100, stdin);
        string Item1(exeLine);
        string::size_type pos;
        pos = Item1.find(" ");
        string keyItem = string(Item1, 0, pos);
        string valueItem = string(Item1.substr(pos+2, Item1.size()-2 - pos - 2));
        changVar[keyItem] = valueItem;
    }
    //cout << "debug" << changVar[string("email")] << endl << endl;
    string::size_type StartPosition = 0, EndPosition = 0;
    StartPosition = holeFile.find("{{ ");
    while(StartPosition!=holeFile.npos){
        result_str += string(holeFile.substr(0, StartPosition));
        holeFile = string(holeFile.substr(StartPosition));
        EndPosition = holeFile.find(" }}");
        //cout << endl << "Debug*** result start " << endl << result_str << endl << "*** end" << endl;
        string item = string(holeFile.substr(3, EndPosition - 3)); // item可能要处理首末空格
        //cout << "debug: "<< EndPosition - StartPosition << "***" << item << endl;
        auto iter = changVar.find(item);
        if(iter!=changVar.end()){
            result_str += changVar[item];
        }
        holeFile = string(holeFile.substr(EndPosition+3));
        //cout << endl << "debug*** holefile" << endl << holeFile << endl << "*** end" << endl;
        StartPosition = holeFile.find("{{ ");
    }
    result_str += holeFile;
    cout << result_str;
    return 0;
}
