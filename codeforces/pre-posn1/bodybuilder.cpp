#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 25;
int s[N], w[N], ans[N];


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i] >> w[i];
    for(int i = 0; i < (1 << n); i++){
        bool shit = false;
        for(int j = 0; j < n; j++){
            if(shit) break;
            for(int k = 0; k < n; k++){
                if(shit) break;
                if(j == k) continue;
                if((i & (1 << j)) && (i & (1 << k))){
                    if(s[j] >= s[k] && w[j] <= w[k]) shit = true;
                }
            }
        }
        ans[__builtin_popcount(i)] += !shit;
    }
    while(m--){
        int x; cin >> x; cout << ans[x] << "\n";
    }
}