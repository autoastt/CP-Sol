#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll a[N], c[N], mst;
struct A{
    ll u,v,w;
    bool operator <(const A&o)const{
        return w > o.w;
    }
};

int parent[N],sz[N],n;

void initial(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		sz[i]=1;
	}
}
int _find(int u){
	return parent[u]=u==parent[u]?u:_find(parent[u]);
}
void unite(int u,int v, ll w){
	u=_find(u);
	v=_find(v);
	if(u!=v){
		if(sz[u]<sz[v]) swap(u,v);
		parent[v]=u;
		sz[u]+=sz[v];
		// MST can be applied here
		mst+=w;
	}
}


void solve() {
    cin >> n;
    vector<A> e;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        e.push_back({i,a[i],2*c[i]});
        e.push_back({a[i],i,c[i]});
    }
    sort(e.begin(), e.end());
    mst = 0;
    for(int i = 0; i < e.size(); i++){

    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}