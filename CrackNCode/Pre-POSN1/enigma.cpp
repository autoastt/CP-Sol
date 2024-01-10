#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int c[N], ok[30], ans;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        cin >> c[i];
    }
    for(int i = 0; i < 26; i++){
        int ch[30] = {};
        for(int j = 0; j < s.size(); j++){
            ch[(s[j] - 'A' + c[j] * i) % 26]++;
        }
        for(int j = 0; j < 26; j++) ans = max(ans, ch[j]);
    }
    cout << ans;
}