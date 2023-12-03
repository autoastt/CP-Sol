#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int s[N], b[N], ans = INT_MAX;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i] >> b[i];
    for(int i = 1; i < (1 << n); i++){
        int snow = 1, bnow = 0;
        for(int j = 0; j < n; j++){
            if((1 << j) & i) {
                snow *= s[j];
                bnow += b[j];
            }
        }
        ans = min(ans, abs(snow - bnow));
    }
    cout << ans;
}