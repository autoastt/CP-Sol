#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;

int t[N][N], a, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool p[N][N];
char b[N][N];
queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        if(p[x][y]) continue;
        p[x][y] = true;
        for(int i = 0; i < 4; i++){
            int xx = x+dx[i], yy = y+dy[i];
            if(b[xx][yy] == 'P') q.push({xx, yy});
        }
    }
}

int main(){
    int w, l;
    cin >> l >> w;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= l; j++){
            cin >> b[i][j];
            if(b[i][j] == 'T') t[i][j]++;
            t[i][j] += t[i-1][j] + t[i][j-1] - t[i-1][j-1];
        }
    }
    for(int sz = 1; sz <= min(w, l); sz++){
        int mn = 1e5;
        for(int i = sz; i <= w; i++){
            for(int j = sz; j <= l; j++){
                if(t[i][j] - t[i-sz][j] - t[i][j-sz] + t[i-sz][j-sz]) continue;
                int cnt = 0;
                fill_n(p[0], N*N, 0);
                for(int ii = i-sz+1; ii <= i; ii++){
                    for(int jj = j-sz+1; jj <= j; jj++){
                        if(b[ii][jj] == 'P' && !p[ii][jj]){
                            cnt++;
                            q.push({ii, jj});
                            bfs();
                        }
                    }
                }
                mn = min(mn, cnt);
            }
        }
        if(mn != 1e5) a = sz*sz, m = mn;
    }
    cout << a << " " << m;
}