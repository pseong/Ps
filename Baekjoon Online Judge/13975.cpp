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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> p;
        for (int i=0; i<n; i++) {
            ll a;
            cin >> a;
            p.push(a);
        }
        ll ans = 0;
        while (p.size() != 1) {
            ll a = p.top();
            p.pop();
            ll b = p.top();
            p.pop();
            ans += a + b;
            p.push(a + b);
        }
        cout << ans << '\n';
    }
}