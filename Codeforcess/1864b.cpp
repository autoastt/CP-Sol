#include<bits/stdc++.h>
using namespace std;
void sol(){
    int n,k;
    string s;
    cin >> n >> k >> s;
    if(k%2==0){
        sort(s.begin(), s.end());
        cout << s << "\n";
        return;
    }
    string a,b;
    for(int i = 0; i < s.size(); i++){
        if(i%2 == 0) a += s[i];
        else b += s[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i = 0, j = 0; i < a.size() && j < b.size();){
        cout << a[i++] << b[j++];
        if(i == a.size() && j != b.size()) cout << b[j++];
        else if(i != a.size() && j == b.size()) cout << a[i++];
    }
    cout << "\n";
    return;
}
int main(){
    int t;
    
    cin >> t;
    while(t--){
        sol();
    }
}