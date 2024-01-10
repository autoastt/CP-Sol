#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 2*n-1; i++){
        cout << "#";
        for(int j = 1; j < 2*n-2; j++){
            cout << (j == i ? "#" : " ");
        }
        cout << "#\n";
    }
}