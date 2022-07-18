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

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    string s;
    cin >> s;
    vector<pi> vp0, vp1;
    for (int i=0; i<n; i++) {
        if (s[i] == '0') {
            vp0.push_back({v[i], i});
        }
        else {
            vp1.push_back({v[i], i});
        }
    }
    srt(vp0);
    srt(vp1);
    int now = 1;
    vector<int> ans(n);
    for (auto at : vp0) {
        ans[at.second] = now;
        now++;
    }
    for (auto at : vp1) {
        ans[at.second] = now;
        now++;
    }
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
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