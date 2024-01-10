/*
Salary Queries
Compressed Coorniates Fenwick Tree
9 Dec 2023
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;

ll a[N], fw[2*N];
vector<int> coord = {0};
queue<pair<int,pair<int,int>>> q;

void update(int idx, int x){
    int i = lower_bound(coord.begin(), coord.end(), idx) - coord.begin();
    for(; i < 2*N; i += i & -i) fw[i] += x;
}

int query(int idx){
    int i = upper_bound(coord.begin(), coord.end(), idx) - coord.begin() - 1;
    ll ret = 0;
    for(; i > 0; i -= i & -i) ret += fw[i];
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        coord.push_back(a[i]);
    }
    while(m--){
        char c;
        int x, y;
        cin >> c >> x >> y;
        if(c == '!'){
            coord.push_back(y);
            q.push({0, {x,y}});
        }
        else{
            q.push({1, {x,y}});
        }
    }
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    for(int i = 1; i <= n; i++) update(a[i], 1);
    while(!q.empty()){
        auto [c, p] = q.front();
        auto [x, y] = p;
        q.pop();
        if(!c){
            update(a[x], -1);
            update(a[x] = y, 1);
        }
        else{
            cout << query(y) - query(x-1) << "\n";
        }
    }
}