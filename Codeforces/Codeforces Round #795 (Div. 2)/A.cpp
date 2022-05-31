#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (v[i]%2 == 1) {
                ans++;
            }
        }
        cout << min(ans, n-ans) << '\n';
    }
}