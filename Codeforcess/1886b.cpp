#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    double px,py,ax,ay,bx,by,ab,ao,bo,ap,bp,ans = 1e9;
    cin >> px >> py >> ax >> ay >> bx >> by;
    ab = sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))/2;
    ao = sqrt((ax)*(ax)+(ay)*(ay));
    bo = sqrt((by)*(by)+(bx)*(bx));
    ap = sqrt((ax-px)*(ax-px)+(ay-py)*(ay-py));
    bp = sqrt((bx-px)*(bx-px)+(by-py)*(by-py));
    ans = min(ans, max(ao, ap));
    ans = min(ans, max(bo, bp));
    ans = min(ans, max({ao, ab, bp}));
    ans = min(ans, max({bo, ab, ap}));
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}