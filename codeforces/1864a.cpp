#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int x,y,n;
        cin >> x >> y >> n;
        if(y-x >= n*(n-1)/2){
            int now = y;
            vector<int> ans;
            for(int i = 1; i < n; i++){
                ans.push_back(now);
                now -= i;
            }
            ans.push_back(x);
            reverse(ans.begin(), ans.end());
            for(auto i : ans) cout << i << " ";
            cout << "\n";
        }
        else cout << -1 << "\n";
    }

}