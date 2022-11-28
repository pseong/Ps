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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<ll>> v(n + 1, vector<ll>(n + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<i128>> dp(n + 1, vector<i128>(n + 1, 0));
    dp[1][1] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (v[i][j] == 0) continue;
            if (i + v[i][j] <= n) dp[i + v[i][j]][j] += dp[i][j];
            if (j + v[i][j] <= n) dp[i][j + v[i][j]] += dp[i][j];
        }
    }
}