#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int arr[10] = {1, 0, 3, 0, 8, 0, 9};
    int len = sizeof(arr)/4;
    int gap = 0;
    int item;
    for(int i = 0; i<len; i++){
        if(arr[i]){
            item = arr[i];
            arr[i] = arr[i-gap];
            arr[i-gap] = item;
        }
        else{
            gap++;
        }
    }
    for(int i = 0; i<len; i++)
    {
        printf("%d \n", arr[i]);
    }
    return 0;
}
