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
    ll n;
    cin >> n;

    ll x, e = 0, o = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> x;
        if (x % 2 == 0)
            e += 1;
        else 
            o += 1;
    }

    if (n == 1) {
        cout << "NO" << endl;
        return;
    }

    if (e == 0) {
        if (o % 2 == 0) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
        return; 
    } 
    
    if (o == 0) {
        cout << "YES" << endl;
        return;
    }

    if (o % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
   
}

void solve() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        caseSol();
    }
}
