#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

vector<int> adj[N][2], st;
int scc[N], now;
bool vis[N], val[N];

void dfs(int u, int t, int cnt = 0){
    vis[u] = true;
    for(auto v : adj[u][t]){
        if(!vis[v]) dfs(v, t, cnt);
    }
    if(t) scc[u] = cnt;
    else st.push_back(u);
}

pair<int,int> neg(char c, int x, int m){
    if(c == '+') return {x, x + m * (x > m ? -1 : 1)};
    return {x + m * (x > m ? -1 : 1), x};
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        char a, b;
        int aa, bb;
        cin >> a >> aa >> b >> bb;
        auto [x, nx] = neg(a, aa, m);
        auto [y, ny] = neg(b, bb, m);
        adj[nx][0].push_back(y);
        adj[ny][0].push_back(x);
        adj[x][1].push_back(ny);
        adj[y][1].push_back(nx);
    }
    for(int i = 1; i <= 2*m; i++){
        if(!vis[i]) dfs(i, 0);
    }
    fill_n(vis, N, false);
    reverse(st.begin(), st.end());
    for(auto i : st){
        if(!vis[i]) dfs(i, 1, ++now);
    }
    for(int i = 1; i <= m; i++){
        if(scc[i] == scc[i+m]){
            cout << "IMPOSSIBLE";
            return 0;
        }
        else if(scc[i] > scc[i+m]) val[i] = true;
    }
    for(int i = 1; i <= m; i++){
        cout << (val[i] ? "+ " : "- ");
    }
}