#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3 + 5;
int f[N][N];

void update(int x, int y){
    for(int i = x; i < N; i += i & -i){
        for(int j = y; j < N; j += j & -j){
            f[i][j]++;
        }
    }
}

int sum(int x, int y){
    int ret = 0;
    for(int i = x; i > 0; i -= i & -i){
        for(int j = y; j > 0; j -= j & -j){
            ret += f[i][j];
        }
    }
    return ret;
}

void solve() {
    fill_n(f[0], N*N, 0);
    int q;
    cin >> q;
    set<pair<int,int>> s;
    while(q--){
        int k;
        cin >> k;
        if(k == 0){
            int x, y;
            cin >> x >> y;
            x++, y++;
            if(s.count({x,y})) continue;
            update(x,y);
            s.insert({x,y});
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1++, y1++;
            x2++, y2++;
            cout << sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solve();
    }
}