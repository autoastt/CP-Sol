#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;
const int N = 1e5 + 5;
int a[N], vis[N];
vector<int> st, scc[N], adj[N], radj[N];

void dfs1(int x) {
    vis[x] = 1;
    for(int y : adj[x]) if(!vis[y]) dfs1(y);
    st.push_back(x);
}

void dfs2(int x, int i){
    vis[x] = 1;
    scc[i].push_back(x);
    for(int y : radj[x]) if(!vis[y]) dfs2(y, i);
}

void solve() {
    int n,k, cnt = 1;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vis[i] = 0;
        scc[i].clear();
        adj[i].clear();
        radj[i].clear();
    }
    if(k == 1){
        for(int i = 1; i <= n; i++){
            if(a[i] != i){
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }
    st.clear();
    for(int i = 1; i <= n; i++){ 
        adj[i].push_back(a[i]);
        radj[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) 
        if(!vis[i]) 
            dfs1(i);
    fill_n(vis, N, false);
    reverse(st.begin(), st.end());
    for(int i : st){
        if(!vis[i]) 
            dfs2(i, cnt++);
    }
    for(int i = 1; i <= cnt; i++){
        if(scc[i].size() == 1 && scc[i][0] == a[scc[i][0]]){
            cout << "No\n";
            return;
        }
        else if(scc[i].size() > 1 && scc[i].size() != k){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}