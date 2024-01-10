/*
Dynamic Range Sum Queries
2 Sep 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;
ll arr[N], t[N];

void build(int n){
    for(int i = 1; i <= n; i++){
        int j = i + (i & -i);
        if(j <= n) t[j] += t[i];
    }
}

void update(int i, ll x, int n){
    for(; i <= n; i += i & -i){
        t[i] += x;
    }
}

ll sum(int i){
    ll s = 0;
    for(; i > 0; i -= i & -i){
        s += t[i];
    }
    return s;
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        t[i] = arr[i];
    }
    build(n);
    while(q--){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 1){
            update(a, b-arr[a], n);
            arr[a] = b;
        }
        else{
            cout << sum(b) - sum(a-1) << "\n";
        }
    }
}

