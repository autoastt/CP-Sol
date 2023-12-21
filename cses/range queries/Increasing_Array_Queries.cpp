#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
// sparse table
ll a[N], qs[N], next_max[20][N], mx[20][N], sum[20][N];
// sum[i][j] = sum from a[j] to next_max[i][j] - 1

int find_max(int l, int r){
    int k = 31 - __builtin_clz(r-l+1);
    return max(mx[k][l], mx[k][r-(1<<k)+1]);
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        qs[i] = qs[i-1] + a[i];
        mx[0][i] = a[i];
    }
    for(int b = 1; b < 20; b++){
        for(int i = 1; i <= n; i++){
            mx[b][i] = max(mx[b-1][i], mx[b-1][i+(1<<b-1)]);       
        }
    }
    for(int i = 1; i <= n; i++){
        int l = i, r = n;
        while(l <= r){
            int mid = (l+r)/2;
            if(find_max(i, mid) == a[i]) 
                l = mid+1;
            else 
                r = mid-1, next_max[0][i] = mid;
        }
        if(!next_max[0][i]) next_max[0][i] = n+1;
        sum[0][i] = (next_max[0][i]-i) * a[i];
        // cout << i << ' ' << next_max[0][i] << " " << sum[0][i] << "\n";
    }
    next_max[0][n+1] = n+1;
    for(int i = 1; i < 20; i++){
        next_max[i][n+1] = n+1;
        for(int j = 1; j <= n; j++){
            int k = next_max[i-1][j];
            next_max[i][j] = next_max[i-1][k];
            sum[i][j] = sum[i-1][j] + sum[i-1][k];
        }
    }
    while(q--){
        ll x, y, ans = 0;
        cin >> x >> y;
        for(int i = 19; i >= 0; i--){
            if(next_max[i][x] <= y){
                ans += sum[i][x] - qs[next_max[i][x]-1] + qs[x-1];
                x = next_max[i][x];
            }
        }
        if(x <= y) ans += (y-x+1) * a[x] - qs[y] + qs[x-1];
        cout << ans << "\n";
    }
}