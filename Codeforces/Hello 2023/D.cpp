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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    int k;
    cin >> k;
    multiset<int> ms;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    for (int i=1; i<=n; i++) {
        if (a[i] < b[i]) {
            no();
            return;
        }
    }
    stack<pi> st;
    for (int i=1; i<=n; i++) {
        while (st.size() && st.top().second < b[i]) {
            if (st.top().first != st.top().second) {
                auto it = ms.lower_bound(st.top().second);
                if (it == ms.end() || *it != st.top().second) {
                    no();
                    return;
                }
                while (st.size() && st.top().second == *it) {
                    st.pop();
                }
                ms.erase(it);
            }
            else st.pop();
        }
        st.push({a[i], b[i]});
    }
    while (st.size()) {
        if (st.top().first == st.top().second) st.pop();
        else {
            auto it = ms.lower_bound(st.top().second);
            if (it == ms.end() || *it != st.top().second) {
                no();
                return;
            }
            while (st.size() && st.top().second == *it) {
                st.pop();
            }
            ms.erase(it);
        }
    }
    yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}