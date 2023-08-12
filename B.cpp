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
    string s;
    cin >> s;
    ll p = 0, r = static_cast<ll>(s.size());
    for (ll i = static_cast<ll>(s.size()) - 1; i >= 0; --i) {
        if (p == 1) {
            if (s[i] == '9') {
                s[i] = '0';
            } else {
                s[i] = s[i] + 1;
                p = 0;
            }
        }
        if (s[i] >= '5') {
           p = 1;
           r = min(r, i);
        }
    }
    if (p == 1) {
        cout << '1';
    }
    for (ll i = 0; i < s.size(); ++i) {
        if (i < r) 
            cout << s[i];
        else 
            cout << '0';
    }
    cout << endl;
}

void solve() {
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        caseSol();
    }
}
