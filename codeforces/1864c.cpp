#include<bits/stdc++.h>
using namespace std;

void sol(){
    int n, k = 0;
    vector<int> ans;
    cin >> n;
    ans.push_back(n);
    while(__builtin_popcount(n) > 1) {
        if(1<<k & n) {
            n -= 1<<k;
            ans.push_back(n);
        }
        k++;
    }
    while(n > 1) {
        ans.push_back(n = n/2);
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i << " ";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        sol();
        cout << "\n";
    }
}