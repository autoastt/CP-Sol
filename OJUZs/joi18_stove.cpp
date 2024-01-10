#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N], b[N], cnt, ans;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0) v.push_back(a[i]-a[i-1]-1);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n-k; i++){
        ans += v[i];
    }
    cout << ans + n;
}