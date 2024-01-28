#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> xa >> ya >> xb >> yb;
    if(xa >= xb) return void(cout << "Draw\n");
    if(xa % 2 == xb % 2){
        // likely to be bob
        if(ya < yb){
            int dx = (xb-xa)/2;
            ya = max(1, ya-dx);
            yb = max(1, yb-dx);
            xa += dx;
            xb -= dx;
        }
        else{
            int dx = (xb-xa)/2;
            ya = min(w, ya+dx);
            yb = min(w, yb+dx);
            xa += dx;
            xb -= dx;
        }
        if(abs(yb-ya) == 0) return void(cout << "Bob\n");
        cout << "Draw\n";
    }
    else{
        // likely to be alice
        if(yb < ya){
            int dx = (xb-xa)/2;
            yb = max(1, yb-dx);
            ya = max(1, ya-dx);
            xa += dx;
            xb -= dx;
        }
        else{
            int dx = (xb-xa)/2;
            yb = min(w, yb+dx);
            ya = min(w, ya+dx);
            xa += dx;
            xb -= dx;
        }
        if(abs(yb-ya) <= 1) return void(cout << "Alice\n");
        cout << "Draw\n";
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