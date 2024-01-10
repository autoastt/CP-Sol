#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int K = 18;
int mx[5][K][N], a[N][5], ans[5], cnt;

int find_max(int op, int l, int r){
    int k = 31 - __builtin_clz(r-l+1);
    return max(mx[op][k][l], mx[op][k][r-(1<<k)+1]);
}


int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            mx[j][0][i] = a[i][j];
        }
    }
    for(int op = 0; op < m; op++){
        for(int i = 1; i < K; i++){
            for(int j = 0; j < n; j++){
                mx[op][i][j] = max(mx[op][i-1][j], mx[op][i-1][j+(1<<(i-1))]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        int l = i, r = n, mid;
        while(l < r){
            mid = (l + r + 1) / 2;
            int sum = 0, tmp[5];
            for(int op = 0; op < m; op++){
                tmp[op] = find_max(op, i, mid);
                sum += tmp[op];
            }
            if(sum <= k){ 
                if(mid - i + 1 > cnt){
                    cnt = mid - i + 1;
                    for(int op = 0; op < m; op++) ans[op] = tmp[op];
                }
                l = mid;
            }
            else r = mid - 1;
        }
    }
    for(int i = 0; i < m; i++) cout << ans[i] << " ";
}