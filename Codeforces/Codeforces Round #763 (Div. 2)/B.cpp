#include <bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

void solve() {
    int n; cin >> n;
    vector<tuple<int, int, int>> v(n);
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = { r-l, l, r };
    }
    sort(v.begin(), v.end());
    vector<int> chk(n+1, 0);
    vector<tuple<int, int, int>> ans;
    for (int i=0; i<n; i++) {
        auto [x, l, r] = v[i];
        for (int j=l; j<=r; j++) {
            if (chk[j] == 0) {
                chk[j] = 1;
                ans.push_back({l, r, j});
            }
        }
    }
    for (auto [l, r, x] : ans) {
        cout << l << ' ' << r << ' ' << x << '\n';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        solve();
    }
}