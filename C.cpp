#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

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
    ll x;
    cin >> x;

    ll n = x * (x - 1) / 2;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //cout << x << endl;
    x -= 1;
    sort(a.begin(), a.end());
    for (ll i = 0; i < n; ) {
        cout << a[i] << " ";
        i += x;
        x -= 1;
    }
    cout << a[n - 1] << endl;
}

void solve() {
    ll t;
    cin  >> t;
    for (ll i = 0; i < t; ++i) {
        caseSol();
    }
    
}
