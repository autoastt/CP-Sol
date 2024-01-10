#include<bits/stdc++.h>
using namespace std;

vector<string> v;
bool vis[3][3][3];
string s[3];

struct A{
    int x, y, px, py, d;
    string ans;
};

void bfs(int a, int b){
    queue<A> q;
    string ss = "";
    ss += s[a][b];
    q.push({a, b, -1, -1, 0, ss});
    fill_n(vis[0][0], 3*3*3, 0);
    while(!q.empty()){
        auto [x, y, px, py, d, ss] = q.front();
        q.pop();
        vis[x][y][d] = true;
        if(d == 2){
            v.push_back(ss);
            continue;
        }
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;
                if(x+i == px && y+j == py) continue;
                if(x+i < 0 || x+i > 2 || y+j < 0 || y+j > 2) continue;
                if(!vis[x+i][y+j][d+1]) 
                    q.push({x+i, y+j, x, y, d+1, ss + s[x+i][y+j]});
            }
        }
    }
}

int main(){
    cin >> s[0] >> s[1] >> s[2];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            bfs(i,j);
    sort(v.begin(), v.end());
    cout << v[0];
}