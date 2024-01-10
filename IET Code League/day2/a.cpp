#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505;
const int A = 8899;
const int B = 15130;
const int C = 10093;

int n, m;
string s[N];
bool vis[N][N];

bool bfs(int sx, int sy){
    queue<pair<int,int>> q;
    bool ret = true;
    int area = 0;
    q.push({sx,sy});
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(vis[x][y]) continue;
        if(x == 0 || x == n-1 || y == 0 || y == m-1) ret = false;
        vis[x][y] = true;
        area++;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(abs(i)+abs(j) == 1){
                    int xx = x+i, yy = y+j;
                    if(xx < n && xx >= 0 && yy < m && yy >= 0 && s[xx][yy] == '1')
                        q.push({x+i,y+j});
                } 
            }
        }
    }
    return (ret && area > 25);
}

void solve() {
    int ans = 0, a = false, b = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '0') continue;
            if(vis[i][j]) continue;
            if(bfs(i, j)) ans++;
        }
    }
    // cout << ans << "\n";
    if(ans == 0) cout << "C";
    else if(ans == 1) cout << "A";
    else cout << "B";
    // else cout << "C";
    // if(ans == 1) cout << "C";
    // else if(ans == 2) cout << "A";
    // else cout << "B";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}