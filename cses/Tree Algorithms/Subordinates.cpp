/*
Euler Tour Training
5 Jan 2024
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int in[N], out[N], timer;
vector<int> adj[N];

void dfs(int u){
    in[u] = ++timer;
    for(auto v : adj[u]) dfs(v);
    out[u] = timer;
}


int main(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) cout << out[i]-in[i] << " ";
}