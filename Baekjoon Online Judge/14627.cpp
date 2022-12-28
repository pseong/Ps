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

ll s, c, v[1010101];

bool f(ll m) {
    ll cnt = 0;
    for (int i=0; i<s; i++) {
        cnt += v[i] / m;
    }
    return cnt >= c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s >> c;
    ll sum = 0;
    for (int i=0; i<s; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll lo = 1;
    ll hi = 1e9;
    ll ans = 0;
    while (lo <= hi) {
        ll m = (lo + hi) / 2;
        if (f(m)) {
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    cout << sum - ans * c << '\n';
}