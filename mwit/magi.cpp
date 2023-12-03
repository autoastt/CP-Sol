#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 105;
const int M = 1e9+7;
const int X = 27;

ll dp[N][3][X][X][X], comp[3][X][X], tre[3], ans;

bool v(int i){
    return (i == 1 || i == 5 || i == 9 || i == 15 || i == 21);
}

bool ch(int i, int j, int k, int x){
    return (i == 't'-'a'+1 && j == 'r'-'a'+1 && k == 'e'-'a'+1 && x == 'e'-'a'+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x = 0;
    string s;
    cin >> n >> s;
    // i = 1:
    if(n == 1){
        cout << 0;
        return 0;
    }
    if(s[0] != '_'){
        dp[1][v(s[0]-'a'+1)][0][0][s[0]-'a'+1] = 1;
    }
    else{
        for(int i = 1; i <= 26; i++){
            dp[1][v(i)][0][0][i] = 1;
        }
    }
    // i = 2:
    if(s[1] != '_'){
        for(int i = 1; i <= 26; i++) 
            dp[2][v(i)+v(s[1]-'a'+1)][0][i][s[1]-'a'+1] += dp[1][v(i)][0][0][i];
    }
    else{
        for(int i = 1; i <= 26; i++){
            for(int j = 1; j <= 26; j++)
                dp[2][v(i)+v(j)][0][i][j] += dp[1][v(i)][0][0][i];
        }
    }
    if(n == 2){
        for(int i = 1; i <= 26; i++)
            for(int j = 1; j <= 26; j++)
                ans += dp[2][2][0][i][j];
        cout << ans;
        return 0;
    }
    // i = 3:
    if(s[2] != '_'){
        for(int i = 1; i <= 26; i++)
            for(int j = 1; j <= 26; j++) 
                dp[3][min(v(i)+v(j)+v(s[2]-'a'+1), 2)][i][j][s[2]-'a'+1] += dp[2][v(i)+v(j)][0][i][j];
    }
    else{
        for(int i = 1; i <= 26; i++){
            for(int j = 1; j <= 26; j++)
                for(int k = 1; k <= 26; k++)
                    dp[3][min(v(i)+v(j)+v(k),2)][i][j][k] += dp[2][v(i)+v(j)][0][i][j];
        }
    }
    if(n == 3){
        for(int i = 1; i <= 26; i++)
            for(int j = 1; j <= 26; j++)
                for(int k = 1; k <= 26; k++)
                    ans += dp[3][2][i][j][k];
        cout << ans;
        return 0;
    }
    // i > 3: O(2 * 100 * 26^4)
    for(int sz = 4; sz <= n; sz++){
        for(int v_last = 0; v_last <= 2; v_last++){
            for(int i = 1; i <= 26; i++){
                for(int j = 1; j <= 26; j++){
                    for(int k = 1; k <= 26; k++){
                        if(s[sz-1] != '_'){
                            x = s[sz-1] - 'a' + 1;
                            if(ch(i,j,k,x)) continue;
                            dp[sz][min(v_last+v(x), 2)][j][k][x] += dp[sz-1][min(v_last, 2)][i][j][k];
                            dp[sz][min(v_last+v(x), 2)][j][k][x] %= M;
                        }
                        else{
                            for(int now = 1; now <= 26; now++){
                                if(ch(i,j,k,now)) continue;
                                dp[sz][min(v_last+v(now), 2)][j][k][now] += dp[sz-1][min(v_last, 2)][i][j][k];
                                dp[sz][min(v_last+v(now), 2)][j][k][now] %= M;
                            }
                        }
                    }
                }
            }
        }
    }
    // calculate ans
    for(int i = 1; i <= 26; i++){
        for(int j = 1; j <= 26; j++){
            for(int k = 1; k <= 26; k++){
                ans += dp[n][2][i][j][k];
                ans %= M;
            }
        }
    }
    cout << ans;
}