#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    int ans=0;
    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a+b+c>=2) ans++;
    }
    cout << ans;
}