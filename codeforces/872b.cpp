#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int K = 18;

int mn[K][N], a[N], mx = -1e9;

int find_min(int l, int r){
    int k = 31 - __builtin_clz(r-l+1);
    return min(mn[k][l], mn[k][r-(1<<k)+1]);
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        mn[0][i] = a[i];
        mx = max(mx, a[i]);
    }
    for(int i = 1; i < K; i++){
        for(int j = 0; j < n; j++){
            mn[i][j] = min(mn[i-1][j], mn[i-1][j+(1<<(i-1))]);
        }
    }
    if(k == 1) cout << find_min(0, n-1);
    else if(k >= 3) cout << mx;
    else{
        int ans = -1e9;
        for(int i = 0; i < n-1; i++){
            ans = max(ans, max(find_min(0, i), find_min(i+1, n-1)));
        }
        cout << ans;
    }
}