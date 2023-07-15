#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
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

void solve(int CASE) {
    ll n, x, y;
    cin >> n >> x >> y;
    string a, b;
    cin >> a >> b;
    vector<ll> v(0);
    for (int i=0; i<n; i++) {
        if (a[i] != b[i]) v.push_back(i);
    }
    if (x >= y) {
        if (v.size() == 2 && v[0]+1 == v[1]) {
            cout << min(x, y*2) << '\n';
        }
        else {
            cout << y * v.size() / 2 << '\n';
        }
    }
    else {
        if (v.empty()) {
            cout << 0 << '\n';
            return;
        }
        vector<ll> dp(n);
        dp[0] = 0;
        dp[1] = min((v[1] - v[0])*x, y);
        for (int i=2; i<n; i++) {
            if (i%2 == 0) {
                dp[i] = min(dp[i-2] + (v[i] - v[i-1])*x, dp[i-1]);
            }
            else {
                dp[i] = min(dp[i-2] + (v[i] - v[i-1])*x, dp[i-1] + y);
            }
        }
        cout << dp[n-1] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

#if TEST
    freopen("/Users/macrent/ProgramSolving/input.txt", "r", stdin);
#endif

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
        // cout << 3 << '\n';
    }
}