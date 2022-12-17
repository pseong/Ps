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
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int j = -1;
    int cnt = 0;
    int ans = 1e9;
    for (int i=0; i<n; i++) {
        while (cnt < k && j + 1 < n) {
            j++;
            if (v[j] == 1) cnt++;
        }
        if (cnt == k) ans = min(ans, j - i + 1);
        if (v[i] == 1) cnt--;
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}