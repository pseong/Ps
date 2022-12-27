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

vector<int> primes;
int chk[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=2; i<=1000; i++) {
        if (chk[i] == 0) {
            primes.push_back(i);
            for (int j=i+i; j<=1000; j+=i) {
                chk[j] = 1;
            }
        }
    }

    int n = primes.size();

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    if (primes[i] + primes[j] + primes[k] == x) {
                        cout << primes[i] << ' ' << primes[j] << ' ' << primes[k] << '\n';
                        goto g;
                    }
                }
            }
        }
        cout << 0 << '\n';
        g:
        continue;
    }
}