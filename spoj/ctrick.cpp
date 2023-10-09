#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int t[N], idx;

// void update(int i, int x){
//     for(i; i > 0; i -= i & -i){

//     }
// }

void sol(){
    int n, idx = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        idx += i+1;
        idx %= n;
        if(idx == 0) idx = n;
        cout << i << " " << idx << "\n";
        t[idx] = i;
    }
    for(int i = 1; i <= n; i++) cout << t[i] << " \n"[i==n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
    }
}