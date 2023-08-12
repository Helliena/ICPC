#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define f first
#define s second

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

void caseSol() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (ll j = 0; j < n; ++j) {
        cin >> b[j];
    }

    ll mx = a[0] - b[0];
    vector<pll> res(n);
    for (ll i = 0; i < n; ++i) {
        res[i].f = a[i] - b[i];
        res[i].s = i;

        mx = max(mx, a[i] - b[i]);
    }

    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        if (res[i].f == mx) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
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
