#include<bits/stdc++.h>
using namespace std;

const int N = 305;

int a[N][N], dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1}, n, m;
// N S E W

int change(int x, int now){
    if(x == 11){
        if(now == 2) now = 0;
        else if(now == 1) now = 3;
    }
    else if(x == 12){
        if(now == 1) now = 2;
        else if(now == 3) now = 0;
    }
    else if(x == 13){
        if(now == 2) now = 1;
        else if(now == 0) now = 3;
    }
    else if(x == 14){
        if(now == 3) now = 1;
        else if(now == 0) now = 2;
    }
    return now;
}

int bfs(int x, int y, int now){
    if(x < 0 || x > n-1 || y < 0 || y > m-1) return 0;
    now = change(a[x][y], now);
    if(a[x][y] == 31){
        if(now == 0 || now == 1) a[x][y] = 22;
        else a[x][y] = 21;
    }
    else a[x][y] = 0;
    x += dx[now];
    y += dy[now];
    return 1 + bfs(x, y, now);
}

vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    for(int j = 0; j < m; j++){
        if(a[0][j] == 11 || a[0][j] == 12 || a[0][j] == 21 || a[0][j] == 31){
            ans.push_back(bfs(0, j, 1));
        }
    }
    for(int j = 0; j < m; j++){
        if(a[n-1][j] == 13 || a[n-1][j] == 14 || a[n-1][j] == 21 || a[n-1][j] == 31){
            ans.push_back(bfs(n-1, j, 0));
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i][0] == 11 || a[i][0] == 13 || a[i][0] == 22 || a[i][0] == 31){
            ans.push_back(bfs(i, 0, 2));
        } 
    }
    for(int i = 0; i < n; i++){
        if(a[i][m-1] == 12 || a[i][m-1] == 14 || a[i][m-1] == 22 || a[i][m-1] == 31){
            ans.push_back(bfs(i, m-1, 3));
        }
    }
    cout << ans.size() << "\n";
    for(int i : ans) cout << i << ' ';
}