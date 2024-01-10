/*
List Removals
7 Dec 2023
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int a[N], fw[N];

int query(int i){
    int ret = 0;
    for(; i > 0; i -= i & -i) ret += fw[i];
    return ret;
}

void update(int i, int x){
    for(; i < N; i += i & -i) fw[i] += x;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        update(i, 1);
    }
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        int l = 1, r = n, mid;
        while(l < r){
            mid = (l + r) / 2;
            if(query(mid) >= x) r = mid;
            else l = mid+1;
        }
        cout << a[r] << " ";
        update(r, -1);
    }
}
