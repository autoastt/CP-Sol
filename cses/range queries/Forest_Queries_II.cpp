#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1005;

ll fw[N][N];
bool a[N][N];

void update(int i, int j, int val){
    for(int x = i; x < N; x += x & -x)
        for(int y = j; y < N; y += y & -y)
            fw[x][y] += val;
}

ll query(int i, int j){
    ll ret = 0;
    for(int x = i; x > 0; x -= x & -x)
        for(int y = j; y > 0; y -= y & -y)
            ret += fw[x][y];
    return ret;
}

int main(){
    int n, q; 
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            a[i][j] = (c == '*');
            if(a[i][j]) update(i, j, 1);
        }
    }
    while(q--){
        int c, x, y;
        cin >> c >> x >> y;
        if(c == 1){
            a[x][y] ? update(x, y, -1) : update(x, y, 1);
            a[x][y] = !a[x][y];
        }
        else{
            int i, j;
            cin >> i >> j;
            cout << query(i, j) - query(x-1,j) - query(i,y-1) + query(x-1,y-1) << "\n";
        }
    }
}