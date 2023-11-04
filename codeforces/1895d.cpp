#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int a[N], cnt[32][2];

int main(){
    int n; 
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a[i];
        a[i] = a[i] ^ a[i-1];
        for(int j = 0; j < 32; j++){
            cnt[j][0] += i & 1<<j;
            cnt[j][1] += a[i] & 1<<j;
        }
    }
    for(int j = 0; j < 32; j++){
        if(cnt[j][0] == cnt[j][1]) continue;
        for(int i = 0; i < n; i++){
            a[i] ^= 1<<j;
        }
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}