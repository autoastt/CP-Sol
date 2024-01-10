#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int f[N];

void build(int n){
    for(int i = 1; i <= n; i++){
        int j = i + (i & -i);
        if(j <= n) f[j] += f[i];
    }
}

void update(int x, int val, int n){
    for(; x <= n; x += x & -x){
        f[x] += val;
    }
}

int sum(int x){
    int ret = 0;
    for(; x > 0; x -= x & -x){
        ret += f[x];
    }
    return ret;
}

void sol(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> f[i];
    build(n);
    while(q--){
        int k;
        cin >> k;
        if(k == 1){
            int x; 
            cin >> x;
            x++;
            cout << sum(x) - sum(x-1) << "\n";
            update(x, -f[x], n);
        }
        else if(k == 2){
            int x, v;
            cin >> x >> v;
            x++;
            update(x, v, n);
        }
        else{
            int x, y;
            cin >> x >> y;
            x++; y++;
            cout << sum(y) - sum(x-1) << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ":\n";
        sol();
    }
}