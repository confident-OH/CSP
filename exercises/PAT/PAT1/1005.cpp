#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    long long int result = 0;
    vector<int> va;
    char c;
    int item;
    while((c = getchar())!='\n'){
        result+=(long long int)(c - '0');
    }
    if(result == 0){
        cout << "zero";
        return 0;
    }
    while(result!=0){
        va.push_back(result%10);
        result/=10;
    }
    item = va.back();
    va.pop_back();
    switch(item){
        case 0:
            {
                cout << "zero";
                break;
            }
        case 1:
            {
                cout << "one";
                break;
            }
        case 2:
            {
                cout << "two";
                break;
            }
        case 3:
            {
                cout << "three";
                break;
            }
        case 4:
            {
                cout << "four";
                break;
            }
        case 5:
            {
                cout << "five";
                break;
            }
        case 6:
            {
                cout << "six";
                break;
            }
        case 7:
            {
                cout << "seven";
                break;
            }
        case 8:
            {
                cout << "eight";
                break;
            }
        case 9:
            {
                cout << "nine";
                break;
            }
        default:
            {
                cout << "error!";
            }
    }
    while(!va.empty()){
        item = va.back();
        va.pop_back();
        switch(item){
            case 0:
                {
                    cout << " zero";
                    break;
                }
            case 1:
                {
                    cout << " one";
                    break;
                }
            case 2:
                {
                    cout << " two";
                    break;
                }
            case 3:
                {
                    cout << " three";
                    break;
                }
            case 4:
                {
                    cout << " four";
                    break;
                }
            case 5:
                {
                    cout << " five";
                    break;
                }
            case 6:
                {
                    cout << " six";
                    break;
                }
            case 7:
                {
                    cout << " seven";
                    break;
                }
            case 8:
                {
                    cout << " eight";
                    break;
                }
            case 9:
                {
                    cout << " nine";
                    break;
                }
            default:
                {
                    cout << " error!";
                }
        }
    }
    return 0;
}
