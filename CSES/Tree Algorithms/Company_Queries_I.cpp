#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int par[N][20];

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) cin >> par[i][0];
    for(int i = 1; i < 20; i++){
        for(int j = 1; j <= n; j++){
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    auto lift = [&](int u, int k){
        while(k){
            int x = 31 - __builtin_clz(k);
            u = par[u][x];
            k -= 1 << x;
        }
        return u ? u : -1;
    };
    while(q--){
        int x, k;
        cin >> x >> k;
        cout << lift(x, k) << "\n";
    }
}
