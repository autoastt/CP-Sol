#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> v;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++) v.push_back({i,j});
    }
    long long ans = 0;
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            for(int k = j+1; k < v.size(); k++){
                ans += abs(v[i].x * v[j].y + v[j].x * v[k].y + v[k].x * v[i].y - v[i].y * v[j].x - v[j].y * v[k].x - v[k].y * v[i].x);
            }
        }
    }
    cout << ans;
}