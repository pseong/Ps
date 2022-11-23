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

int cost[30][30];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            bool ok = true;
            for (int k=1; k<=n; k++) {
                if (i == k || j == k) continue;
                if (v[i][j] > v[i][k] + v[k][j]) {
                    cout << -1 << '\n';
                    return 0;
                }
                else if (v[i][j] == v[i][k] + v[k][j]) {
                    ok = false;
                }
            }
            if (ok) ans += v[i][j];
        }
    }
    cout << ans << '\n';
}