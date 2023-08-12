#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define f first
#define s second

ll const INF = 1e18;

void acceleration(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve();

int main() {
    acceleration();
    solve();
}

ll checkPair(map<ll, ll>& m, ll x1, ll y1, ll x, ll y) {
    if (!(x1 * y1 == y && x1 + y1 == x)) {
        return 0;
    }

    if (x1 != y1) {
        return m[x1] * m[y1];
    } else {
        return m[x1] * (m[x1] - 1) / 2;
    }
}

ll getNumOfPairs(map<ll, ll>& m, ll x, ll y) {
    ll d = x * x - 4 * y;
    if (d < 0)
      return 0;
    
    if (d == 0) {
        ll x1 = x / 2;
        ll y1 = x - x1;

        return checkPair(m, x1, y1, x, y);
    } 

    ll x1 = (x + sqrt(d)) / 2;
    ll y1 = x - x1;

    return checkPair(m, x1, y1, x, y);
}

void caseSol() {
    ll n, m;
    cin >> n;
    map<ll, ll> a;
    ll x, y;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        a[x] += 1;
    }
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        cin >> x >> y;
        cout << getNumOfPairs(a, x, y) << " ";
    }
    cout << endl;
}

void solve() {
    ll t;
    cin  >> t;
    for (ll i = 0; i < t; ++i) {
        caseSol();
    }
}
