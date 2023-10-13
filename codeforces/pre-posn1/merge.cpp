#include<bits/stdc++.h>
using namespace std;

int main(){
    int odd = 0, n, c, d;
    cin >> n >> c >> d;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x%2) odd++;
    }
    bool shit = false;
    for(int i = 0; i < n; i++){
        if(shit) break;
        if(n-i*c+i < 0 && n-i*d+i < 0) break;
        if(n-i*c+i >= 0 && (n-i*c+i) % (d-1) == 1) shit = true;
        if(n-i*d+i >= 0 && (n-i*d+i) % (c-1) == 1) shit = true;
    }
    if(odd%2 && (shit || c == 2 || d == 2)) cout << "Yes";
    else cout << "No";
}